/*
 * function: DELIVERY_IRC_StepSendRequest
 * address:  0x02157D0C
 * packet:   pkt_ov010_02157D0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   DELIVERY_IRC_SetStepAtLine  0x02157960  thumb
 *   DELIVERY_IRC_StepSearchEntry  0x02157C48  thumb
 */
#include "../include/Obj04915.h"

typedef unsigned char u8;
typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void DELIVERY_IRC_SetStepAtLine(int a, int b, int c);
struct Object;
extern void DELIVERY_IRC_StepSearchEntry(struct Object *p);

void DELIVERY_IRC_StepSendRequest(int *p)
{
    if (*((u8 *)p + 0x675) == 0) {
        ((struct Obj04915 *)p)->f67C = p[4];
        ((struct Obj04915 *)p)->f680 = p[5];
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)((p[0] << 8) + 2), (u16)8, (u32)((u8 *)p + 0x67C)) == 0)
            return;
        DELIVERY_IRC_SetStepAtLine((int)p, (int)((void *)DELIVERY_IRC_StepSearchEntry), 0x1A2);
        return;
    }
    DELIVERY_IRC_SetStepAtLine((int)p, (int)((void *)DELIVERY_IRC_StepSearchEntry), 0x1A6);
}
