/*
 * function: BOX2_SEQ_StateWaitInput
 * address: 0x021E2094
 * packet: pkt_ov170_021E2094
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00000.h"

typedef unsigned int u32;
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
typedef unsigned char  u8;
extern void UI_SetInputMode(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
int BOX2_SEQ_StateWaitInput(char *p)
{
    if (TOUCHPANEL_GetTrg() == 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        UI_SetInputMode(1);
        return ((struct Obj00000 *)p)->f28;
    }
    if (KEY_GetTrg() & 3) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        UI_SetInputMode(0);
        return ((struct Obj00000 *)p)->f28;
    }
    return 6;
}
