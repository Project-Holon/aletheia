/*
 * function: func_02155678
 * address:  0x02155678
 * packet:   pkt_ov009_02155678
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
    char pad[0x7a5];
    u8 b7a5;
} G;

extern G *d_021A8264;

u8 func_02155678(void)
{
    return d_021A8264->b7a5;
}
