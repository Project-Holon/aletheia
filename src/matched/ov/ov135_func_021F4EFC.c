/*
 * function: func_021F4EFC
 * address:  0x021F4EFC
 * packet:   pkt_021F4EFC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFCD4  0x021FFCD4  thumb
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 */
#include "../include/Obj00996.h"

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021FFCD4(u8 *p);
extern void func_0204ADA4(u32 v);
extern void func_0204A8D4(u32 v);
extern void func_0204AFD8(u32 v);
struct Bank;
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);

void func_021F4EFC(u8 *p)
{
    func_021FFCD4(p);
    func_0204ADA4(((struct Obj00996 *)p)->fBE0);
    func_0204A8D4(((struct Obj00996 *)p)->fBDC);
    func_0204AFD8(((struct Obj00996 *)p)->fBE4);
    func_0204ADA4(((struct Obj00996 *)p)->fBD4);
    func_0204A8D4(((struct Obj00996 *)p)->fBD0);
    func_0204AFD8(((struct Obj00996 *)p)->fBD8);
    func_0204ADA4(((struct Obj00996 *)p)->fBC8);
    func_0204A8D4(((struct Obj00996 *)p)->fBC4);
    func_0204AFD8(((struct Obj00996 *)p)->fBCC);
    func_0204A8D4(((struct Obj00996 *)p)->fBE8);
    func_0204AFD8(((struct Obj00996 *)p)->fBF0);
    func_0204B1CC((struct Bank *)(((struct Obj00996 *)p)->fBC0));
    ((struct Obj00996 *)p)->fBC0 = 0;
    func_0204A5AC();
}
