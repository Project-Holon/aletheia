/*
 * function: func_021BD628
 * address: 0x021BD628
 * packet: pkt_ov209_021BD628
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200CA70 0x0200CA70 thumb
 *   func_0200D0CC 0x0200D0CC thumb
 *   func_0200CF28 0x0200CF28 thumb
 *   func_0200D0F8 0x0200D0F8 thumb
 *   func_0200CF54 0x0200CF54 thumb
 *   func_021BD4F4 0x021BD4F4 thumb ov209
 *   func_021BD440 0x021BD440 thumb ov209
 *   func_021BD488 0x021BD488 thumb ov209
 *   func_021BD4DC 0x021BD4DC thumb ov209
 *   func_0201EFA4 0x0201EFA4 thumb
 */
#include "../include/Obj00123.h"
#include "../include/Obj25561.h"
#include "../include/Obj25562.h"
#include "../include/Obj25563.h"
#include "../include/Obj25564.h"
#include "../include/Obj25565.h"
typedef unsigned short u16;
typedef struct WordSet WordSet;
typedef unsigned int   u32;
struct Blk37;
extern u32 func_0200CA70(struct Blk37 *p);
extern u16 func_0200D0CC(struct Blk37 *p);
extern u16 func_0200CF28(struct Blk37 *p);
extern u16 func_0200D0F8(struct Blk37 *p, u32 heap);
extern u16 func_0200CF54(struct Blk37 *p, u32 heap);
extern void func_021BD4F4(char *, unsigned);
extern void func_021BD440(char *, unsigned, unsigned, unsigned, unsigned, u16, unsigned);
extern void func_021BD488(char *, unsigned, unsigned, unsigned, unsigned, u16, unsigned);
extern void func_021BD4DC(char *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void func_021BD628(char *p)
{
    unsigned a, b;
    if (func_0200CA70(((struct Obj25561 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4) == 1) {
        a = func_0200D0CC(((struct Obj25562 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4);
        b = func_0200CF28(((struct Obj25563 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4);
    } else {
        a = func_0200D0F8(((struct Obj25564 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4, 0x806b);
        b = func_0200CF54(((struct Obj25565 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4, 0x806b);
    }
    func_021BD4F4(p, 1);
    func_021BD4F4(p, 2);
    func_021BD440(p, 1, 2, 0x48, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet * *)&((struct Obj00123 *)p)->f40, 0, a, 3, 0, 1);
    func_021BD488(p, 1, 5, 0x68, 4, 0x31a0, 1);
    func_021BD440(p, 2, 3, 0x58, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet * *)&((struct Obj00123 *)p)->f40, 0, b, 3, 0, 1);
    func_021BD488(p, 2, 5, 0x78, 4, 0x31a0, 1);
    func_021BD4DC(p + 0x28);
    func_021BD4DC(p + 0x30);
}
