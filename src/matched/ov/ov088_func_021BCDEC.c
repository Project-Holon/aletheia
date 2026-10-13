/*
 * function: STARTMENU_SaveEraseStepFirstConfirm
 * address:  0x021BCDEC
 * packet:   pkt_ov088_021BCDEC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 *
 * symbols:
 *   BMP_MENU_ProcessYesNo  0x0201FEBC  thumb
 *   STARTMENU_SaveEraseStartMessage  0x021BD118  thumb  ov088
 *   STARTMENU_SaveEraseStartFadeOut  0x021BD23C  thumb  ov088
 */
#include "../include/Obj00578.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BMP_MENU_ProcessYesNo(u8 *p);
extern void STARTMENU_SaveEraseStartMessage(int *p, u32 mode);
extern void STARTMENU_SaveEraseStartFadeOut(void);

void STARTMENU_SaveEraseStepFirstConfirm(void *p, int *st)
{
    int r = BMP_MENU_ProcessYesNo(((struct Obj00578 *)p)->f20);

    if (r == 0)
        goto a;
    if (r == -2)
        goto b;
    return;
a:
    STARTMENU_SaveEraseStartMessage(p, 1);
    *st = 4;
    return;
b:
    STARTMENU_SaveEraseStartFadeOut();
    *st = 7;
}
