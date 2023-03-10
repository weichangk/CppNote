#include "section_02.h"
static int getG(void)
{
  return va;
}
int getO(void)
{
  return getG();
}

