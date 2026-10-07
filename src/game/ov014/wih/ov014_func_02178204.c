/*
 * function: func_02178204
 * address:  0x02178204
 * packet:   pkt_ov014_02178204
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217807C  0x0217807C  thumb  ov014
 *   func_02178304  0x02178304  thumb  ov014
 *   func_0203D650  0x0203D650  arm
 *   func_0208F938  0x0208F938  arm
 *   func_0203A338  0x0203A338  arm
 *   func_02039A2C  0x02039A2C  arm
 */
#include "../../../matched/include/Obj02672.h"
#include "../../../matched/include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *g_021797A8;
void func_0217814C(int err);
void func_02178138(int a);
void func_0217807C(void);
int func_02178304(void);
u32 func_0203D650(void);
int func_0208F938(int a, u16 b);
void func_0203A338(u32 a0);
void func_02039A2C(int a);

typedef int (*ConnFn)(void *obj, u32 a);
typedef void (*SlotFn)(u16 slot);

void func_02178204(u8 *obj)
{
    int ok = 1;
    u16 mask = 1 << ((struct Obj02672 *)obj)->f10;
    SlotFn cb;
    int res;

    if (((struct Obj02672 *)obj)->f2 != 0) {
        func_0217814C(((struct Obj02672 *)obj)->f2);
        func_02178138(9);
        return;
    }
    switch (((struct Obj02672 *)obj)->f8) {
    case 2:
        *(u16 *)(((u8 *)g_021797A8) + 0x1EBA) += 1;
        break;
    case 7:
        if (*(ConnFn *)(((u8 *)g_021797A8) + 0x1E7C) != 0)
            ok = (*(ConnFn *)(((u8 *)g_021797A8) + 0x1E7C))(obj, func_0203D650());
        if (ok == 0) {
            res = func_0208F938(0, ((struct Obj02672 *)obj)->f10);
            if (res != 2) {
                func_0217814C(res);
                func_02178138(9);
            }
        } else {
            *(u16 *)(((u8 *)g_021797A8) + 0x1EAA) |= mask;
            cb = *(SlotFn *)(((u8 *)g_021797A8) + 0x1E84);
            if (cb != 0)
                cb(((struct Obj02672 *)obj)->f10);
        }
        break;
    case 9:
    case 0x1A:
        if (*(u16 *)(((u8 *)g_021797A8) + 0x1EAA) & (1 << ((struct Obj02672 *)obj)->f10)) {
            *(u16 *)(((u8 *)g_021797A8) + 0x1EAA) &= ~mask;
            cb = *(SlotFn *)(((u8 *)g_021797A8) + 0x1E80);
            if (cb != 0)
                cb(((struct Obj02672 *)obj)->f10);
            func_0217807C();
            func_0203A338(((struct Obj02672 *)obj)->f10);
            func_02039A2C(((struct Obj02672 *)obj)->f10);
        }
        break;
    case 0:
        if (func_02178304() == 0)
            func_02178138(9);
        break;
    }
}
