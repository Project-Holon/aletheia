/*
 * function: FIELD_MSGBG_TalkWinDrawCursor
 * address:  0x021914CC
 * packet:   pkt_ov021_021914CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   func_02045770  0x02045770  arm  arm9
 *   FIELD_MSGBG_AnimateCursor  0x021928C0  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetAuto  0x0219320C  thumb  ov021
 *   TALKMSGWIN_GetBmpWin  0x02194990  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct S {
    u8  f00;
    u8  f01;
    u8  pad02[6];
    u32 f08;
    u32 sub[2];
    u8 *f14;
} S;

extern u8 FIELD_MSGBG_KeyWaitGetAuto(u8 *p);
extern u32 TALKMSGWIN_GetBmpWin(u32 a, u32 b);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct Cur;
extern void FIELD_MSGBG_AnimateCursor(struct Cur *c, u32 win, u32 col);
extern void BMP_WIN_TransferChars(struct Descriptor *a);

void FIELD_MSGBG_TalkWinDrawCursor(S *s)
{
    u32 x;

    if (FIELD_MSGBG_KeyWaitGetAuto(s->f14 + 0x160) == 0) {
        x = TALKMSGWIN_GetBmpWin(s->f08, s->f01);
        FIELD_MSGBG_AnimateCursor((struct Cur *)s->sub, (u32)func_02045770((struct Descriptor *)x), 0xF);
        BMP_WIN_TransferChars((struct Descriptor *)x);
    }
}
