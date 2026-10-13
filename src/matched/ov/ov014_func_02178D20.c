/*
 * function: DWCi_MOV_WH_StateInSetMPData
 * address:  0x02178D20
 * packet:   pkt_ov014_02178D20
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gWihWork     0x021797A8  data  a4
 *   WIH_StateOutSetMPData  0x02178D74  thumb  ov014
 *   func_020862F0  0x020862F0  arm
 *   WM_SetMPDataToPortEx  0x0208FCB4  arm
 */

#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *gWihWork;
void WIH_StateOutSetMPData(u8 *m);
void func_020862F0(u32 a, u32 b);
int WM_SetMPDataToPortEx(void *cb, u32 c, u32 a, u32 b, u32 d, u32 e, u32 f);

int DWCi_MOV_WH_StateInSetMPData(u32 a, u32 b, u32 c)
{
    func_020862F0(*(u32 *)(((u8 *)gWihWork) + 0x1E68), *(u32 *)(((u8 *)gWihWork) + 0x1E8C));
    if (WM_SetMPDataToPortEx((void *)WIH_StateOutSetMPData, c, a, b, 0xFFFF, 0xE, 2) == 2)
        return 1;
    return 0;
}
