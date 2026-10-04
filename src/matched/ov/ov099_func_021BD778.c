/*
 * function: func_021BD778
 * address: 0x021BD778
 * packet: pkt_ov099_021BD778
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 */
#include "../include/Obj22040.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C18C8(char *, int, int);
extern void func_0203D7B0(int);
extern void func_0203D7BC(int);
int func_021BD778(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    func_0203D7B0(0);
    func_0203D7BC(0);
    ((struct Obj22040 *)p)->f1CC = 0x99;
    return v;
}
