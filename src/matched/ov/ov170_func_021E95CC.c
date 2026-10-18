/*
 * function: BOX2_SEQ_GotoBox2Ui
 * address:  0x021E95CC
 * packet:   pkt_ov170_021E95CC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   UI_SetInputMode 0x020355D8 arm
 *   BOX2_SEQ_StartWipeBlack 0x021E8F90 thumb
 *
 * Enters state 9 with reason v.
 */
#include "../include/Obj00000.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
extern u32 CURSOR_MOVE_GetState(struct Sound *obj);
extern void UI_SetInputMode(u8 v);
extern int BOX2_SEQ_StartWipeBlack(void *p, int a);

#define WORK(p) (*(char **)((p) + 0x2C))

int BOX2_SEQ_GotoBox2Ui(unsigned char *p, unsigned char v)
{
    if (CURSOR_MOVE_GetState(*(void **)(WORK(p) + 0x70)) == 1)
        UI_SetInputMode(0);
    else
        UI_SetInputMode(1);
    ((struct Obj00000 *)p)->f28 = 9;
    p[0x12] = v;
    return BOX2_SEQ_StartWipeBlack(p, 1);
}
