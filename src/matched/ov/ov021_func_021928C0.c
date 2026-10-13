/*
 * function: FIELD_MSGBG_AnimateCursor
 * address:  0x021928C0
 * packet:   pkt_ov021_021928C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_ClearCursor  0x021927FC  thumb  ov021
 *   FIELD_MSGBG_DrawCursor  0x02192860  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Cur {
    u8 f00;
    u8 f01;
    u8 f02;
} Cur;

extern void FIELD_MSGBG_ClearCursor(Cur *c, u32 win, u32 col);
extern void FIELD_MSGBG_DrawCursor(u8 *a, u32 b, u32 col);

void FIELD_MSGBG_AnimateCursor(Cur *c, u32 win, u32 col)
{
    FIELD_MSGBG_ClearCursor(c, win, col);
    c->f02++;
    if (c->f02 >= 4) {
        c->f02 = 0;
        c->f01++;
        c->f01 %= 3;
    }
    FIELD_MSGBG_DrawCursor((u8 *)c, win, col);
}
