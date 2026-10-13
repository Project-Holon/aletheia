/*
 * function: STARTMENU_SaveEraseStepSecondConfirm
 * address:  0x021BCE3C
 * packet:   pkt_ov088_021BCE3C
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs 20 bytes long; the follower at 0x021BCE70 is an
 * unlabelled tail-call stub (ldr r0,[pc]; ldr r3,[pc]; ldr r0,[r0]; bx r3).
 * The switch value is unsigned so that case 0xFFFFFFFE sorts after case 0.
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

void STARTMENU_SaveEraseStepSecondConfirm(char *p, int *out)
{
    unsigned r = BMP_MENU_ProcessYesNo((u8 *)(*(char * *)&((struct Obj00578 *)p)->f20));
    switch (r) {
    case 0:
        STARTMENU_SaveEraseStartMessage((int *)p, 2);
        *out = 6;
        break;
    case 0xFFFFFFFE:
        STARTMENU_SaveEraseStartFadeOut();
        *out = 7;
        break;
    }
}
