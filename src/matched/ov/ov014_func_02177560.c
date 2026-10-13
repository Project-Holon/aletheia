/*
 * function: NET_WHPIPE_ClearEntries
 * address: 0x02177560
 * packet: pkt_ov014_02177560
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data a4
 *   MI_CpuFill8 0x02082BCC arm
 */

#include "../include/G_W.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern struct W *g_pWhPipeWork;
extern void MI_CpuFill8(void *, u32, u32);
void NET_WHPIPE_ClearEntries(void)
{
    u8 *p = ((u8 *)g_pWhPipeWork);
    int i;
    for (i = 0; i < 16; i++) *(u16 *)(p + i*2 + 0xC40) = 0;
    MI_CpuFill8(p + 8, 0, 0xC00);
}
