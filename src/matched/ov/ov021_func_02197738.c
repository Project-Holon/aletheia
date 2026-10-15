/*
 * function: IRCBATTLEMENU_SeqSaveMain
 * address:  0x02197738
 * packet:   pkt_ov021_02197738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_SaveMain  0x02012DD0  thumb
 *   IRCBATTLEMENU_SetSubPaletteActive  0x02196228  thumb  ov021
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqSetupKindMenu  0x02196A60  thumb  ov021
 *   IRCBATTLEMENU_SeqStartFadeOut  0x02196804  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05989.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int GAME_DATA_SaveMain(u8 *p);
extern void IRCBATTLEMENU_SetSubPaletteActive(u8 *p, int flag);
struct Descriptor;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32);
extern void IRCBATTLEMENU_SetSeq(u8 *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqSetupKindMenu(u8 *p);
extern void IRCBATTLEMENU_SeqStartFadeOut(u8 *p);

void IRCBATTLEMENU_SeqSaveMain(u8 *a)
{
    if (GAME_DATA_SaveMain(*(u8 * *)&((struct Obj05989 *)a)->f30) == 2) {
        IRCBATTLEMENU_SetSubPaletteActive(a, 0);
        BMP_MENUWORK_DrawWindowBorder((void *)(((struct Obj05989 *)a)->f2B0), 2);
        BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj05989 *)a)->f2B0));
        func_02041B6C(5);
        if (((struct Obj05989 *)a)->f8 == 1) {
            IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqSetupKindMenu, 0x776);
        } else {
            IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqStartFadeOut, 0x779);
        }
        ((struct Obj05989 *)a)->f2F8 = 1;
    }
}
