/*
 * function: func_021C0BBC
 * address: 0x021C0BBC
 * packet: pkt_ov217_021C0BBC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: DBC reads only r0/r1; original r2 was an earlier local-store base, not a live reader input. B294 caller observes r0 despite legacy void return.
 * symbols:
 *   d_021C3F80 0x021C3F80 data a4
 *   func_021C0DBC 0x021C0DBC thumb ov217
 *   func_021C0DB4 0x021C0DB4 thumb ov217
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj00791.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Arg { s16 x,y,z; u8 a,b; };
struct Entry { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };
struct Obj;
extern const struct Entry d_021C3F80;
extern u32 func_021C0DBC(void *, u32);
extern u32 func_021C0DB4(void *, u32);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, u32);
void func_021C0BBC(u8 *p)
{
    struct Arg arg;
    u32 a,b,c,d;
    arg.x=d_021C3F80.x; arg.y=d_021C3F80.y; arg.z=d_021C3F80.z;
    arg.a=d_021C3F80.a; arg.b=d_021C3F80.b;
    a=func_021C0DBC(p,d_021C3F80.c);
    b=func_021C0DB4(p,d_021C3F80.d);
    c=func_021C0DB4(p,d_021C3F80.e);
    d=func_021C0DB4(p,d_021C3F80.f);
    *(u32 *)&((struct Obj00791 *)p)->f24=(u32)func_0204B294((void *)a,b,c,d,&arg,d_021C3F80.g,((struct Obj00791 *)p)->f0);
    func_0204B3DC(*(struct Obj * *)&((struct Obj00791 *)p)->f24,1);
}
