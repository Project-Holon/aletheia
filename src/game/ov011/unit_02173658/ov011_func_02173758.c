/*
 * function: func_02173758
 * address:  0x02173758
 * packet:   pkt_ov011_02173758
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Handed as 0x0217375A; the function starts at the push {r0-r3} at 0x02173758.
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb  ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

extern int func_021736D8(void);
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int func_02173758(int a, int b, ...)
{
    if (func_021736D8() == 0)
        return 0;
    return func_0203D3F8((int)func_020399A8(), 0xff, 0x201, 1, (u32)(&b), 1, 0, 0);
}
