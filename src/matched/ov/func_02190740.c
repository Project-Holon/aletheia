/*
 * function: FIELD_MSGBG_MsgWinPrintMsg
 * address:  0x02190740
 * packet:   pkt_02190740
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_MSGBG_MsgPrintPrintMsg  0x02190550  thumb  ov021
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12066.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 BG_SYS_PushTile(u32);
struct Descriptor;
struct Slot;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void FIELD_MSGBG_MsgPrintPrintMsg(struct Slot *s, int x, int y, u32 z);

int FIELD_MSGBG_MsgWinPrintMsg(u32 a, u32 b, u32 c, u32 d)
{
FIELD_MSGBG_MsgPrintPrintMsg((struct Slot *)(((struct Obj12066 *)((u8 *)(a)))->f4), b, c, d);
return BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)(((struct Obj12066 *)((u8 *)(a)))->f0)));
}

