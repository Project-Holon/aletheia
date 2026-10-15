/*
 * function: B_PLIST_MAIN_SetActorsVisible
 * address:  0x02211A10
 * packet:   pkt_ov198_02211A10
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the callee takes (p, v); passing v as the second argument keeps r1 live
 *           across the store, so the index decrement stays in r2.
 *
 * symbols:
 *   B_APP_TOOL_SetActorsVisible  0x0220AFDC  thumb  ov196
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
extern u32 B_APP_TOOL_SetActorsVisible(u32, u32);

u32 B_PLIST_MAIN_SetActorsVisible(u8 *p, u32 v)
{
    u32 i = 0x218c;

    *(u32 *)(p + i) = v;
    i -= 4;
    return B_APP_TOOL_SetActorsVisible(*(u32 *)(p + i), v);
}
