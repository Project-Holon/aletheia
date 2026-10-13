/*
 * function: IRCBATTLEMENU_DeleteMsgWin
 * address:  0x021962F4
 * packet:   pkt_ov021_021962F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRCBATTLEMENU_ClearMessageWindow  0x021962C4  thumb  ov021
 *   BMP_WIN_Delete  0x020452E8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

struct Descriptor;
extern int IRCBATTLEMENU_ClearMessageWindow(u32 a);
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void IRCBATTLEMENU_DeleteMsgWin(u8 *a)
{
    IRCBATTLEMENU_ClearMessageWindow((u32)a);
    BMP_WIN_Delete((struct Descriptor *)(*(u32 *)&((struct Obj00094 *)a)->f2B0));
    *(u32 *)&((struct Obj00094 *)a)->f2B0 = 0;
}
