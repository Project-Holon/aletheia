/*
 * function: FIELD_MSGBG_PlainWinMain
 * address:  0x021916E0
 * packet:   pkt_ov021_021916E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   FIELD_MSGBG_MsgStreamMain  0x02190D5C  thumb  ov021
 *   func_0201CE30  0x0201CE30  thumb
 *   func_02040618  0x02040618  arm
 *   FIELD_MSGBG_IsCursorDrawn  0x021927F8  thumb  ov021
 *   FIELD_MSGBG_ClearCursor  0x021927FC  thumb  ov021
 *   FIELD_MSGBG_AnimateCursor  0x021928C0  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetAuto  0x0219320C  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00005.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern int FIELD_MSGBG_MsgStreamMain(u32 *p);
extern u32 func_0201CE30(void *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u8 FIELD_MSGBG_IsCursorDrawn(u8 *p);
struct Cur;
extern void FIELD_MSGBG_ClearCursor(struct Cur *c, u32 win, u32 col);
extern void FIELD_MSGBG_AnimateCursor(struct Cur *c, u32 win, u32 col);
extern u8 FIELD_MSGBG_KeyWaitGetAuto(u8 *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void BMP_WIN_TransferChars(struct Descriptor *);

u32 FIELD_MSGBG_PlainWinMain(u32 *a)
{
    u32 r;
    func_020362DC();
    func_0203630C();
    r = FIELD_MSGBG_MsgStreamMain((u32 *)a[7]);
    a[9] = func_0201CE30((void *)(*(u32 *)(a[7] + 4)));
    func_02040618(1, 3, ((struct Obj00005 *)a)->f28);
    if (((struct Obj00005 *)a)->f28 < 0) {
        ((struct Obj00005 *)a)->f28 += 2;
        if (((struct Obj00005 *)a)->f28 > 0) {
            ((struct Obj00005 *)a)->f28 = 0;
        }
    }
    ((struct Obj00005 *)a)->f28 = -((struct Obj00005 *)a)->f28;
    switch (r) {
    case 0:
        if (FIELD_MSGBG_IsCursorDrawn((u8 *)a) == 1) {
            FIELD_MSGBG_ClearCursor((struct Cur *)a, (u32)func_02045770((struct Descriptor *)a[6]), 15);
            BMP_WIN_TransferChars((struct Descriptor *)a[6]);
        }
        break;
    case 1:
        if (FIELD_MSGBG_KeyWaitGetAuto((u8 *)(a[3] + 0x160)) == 0) {
            FIELD_MSGBG_AnimateCursor((struct Cur *)a, (u32)func_02045770((struct Descriptor *)a[6]), 15);
            BMP_WIN_TransferChars((struct Descriptor *)a[6]);
        }
        break;
    case 2:
        if (((struct Obj00005 *)a)->f28 != 0) {
            ((struct Obj00005 *)a)->f28 = 0;
            func_02040618(1, 3, ((struct Obj00005 *)a)->f28);
        }
        return 1;
    }
    return 0;
}
