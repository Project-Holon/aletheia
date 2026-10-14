/*
 * function: WORLDTRADE_DETAIL_CallStateHandler
 * address:  0x021FC174
 * packet:   pkt_021FC174
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02203CF0  0x02203CF0  data  ov135

 * State-table dispatch through the table at 0x02203CF0.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void *g_02203CF0[];

void WORLDTRADE_DETAIL_CallStateHandler(u8 *p)
{
    ((void (*)(u8 *))g_02203CF0[*(u32 *)(p + 0x28)])(p);
}
