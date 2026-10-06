/*
 * function: func_021F5C08
 * address: 0x021F5C08
 * packet: pkt_ov215_021F5C08
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj14705.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);
void func_021F5C08(void *unused, char *p)
{
    if (((struct Obj14705 *)p)->f6C) {
        func_02040588(1, 1);
        ((struct Obj14705 *)p)->f6C = 0;
    }
}
