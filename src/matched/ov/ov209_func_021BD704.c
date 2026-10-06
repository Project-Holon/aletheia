/*
 * function: func_021BD704
 * address: 0x021BD704
 * packet: pkt_ov209_021BD704
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD4F4 0x021BD4F4 thumb ov209
 *   func_021BD440 0x021BD440 thumb ov209
 *   func_021BD488 0x021BD488 thumb ov209
 *   func_021BD4DC 0x021BD4DC thumb ov209
 *   func_0201EFA4 0x0201EFA4 thumb
 */
#include "../include/Obj00123.h"
#include "../include/Obj25566.h"
struct WordSet;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021BD4F4(u8 *p, u32 idx);
extern void func_021BD440(char *, unsigned, unsigned, unsigned, unsigned, unsigned short, unsigned);
extern void func_021BD488(char *, unsigned, unsigned, unsigned, unsigned, unsigned short, unsigned);
extern void func_021BD4DC(void **p);
extern void func_0201EFA4(struct WordSet *, unsigned, unsigned, unsigned, unsigned, unsigned);
void func_021BD704(char *p)
{
    func_021BD4F4((u8 *)p, 2);
    func_021BD440(p, 2, 4, 88, 4, 0x31a0, 1);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00123 *)p)->f40, 0, ((struct Obj25566 *)(*(char * *)&((struct Obj00123 *)p)->f0))->fA, 3, 0, 1);
    func_021BD488(p, 2, 5, 120, 4, 0x31a0, 1);
    func_021BD4DC((void **)(p + 48));
}
