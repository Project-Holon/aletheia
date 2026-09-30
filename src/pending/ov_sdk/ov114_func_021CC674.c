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
 * notes: DIFF, 39 concrete bytes.  Control flow and every instruction shape
 *        match.  lane13 (2026-09-30): the vendor object crypto_bobj1.o is
 *        .comment 4.0.0.1024 (dsi/1.1p1), so this is a source wall, not a
 *        front-end one.  Assigning `tab = g_021CF930[window]` BEFORE
 *        `mask = (1 << window) - 1` reproduces the image's early register
 *        pair exactly (image `lsl r2, r1, r6` + `ldr r3, [pc]`; was the
 *        reverse, r3/r2), 16 -> 12 mismatched instructions.  Residue, three
 *        scheduler/coloring ties: (1) target schedules the ldm {d,top} AFTER
 *        the two terminator byte stores, this build hoists it above them;
 *        (2) target if-converts `hi = 0` to `movle ip, r4` after `cmp r3,#1`,
 *        this build emits an unconditional `mov ip, r4` before the cmp;
 *        (3) target keeps 0xff in fp (and so saves r3/fp), this build reuses
 *        sl for it.  Declaration/statement/ternary orders and a do/while
 *        spelling of the cnt>=256 loop were all measured and are worse.
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
    tab = g_021CF930[window];
    mask = (1 << window) - 1;
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
