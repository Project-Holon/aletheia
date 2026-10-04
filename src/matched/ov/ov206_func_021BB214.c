/*
 * function: func_021BB214
 * address: 0x021BB214
 * packet: pkt_ov206_021BB214
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../include/Obj10887.h"
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021BB214(char *p, int i)
{
    char *s = p + i * 4;
    func_0204ADA4((u32)(((struct Obj10887 *)s)->f9C));
    func_0204A8D4((u32)(((struct Obj10887 *)s)->f94));
    func_0204AFD8((u32)(((struct Obj10887 *)s)->fA4));
}
