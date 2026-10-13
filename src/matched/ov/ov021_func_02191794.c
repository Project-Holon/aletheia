/*
 * function: FIELD_MSGBG_PlainWinDrawCursor
 * address:  0x02191794
 * packet:   pkt_ov021_02191794
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
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

typedef struct R {
    u32 f00;
    u32 f04;
    u32 f08;
    Fx *f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    void *f20;
    u32 f24;
    u16 f28;
} R;

extern u8 FIELD_MSGBG_KeyWaitGetAuto(u8 *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
struct Cur;
extern void FIELD_MSGBG_AnimateCursor(struct Cur *c, u32 win, u32 col);
extern void BMP_WIN_TransferChars(struct Descriptor *a);

void FIELD_MSGBG_PlainWinDrawCursor(R *r)
{
    if (FIELD_MSGBG_KeyWaitGetAuto((u8 *)r->f0c + 0x160) == 0) {
        FIELD_MSGBG_AnimateCursor((struct Cur *)r, (u32)BMP_WIN_GetBmp((struct Descriptor *)r->f18), 0xF);
        BMP_WIN_TransferChars((struct Descriptor *)r->f18);
    }
}
