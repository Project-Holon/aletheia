/*
 * function: OEKAKI_RecvMemberJoined
 * address:  0x02184474
 * packet:   pkt_ov023_02184474
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OEKAKI_HandleEvent  0x02185AB0  thumb  ov023
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   OEKAKI_SendCanvasChunk  0x021844D8  thumb  ov023
 */
#include "../include/Obj09766.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void OEKAKI_HandleEvent(char *p, int a, int b);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern u32 OEKAKI_SendCanvasChunk(char *p, int x, int y);

void OEKAKI_RecvMemberJoined(int a0, int a1, u8 *a2, char *p, int a4)
{
    if (((struct Obj09766 *)p)->f928A == 0) {
        OEKAKI_HandleEvent(p, 1, *a2);
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0 && ((struct Obj09766 *)p)->f194 == 1) {
            ((struct Obj09766 *)p)->f428C = 0;
            OEKAKI_SendCanvasChunk(p, 0, a4);
        }
    }
}
