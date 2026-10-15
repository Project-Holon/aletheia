/*
 * function: BOX2_SEQ_StateSetMiniIcon
 * address:  0x021E8A58
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_SetMiniIconVisible  0x021EE008  thumb  ov170
 *   CURSOR_MOVE_GetCurrent  0x020260E0  thumb  arm9
 *
 * Restart the sequence counter one below the queue length and
 *   return 0x61.
 */
#include "../include/Obj00000.h"


typedef unsigned char  u8;
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void BOX2_UI_SetMiniIconVisible(char *, int, int);
int BOX2_SEQ_StateSetMiniIcon(char *p)
{
    BOX2_UI_SetMiniIconVisible(p, CURSOR_MOVE_GetCurrent((struct Sound *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x70))) - 1, 1);
    return 0x61;
}
