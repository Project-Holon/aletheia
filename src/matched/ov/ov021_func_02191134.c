/*
 * function: FIELD_MSGBG_SysWinDrawCursor
 * address:  0x02191134
 * packet:   pkt_ov021_02191134
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
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct P {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    Fx *f14;
} P;

extern u8 FIELD_MSGBG_KeyWaitGetAuto(u8 *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct Cur;
extern void FIELD_MSGBG_AnimateCursor(struct Cur *c, u32 win, u32 col);
extern void BMP_WIN_TransferChars(struct Descriptor *a);

void FIELD_MSGBG_SysWinDrawCursor(P *p)
{
    if (FIELD_MSGBG_KeyWaitGetAuto((u8 *)p->f14 + 0x160) == 0) {
        FIELD_MSGBG_AnimateCursor((struct Cur *)((u8 *)p + 0x18), (u32)func_02045770((struct Descriptor *)p->f00), 0xF);
        BMP_WIN_TransferChars((struct Descriptor *)p->f00);
    }
}
