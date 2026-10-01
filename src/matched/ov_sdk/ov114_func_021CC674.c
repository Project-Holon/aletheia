/*
 * function: func_021CC674
 * address:  0x021CC674
 * packet:   pkt_ov114_021CC674
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_gen_exp_string (crypto_bobj1.o)
 *
 * symbols:
 *   g_021CF930  0x021CF930  data  ov114
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

extern unsigned char *g_021CF930[7];

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
