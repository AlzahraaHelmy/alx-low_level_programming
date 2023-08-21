#ifndef _MAIN_H_
#define _MAIN_H_

int _putchar(char s);
int _islower(int s);
int _isalpha(int s);
int _abs(int m);
int _isupper(int s);
int _isdigit(int s);
int _strlen(char *t);
void _puts(char *t);
char *_strcpy(char *dest, char *src);
int _atoi(char *t);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int m);
char *_strncpy(char *dest, char *src, int m);
int _strcmp(char *s1, char *s2);
char *_memset(char *t, char b, unsigned int m);
char *_memcpy(char *dest, char *src, unsigned int m);
char *_strchr(char *t, char s);
unsigned int _strspn(char *t, char *accept);
char *_strpbrk(char *t, char *accept);
char *_strstr(char *haystack, char *needle);

#endif /* _MAIN_H_ */
