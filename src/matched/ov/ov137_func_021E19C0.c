/*
 * function: GURU2_MAIN_BroadcastResult
 * address:  0x021E19C0
 * packet:   pkt_ov137_021E19C0
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid   0x02039338  arm
 *   GURU2_MAIN_RotateAll   0x021E1604  thumb  ov137
 *   GURU2_COMM_Send   0x021DCBC4  thumb  ov137
 */
#include "../include/Obj04542.h"

typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GURU2_MAIN_RotateAll(char *, int);
typedef unsigned int   u32;
extern void GURU2_COMM_Send(void *p, u32 a, const void *b, u32 c);

void GURU2_MAIN_BroadcastResult(char *r4, int r5)
{
    struct {
        int a;
        int b;
        short h[6];
    } buf;
    int i;

    if (GFL_NET_SYSTEM_GetCurrentAid() != 0)
        return;
    GURU2_MAIN_RotateAll(r4, r5);
    buf.a = ((struct Obj04542 *)r4)->f11C;
    buf.b = ((struct Obj04542 *)r4)->f33C;
    for (i = 0; i < ((struct Obj04542 *)r4)->f30; i++) {
        int v = *(int *)(r4 + 0x2FC + i * 0xB4);
        buf.h[i] = (short)(v / 4096);
    }
    GURU2_COMM_Send((void *)(((struct Obj04542 *)r4)->fDC), 0x2808, &buf, 0x14);
}
