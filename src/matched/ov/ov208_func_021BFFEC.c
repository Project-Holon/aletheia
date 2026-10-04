/*
 * function: func_021BFFEC
 * address: 0x021BFFEC
 * packet: pkt_ov208_021BFFEC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C239C 0x021C239C thumb ov208
 *   func_021C2304 0x021C2304 thumb ov208
 *   func_021C231C 0x021C231C thumb ov208
 *   func_021C232C 0x021C232C thumb ov208
 *   func_021BC4F4 0x021BC4F4 thumb ov208
 *   func_021BC6BC 0x021BC6BC thumb ov208
 */
#include "../include/Obj08397.h"
typedef unsigned char u8;
extern void func_021C239C(char *);
extern void func_021C2304(char *);
extern void func_021C231C(char *);
extern void func_021C232C(char *);
extern void func_021BC4F4(int flag, int *p);
extern void func_021BC6BC(char *p);
void func_021BFFEC(void *unused, char *p)
{
    switch (((struct Obj08397 *)p)->f414) {
    case 1: func_021C239C(p); func_021C2304(p); break;
    case 2: func_021C231C(p); func_021C232C(p); break;
    case 3:
        func_021C239C(p);
        func_021C231C(p);
        func_021BC4F4(0, (int *)(((struct Obj08397 *)p)->f418));
        break;
    }
    ((struct Obj08397 *)p)->f414 = 0;
    func_021BC6BC(((struct Obj08397 *)p)->f420);
}
