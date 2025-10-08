/* string_utils.c - String Manipulation Module */
#include <stdio.h>
#include "stringutils.h"
int stringCompare(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        
    }
    return *s1 - *s2;
}




