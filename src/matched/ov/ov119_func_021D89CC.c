/*
 * function: func_021D89CC
 * address: 0x021D89CC
 * packet: pkt_ov119_021D89CC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203C554 0x0203C554 arm
 */
#include "../include/Obj22698.h"
#include "../include/Obj22699.h"
typedef unsigned char  u8;
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
typedef unsigned int   u32;
extern void func_0203C554(u32 a);

void func_021D89CC(char *p)
{
    func_0203D7B0(0);
    func_0203D7BC(0);
    func_0203C554(0);
    ((struct Obj22699 *)(*(char * *)&((struct Obj22698 *)p)->f8))->f8 = 3;
}
