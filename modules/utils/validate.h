#ifndef VALIDATE_H
#define VALIDATE_H
#include <stdbool.h>

bool isOnlyNumbers(const char *value);
bool validateFieldNumber(const char *value, const char *fieldName);
bool validateField(const char *value, const char *fieldName);

#endif