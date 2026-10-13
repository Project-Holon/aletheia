/*
 * function: CRYPTOi_GetDecodedHash
 * address:  0x021CA8EC
 * packet:   pkt_ov114_021CA8EC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi_GetDecodedHash (sign.o)
 *
 * symbols:
 *   CRYPTOi_RSA  0x021CA494  arm  ov114
 *   SkipPadding  0x021CA69C  arm  ov114
 *   ParseSignHash  0x021CA734  arm  ov114
 */

extern int CRYPTOi_RSA(void *dst_ptr, int dst_len, void *src_ptr, int src_len, void *mod_ptr, int mod_len, unsigned long exp_num);
extern int SkipPadding(unsigned char *psrc_adrs, unsigned int nsrc_size, unsigned char **ppsign_adrs, unsigned int *psign_size);
extern int ParseSignHash(unsigned char *data, unsigned int dlen, unsigned char **ppdgst_adrs, unsigned int *pdgst_size, unsigned char **pphash_adrs, unsigned int *phash_size);

int CRYPTOi_GetDecodedHash(void *decoded_hash_ptr, unsigned long decoded_hash_len, void *sign_ptr, unsigned long sign_len, void *mod_ptr, unsigned long mod_len, unsigned long exp_num)
{
    unsigned long decode[64];
    int decode_len;
    int i = 0;
    unsigned char *decoded_sign;
    unsigned int decoded_sign_len = 0;
    unsigned char *tmp_decoded_hash;
    unsigned int tmp_decoded_hash_len = 0;
    unsigned char *p_decoded_hash = (unsigned char *)decoded_hash_ptr;

    decode_len = CRYPTOi_RSA(decode, sizeof(decode), sign_ptr, (int)sign_len, mod_ptr, (int)mod_len, exp_num);
    if (decode_len < 0)
        return -1;
    if (!SkipPadding((unsigned char *)decode, (unsigned int)decode_len, &decoded_sign, &decoded_sign_len))
        return -1;
    if (!ParseSignHash(decoded_sign, decoded_sign_len, 0, 0, &tmp_decoded_hash, &tmp_decoded_hash_len))
        return -1;
    if (tmp_decoded_hash_len > decoded_hash_len)
        return -1;
    for (i = 0; i < tmp_decoded_hash_len; i++)
        *p_decoded_hash++ = tmp_decoded_hash[i];
    for (; i < decoded_hash_len; i++)
        *p_decoded_hash++ = 0;
    return (int)tmp_decoded_hash_len;
}
