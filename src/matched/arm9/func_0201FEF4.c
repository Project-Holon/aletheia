/*
 * function: func_0201FEF4
 * address:  0x0201FEF4
 * packet:   pkt_0201F93C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj02993.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020307B0(void *ptr);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_0201D83C(void *ptr);
extern void func_0201F868(void *p);
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void func_0201F9E8(u8 *o, u8 *out);

void func_0201FEF4(u8 *o)
{
    func_0201C6EC((struct PrintSys *)(((struct Obj02993 *)o)->f18));
    func_0201C4C0((struct PrintSys *)(((struct Obj02993 *)o)->f18));
    func_020307B0(((struct Obj02993 *)o)->f14);
    func_0201F7A8(((struct Obj02993 *)o)->f4, 0);
    func_0201D83C(((struct Obj02993 *)o)->f1C);
    func_0201F868(((struct Obj02993 *)o)->f0);
    func_020452E8(((struct Obj02993 *)o)->f4);
    func_0201F9E8(o, 0);
}
