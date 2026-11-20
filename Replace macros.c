#include <stdio.h>
#include "myheader.h"

#define TEST 1

int main()
{
    printf("===== CONDITIONAL COMPILATION =====\n");

#ifdef TEST
    printf("TEST is defined\n");
#else
    printf("TEST is not defined\n");
#endif

#if TEST == 1
    printf("Condition is TRUE\n");
#else
    printf("Condition is FALSE\n");
#endif

#ifndef XYZ
    printf("XYZ is not defined\n");
-- INSERT --                                   