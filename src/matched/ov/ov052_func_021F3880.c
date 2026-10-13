/*
 * function: FIELD_GIMMICK_BSUBWAY_ExitTrain
 * address: 0x021F3880
 * packet: pkt_ov052_021F3880
 * region: ov052
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov052/field_gimmick_bsubway.c and filed here.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */

#include "../include/Obj20567.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void FIELD_GIMMICK_BSUBWAY_ExitTrain(char *a);

void FIELD_GIMMICK_BSUBWAY_ExitTrain(char *a)
{
    func_020307B0(((struct Obj20567 *)a)->f24);
}
