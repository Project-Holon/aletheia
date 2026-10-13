/*
 * function: IRCBATTLEMENU_TouchPartyMenu
 * address:  0x02196D94
 * packet:   pkt_ov021_02196D94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Handler: stores the request at +0x300 and dispatches on it.
 *
 * symbols:
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqPressPartyButton  0x02196D24  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07463.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void IRCBATTLEMENU_SetSeq(u8 *p, void *fn, u32 n);
struct Obj;
extern void IRCBATTLEMENU_SeqPressPartyButton(struct Obj *a);
extern void func_020061E4(u32 a);

int IRCBATTLEMENU_TouchPartyMenu(u32 v, u8 *p)
{
    int r = 0;

    ((struct Obj07463 *)p)->f300 = v;
    switch (v) {
    case 1:
        func_020061E4(0x73B);
        ((struct Obj07463 *)p)->fC = 0;
        IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqPressPartyButton, 0x524);
        r = 1;
        break;
    case 0:
        func_020061E4(0x73B);
        r = 1;
        ((struct Obj07463 *)p)->fC = 1;
        IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqPressPartyButton, 0x52A);
        break;
    case 2:
        func_020061E4(0x73C);
        ((struct Obj07463 *)p)->fC = 2;
        IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqPressPartyButton, 0x530);
        break;
    }
    return r;
}
