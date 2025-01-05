#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "./validate.h"

bool isOnlyNumbers(const char *value)
{
  for (int i = 0; value[i] != '\0'; i++)
  {
    if (!isdigit(value[i]))
    {
      return false;
    }
  }
  return true;
}

bool validateField(const char *value, const char *fieldName)
{
  if (isOnlyNumbers(value))
  {
    printf("O campo %s não pode conter apenas números.\n", fieldName);
    return false;
  }
  return true;
}

bool validateFieldNumber(const char *value, const char *fieldName)
{
  if (!isOnlyNumbers(value))
  {
    printf("O campo %s não pode conter caracteres.\n", fieldName);
    return false;
  }
  return true;
}