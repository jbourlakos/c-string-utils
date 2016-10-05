#ifndef _STRING_UTILS_H
#define	_STRING_UTILS_H

char* stringCreate(int length);
void stringDestroy(char* allocatedString);
char* stringReplace(char** allocatedStringPtr, char* newStringValue);
char* stringCopy(char** allocatedStringPtr, char* stringValue);
int stringHasSuffix(char* string, char* suffix);
int stringHasSuffixCI(char* str, char* suf);
char* stringCreateUpper(char* str);
char* stringCreateLower(char* str);
char* stringCreateJoin(char* str1, char* str2, char* delim);
char* stringCreateHumanName(char* newStringValue);
int stringContains(char* string, char* substr);
int stringContainsCI(char* string, char* substr);
int stringCompare(char* s1, char* s2);
int stringCompareCI(char* s1, char* s2);

#endif	/* _STRING_UTILS_H */

