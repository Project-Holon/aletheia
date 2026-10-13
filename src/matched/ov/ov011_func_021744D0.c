/*
 * function: func_021744D0
 * address:  0x021744D0
 * packet:   pkt_ov011_021744D0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Handed as 0x021744D2; the function starts at the push {r0-r3} at 0x021744D0.
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned int   u32;
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int func_021744D0(int a, int b, int c, ...)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return func_0203D3F8((int)func_020399A8(), b, 0x220, 1, (u32)(&c), 0, 0, 0);
}
