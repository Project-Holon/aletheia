/*
 * function: func_021CC80C
 * address:  0x021CC80C
 * packet:   pkt_ov114_021CC80C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_MONT_CTX_set_word (crypto_bobj1.o)
 *
 * symbols:
 *   func_021CAE20  0x021CAE20  arm  ov114
 *   func_021CACD0  0x021CACD0  arm  ov114
 *   func_021CAB94  0x021CAB94  arm  ov114
 *   func_021CAEC8  0x021CAEC8  arm  ov114
 *   func_021CB0C8  0x021CB0C8  arm  ov114
 *   func_021CC4A0  0x021CC4A0  arm  ov114
 *   func_021CB1A8  0x021CB1A8  arm  ov114
 *   func_021CB494  0x021CB494  arm  ov114
 *   func_021CDAE8  0x021CDAE8  arm  ov114
 *   func_021CC0FC  0x021CC0FC  arm  ov114
 *   func_021CAC24  0x021CAC24  arm  ov114
 *   func_021CABDC  0x021CABDC  arm  ov114
 */

typedef unsigned int BN_ULONG;

typedef struct
{
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

typedef struct
{
    int tos;
    BIGNUM bn[13];
    int flags;
    int depth;
} BN_CTX;


typedef struct
{
    int use_word;
    int unused;
    int ri;
    BIGNUM RR;
    BIGNUM N;
    BIGNUM Ni;
    BN_ULONG n0;
    int flags;
} BN_MONT_CTX;

extern BIGNUM *func_021CAE20(BIGNUM *, const BIGNUM *);
extern void func_021CACD0(BIGNUM *);
extern int func_021CAB94(const BIGNUM *);
extern int func_021CAEC8(BIGNUM *, BN_ULONG);
extern int func_021CB0C8(BIGNUM *, int);
extern BN_ULONG func_021CC4A0(BN_ULONG);
extern int func_021CB1A8(BIGNUM *, const BIGNUM *, int);
extern int func_021CB494(BIGNUM *, BN_ULONG);
extern BN_ULONG func_021CDAE8(BN_ULONG, BN_ULONG, BN_ULONG);
extern int func_021CC0FC(BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *);
extern BIGNUM *func_021CAC24(BIGNUM *, int);
extern void func_021CABDC(BIGNUM *);

int func_021CC80C(BN_MONT_CTX *mont, const BIGNUM *mod, BN_CTX *ctx)
{
    BIGNUM Ri;
    int ret;
    BN_ULONG w;

    ret = 0;
    if (mod->top == 0)
        return ret;
    if (func_021CAE20(&mont->N, mod) == 0)
        return ret;

    func_021CACD0(&Ri);
    mont->use_word = 1;
    mont->ri = (func_021CAB94(mod) + 31) / 32;
    if (!func_021CAEC8(&mont->RR, 0))
        return ret;
    if (!func_021CB0C8(&mont->RR, 32))
        goto err;

    w = mod->d[0];
    if (!func_021CAEC8(&Ri, func_021CC4A0(w)))
        goto err;
    if (!func_021CB1A8(&Ri, &Ri, 32))
        goto err;
    if (!(Ri.top == 0 || (Ri.top == 1 && Ri.d[0] == 0)))
    {
        func_021CB494(&Ri, 1);
    }
    else if (!func_021CAEC8(&Ri, 0xffffffff))
    {
        goto err;
    }

    mont->n0 = func_021CDAE8((Ri.top >= 2) ? Ri.d[1] : 0, (Ri.top >= 1) ? Ri.d[0] : 0, w);

    func_021CAEC8(&mont->RR, 0);
    if (!func_021CB0C8(&mont->RR, mont->ri * 64))
        goto err;
    func_021CC0FC(&mont->RR, &mont->RR, &mont->N, ctx);
    if (func_021CAC24(&mont->RR, mont->ri))
        ret = 1;

err:
    func_021CABDC(&Ri);
    return ret;
}
