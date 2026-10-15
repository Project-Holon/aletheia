/*
 * function: BEACON_VIEW_ShowFormatMessage
 * address: 0x021F18C4
 * packet: pkt_ov032_021F18C4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BEACON_VIEW_SetupMessageText 0x021F0A98 thumb ov032
 *   BEACON_VIEW_StartFadeTask 0x021F18E0 thumb ov032
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void BEACON_VIEW_SetupMessageText(char *p, unsigned a);
extern void BEACON_VIEW_StartFadeTask(char *p, u32 a, int *c);
void BEACON_VIEW_ShowFormatMessage(char *p, int b)
{
    BEACON_VIEW_SetupMessageText(p, b);
    BEACON_VIEW_StartFadeTask(p, *(u32 *)&((struct Obj00007 *)p)->f11C, (int *)(p + 0xa8));
}
