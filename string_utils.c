#include "string_utils.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* stringCreate(int length) {
    char* result;
    if (length < 0) return NULL;
    result = (char*)malloc((length+1)*sizeof(char));
    result[length] = '\0';
    return result;
}

void stringDestroy(char* allocatedString) {
    free(allocatedString);
}

char* stringReplace(char** allocatedStringPtr, char* newStringValue) {
    if (allocatedStringPtr == NULL) return NULL;
    if (newStringValue == NULL) return NULL;
    free(*allocatedStringPtr);
    *allocatedStringPtr = stringCreate(strlen(newStringValue));
    strcpy(*allocatedStringPtr,newStringValue);
    return *allocatedStringPtr;
}

char* stringCopy(char** allocatedStringPtr, char* stringValue) {
    if (allocatedStringPtr == NULL) return NULL;
    if (stringValue == NULL) return NULL;
    free(*allocatedStringPtr);
    *allocatedStringPtr = stringCreate(strlen(stringValue));
    strcpy(*allocatedStringPtr,stringValue);
    return *allocatedStringPtr;
}

int stringHasSuffix(char* str, char* suf) {
    int strLen, sufLen;
    if ((str == NULL) || (suf == NULL)) return 0;
    strLen = strlen(str);
    sufLen = strlen(suf);
    if (sufLen == 0) return 1;
    if (sufLen > strLen) return 0;
    str = str + (strLen-1);
    suf = suf + (sufLen-1);
    while ((*suf == *str)&&(sufLen>0)) {
        suf--;
        str--;
        sufLen--;
    }
    if (sufLen == 0) return 1;
    return 0;
}

int stringHasSuffixCI(char* str, char* suf) {
    char * strCI, * sufCI;
    int result;
    strCI = stringCreateUpper(str);
    sufCI = stringCreateUpper(suf);
    result = stringHasSuffix(strCI,sufCI);
    stringDestroy(sufCI);
    stringDestroy(strCI);
    return result;
}

char* stringCreateUpper(char* str) {
    char* result;
    int length;
    int i = 0;
    if (str == NULL) return NULL;
    length = strlen(str);
    result = stringCreate(length);
    if (result == NULL) return NULL;
    for (i = 0; i < length; i++) {
        result[i] = toupper(str[i]);
    }
    return result;
}

char* stringCreateLower(char* str) {
    char* result;
    int length;
    int i = 0;
    if (str == NULL) return NULL;
    length = strlen(str);
    result = stringCreate(length);
    if (result == NULL) return NULL;
    for (i = 0; i < length; i++) {
        result[i] = tolower(str[i]);
    }
    return result;
}

char* stringCreateJoin(char* str1, char* str2, char* delim) {
    char* result;
    int sl1, sl2, sld;
    sl1 = strlen(str1);
    sl2 = strlen(str2);
    sld = strlen(delim);
    result = stringCreate(sl1+sld+sl2);
    strcpy(result,str1);
    strcpy(result + sl1,delim);
    strcpy(result + sl1 + sld,str2);
    return result;
}

int stringContains(char* string, char* substr) {
    return (strstr(string,substr) != NULL);
}

int stringContainsCI(char* string, char* substr) {
    char * strCI, * sufCI;
    int result;
    strCI = stringCreateUpper(string);
    sufCI = stringCreateUpper(substr);
    result = stringContains(strCI,sufCI);
    stringDestroy(sufCI);
    stringDestroy(strCI);
    return result;
}

int stringCompare(char* s1, char* s2) {
    return (strcmp(s1,s2));
}
int stringCompareCI(char* s1, char* s2) {
    char * strCI, * sufCI;
    int result;
    strCI = stringCreateUpper(s1);
    sufCI = stringCreateUpper(s2);
    result = stringCompare(strCI,sufCI);
    stringDestroy(sufCI);
    stringDestroy(strCI);
    return result;
}

char* stringCreateHumanName(char* newStringValue) {
    char* result = NULL;
    result = stringCreateLower(newStringValue);
    result[0] = toupper(result[0]);
    return result;
}