/*
 * function: func_02174660
 * address:  0x02174660
 * packet:   pkt_ov011_02174660
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Handed as 0x02174662; the function starts at the push {r0-r3} at 0x02174660.
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */

typedef unsigned short u16;

int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
int func_0203D3A8(void *a, u16 b, u16 c, void *d);

int func_02174660(int a, ...)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x223, 1, &a);
}
