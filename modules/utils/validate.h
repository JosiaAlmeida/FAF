#ifndef VALIDATE_H
#define VALIDATE_H
#include <stdbool.h>

bool isOnlyNumbers(const char *value);
bool validateField(const char *value, const char *fieldName);

#endif