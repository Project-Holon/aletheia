/*
 * function: PMS_INPUT_OnButton
 * address: 0x021BD578
 * packet: pkt_ov110_021BD578
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: independent switch leaf following PMS_INPUT_ProcMain; all registers
 * are incoming arguments; each arm returns through bx lr.
 */
#include "../include/Obj10281.h"
typedef unsigned char u8;
void PMS_INPUT_OnButton(int value,unsigned int which,u8 *p) {
    switch(which) {
    case 0: ((struct Obj10281 *)p)->f3C=value; break;
    case 1:
    case 3: ((struct Obj10281 *)p)->f3C=1; break;
    case 2: break;
    default: ((struct Obj10281 *)p)->f3C=1; break;
    }
}
