/*
 * file:     unit_021CAB34_p11.c
 * unit:     yes
 * function: func_021CC674, func_021CC80C, func_021CC9C4, func_021CC9F0, func_021CCA24, func_021CCA5C
 * address:  0x021CC674
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
 *   g_021CF930  0x021CF930  data  ov114
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
 *   func_021CAAB4  0x021CAAB4  arm  ov114
 *   func_021CAAE8  0x021CAAE8  arm  ov114
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

typedef unsigned int u32;

extern u8 *func_021CAE20(u8 *a, u8 *b);
extern void func_021CACD0(int a);
extern int func_021CAB94(const BIGNUM *);
extern int func_021CAEC8(u8 *a, unsigned long w);
extern int func_021CB0C8(BIGNUM *, int);
extern BN_ULONG func_021CC4A0(BN_ULONG);
extern int func_021CB1A8(BIGNUM *, const BIGNUM *, int);
extern int func_021CB494(BIGNUM *, BN_ULONG);
extern BN_ULONG func_021CDAE8(BN_ULONG, BN_ULONG, BN_ULONG);
extern void func_021CC0FC(int a, int b, int c, int d);
extern BIGNUM *func_021CAC24(BIGNUM *, int);
extern void func_021CABDC(u8 *p);
extern void *func_021CAAB4(unsigned long);
extern void func_021CAAE8(void *);
int func_021CC674(unsigned char *str, BIGNUM *p, int bits);
int func_021CC80C(BN_MONT_CTX *mont, const BIGNUM *mod, BN_CTX *ctx);
void *func_021CC9C4(void);
void func_021CC9F0(u8 *p);
void func_021CCA24(u8 *p);
void func_021CCA5C(u8 *p);
extern unsigned char *g_021CF930[7];


/*
 * sdk:      CRYPTOi__BN_gen_exp_string (crypto_bobj1.o)
 *
 * notes: EXACT 2026-10-01 (lane29). Locals and types from the object's
 *        DWARF 1 entry (str, p, bits; sp, mask, shift, w, wh, wl, d, i,
 *        sqr, t, s, ss, top; d is the walking word pointer, i is both the
 *        string length and the return count). Closed by three source-shape
 *        changes, each fixing a scheduler tie: `w = wl = d[0];` before the
 *        top test (ldr above cmp), and post-decrement byte stores
 *        `*sp-- = x;` for every pair (terminator: add sp above strb; the
 *        256-run loop: sub above strb and 0xff in fp, which restores the
 *        r3/fp frame words). The declaration order
 *        below matches; the DWARF order recolours the whole body.
 */
int func_021CC674(unsigned char *str, BIGNUM *p, int bits)
{
    unsigned char *shift;
    unsigned char *sp;
    BN_ULONG *d;
    BN_ULONG wl;
    unsigned int sqr;
    int top;
    BN_ULONG wh;
    BN_ULONG w;
    unsigned int ss;
    unsigned int mask;
    unsigned int t;
    unsigned int s;
    unsigned int i;

    if (bits > 6)
        bits = 6;
    shift = g_021CF930[bits];
    mask = (1 << bits) - 1;
    ss = 0;
    i = ((p->top << 5) + bits - 1) / bits;
    i = i * 2 + 2;
    sp = str + i;
    *sp-- = 0;
    *sp-- = 0;

    d = p->d;
    top = p->top;
    w = wl = d[0];
    d++;
    if (top <= 1)
        wh = 0;
    else
        wh = *d++;
    sqr = 0;
    for (;;)
    {
        for (;;)
        {
            t = w & mask;
            s = shift[t];
            if (s == 0)
                break;
            ss += s;
            sqr += s;
            if (ss >= 32)
            {
                if (top <= 1)
                    break;
                top--;
                wl = wh;
                wh = 0;
                if (top > 1)
                    wh = *d++;
                ss -= 32;
            }
            if (ss == 0)
                w = wl;
            else
                w = (wl >> ss) | (wh << (32 - ss));
        }
        if (t == 0)
            break;
        *sp-- = sqr;
        *sp-- = t;
        if (sqr >= 256)
        {
            while (sqr >= 256)
            {
                sqr -= 256;
                *sp-- = 0xff;
                *sp-- = 0;
            }
        }
        ss += bits;
        sqr = bits;
        if (ss >= 32)
        {
            if (top <= 1)
                break;
            top--;
            wl = wh;
            wh = 0;
            if (top > 1)
                wh = *d++;
            ss -= 32;
        }
        if (ss == 0)
            w = wl;
        else
            w = (wl >> ss) | (wh << (32 - ss));
    }

    sp++;
    i = 2;
    while (sp[0] != 0 || sp[1] != 0)
    {
        str[0] = sp[0];
        str[1] = sp[1];
        sp += 2;
        i += 2;
        str += 2;
    }
    str[0] = 0;
    str[1] = 0;
    return i;
}


/*
 * sdk:      CRYPTOi__BN_MONT_CTX_set_word (crypto_bobj1.o)
 */
int func_021CC80C(BN_MONT_CTX *mont, const BIGNUM *mod, BN_CTX *ctx)
{
    BIGNUM Ri;
    int ret;
    BN_ULONG w;

    ret = 0;
    if (mod->top == 0)
        return ret;
    if (func_021CAE20((u8 *)(&mont->N), (u8 *)mod) == 0)
        return ret;

    func_021CACD0((int)(&Ri));
    mont->use_word = 1;
    mont->ri = (func_021CAB94(mod) + 31) / 32;
    if (!func_021CAEC8((u8 *)(&mont->RR), 0))
        return ret;
    if (!func_021CB0C8(&mont->RR, 32))
        goto err;

    w = mod->d[0];
    if (!func_021CAEC8((u8 *)(&Ri), func_021CC4A0(w)))
        goto err;
    if (!func_021CB1A8(&Ri, &Ri, 32))
        goto err;
    if (!(Ri.top == 0 || (Ri.top == 1 && Ri.d[0] == 0)))
    {
        func_021CB494(&Ri, 1);
    }
    else if (!func_021CAEC8((u8 *)(&Ri), 0xffffffff))
    {
        goto err;
    }

    mont->n0 = func_021CDAE8((Ri.top >= 2) ? Ri.d[1] : 0, (Ri.top >= 1) ? Ri.d[0] : 0, w);

    func_021CAEC8((u8 *)(&mont->RR), 0);
    if (!func_021CB0C8(&mont->RR, mont->ri * 64))
        goto err;
    func_021CC0FC((int)(&mont->RR), (int)(&mont->RR), (int)(&mont->N), (int)ctx);
    if (func_021CAC24(&mont->RR, mont->ri))
        ret = 1;

err:
    func_021CABDC((u8 *)(&Ri));
    return ret;
}


/*
 * sdk:      CRYPTOi__BN_MONT_CTX_new (crypto_bobj1.o)
 */
void *func_021CC9C4(void)
{
    u8 *p = func_021CAAB4(0x50);
    if (p == 0)
        return 0;
    func_021CC9F0(p);
    *(u32 *)(p + 0x4c) = 1;
    return p;
}


/*
 * sdk:      CRYPTOi__BN_MONT_CTX_init (crypto_bobj1.o)
 */
void func_021CC9F0(u8 *p)
{
    *(u32 *)p = 0;
    *(u32 *)(p + 8) = 0;
    func_021CACD0((int)(p + 0xc));
    func_021CACD0((int)(p + 0x20));
    func_021CACD0((int)(p + 0x34));
    *(u32 *)(p + 0x4c) = 0;
}


/*
 * sdk:      CRYPTOi__BN_MONT_CTX_free (crypto_bobj1.o)
 */
void func_021CCA24(u8 *p)
{
    func_021CABDC(p + 0xc);
    func_021CABDC(p + 0x20);
    func_021CABDC(p + 0x34);
    if (*(u32 *)(p + 0x4c) & 1)
        func_021CAAE8(p);
}


/*
 * Releases both halves of the pair at p and p+0x14, then clears two words.
 */
void func_021CCA5C(u8 *p)
{
    func_021CACD0((int)p);
    func_021CACD0((int)(p + 0x14));
    *(u32 *)(p + 0x28) = 0;
    *(u32 *)(p + 0x30) = 0;
}
