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
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 */
#include "../include/Obj22040.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C18C8(char *, int, int);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
int func_021BD778(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    ((struct Obj22040 *)p)->f1CC = 0x99;
    return v;
}
