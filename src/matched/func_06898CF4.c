/*
 * function: func_06898CF4
 * address:  0x06898CF4
 * packet:   pkt_06898CF4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed presence test: element (a,b) of a 0xe0-stride record array with a
 * 16-byte element stride starting at g_0689E7E0.  Returns 1 when the word is
 * non-zero, 0 otherwise.
 *
 * symbols:
 *   g_0689E7E0     0x0689E7E0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 g_0689E7E0[];

int func_06898CF4(int a, int b)
{
    return *(u32 *)(g_0689E7E0 + a * 0xe0 + b * 16) != 0;
}
