/*
 * function: func_021C41BC
 * address: 0x021C41BC
 * packet: pkt_ov127_021C41BC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj10462.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *);
extern void func_02082BCC(void *, int, int);
void func_021C41BC(u8 *p)
{
    if (((struct Obj10462 *)p)->f8 != 0) CLACT_DeleteActor(*(struct Obj * *)&((struct Obj10462 *)p)->f8);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj10462 *)p)->f4);
    func_02082BCC(p, 0, 24);
}
