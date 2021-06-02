#include <iomanip>
#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>

int main();
void operate_calculator();
void output_imm(double a, double b, bool init);
void negate(double &a, double &b, bool init);
void invert(double &a, double &b, bool &init);
void ms(double a, double b, double &ma, double &mb, bool init, bool &minit);
void mr(double &a, double &b, double ma, double mb, bool init, bool minit);
void mc(double a, double b, bool init, bool &minit);
void mplus(double a, double b, double &ma, double &mb, bool init, bool minit);
void msubtract(double a, double b, double &ma, double &mb, bool init,
               bool minit);
void scalar_add(double scalar, double &a, double &b, bool init);
void scalar_subtract(double scalar, double &a, double &b, bool init);
void scalar_multiply(double scalar, double &a, double &b, bool init);
void scalar_divide(double scalar, double &a, double &b, bool &init);
void scalar_divided_by(double scalar, double &a, double &b, bool &init);
void interval_add(double c, double d, double &a, double &b, bool init);
void interval_subtract(double c, double d, double &a, double &b, bool init);
void interval_multiply(double c, double d, double &a, double &b, bool init);
void interval_divide(double c, double d, double &a, double &b, bool &init);
void intersect(double c, double d, double &a, double &b, bool &init);
void integers(double a, double b, bool init);
void cartesian_integers(double c, double d, double a, double b, bool init);
double get_min(double a, double b, double c, double d);
double get_max(double a, double b, double c, double d);

int main() {
  operate_calculator();
  return 0;
}

void operate_calculator() {

  double mem_val_a{0};
  double mem_val_b{0};
  double imm_val_a{0};
  double imm_val_b{0};
  bool imm_is_initialized{false};
  bool mem_is_initialized{false};

  std::string input;
  bool quit{false};

  while (!quit) {
    std::cout << "input :> ";
    std::getline(std::cin, input);
    if (input == "exit") {
      quit = true;
    } else {
      std::vector<std::string> tokens;
      std::istringstream str(input);
      for (std::string input; str >> input;) {
        tokens.push_back(input);
      }

      if (tokens[0] == "enter") {
        if (stod(tokens[1]) > stod(tokens[2])) {
          std::cout << "Error: invalid interval as " << tokens[1] << " > "
                    << tokens[2];
          std::cout << std::endl;
        } else {
          imm_is_initialized = true;
          imm_val_a = stod(tokens[1]);
          imm_val_b = stod(tokens[2]);
        }
        output_imm(imm_val_a, imm_val_b, imm_is_initialized);
      } else if (tokens[0] == "negate") {
        negate(imm_val_a, imm_val_b, imm_is_initialized);
      } else if (tokens[0] == "invert") {
        invert(imm_val_a, imm_val_b, imm_is_initialized);
      } else if (tokens[0] == "ms") {
        ms(imm_val_a, imm_val_b, mem_val_a, mem_val_b, imm_is_initialized,
           mem_is_initialized);
      } else if (tokens[0] == "mr") {
        mr(imm_val_a, imm_val_b, mem_val_a, mem_val_b, imm_is_initialized,
           mem_is_initialized);
      } else if (tokens[0] == "mc") {
        mc(imm_val_a, imm_val_b, imm_is_initialized, mem_is_initialized);
      } else if (tokens[0] == "m+") {
        mplus(imm_val_a, imm_val_b, mem_val_a, mem_val_b, imm_is_initialized,
              mem_is_initialized);
      } else if (tokens[0] == "m-") {
        msubtract(imm_val_a, imm_val_b, mem_val_a, mem_val_b,
                  imm_is_initialized, mem_is_initialized);
      } else if (tokens[0] == "scalar_add") {
        scalar_add(stod(tokens[1]), imm_val_a, imm_val_b, imm_is_initialized);
      } else if (tokens[0] == "scalar_subtract") {
        scalar_subtract(stod(tokens[1]), imm_val_a, imm_val_b,
                        imm_is_initialized);
      } else if (tokens[0] == "scalar_multiply") {
        scalar_multiply(stod(tokens[1]), imm_val_a, imm_val_b,
                        imm_is_initialized);
      } else if (tokens[0] == "scalar_divide") {
        scalar_divide(stod(tokens[1]), imm_val_a, imm_val_b,
                      imm_is_initialized);
      } else if (tokens[0] == "scalar_divided_by") {
        scalar_divided_by(stod(tokens[1]), imm_val_a, imm_val_b,
                          imm_is_initialized);
      } else if (tokens[0] == "interval_add") {
        interval_add(stod(tokens[1]), stod(tokens[2]), imm_val_a, imm_val_b,
                     imm_is_initialized);
      } else if (tokens[0] == "interval_subtract") {
        interval_subtract(stod(tokens[1]), stod(tokens[2]), imm_val_a,
                          imm_val_b, imm_is_initialized);
      } else if (tokens[0] == "interval_multiply") {
        interval_multiply(stod(tokens[1]), stod(tokens[2]), imm_val_a,
                          imm_val_b, imm_is_initialized);
      } else if (tokens[0] == "interval_divide") {
        interval_divide(stod(tokens[1]), stod(tokens[2]), imm_val_a, imm_val_b,
                        imm_is_initialized);
      } else if (tokens[0] == "intersect") {
        intersect(stod(tokens[1]), stod(tokens[2]), imm_val_a, imm_val_b,
                  imm_is_initialized);
      } else if (tokens[0] == "integers") {
        integers(imm_val_a, imm_val_b, imm_is_initialized);
      } else if (tokens[0] == "cartesian_integers") {
        cartesian_integers(stod(tokens[1]), stod(tokens[2]), imm_val_a,
                           imm_val_b, imm_is_initialized);
      } else {
        std::cout << "Error: illegal command" << std::endl;
      }
    }
  }
  std::cout << "Bye bye: Terminating interval calculator program.";
}

void output_imm(double a, double b, bool init) {
  if (!init) {
    std::cout << "--" << std::endl;
  } else {
    std::cout << "[" << a << ", " << b << "]" << std::endl;
  }
}

void negate(double &a, double &b, bool init) {
  double temp{a};
  a = b;
  b = temp;
  a /= -1;
  b /= -1;
  output_imm(a, b, init);
}

void invert(double &a, double &b, bool &init) {
  if (!init) {
    output_imm(a, b, init);
  } else {
    if ((a <= 0) && (b >= 0)) {
      std::cout << "Error: division by zero" << std::endl;
      init = false;
      output_imm(a, b, init);
    } else {
      double temp{a};
      a = b;
      b = temp;
      a = 1 / a;
      b = 1 / b;
      output_imm(a, b, init);
    }
  }
}

void ms(double a, double b, double &ma, double &mb, bool init, bool &minit) {
  if (!init) {
    output_imm(a, b, init);
  } else {
    ma = a;
    mb = b;
    minit = true;
    output_imm(a, b, init);
  }
}

void mr(double &a, double &b, double ma, double mb, bool init, bool minit) {
  if (minit && init) {
    a = ma;
    b = mb;
  }
  output_imm(a, b, init);
}

void mc(double a, double b, bool init, bool &minit) {
  minit = false;
  output_imm(a, b, init);
}

void mplus(double a, double b, double &ma, double &mb, bool init, bool minit) {
  if (minit && init) {
    ma += a;
    mb += b;
  }
  output_imm(a, b, init);
}

void msubtract(double a, double b, double &ma, double &mb, bool init,
               bool minit) {
  if (minit && init) {
    ma -= b;
    mb -= a;
  }
  output_imm(a, b, init);
}

void scalar_add(double scalar, double &a, double &b, bool init) {
  if (!init) {
    output_imm(a, b, init);
  } else {
    a += scalar;
    b += scalar;
    output_imm(a, b, init);
  }
}

void scalar_subtract(double scalar, double &a, double &b, bool init) {
  if (!init) {
    output_imm(a, b, init);
  } else {
    a -= scalar;
    b -= scalar;
    output_imm(a, b, init);
  }
}

void scalar_multiply(double scalar, double &a, double &b, bool init) {
  if (!init) {
    output_imm(a, b, init);
  } else {
    if (scalar < 0) {
      double temp{a};
      a = b;
      b = temp;
      a = a * scalar;
      b = b * scalar;
    } else {
      a = a * scalar;
      b = b * scalar;
    }
    output_imm(a, b, init);
  }
}

void scalar_divide(double scalar, double &a, double &b, bool &init) {
  if (!init) {
    output_imm(a, b, init);
  } else {
    if (scalar > 0) {
      a = a / scalar;
      b = b / scalar;
    } else if (scalar == 0) {
      std::cout << "Error: division by zero" << std::endl;
      init = false;
    } else {
      double temp{a};
      a = b;
      b = temp;
      a = a / scalar;
      b = b / scalar;
    }
    output_imm(a, b, init);
  }
}

void scalar_divided_by(double scalar, double &a, double &b, bool &init) {
  if (!init) {
    output_imm(a, b, init);
  } else {
    if ((a <= 0) && (b >= 0)) {
      std::cout << "Error: division by zero" << std::endl;
      init = false;
    } else if (scalar > 0) {
      double temp{a};
      a = b;
      b = temp;
      a = scalar / a;
      b = scalar / b;
    } else {
      a = scalar / a;
      b = scalar / b;
    }
    output_imm(a, b, init);
  }
}

void interval_add(double c, double d, double &a, double &b, bool init) {
  if (c > d) {
    std::cout << "Error: invalid interval as " << c << " > " << d;
    std::cout << std::endl;
    output_imm(a, b, init);
  } else if (!init) {
    output_imm(a, b, init);
  } else {
    a += c;
    b += d;
    output_imm(a, b, init);
  }
}

void interval_subtract(double c, double d, double &a, double &b, bool init) {
  if (c > d) {
    std::cout << "Error: invalid interval as " << c << " > " << d;
    std::cout << std::endl;
    output_imm(a, b, init);
  } else if (!init) {
    output_imm(a, b, init);
  } else {
    a -= d;
    b -= c;
    output_imm(a, b, init);
  }
}

void interval_multiply(double c, double d, double &a, double &b, bool init) {
  if (c > d) {
    std::cout << "Error: invalid interval as " << c << " > " << d;
    std::cout << std::endl;
    output_imm(a, b, init);
  } else if (!init) {
    output_imm(a, b, init);
  } else {
    double tempa{a};
    double tempb{b};
    a = get_min(tempa * c, tempa * d, tempb * c, tempb * d);
    b = get_max(tempa * c, tempa * d, tempb * c, tempb * d);
    output_imm(a, b, init);
  }
}

void interval_divide(double c, double d, double &a, double &b, bool &init) {
  if ((c <= 0) && (d >= 0)) {
    std::cout << "Error: division by zero" << std::endl;
    init = false;
    output_imm(a, b, init);
  } else if (c > d) {
    std::cout << "Error: invalid interval as " << c << " > " << d;
    std::cout << std::endl;
    output_imm(a, b, init);
  } else if (!init) {
    output_imm(a, b, init);
  } else {
    double tempa{a};
    double tempb{b};
    a = get_min(tempa / c, tempa / d, tempb / c, tempb / d);
    b = get_max(tempa / c, tempa / d, tempb / c, tempb / d);
    output_imm(a, b, init);
  }
}

void intersect(double c, double d, double &a, double &b, bool &init) {
  if (c > d) {
    std::cout << "Error: invalid interval as " << c << " > " << d;
    std::cout << std::endl;
    output_imm(a, b, init);
  } else if (!init) {
    output_imm(a, b, init);
  } else {
    double intersect_start{0};
    double intersect_end{0};
    if (((c < a) && (d < a)) || ((c > b) && (d > b))) {
      init = false;
    } else {
      if (a >= c) {
        intersect_start = a;
      } else {
        intersect_start = c;
      }
      if (d <= b) {
        intersect_end = d;
      } else {
        intersect_end = b;
      }
      a = intersect_start;
      b = intersect_end;
    }
    output_imm(a, b, init);
  }
}

void integers(double a, double b, bool init) {
  if (!init) {
    output_imm(a, b, init);
  } else {
    int ceila{ceil(a)};
    int floorb{floor(b)};
    while (ceila <= floorb) {
      if (!(ceila == floorb)) {
        std::cout << ceila << ", ";
      } else {
        std::cout << ceila;
      }
      ceila++;
    }
    std::cout << std::endl;
    output_imm(a, b, init);
  }
}

void cartesian_integers(double c, double d, double a, double b, bool init) {
  if (c > d) {
    std::cout << "Error: invalid interval as " << c << " > " << d;
    std::cout << std::endl;
    output_imm(a, b, init);
  } else if (!init) {
    output_imm(a, b, init);
  } else {
    double ceila{ceil(a)};
    double floorb{floor(b)};
    double ceilc{ceil(c)};
    double floord{floor(d)};
    double ceilctemp{ceilc};

    while (ceila <= floorb) {
      while (ceilc <= floord) {
        if (!((ceilc == floord) && (ceila == floorb))) {
          std::cout << "(" << ceila << "," << ceilc << "), ";
        } else {
          std::cout << "(" << ceila << "," << ceilc << ")" << std::endl;
        }
        ceilc++;
      }
      ceilc = ceilctemp;
      ceila++;
    }

    output_imm(a, b, init);
  }
}

double get_min(double a, double b, double c, double d) {
  double min{0};
  if (a <= b) {
    min = a;
  } else {
    min = b;
  }
  if (c <= min) {
    min = c;
  }
  if (d <= min) {
    min = d;
  }
  return min;
}

double get_max(double a, double b, double c, double d) {
  double max{0};
  if (a >= b) {
    max = a;
  } else {
    max = b;
  }
  if (c >= max) {
    max = c;
  }
  if (d >= max) {
    max = d;
  }
  return max;
}