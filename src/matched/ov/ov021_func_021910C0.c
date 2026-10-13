/*
 * function: FIELD_MSGBG_InfoSysWinMain
 * address:  0x021910C0
 * packet:   pkt_ov021_021910C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_MsgStreamMain  0x02190D5C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   FIELD_MSGBG_IsCursorDrawn  0x021927F8  thumb  ov021
 *   FIELD_MSGBG_ClearCursor  0x021927FC  thumb  ov021
 *   FIELD_MSGBG_AnimateCursor  0x021928C0  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetAuto  0x0219320C  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_MSGBG_MsgStreamMain(u32 *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u8 FIELD_MSGBG_IsCursorDrawn(u8 *p);
struct Cur;
extern void FIELD_MSGBG_ClearCursor(struct Cur *c, u32 win, u32 col);
extern void FIELD_MSGBG_AnimateCursor(struct Cur *c, u32 win, u32 col);
extern u8 FIELD_MSGBG_KeyWaitGetAuto(u8 *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void BMP_WIN_TransferChars(struct Descriptor *);

u32 FIELD_MSGBG_InfoSysWinMain(u32 *p)
{
    u32 r = FIELD_MSGBG_MsgStreamMain((u32 *)p[1]);
    func_020362DC();
    func_0203630C();
    switch (r) {
    case 0:
        if (FIELD_MSGBG_IsCursorDrawn((u8 *)(p + 6)) == 1) {
            FIELD_MSGBG_ClearCursor((struct Cur *)(p + 6), (u32)func_02045770((struct Descriptor *)p[0]), 15);
            BMP_WIN_TransferChars((struct Descriptor *)p[0]);
        }
        break;
    case 1:
        if (FIELD_MSGBG_KeyWaitGetAuto((u8 *)(p[5] + 0x160)) == 0) {
            FIELD_MSGBG_AnimateCursor((struct Cur *)(p + 6), (u32)func_02045770((struct Descriptor *)p[0]), 15);
            BMP_WIN_TransferChars((struct Descriptor *)p[0]);
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}
