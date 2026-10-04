/*
 * function: func_02027B30
 * address:  0x02027B30
 * packet:   pkt_02027A24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj11289.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

struct S;

struct Cfg;
struct Descriptor;
extern void func_02045798(struct Descriptor *p, u8 v);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void func_02027B30(u32 a0, struct S *s, int mode)
{
    if (mode == 1) {
        func_02045798((struct Descriptor *)a0, (u8)((struct Obj11289 *)s)->f2);
    } else if (mode == 0) {
        func_02045798((struct Descriptor *)a0, (u8)(((struct Obj11289 *)s)->f2 + 1));
    }
    func_02045374((struct Cfg *)a0);
    func_02041B6C(func_02045730((struct Descriptor *)a0));
}
