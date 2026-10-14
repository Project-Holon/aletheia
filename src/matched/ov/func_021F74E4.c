/*
 * function: WORLDTRADE_DEPOSIT_Main
 * address:  0x021F74E4
 * packet:   pkt_021F74E4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02203BBC  0x02203BBC  data  ov135

 * State-table dispatch through the table at 0x02203BBC.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void *g_02203BBC[];

void WORLDTRADE_DEPOSIT_Main(u8 *p)
{
    ((void (*)(u8 *))g_02203BBC[*(u32 *)(p + 0x28)])(p);
}
