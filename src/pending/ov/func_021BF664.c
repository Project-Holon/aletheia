/*
 * function: func_021BF664
 * address:  0x021BF664
 * packet:   pkt_021BF664
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-04 (D2-16): tried the dst store as one expression (b<<10 | g<<5 | r, each channel inline) and A, g, B, r, b statement order:
 * 135 and 135 bytes out, still 288 vs 292 bytes. Statement order does not move the scheduler. The image spills gA, b<<10 and a
 * second 0x7c00; we spill rA/bA. Image order: A load, gA, B load, rA, bA, bB, b lerp, rB, gB, g lerp, r lerp.
 *
 * Near miss, 288 compiled vs 292 original, ~148 bytes differ.  The two
 * external calls and the tbl_020A1B38 ABS32 all resolve.  The residual is the
 * loop's register scheduling: the original spills the A.g extraction (offset
 * 0x3e0>>5) to the stack and re-reads it, and orders the B-channel reads
 * (B.b, then the b result, then B.r/B.g); this C keeps a different channel in
 * the slot, so every following instruction is transposed.  The 16-bit division
 * by two needs the (s16) narrowing-shift-pair (lsls #0xf / asrs #0x10), which
 * a `short ratio` reproduces; the block-2 clamp needs the `>=` polarity.
 *
 * 2026-10-04 (D1-08): also tried y/x declaration order, function-top x/y, ternary store, y -= 0x10000 form
 * for the f108 wrap (x lands in r3 not r2; ternary and y-form are worse), and the g-before-r result order.
 * Image spills gA ([sp]) and keeps two 0x7c00 constants (ip and [sp,#4]); ours spills rA instead.
 *
 * symbols:
 *   tbl_020A1B38  0x020A1B38  data
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02061CA4  0x02061CA4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    char pad0[0x98];
    int f98;
    char pad9c[0xa8 - 0x9c];
    unsigned short srcA[0x10];
    unsigned short srcB[0x10];
    unsigned short dst[0x10];
    int f108;
    int f10c;
} Ent;

extern short tbl_020A1B38[];
extern void func_0204B6F4(int, int, int);
extern void func_02061CA4(int, int, int, int);

void func_021BF664(int a0, Ent *e)
{
    if (e->f10c != 0) {
        int v = e->f98;

        if (v != 6)
            func_0204B6F4(*(int *)((char *)e + v * 0x14 + 0x1c), 2, 0);
        e->f10c = 0;
    }

    {
        int x = e->f108;
        int y = x + 0x400;

        if (y >= 0x10000)
            e->f108 = x - 0xfc00;
        else
            e->f108 = y;
    }

    {
        unsigned char i;
        int t = e->f108;
        short ratio;

        t = ((t >> 4) << 1) + 1;
        ratio = (tbl_020A1B38[t] + 0x1000) / 2;

        for (i = 0; i < 0x10; i++) {
            unsigned short A = e->srcA[i];
            unsigned short B = e->srcB[i];
            int g = (unsigned char)((A & 0x3e0) >> 5);
            int r = (unsigned char)(A & 0x1f);
            int b = (unsigned char)((A & 0x7c00) >> 10);

            b = (unsigned char)(b + ((ratio * ((unsigned char)((B & 0x7c00) >> 10) - b)) >> 12));
            r = (unsigned char)(r + ((ratio * ((unsigned char)(B & 0x1f) - r)) >> 12));
            g = (unsigned char)(g + ((ratio * ((unsigned char)((B & 0x3e0) >> 5) - g)) >> 12));

            e->dst[i] = (unsigned short)((b << 10) | (g << 5) | r);
        }

        func_02061CA4(0xe, 0xc0, (int)e->dst, 0x20);
    }
}
