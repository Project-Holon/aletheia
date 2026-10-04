/*
 * function: func_021FE7F8
 * address: 0x021FE7F8
 * packet: pkt_ov186_021FE7F8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02022004 0x02022004 thumb
 *   func_02021F08 0x02021F08 thumb
 *   func_02021D50 0x02021D50 thumb
 */
#include "../include/Obj05507.h"
extern void func_02022004(unsigned, unsigned, unsigned short, unsigned, unsigned);
struct Obj02021F08;
struct S02021D50;
extern void func_02021F08(struct Obj02021F08 *o, int v);
extern void func_02021D50(struct S02021D50 *p);
void func_021FE7F8(char *p, int mask)
{
    if (mask & 1)
        func_02022004(*(unsigned *)&((struct Obj05507 *)p)->f20, 0, 0xBFFF, 16, ((struct Obj05507 *)p)->f24);
    if (mask & 2)
        func_02022004(*(unsigned *)&((struct Obj05507 *)p)->f20, 1, 0xBFFF, 16, ((struct Obj05507 *)p)->f24);
    func_02021F08(((struct Obj05507 *)p)->f20, 1);
    func_02021D50(((struct Obj05507 *)p)->f20);
}
