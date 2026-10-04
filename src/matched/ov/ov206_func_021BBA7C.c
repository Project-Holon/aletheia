/*
 * function: func_021BBA7C
 * address: 0x021BBA7C
 * packet: pkt_ov206_021BBA7C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BBBD8 0x021BBBD8 thumb
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
#include "../include/Obj00173.h"
extern void func_021BBBD8(char *, int);
typedef unsigned int   u32;
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
void func_021BBA7C(char *p)
{
    unsigned char i;
    for (i = 0; i < 2; i++) {
        func_021BBBD8(p, i);
    }
    func_0204AFD8((u32)(((struct Obj00173 *)p)->f184));
    func_0204AFD8((u32)(((struct Obj00173 *)p)->f180));
    func_0204ADA4((u32)(((struct Obj00173 *)p)->f17C));
}
