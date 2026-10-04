/*
 * function: func_021BD7E0
 * address: 0x021BD7E0
 * packet: pkt_ov099_021BD7E0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0203D378 0x0203D378 arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
#include "../include/Obj22041.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C18C8(char *, int, int);
extern u32 func_0203D378(void);
extern void func_021BAAB8(char *, int, int);
int func_021BD7E0(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    if (func_0203D378() != 0) func_021BAAB8(p, 0x73, 0);
    else func_021BAAB8(p, 0x72, 0);
    ((struct Obj22041 *)p)->f1CC = 0x8e;
    return v;
}
