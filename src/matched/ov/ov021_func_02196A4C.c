/*
 * function: IRCBATTLEMENU_SeqUpdateTouchTop
 * address:  0x02196A4C
 * packet:   pkt_ov021_02196A4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19634.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 WIPE_SYS_EndCheck(void);
typedef signed int     s32;
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);

void IRCBATTLEMENU_SeqUpdateTouchTop(u8 *a)
{
    if (WIPE_SYS_EndCheck() != 0) {
        BUTTON_MAN_UpdateSlots((struct Ctx *)(((struct Obj19634 *)a)->f24));
    }
}
