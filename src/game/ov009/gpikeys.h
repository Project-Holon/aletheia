#ifndef GAME_OV009_GPIKEYS_H
#define GAME_OV009_GPIKEYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpikeys.c, prototypes copied from their definitions. */

void gpiStatusInfoKeyFree(void *element);
int gpiStatusInfoKeysInit(void **connection);
void gpiStatusInfoKeysDestroy(void **connection);
int gpiStatusInfoKeyCompFunc(char **elem1, char **elem2);
int gpiStatusInfoAddKey(void **connection, void *keys, char *theKeyName, char *theKeyValue);
int gpiStatusInfoSetKey(void **connection, void *keys, char *keyName, char *newKeyValue);
int gpiStatusInfoCheckKey(void **connection, void *keys, char *keyName, char **keyValue);
int gpiSaveKeysToBuffer(void **connection, char **buffer);
/* END mkheaders: generated region */

#endif
