#include "application.hpp"

int main(int argc, char **argv) {
  ExtexApplication app;
  STATUS result = app.Start();
  return result;
}
