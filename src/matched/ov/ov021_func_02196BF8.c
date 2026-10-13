/*
 * function: IRCBATTLEMENU_TouchKindMenu
 * address:  0x02196BF8
 * packet:   pkt_ov021_02196BF8
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
 *   IRCBATTLEMENU_SeqPressKindButton  0x02196B28  thumb  ov021
 *   IRCBATTLEMENU_SeqPressKindBack  0x02196B94  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09493.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void IRCBATTLEMENU_SetSeq(u8 *p, void *fn, u32 n);
struct Obj;
extern void IRCBATTLEMENU_SeqPressKindButton(struct Obj *a);
extern void IRCBATTLEMENU_SeqPressKindBack(struct Obj *a);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

int IRCBATTLEMENU_TouchKindMenu(u32 v, u8 *p)
{
    int r = 1;

    ((struct Obj09493 *)p)->f300 = v;
    switch (v) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqPressKindButton, 0x4A3);
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x73B);
        ((struct Obj09493 *)p)->f8 = 5;
        IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqPressKindButton, 0x4A9);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73C);
        ((struct Obj09493 *)p)->f8 = 0xC;
        IRCBATTLEMENU_SetSeq(p, IRCBATTLEMENU_SeqPressKindBack, 0x4AF);
        break;
    default:
        r = 1;
        break;
    }
    return r;
}
