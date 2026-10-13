/*
 * function: OEKAKI_SendStrokes
 * address:  0x021860D0
 * packet:   pkt_ov023_021860D0
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_ResetSendQueue  0x0203D56C  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   OEKAKI_FillSendGroup  0x02186A04  thumb  ov023
 *   OEKAKI_PeekStroke  0x021869C0  thumb  ov023
 *   OEKAKI_PopStrokeGroup  0x02186958  thumb  ov023
 */
#include "../include/Obj01221.h"

typedef unsigned short u16;

struct Entry;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int  GFL_NET_ResetSendQueue(void *h);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void OEKAKI_FillSendGroup(char *a, char *b);
extern void OEKAKI_PeekStroke(char *a, char *b);
extern void OEKAKI_PopStrokeGroup(char *a);

void OEKAKI_SendStrokes(char *p)
{
    void *h;

    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        h = GFL_NET_HANDLE_GetCurrentHandle();
        if (GFL_NET_ResetSendQueue(h) == 0)
            return;
        OEKAKI_FillSendGroup(p + 0x9e4c, p + 0x928c);
        ((struct Obj01221 *)p)->f9E51 = ((struct Obj01221 *)p)->f9E6C;
        if (GFL_NET_SendToHandle(h, 0x2902, 0x1e, (u32)(p + 0x9e4c)) == 1)
            OEKAKI_PopStrokeGroup(p + 0x928c);
    } else {
        h = GFL_NET_HANDLE_GetCurrentHandle();
        OEKAKI_PeekStroke(p + 0x420c, p + 0x928c);
        if (GFL_NET_ResetSendQueue(h) == 0)
            return;
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2901, 6, (u32)(p + 0x420c)) == 1)
            OEKAKI_PopStrokeGroup(p + 0x928c);
    }
}
