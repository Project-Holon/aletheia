/*
 * function: DWCi_MOV_WH_StateOutEndScan
 * address:  0x02178980
 * packet:   pkt_ov014_02178980
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
 *   DWCi_MOV_WH_StateInStartChild  0x021789C8  thumb  ov014
 */
#include "../include/Obj12472.h"
#include "../include/Obj12473.h"
#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *gWihWork;
void WIH_ChangeSysState(int a);
void WIH_SetError(int a);
int DWCi_MOV_WH_StateInStartChild(void);

void DWCi_MOV_WH_StateOutEndScan(u8 *m)
{
    u8 *g;

    ((u8 *)gWihWork)[0x1EDF] = 0;
    if (((struct Obj12472 *)m)->f2 != 0) {
        WIH_SetError(((struct Obj12472 *)m)->f2);
        return;
    }
    WIH_ChangeSysState(1);
    g = ((u8 *)gWihWork);
    if (((struct Obj12473 *)g)->f1EB4 != 0) {
        ((struct Obj12473 *)g)->f1EB4 = 0;
        if (DWCi_MOV_WH_StateInStartChild() == 0)
            WIH_ChangeSysState(9);
    }
}
