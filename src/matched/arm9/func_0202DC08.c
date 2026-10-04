/*
 * function: func_0202DC08
 * address:  0x0202DC08
 * packet:   pkt_0202DAA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT

 */
#include "../include/Obj08809.h"

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj {
    u8  pad00[0xC];
    u8 *f0C;
    u8  pad10[0x20];
};

extern void func_0202E0C8(u8 *e);
extern void func_0202DFD4(u8 *p);
extern void func_020307B0(void *p);

void func_0202DC08(struct Obj *p)
{
    int i;

    for (i = 0; i < ((struct Obj08809 *)p)->f30; i++) {
        func_0202E0C8(p->f0C + i * 0x28);
    }

    func_020307B0(p->f0C);
    func_0202DFD4((u8 *)p + 0x10);
    func_020307B0(p);
}
