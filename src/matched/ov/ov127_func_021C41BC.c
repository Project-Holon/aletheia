/*
 * function: WIFI_2DCHAR_DeleteActor
 * address: 0x021C41BC
 * packet: pkt_ov127_021C41BC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj10462.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *);
extern void MI_CpuFill8(void *, int, int);
void WIFI_2DCHAR_DeleteActor(u8 *p)
{
    if (((struct Obj10462 *)p)->f8 != 0) CLACT_DeleteActor(*(struct Obj * *)&((struct Obj10462 *)p)->f8);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj10462 *)p)->f4);
    MI_CpuFill8(p, 0, 24);
}
