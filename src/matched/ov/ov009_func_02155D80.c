/*
 * function: func_02155D80
 * address:  0x02155D80
 * packet:   pkt_ov009_02155D80
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, so disasm.py prints it as .word data); its
 * address is taken as a callback by func_02156888 / func_0215568C.
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    char pad[0x760];
    int f760;           /* 0x760 */
    char pad1[0x784 - 0x764];
    int cnt[2];         /* 0x784 */
} G;

extern G *d_021A8264;

void func_02155D80(int a, u32 i)
{
    if (i < 2) {
        d_021A8264->f760 = 0;
        d_021A8264->cnt[i] = 0;
    }
}
