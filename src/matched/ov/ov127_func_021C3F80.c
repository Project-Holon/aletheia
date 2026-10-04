/*
 * function: func_021C3F80
 * address: 0x021C3F80
 * packet: pkt_ov127_021C3F80
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4790 0x021C4790 thumb ov127
 *   func_021C41BC 0x021C41BC thumb ov127
 *   func_021C4330 0x021C4330 thumb ov127
 *   func_021C4010 0x021C4010 thumb ov127
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj05371.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021C4790(void *);
extern void func_021C41BC(u8 *p);
extern void func_021C4330(void *, int);
extern void func_021C4010(u8 *p);
extern void func_02049238(u32);
extern void func_020307B0(void *);
void func_021C3F80(u8 *p)
{
    u32 i;
    for (i = 0; i < ((struct Obj05371 *)p)->fC; i++) {
        if (!func_021C4790(*(u8 * *)&((struct Obj05371 *)p)->f8 + i * 24))
            func_021C41BC(*(u8 * *)&((struct Obj05371 *)p)->f8 + i * 24);
    }
    func_021C4330(p, 0);
    func_021C4010(p);
    func_02049238(((struct Obj05371 *)p)->f2F8);
    func_02049238(((struct Obj05371 *)p)->f2FC);
    func_020307B0(((struct Obj05371 *)p)->f8);
    func_020307B0(p);
}
