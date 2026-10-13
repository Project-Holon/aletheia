/*
 * function: IRCBATTLEMENU_SeqUpdateTouchSub
 * address:  0x02196FF0
 * packet:   pkt_02196FF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Untraced thunk: tail call on the word at +0x24 into the ARM9 image.
 *
 * symbols:
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17949.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);

void IRCBATTLEMENU_SeqUpdateTouchSub(u8 *p)
{
    BUTTON_MAN_UpdateSlots((struct Ctx *)(((struct Obj17949 *)p)->f24));
}
