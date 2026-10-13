/*
 * function: PMSIV_EDIT_InitSlotPositions
 * address: 0x021BC120
 * packet: pkt_ov110_021BC120
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov110
 */
#include "../include/Obj02817.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned PMS_INPUT_GetInputMode(u8 *);
void PMSIV_EDIT_InitSlotPositions(u8 *p)
{
    switch (PMS_INPUT_GetInputMode(*(u8 * *)&((struct Obj02817 *)p)->f4)) {
    case 0: ((struct Obj02817 *)p)->f38=104; ((struct Obj02817 *)p)->f3A=16; ((struct Obj02817 *)p)->f44=1; break;
    case 1: ((struct Obj02817 *)p)->f38=48; ((struct Obj02817 *)p)->f3A=16; ((struct Obj02817 *)p)->f3C=160; ((struct Obj02817 *)p)->f3E=16; ((struct Obj02817 *)p)->f44=2; break;
    case 2: ((struct Obj02817 *)p)->f44=0; break;
    }
}
