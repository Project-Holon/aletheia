/*
 * file:     crypto_sign.c
 * unit:     yes
 * function: CRYPTOi_RSA, ASN1Skip, SkipPadding, ParseSignHash, CRYPTOi_GetDecodedHash, CRYPTO_VerifySignatureWithHash, CRYPTO_VerifySignature
 * address:  0x021CA494
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CRYPTOi__BN_CTX_new  0x021CAD1C  arm  ov114
 *   CRYPTOi__BN_init  0x021CACD0  arm  ov114
 *   CRYPTOi__BN_bin2bn  0x021CAF24  arm  ov114
 *   CRYPTOi__BN_set_word  0x021CAEC8  arm  ov114
 *   CRYPTOi__BN_mod_exp  0x021CC124  arm  ov114
 *   CRYPTOi__BN_num_bits  0x021CAB94  arm  ov114
 *   CRYPTOi__BN_bn2bin  0x021CB010  arm  ov114
 *   CRYPTOi__BN_free  0x021CABDC  arm  ov114
 *   CRYPTOi__BN_CTX_free  0x021CAD6C  arm  ov114
 *   MATH_CalcSHA1  0x020816B8  arm
 */
#include "crypto_types.h"

extern BN_CTX *CRYPTOi__BN_CTX_new(void);
extern void CRYPTOi__BN_init(BIGNUM *a);
extern BIGNUM *CRYPTOi__BN_bin2bn(const unsigned char *s, unsigned int len, BIGNUM *ret);
extern int CRYPTOi__BN_set_word(BIGNUM *a, unsigned long w);
extern int CRYPTOi__BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx);
extern int CRYPTOi__BN_num_bits(const BIGNUM *a);
extern int CRYPTOi__BN_bn2bin(const BIGNUM *a, unsigned char *to);
extern void CRYPTOi__BN_free(BIGNUM *a);
extern void CRYPTOi__BN_CTX_free(BN_CTX *ctx);
extern void MATH_CalcSHA1(void *digest, void *data, unsigned long dataLength);
int CRYPTOi_RSA(void *dst_ptr, int dst_len, void *src_ptr, int src_len, void *mod_ptr, int mod_len, unsigned long exp_num);
int ASN1Skip(unsigned char **datap, unsigned int *dlenp, unsigned char type, unsigned int *lenp);
int SkipPadding(unsigned char *psrc_adrs, unsigned int nsrc_size, unsigned char **ppsign_adrs, unsigned int *psign_size);
int ParseSignHash(unsigned char *data, unsigned int dlen, unsigned char **ppdgst_adrs, unsigned int *pdgst_size, unsigned char **pphash_adrs, unsigned int *phash_size);
int CRYPTOi_GetDecodedHash(void *decoded_hash_ptr, unsigned long decoded_hash_len, void *sign_ptr, unsigned long sign_len, void *mod_ptr, unsigned long mod_len, unsigned long exp_num);
int CRYPTO_VerifySignatureWithHash(void *hash_ptr, void *sign_ptr, void *mod_ptr);
int CRYPTO_VerifySignature(void *data_ptr, int data_len, void *sign_ptr, void *mod_ptr);


/*
 * sdk:      CRYPTOi_RSA (sign.o)
 */
int CRYPTOi_RSA(void *dst_ptr, int dst_len, void *src_ptr, int src_len, void *mod_ptr, int mod_len, unsigned long exp_num)
{
    BN_CTX *ctx;
    BIGNUM src;
    BIGNUM dst;
    BIGNUM exp;
    BIGNUM mod;
    int ret;

    if (dst_ptr == 0 || src_ptr == 0 || mod_ptr == 0)
        return -3;

    ctx = CRYPTOi__BN_CTX_new();
    CRYPTOi__BN_init(&src);
    CRYPTOi__BN_init(&dst);
    CRYPTOi__BN_init(&exp);
    CRYPTOi__BN_init(&mod);

    if (ctx == 0)
    {
        ret = -2;
        goto end;
    }
    if (CRYPTOi__BN_bin2bn(src_ptr, src_len, &src) == 0)
    {
        ret = -2;
        goto end;
    }
    if (CRYPTOi__BN_set_word(&exp, exp_num) == 0)
    {
        ret = -2;
        goto end;
    }
    if (CRYPTOi__BN_bin2bn(mod_ptr, mod_len, &mod) == 0)
    {
        ret = -2;
        goto end;
    }
    if (CRYPTOi__BN_mod_exp(&dst, &src, &exp, &mod, ctx) == 0)
    {
        ret = -2;
        goto end;
    }
    if (dst_len < (CRYPTOi__BN_num_bits(&dst) + 7) / 8)
    {
        ret = -1;
        goto end;
    }
    ret = CRYPTOi__BN_bn2bin(&dst, dst_ptr);

end:
    CRYPTOi__BN_free(&src);
    CRYPTOi__BN_free(&dst);
    CRYPTOi__BN_free(&exp);
    CRYPTOi__BN_free(&mod);
    if (ctx != 0)
        CRYPTOi__BN_CTX_free(ctx);
    return ret;
}

/*
 * The DWARF local list is l(r6), len(r12), dlen(r5), data(r4) (reverse source
 * order), and the vendor's long-form parse hoists `data++` out of the
 * do/while: `data++; do { len = (*data & 0x7f) + (len << 7); } while (--l);`.
 * With the increment inside the loop this front end keeps the reload in the
 * loop (180 B, 80 concrete bytes); hoisted, the load is loop-invariant and
 * CSE'd into `lr`, giving the image's 4 instruction loop and 184/184.
 *
 * sdk:      ASN1Skip (libcrypto.TWL.HYB.a(sign.o))
 */
int ASN1Skip(unsigned char **datap, unsigned int *dlenp, unsigned char type, unsigned int *lenp)
{
    unsigned int dlen;
    unsigned int len;
    unsigned char *data;
    unsigned char l;

    data = *datap;
    dlen = *dlenp;
    len = 0;
    if (*data++ != type)
        return 0;
    if (dlen < 1)
        return 0;
    dlen--;
    l = *data;
    if (l & 0x80) {
        l &= 0x7f;
        if (dlen < (unsigned int)l + 1)
            return 0;
        dlen -= l;
        if (lenp != 0) {
            data++;
            do {
                len = (*data & 0x7f) + (len << 7);
            } while (--l);
        } else {
            data += l;
        }
    } else {
        data++;
        len = l;
        if (dlen < 1)
            return 0;
        dlen--;
    }
    *datap = data;
    *dlenp = dlen;
    if (lenp != 0)
        *lenp = len;
    return 1;
}

/*
 * sdk:      SkipPadding (libcrypto.TWL.HYB.a(sign.o))
 */
int SkipPadding(unsigned char *psrc_adrs, unsigned int nsrc_size, unsigned char **ppsign_adrs, unsigned int *psign_size)
{
    unsigned char *p;
    unsigned char *pe;
    int i;

    if (nsrc_size < 10)
        return 0;
    p = psrc_adrs;
    pe = psrc_adrs + nsrc_size;
    if (*p != 1)
        return 0;
    p++;
    for (i = 0; i < 8; i++) {
        if (*p++ != 0xff)
            return 0;
    }
    for (; p != pe; p++) {
        if (*p != 0xff)
            break;
    }
    if (p == pe)
        return 0;
    if (*p != 0)
        return 0;
    p++;
    *psign_size = pe - p;
    *ppsign_adrs = p;
    return 1;
}


/*
 * sdk:      ParseSignHash (sign.o)
 */
int ParseSignHash(unsigned char *data, unsigned int dlen, unsigned char **ppdgst_adrs, unsigned int *pdgst_size, unsigned char **pphash_adrs, unsigned int *phash_size)
{
    unsigned int len;

    if (!ASN1Skip(&data, &dlen, 0x30, 0))
        return 0;
    if (!ASN1Skip(&data, &dlen, 0x30, 0))
        return 0;
    if (!ASN1Skip(&data, &dlen, 0x06, &len))
        return 0;
    if (ppdgst_adrs)
        *ppdgst_adrs = data;
    if (pdgst_size)
        *pdgst_size = len;
    data += len;
    if (dlen < len)
        return 0;
    dlen -= len;
    if (!ASN1Skip(&data, &dlen, 0x05, &len))
        return 0;
    data += len;
    if (dlen < len)
        return 0;
    dlen -= len;
    if (!ASN1Skip(&data, &dlen, 0x04, &len))
        return 0;
    if (dlen != len)
        return 0;
    if (pphash_adrs)
        *pphash_adrs = data;
    if (phash_size)
        *phash_size = len;
    return 1;
}


/*
 * sdk:      CRYPTOi_GetDecodedHash (sign.o)
 */
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


/*
 * sdk:      CRYPTO_VerifySignatureWithHash (libcrypto.TWL.HYB.a(sign.o))
 */
int CRYPTO_VerifySignatureWithHash(void *hash_ptr, void *sign_ptr, void *mod_ptr)
{
    unsigned char decoded_hash[20];
    int decoded_hash_len;
    int i;

    decoded_hash_len = CRYPTOi_GetDecodedHash(decoded_hash, 20, sign_ptr, 128, mod_ptr, 128, 0x10001);
    if (decoded_hash_len != 20)
        return 0;
    for (i = 0; i < 20; i++) {
        if (decoded_hash[i] != ((unsigned char *)hash_ptr)[i])
            return 0;
    }
    return 1;
}


/*
 * sdk:      CRYPTO_VerifySignature (libcrypto.TWL.HYB.a(sign.o))
 */
int CRYPTO_VerifySignature(void *data_ptr, int data_len, void *sign_ptr, void *mod_ptr)
{
    unsigned char hash[20];

    MATH_CalcSHA1(hash, data_ptr, data_len);
    return CRYPTO_VerifySignatureWithHash(hash, sign_ptr, mod_ptr);
}
