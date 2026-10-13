/*
 * function: DWCi_MOV_WH_StateInStartChild
 * address:  0x021789C8
 * packet:   pkt_ov014_021789C8
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
 *   DWCi_MOV_WH_StateOutStartChild  0x02178A18  thumb  ov014
 *   WM_StartConnectEx  0x0208F84C  arm
 */

#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *gWihWork;
void WIH_ChangeSysState(int a);
void WIH_SetError(int a);
void DWCi_MOV_WH_StateOutStartChild(u8 *m);
int WM_StartConnectEx(void *cb, void *a, void *b, int c, int d);

int DWCi_MOV_WH_StateInStartChild(void)
{
    int r;

    if (*(u32 *)(((u8 *)gWihWork) + 0x1E70) - 4 <= 1)
        return 1;
    WIH_ChangeSysState(3);
    r = WM_StartConnectEx((void *)DWCi_MOV_WH_StateOutStartChild, ((u8 *)gWihWork) + 0xF40, ((u8 *)gWihWork) + 0x1EC4, 1, 0);
    if (r != 2) {
        WIH_SetError(r);
        return 0;
    }
    return 1;
}
