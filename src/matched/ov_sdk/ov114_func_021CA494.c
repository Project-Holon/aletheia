/*
 * function: CRYPTOi_RSA
 * address:  0x021CA494
 * packet:   pkt_ov114_021CA494
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi_RSA (sign.o)
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
 */

typedef struct bignum_st
{
    unsigned int *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

typedef struct bignum_ctx BN_CTX;

extern void *CRYPTOi__BN_CTX_new(void);
extern void CRYPTOi__BN_init(int a);
extern BIGNUM *CRYPTOi__BN_bin2bn(const unsigned char *, int, BIGNUM *);
typedef unsigned char  u8;
extern int CRYPTOi__BN_set_word(u8 *a, unsigned long w);
extern int CRYPTOi__BN_mod_exp(BIGNUM *, const BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern int CRYPTOi__BN_num_bits(const BIGNUM *);
extern int CRYPTOi__BN_bn2bin(const BIGNUM *, unsigned char *);
extern void CRYPTOi__BN_free(u8 *p);
extern void CRYPTOi__BN_CTX_free(u8 *ctx);

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
    CRYPTOi__BN_init((int)(&src));
    CRYPTOi__BN_init((int)(&dst));
    CRYPTOi__BN_init((int)(&exp));
    CRYPTOi__BN_init((int)(&mod));

    if (ctx == 0)
    {
        ret = -2;
        goto end;
    }
    if (CRYPTOi__BN_bin2bn((unsigned char *)src_ptr, src_len, &src) == 0)
    {
        ret = -2;
        goto end;
    }
    if (CRYPTOi__BN_set_word((u8 *)(&exp), exp_num) == 0)
    {
        ret = -2;
        goto end;
    }
    if (CRYPTOi__BN_bin2bn((unsigned char *)mod_ptr, mod_len, &mod) == 0)
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
    ret = CRYPTOi__BN_bn2bin(&dst, (unsigned char *)dst_ptr);

end:
    CRYPTOi__BN_free((u8 *)(&src));
    CRYPTOi__BN_free((u8 *)(&dst));
    CRYPTOi__BN_free((u8 *)(&exp));
    CRYPTOi__BN_free((u8 *)(&mod));
    if (ctx != 0)
        CRYPTOi__BN_CTX_free((u8 *)ctx);
    return ret;
}
