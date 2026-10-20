#ifndef GAME_OV009_GPIUTILITY_H
#define GAME_OV009_GPIUTILITY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpiutility.c, prototypes copied from their definitions. */

void strzcpy(char *p, const char *src, int n);
int gpiCheckForError(void **connection, const char *input, int fatal);
int gpiValueForKeyWithIndex(char *command, char *key, int *index, char *value, int len);
int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
int gpiCheckSocketConnect(void **connection, int sock, int *state);
int gpiReadKeyAndValue(void **connection, const char *buffer, int *index, char *key, char *value);
void gpiSetError(void **connection, int result, char *errorString);
void gpiSetErrorString(void **connection, char *errorString);
void gpiEncodeString(const char *plaintext, char *encoded);
/* END mkheaders: generated region */

#endif
