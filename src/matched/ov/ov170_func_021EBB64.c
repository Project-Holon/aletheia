/*
 * function: func_021EBB64
 * address: 0x021EBB64
 * packet: pkt_ov170_021EBB64
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021EBA84 0x021EBA84 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23990.h"
#include "../include/Obj23991.h"
typedef unsigned int   u32;
struct WordSet;
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern unsigned func_0202136C(unsigned short);
extern void func_021EBA84(unsigned char *, int, int);
void func_021EBB64(unsigned char *p, unsigned v, int i)
{
    if (v == 0) {
        func_0201EF40(((struct Obj23990 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, 0x70);
        func_021EBA84(p, 0x2c, i);
    } else if (func_0202136C(v) == 1) {
        func_021EBA84(p, 0x30, i);
    } else {
        func_0201EF40(((struct Obj23991 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, v);
        func_021EBA84(p, 15, i);
    }
}
