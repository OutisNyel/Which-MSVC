#include "win_compat.h"

char *dup_env_value(const char *name)
{
  char *value = NULL;
  size_t len = 0;
  if (_dupenv_s(&value, &len, name) != 0 || value == NULL)
    return NULL;
  return value;
}
