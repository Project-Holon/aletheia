/*
 * function: BOX2_UI_HideCursor
 * address: 0x021EE42C
 * packet: pkt_ov170_021EE42C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov170/box2_ui.c and filed here.
 *
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 */

#include "../include/Obj18526.h"

extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
void BOX2_UI_HideCursor(char *p);

void BOX2_UI_HideCursor(char *p)
{
    BOX2_SEQ_SetActorDrawEnable((char *)(((struct Obj18526 *)p)->f2C), 4, 0);
}
