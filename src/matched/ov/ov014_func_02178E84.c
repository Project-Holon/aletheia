/*
 * function: WIH_StartMeasureChannel
 * address:  0x02178E84
 * packet:   pkt_ov014_02178E84
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gWihWork     0x021797A8  data  a4
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 *   WIH_SetError  0x0217814C  thumb  ov014
 *   WIH_StateInMeasureChannel  0x02178F1C  thumb  ov014
 *   OS_GetMacAddress  0x02087C6C  arm
 */

#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *gWihWork;
void WIH_ChangeSysState(int a);
void WIH_SetError(int a);
int WIH_StateInMeasureChannel(u16 n);
void OS_GetMacAddress(u16 *p);

int WIH_StartMeasureChannel(void)
{
    u16 t[3];
    int r;
    int ok;
    u32 x;

    OS_GetMacAddress(t);
    x = *(volatile u32 *)0x02FFFC3C;
    *(u32 *)(((u8 *)gWihWork) + 0x1E9C) = t[2] + (t[1] + (t[0] + x));
    *(u32 *)(((u8 *)gWihWork) + 0x1E9C) = *(u32 *)(((u8 *)gWihWork) + 0x1E9C) * 0x10DCD + 0x3039;
    *(u16 *)(((u8 *)gWihWork) + 0x1EAC) = 0;
    *(u16 *)(((u8 *)gWihWork) + 0x1EAE) = 0x65;
    WIH_ChangeSysState(3);
    ok = 1;
    r = WIH_StateInMeasureChannel(1);
    if (r == 0x18) {
        WIH_SetError(0x18);
        WIH_ChangeSysState(9);
        return 0;
    }
    if (r != 2) {
        WIH_SetError(r);
        WIH_ChangeSysState(9);
        return 0;
    }
    return ok;
}
