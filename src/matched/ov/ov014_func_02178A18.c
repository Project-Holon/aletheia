/*
 * function: DWCi_MOV_WH_StateOutStartChild
 * address:  0x02178A18
 * packet:   pkt_ov014_02178A18
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
 *   DWCi_MOV_WH_StateInStartChildMP  0x02178AB8  thumb  ov014
 */
#include "../include/Obj04957.h"
#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *gWihWork;
void WIH_ChangeSysState(int a);
void WIH_SetError(int a);
int DWCi_MOV_WH_StateInStartChildMP(void);

void DWCi_MOV_WH_StateOutStartChild(u8 *m)
{
    u32 v;
    void (*cb)(int);

    if (((struct Obj04957 *)m)->f2 != 0) {
        WIH_SetError(((struct Obj04957 *)m)->f2);
        v = ((struct Obj04957 *)m)->f2;
        if (v == 0xC) {
            WIH_ChangeSysState(9);
            return;
        }
        if (v == 0xB) {
            WIH_ChangeSysState(9);
            return;
        }
        if (v == 1) {
            WIH_ChangeSysState(8);
            return;
        }
        WIH_ChangeSysState(9);
        return;
    }
    v = ((struct Obj04957 *)m)->f8;
    if (v == 8)
        return;
    if (v == 7) {
        WIH_ChangeSysState(4);
        if (DWCi_MOV_WH_StateInStartChildMP() == 0) {
            WIH_ChangeSysState(3);
            return;
        }
        *(u16 *)(((u8 *)gWihWork) + 0x1EA8) = ((struct Obj04957 *)m)->fA;
        cb = *(void (**)(int))(((u8 *)gWihWork) + 0x1E84);
        if (cb != 0)
            cb(((struct Obj04957 *)m)->fA);
        return;
    }
    if (v == 6)
        return;
    if (v == 9) {
        WIH_SetError(0x14);
        WIH_ChangeSysState(9);
        return;
    }
    if (v == 0x1A)
        return;
    WIH_ChangeSysState(9);
}
