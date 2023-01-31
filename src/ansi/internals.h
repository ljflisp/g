#pragma once
#include <string.h>

namespace _ansi_internals {
  char intToChar(int num) {
    return num + 48;
  }

  char* concat(char* str1, char* str2) {
    int len1 = 0;
    while(str1[len1] != '\0')
      ++len1;
    int len2 = 0;
    while(str2[len2] != '\0')
      ++len2;
    char* temp = (char*)malloc((len1 + len2) * sizeof(char*));
    strcpy(temp, str1);
    for(int i = 0; i < len2; ++i) {
      temp[len1 + i] = str2[i];
    }
    return temp;
  }

  char* intToString(int num) {
    int n = num;
    int len = 0;
    char* res = (char*) malloc(0);
    while(n > 0) {
      char curr_dig = intToChar(n % 10);
      n = n / 10;
      ++len;
      char* temp = res;
      int i = 1;
      res = (char*)malloc(len * sizeof(char*));
      while(i < len + 1) {
        res[i] = temp[i-1];
        ++i;
      }
      res[0] = curr_dig;
    }
    return res;
  }
}