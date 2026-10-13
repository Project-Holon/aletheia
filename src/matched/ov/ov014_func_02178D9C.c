/*
 * function: DWCi_MOV_WH_PortReceiveCallback
 * address:  0x02178D9C
 * packet:   pkt_ov014_02178D9C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gWihWork     0x021797A8  data  a4
 *   WIH_SetError  0x0217814C  thumb  ov014
 */
#include "../include/Obj03559.h"
#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *gWihWork;
void WIH_SetError(int a);

void DWCi_MOV_WH_PortReceiveCallback(u8 *m)
{
    void (*cb)(u32, u32, u32);

    if (((struct Obj03559 *)m)->f2 != 0) {
        WIH_SetError(((struct Obj03559 *)m)->f2);
        return;
    }
    cb = *(void (**)(u32, u32, u32))(((u8 *)gWihWork) + 0x1E78);
    if (cb != 0) {
        if (((struct Obj03559 *)m)->f4 == 0x15)
            cb(((struct Obj03559 *)m)->f12, ((struct Obj03559 *)m)->fC, ((struct Obj03559 *)m)->f10);
        else if (((struct Obj03559 *)m)->f4 == 9)
            cb(((struct Obj03559 *)m)->f12, 0, 0);
    }
}
