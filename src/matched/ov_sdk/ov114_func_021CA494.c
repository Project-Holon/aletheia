/*
 * function: func_021CA494
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
 *   func_021CAD1C  0x021CAD1C  arm  ov114
 *   func_021CACD0  0x021CACD0  arm  ov114
 *   func_021CAF24  0x021CAF24  arm  ov114
 *   func_021CAEC8  0x021CAEC8  arm  ov114
 *   func_021CC124  0x021CC124  arm  ov114
 *   func_021CAB94  0x021CAB94  arm  ov114
 *   func_021CB010  0x021CB010  arm  ov114
 *   func_021CABDC  0x021CABDC  arm  ov114
 *   func_021CAD6C  0x021CAD6C  arm  ov114
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

extern void *func_021CAD1C(void);
extern void func_021CACD0(int a);
extern BIGNUM *func_021CAF24(const unsigned char *, int, BIGNUM *);
typedef unsigned char  u8;
extern int func_021CAEC8(u8 *a, unsigned long w);
extern int func_021CC124(BIGNUM *, const BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern int func_021CAB94(const BIGNUM *);
extern int func_021CB010(const BIGNUM *, unsigned char *);
extern void func_021CABDC(u8 *p);
extern void func_021CAD6C(u8 *ctx);

int func_021CA494(void *dst_ptr, int dst_len, void *src_ptr, int src_len, void *mod_ptr, int mod_len, unsigned long exp_num)
{
    BN_CTX *ctx;
    BIGNUM src;
    BIGNUM dst;
    BIGNUM exp;
    BIGNUM mod;
    int ret;

    if (dst_ptr == 0 || src_ptr == 0 || mod_ptr == 0)
        return -3;

    ctx = func_021CAD1C();
    func_021CACD0((int)(&src));
    func_021CACD0((int)(&dst));
    func_021CACD0((int)(&exp));
    func_021CACD0((int)(&mod));

    if (ctx == 0)
    {
        ret = -2;
        goto end;
    }
    if (func_021CAF24((unsigned char *)src_ptr, src_len, &src) == 0)
    {
        ret = -2;
        goto end;
    }
    if (func_021CAEC8((u8 *)(&exp), exp_num) == 0)
    {
        ret = -2;
        goto end;
    }
    if (func_021CAF24((unsigned char *)mod_ptr, mod_len, &mod) == 0)
    {
        ret = -2;
        goto end;
    }
    if (func_021CC124(&dst, &src, &exp, &mod, ctx) == 0)
    {
        ret = -2;
        goto end;
    }
    if (dst_len < (func_021CAB94(&dst) + 7) / 8)
    {
        ret = -1;
        goto end;
    }
    ret = func_021CB010(&dst, (unsigned char *)dst_ptr);

end:
    func_021CABDC((u8 *)(&src));
    func_021CABDC((u8 *)(&dst));
    func_021CABDC((u8 *)(&exp));
    func_021CABDC((u8 *)(&mod));
    if (ctx != 0)
        func_021CAD6C((u8 *)ctx);
    return ret;
}
