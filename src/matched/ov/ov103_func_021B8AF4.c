/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_InitExchange
 * address: 0x021B8AF4
 * packet: pkt_ov103_021B8AF4
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   COMPATIBLE_IRC_SYS_AddCommandTable 0x021B64F0 thumb ov101
 *   IRC_COMPATIBLE_TOUCH_TEST_ExchangeCommandTable 0x021B9220 data a4
 */
#include "../include/Obj22209.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,u32); extern void COMPATIBLE_IRC_SYS_AddCommandTable(void *,int,void *,int,void *); extern u8 IRC_COMPATIBLE_TOUCH_TEST_ExchangeCommandTable[];
void IRC_COMPATIBLE_TOUCH_TEST_InitExchange(u8 *p,void *q) {MI_CpuFill8(p,0,0x294);((struct Obj22209 *)p)->f0=q;COMPATIBLE_IRC_SYS_AddCommandTable(q,0xe00,IRC_COMPATIBLE_TOUCH_TEST_ExchangeCommandTable,1,p);}
