/*
 * function: func_021C1D24
 * address:  0x021C1D24
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Field getter, u32 at +4.
 *
 * BLOCKED.  ISA conflict: callee func_021C1920 is labelled thumb in ov208 but arm in ov114, so match.py refuses to resolve the call.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021C1D24(void *p)
{
    return *(u32 *)((char *)p + 4);
}
