/*
 * function: DELIVERY_IRC_StepSendCrc
 * address:  0x02157B88
 * packet:   pkt_ov010_02157B88
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
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   DELIVERY_IRC_SetStepAtLine  0x02157960  thumb
 *   DELIVERY_IRC_StepSendData  0x02157AF0  thumb
 */
#include "../include/Obj02664.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int a; u16 b; } Loc;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
extern void DELIVERY_IRC_SetStepAtLine(int a, int b, int c);
extern void DELIVERY_IRC_StepSendData(int *p);

void DELIVERY_IRC_StepSendCrc(int *p)
{
    u8 *b = (u8 *)p;
    if (b[0x676] == 1) {
        Loc l;
        int *s = *(int * *)&((struct Obj02664 *)b)->f664;
        l.b = GF_STANDARD_SetupCalc((const u8 *)s[1], s[0]);
        l.a = ((struct Obj02664 *)b)->f668;
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)((p[0] << 8) + 1), (u16)8, (u32)(&l)) == 0)
            return;
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)p[0]);
        ((struct Obj02664 *)b)->f670 = 0;
        DELIVERY_IRC_SetStepAtLine((int)p, (int)((void *)DELIVERY_IRC_StepSendData), 0x152);
        return;
    }
    ((struct Obj02664 *)b)->f66C = 1;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)((p[0] << 8) + 3), (u16)4, (u32)(b + 0x66C)) == 0)
        return;
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)p[0]);
    ((struct Obj02664 *)b)->f670 = 0;
    DELIVERY_IRC_SetStepAtLine((int)p, (int)((void *)DELIVERY_IRC_StepSendData), 0x162);
}
