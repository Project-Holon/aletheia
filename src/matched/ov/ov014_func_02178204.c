/*
 * function: WIH_StateOutStartParent
 * address:  0x02178204
 * packet:   pkt_ov014_02178204
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gWihWork     0x021797A8  data  a4
 *   WIH_SetError  0x0217814C  thumb  ov014
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 *   NET_WHPIPE_OnChildDisconnected  0x0217807C  thumb  ov014
 *   WIH_StateInStartParentMP  0x02178304  thumb  ov014
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   WM_Disconnect  0x0208F938  arm
 *   GFL_NET_HANDLE_RemoveHandle  0x0203A338  arm
 *   GFL_NET_HANDLE_RequestNegotiation  0x02039A2C  arm
 */
#include "../include/Obj02672.h"
#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *gWihWork;
void WIH_SetError(int err);
void WIH_ChangeSysState(int a);
void NET_WHPIPE_OnChildDisconnected(void);
int WIH_StateInStartParentMP(void);
u32 GFL_NET_GetUserArg(void);
int WM_Disconnect(int a, u16 b);
void GFL_NET_HANDLE_RemoveHandle(u32 a0);
void GFL_NET_HANDLE_RequestNegotiation(int a);

typedef int (*ConnFn)(void *obj, u32 a);
typedef void (*SlotFn)(u16 slot);

void WIH_StateOutStartParent(u8 *obj)
{
    int ok = 1;
    u16 mask = 1 << ((struct Obj02672 *)obj)->f10;
    SlotFn cb;
    int res;

    if (((struct Obj02672 *)obj)->f2 != 0) {
        WIH_SetError(((struct Obj02672 *)obj)->f2);
        WIH_ChangeSysState(9);
        return;
    }
    switch (((struct Obj02672 *)obj)->f8) {
    case 2:
        *(u16 *)(((u8 *)gWihWork) + 0x1EBA) += 1;
        break;
    case 7:
        if (*(ConnFn *)(((u8 *)gWihWork) + 0x1E7C) != 0)
            ok = (*(ConnFn *)(((u8 *)gWihWork) + 0x1E7C))(obj, GFL_NET_GetUserArg());
        if (ok == 0) {
            res = WM_Disconnect(0, ((struct Obj02672 *)obj)->f10);
            if (res != 2) {
                WIH_SetError(res);
                WIH_ChangeSysState(9);
            }
        } else {
            *(u16 *)(((u8 *)gWihWork) + 0x1EAA) |= mask;
            cb = *(SlotFn *)(((u8 *)gWihWork) + 0x1E84);
            if (cb != 0)
                cb(((struct Obj02672 *)obj)->f10);
        }
        break;
    case 9:
    case 0x1A:
        if (*(u16 *)(((u8 *)gWihWork) + 0x1EAA) & (1 << ((struct Obj02672 *)obj)->f10)) {
            *(u16 *)(((u8 *)gWihWork) + 0x1EAA) &= ~mask;
            cb = *(SlotFn *)(((u8 *)gWihWork) + 0x1E80);
            if (cb != 0)
                cb(((struct Obj02672 *)obj)->f10);
            NET_WHPIPE_OnChildDisconnected();
            GFL_NET_HANDLE_RemoveHandle(((struct Obj02672 *)obj)->f10);
            GFL_NET_HANDLE_RequestNegotiation(((struct Obj02672 *)obj)->f10);
        }
        break;
    case 0:
        if (WIH_StateInStartParentMP() == 0)
            WIH_ChangeSysState(9);
        break;
    }
}
