/*
 * function: func_021CC674
 * address:  0x021CC674
 * packet:   pkt_ov114_021CC674
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      CRYPTOi__BN_gen_exp_string (crypto_bobj1.o)
 *
 * symbols:
 *   g_021CF930  0x021CF930  data  ov114
 *
 * notes: DIFF, 16 lines. Control flow and every instruction shape match; residue is (1) target keeps 0xff in fp (pushes r3/fp) where this build uses sl, (2) target schedules ldm {d,top} after the two terminator byte stores, (3) target sets hi=0 as movle after cmp. Declaration order was hill-climbed.
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

int func_021CC674(unsigned char *str, const BIGNUM *e, int window)
{
    unsigned char *tab;
    unsigned char *p;
    BN_ULONG *d;
    BN_ULONG *dp;
    BN_ULONG lo;
    unsigned int cnt;
    int top;
    BN_ULONG hi;
    BN_ULONG w;
    unsigned int bitsh;
    unsigned int mask;
    unsigned int v;
    unsigned int s;
    int n;
    int ret;
    if (window > 6)
        window = 6;
    mask = (1 << window) - 1;
    tab = g_021CF930[window];
    bitsh = 0;
    n = ((e->top << 5) + window - 1) / window;
    n = n * 2 + 2;
    str[n] = 0;
    p = str + n;
    p[-1] = 0;

    d = e->d;
    top = e->top;
    lo = d[0];
    dp = d + 1;
    hi = 0;
    if (top > 1)
        hi = *dp++;
    w = lo;
    p -= 2;
    cnt = 0;
    for (;;)
    {
        for (;;)
        {
            v = w & mask;
            s = tab[v];
            if (s == 0)
                break;
            bitsh += s;
            cnt += s;
            if (bitsh >= 32)
            {
                if (top <= 1)
                    break;
                top--;
                lo = hi;
                hi = 0;
                if (top > 1)
                    hi = *dp++;
                bitsh -= 32;
            }
            if (bitsh == 0)
                w = lo;
            else
                w = (lo >> bitsh) | (hi << (32 - bitsh));
        }
        if (v == 0)
            break;
        p[0] = cnt;
        p[-1] = v;
        p -= 2;
        if (cnt >= 256)
        {
            while (cnt >= 256)
            {
                cnt -= 256;
                p[0] = 0xff;
                p[-1] = 0;
                p -= 2;
            }
        }
        bitsh += window;
        cnt = window;
        if (bitsh >= 32)
        {
            if (top <= 1)
                break;
            top--;
            lo = hi;
            hi = 0;
            if (top > 1)
                hi = *dp++;
            bitsh -= 32;
        }
        if (bitsh == 0)
            w = lo;
        else
            w = (lo >> bitsh) | (hi << (32 - bitsh));
    }

    p++;
    ret = 2;
    while (p[0] != 0 || p[1] != 0)
    {
        str[0] = p[0];
        str[1] = p[1];
        p += 2;
        ret += 2;
        str += 2;
    }
    str[0] = 0;
    str[1] = 0;
    return ret;
}
