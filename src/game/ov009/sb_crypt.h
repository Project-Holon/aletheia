#ifndef GAME_OV009_SB_CRYPT_H
#define GAME_OV009_SB_CRYPT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sb_crypt.c, prototypes copied from their definitions. */

struct GOACryptState;

unsigned char keyrand(struct GOACryptState *state, int limit, unsigned char *user_key, unsigned char keysize, unsigned char *rsum, unsigned int *keypos);
void GOAHashInit(struct GOACryptState *state);
void GOACryptInit(struct GOACryptState *state, unsigned char *key, unsigned char keysize);
unsigned char GOADecryptByte(struct GOACryptState *state, unsigned char b);
void GOADecrypt(struct GOACryptState *state, unsigned char *bp, int len);
/* END mkheaders: generated region */

#endif
