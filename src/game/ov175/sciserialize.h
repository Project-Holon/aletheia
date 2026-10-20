#ifndef GAME_OV175_SCISERIALIZE_H
#define GAME_OV175_SCISERIALIZE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sciserialize.c, prototypes copied from their definitions. */

char *sciSerializeInt8(char *dst, int value);
unsigned char *sciSerializeInt16(unsigned char *dst, unsigned int value);
unsigned char *sciSerializeInt32(unsigned char *dst, unsigned int value);
unsigned char *sciSerializeGUID(unsigned char *theCursor, unsigned char *theGUID);
/* END mkheaders: generated region */

#endif
