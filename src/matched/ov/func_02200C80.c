/*
 * function: WORLDTRADE_SERVER_CallStateHandler
 * address:  0x02200C80
 * packet:   pkt_02200C80
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02203E94  0x02203E94  data  ov135

 * State-table dispatch through the table at 0x02203E94.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void *g_02203E94[];

void WORLDTRADE_SERVER_CallStateHandler(u8 *p)
{
    ((void (*)(u8 *))g_02203E94[*(u32 *)(p + 0x28)])(p);
}
