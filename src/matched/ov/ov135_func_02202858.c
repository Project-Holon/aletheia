/*
 * function: WORLDTRADE_ADAPTER_QueuePrintDefaultColor
 * address: 0x02202858
 * packet: pkt_ov135_02202858
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_ADAPTER_PrintQueColor 0x022028C8 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WORLDTRADE_ADAPTER_PrintQueColor(void *,u8,void *,u32,u32,u32,u16,void *);
u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p,u8 b,void *s,u32 x,u32 y,void *out) { return WORLDTRADE_ADAPTER_PrintQueColor(p,b,s,x,y,0,0x44f,out); }
