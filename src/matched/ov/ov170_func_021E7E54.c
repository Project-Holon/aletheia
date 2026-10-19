/*
 * function: BOX2_SEQ_StateCloseMenu
 * address: 0x021E7E54
 * packet: pkt_ov170_021E7E54
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_ToggleHandSlot 0x021EA908 thumb ov170
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb ov170
 *   BOX2_MAIN_SetBodySlots 0x021DF11C thumb ov170
 *   BOX2_SEQ_SetupFrameFadeAndWait 0x021E94AC thumb ov170
 *   BOX2_SEQ_SetSeqSecond 0x021E8FD0 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23925.h"
#include "../include/Obj23926.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void BOX2_SEQ_ToggleHandSlot(int p, int bit);
extern void BOX2_MAIN_SetBoxValueAt(int a, int b, int c, int d, int e);
extern void BOX2_MAIN_SetBodySlots(char *p, int b);
extern int BOX2_SEQ_SetupFrameFadeAndWait(u8 *, int, int);
extern int BOX2_SEQ_SetSeqSecond(char *p, int a);
int BOX2_SEQ_StateCloseMenu(u8 *p)
{
    u8 mask;
    switch ((unsigned)CURSOR_MOVE_PollRepeatInput(((struct Obj23925 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 0);
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 1);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 2);
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 3);
        break;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 4);
        break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 5);
        break;
    case 6:
        mask = ((struct Obj23926 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA174;
        BOX2_MAIN_SetBoxValueAt((int)p, p[22], p[20], 11, mask);
        BOX2_MAIN_SetBodySlots((char *)p, (unsigned)mask);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return BOX2_SEQ_SetupFrameFadeAndWait(p, 0, 87);
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_SetupFrameFadeAndWait(p, 1, 87);
    case (unsigned)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_SetupFrameFadeAndWait(p, 1, 87);
    case (unsigned)-3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((char *)p, 88);
    case (unsigned)-4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    }
    return 86;
}
