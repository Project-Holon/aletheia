#ifndef GAME_OV114_CRYPTO_SIGN_H
#define GAME_OV114_CRYPTO_SIGN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of crypto_sign.c, prototypes copied from their definitions. */

int CRYPTOi_RSA(void *dst_ptr, int dst_len, void *src_ptr, int src_len, void *mod_ptr, int mod_len, unsigned long exp_num);
int ASN1Skip(unsigned char **datap, unsigned int *dlenp, unsigned char type, unsigned int *lenp);
int SkipPadding(unsigned char *psrc_adrs, unsigned int nsrc_size, unsigned char **ppsign_adrs, unsigned int *psign_size);
int ParseSignHash(unsigned char *data, unsigned int dlen, unsigned char **ppdgst_adrs, unsigned int *pdgst_size, unsigned char **pphash_adrs, unsigned int *phash_size);
int CRYPTOi_GetDecodedHash(void *decoded_hash_ptr, unsigned long decoded_hash_len, void *sign_ptr, unsigned long sign_len, void *mod_ptr, unsigned long mod_len, unsigned long exp_num);
int CRYPTO_VerifySignatureWithHash(void *hash_ptr, void *sign_ptr, void *mod_ptr);
int CRYPTO_VerifySignature(void *data_ptr, int data_len, void *sign_ptr, void *mod_ptr);
/* END mkheaders: generated region */

#endif
