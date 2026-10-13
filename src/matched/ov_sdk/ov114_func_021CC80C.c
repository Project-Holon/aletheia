/*
 * function: CRYPTOi__BN_MONT_CTX_set_word
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
 *   CRYPTOi__BN_copy  0x021CAE20  arm  ov114
 *   CRYPTOi__BN_init  0x021CACD0  arm  ov114
 *   CRYPTOi__BN_num_bits  0x021CAB94  arm  ov114
 *   CRYPTOi__BN_set_word  0x021CAEC8  arm  ov114
 *   CRYPTOi__BN_set_bit  0x021CB0C8  arm  ov114
 *   CRYPTOi__BN_mod_inverse_word  0x021CC4A0  arm  ov114
 *   CRYPTOi__BN_lshift  0x021CB1A8  arm  ov114
 *   CRYPTOi__BN_sub_word  0x021CB494  arm  ov114
 *   CRYPTOi__bn_div_words  0x021CDAE8  arm  ov114
 *   CRYPTOi__BN_mod  0x021CC0FC  arm  ov114
 *   CRYPTOi__bn_zexpand  0x021CAC24  arm  ov114
 *   CRYPTOi__BN_free  0x021CABDC  arm  ov114
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

typedef unsigned char  u8;
extern u8 *CRYPTOi__BN_copy(u8 *a, u8 *b);
extern void CRYPTOi__BN_init(int a);
extern int CRYPTOi__BN_num_bits(const BIGNUM *);
extern int CRYPTOi__BN_set_word(u8 *a, unsigned long w);
extern int CRYPTOi__BN_set_bit(BIGNUM *, int);
extern BN_ULONG CRYPTOi__BN_mod_inverse_word(BN_ULONG);
extern int CRYPTOi__BN_lshift(BIGNUM *, const BIGNUM *, int);
extern int CRYPTOi__BN_sub_word(BIGNUM *, BN_ULONG);
extern BN_ULONG CRYPTOi__bn_div_words(BN_ULONG, BN_ULONG, BN_ULONG);
extern void CRYPTOi__BN_mod(int a, int b, int c, int d);
extern BIGNUM *CRYPTOi__bn_zexpand(BIGNUM *, int);
extern void CRYPTOi__BN_free(u8 *p);

int CRYPTOi__BN_MONT_CTX_set_word(BN_MONT_CTX *mont, const BIGNUM *mod, BN_CTX *ctx)
{
    BIGNUM Ri;
    int ret;
    BN_ULONG w;

    ret = 0;
    if (mod->top == 0)
        return ret;
    if (CRYPTOi__BN_copy((u8 *)(&mont->N), (u8 *)mod) == 0)
        return ret;

    CRYPTOi__BN_init((int)(&Ri));
    mont->use_word = 1;
    mont->ri = (CRYPTOi__BN_num_bits(mod) + 31) / 32;
    if (!CRYPTOi__BN_set_word((u8 *)(&mont->RR), 0))
        return ret;
    if (!CRYPTOi__BN_set_bit(&mont->RR, 32))
        goto err;

    w = mod->d[0];
    if (!CRYPTOi__BN_set_word((u8 *)(&Ri), CRYPTOi__BN_mod_inverse_word(w)))
        goto err;
    if (!CRYPTOi__BN_lshift(&Ri, &Ri, 32))
        goto err;
    if (!(Ri.top == 0 || (Ri.top == 1 && Ri.d[0] == 0)))
    {
        CRYPTOi__BN_sub_word(&Ri, 1);
    }
    else if (!CRYPTOi__BN_set_word((u8 *)(&Ri), 0xffffffff))
    {
        goto err;
    }

    mont->n0 = CRYPTOi__bn_div_words((Ri.top >= 2) ? Ri.d[1] : 0, (Ri.top >= 1) ? Ri.d[0] : 0, w);

    CRYPTOi__BN_set_word((u8 *)(&mont->RR), 0);
    if (!CRYPTOi__BN_set_bit(&mont->RR, mont->ri * 64))
        goto err;
    CRYPTOi__BN_mod((int)(&mont->RR), (int)(&mont->RR), (int)(&mont->N), (int)ctx);
    if (CRYPTOi__bn_zexpand(&mont->RR, mont->ri))
        ret = 1;

err:
    CRYPTOi__BN_free((u8 *)(&Ri));
    return ret;
}
