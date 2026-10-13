/*
 * function: FIELD_MSGBG_TalkWinMain
 * address:  0x02191388
 * packet:   pkt_ov021_02191388
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TALKMSGWIN_IsShown  0x02194974  thumb  ov021
 *   TALKMSGWIN_GetPrintStream  0x02194984  thumb  ov021
 *   func_0201CE30  0x0201CE30  thumb
 *   func_02040618  0x02040618  arm
 *   FIELD_MSGBG_IsCursorDrawn  0x021927F8  thumb  ov021
 *   TALKMSGWIN_GetBmpWin  0x02194990  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   FIELD_MSGBG_ClearCursor  0x021927FC  thumb  ov021
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   FIELD_MSGBG_KeyWaitCheckSkip  0x02193228  thumb  ov021
 *   FIELD_MSGBG_StreamSetSpeed  0x021932A0  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetAuto  0x0219320C  thumb  ov021
 *   FIELD_MSGBG_AnimateCursor  0x021928C0  thumb  ov021
 *   func_0201CE34  0x0201CE34  thumb
 *   FIELD_MSGBG_KeyWaitCheckAdvance  0x02193260  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern int TALKMSGWIN_IsShown(u8 *p, int i);
extern u32 TALKMSGWIN_GetPrintStream(u32, u32);
extern u32 func_0201CE30(void *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u8 FIELD_MSGBG_IsCursorDrawn(u8 *p);
extern u32 TALKMSGWIN_GetBmpWin(u32, u32);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct Cur;
extern void FIELD_MSGBG_ClearCursor(struct Cur *c, u32 win, u32 col);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern int FIELD_MSGBG_KeyWaitCheckSkip(u8 *p);
extern void FIELD_MSGBG_StreamSetSpeed(u32 a, int f);
extern u8 FIELD_MSGBG_KeyWaitGetAuto(u8 *p);
extern void FIELD_MSGBG_AnimateCursor(struct Cur *c, u32 win, u32 col);
extern u32 func_0201CE34(void *p);
extern int FIELD_MSGBG_KeyWaitCheckAdvance(u8 *p, u32 q);
extern void func_020061E4(u32);
extern void func_0201CE38(void *p);

u32 FIELD_MSGBG_TalkWinMain(u32 *a)
{
    u32 h;
    u32 r;
    u32 w;
    u32 c;

    if (TALKMSGWIN_IsShown((u8 *)a[2], *((u8 *)a + 1)) == 0) {
        return 0;
    }
    h = TALKMSGWIN_GetPrintStream(a[2], *((u8 *)a + 1));
    r = func_0201CE30((void *)h);
    func_02040618(1, 3, *(s16 *)((u8 *)a + 2));
    if (*(s16 *)((u8 *)a + 2) < 0) {
        *(s16 *)((u8 *)a + 2) += 2;
        if (*(s16 *)((u8 *)a + 2) > 0) {
            *(s16 *)((u8 *)a + 2) = 0;
        }
    }
    *(s16 *)((u8 *)a + 2) = -*(s16 *)((u8 *)a + 2);
    switch (r) {
    case 0:
        if (FIELD_MSGBG_IsCursorDrawn((u8 *)(a + 3)) == 1) {
            w = TALKMSGWIN_GetBmpWin(a[2], *((u8 *)a + 1));
            FIELD_MSGBG_ClearCursor((struct Cur *)(a + 3), (u32)func_02045770((struct Descriptor *)w), 15);
            BMP_WIN_TransferChars((struct Descriptor *)w);
        }
        if (FIELD_MSGBG_KeyWaitCheckSkip((u8 *)(a[5] + 0x160)) != 0) {
            FIELD_MSGBG_StreamSetSpeed(h, 1);
        } else {
            FIELD_MSGBG_StreamSetSpeed(h, 0);
        }
        break;
    case 1:
        w = TALKMSGWIN_GetBmpWin(a[2], *((u8 *)a + 1));
        c = (u32)func_02045770((struct Descriptor *)w);
        if (FIELD_MSGBG_KeyWaitGetAuto((u8 *)(a[5] + 0x160)) == 0) {
            FIELD_MSGBG_AnimateCursor((struct Cur *)(a + 3), c, 15);
        }
        if (FIELD_MSGBG_KeyWaitCheckAdvance((u8 *)(a[5] + 0x160), func_0201CE34((void *)h)) != 0) {
            if (FIELD_MSGBG_KeyWaitGetAuto((u8 *)(a[5] + 0x160)) == 0) {
                func_020061E4(0x547);
            }
            func_0201CE38((void *)h);
            FIELD_MSGBG_ClearCursor((struct Cur *)(a + 3), c, 15);
            FIELD_MSGBG_StreamSetSpeed(h, 0);
        }
        BMP_WIN_TransferChars((struct Descriptor *)w);
        break;
    case 2:
        if (*(s16 *)((u8 *)a + 2) != 0) {
            *(s16 *)((u8 *)a + 2) = 0;
            func_02040618(1, 3, *(s16 *)((u8 *)a + 2));
        }
        return 1;
    }
    return 0;
}
