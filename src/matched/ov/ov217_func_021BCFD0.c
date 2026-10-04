/*
 * function: func_021BCFD0
 * address: 0x021BCFD0
 * packet: pkt_ov217_021BCFD0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: const source table and destination base without the field offset.
 * symbols:
 *   d_021C320C 0x021C320C data a4
 *   func_021BC714 0x021BC714 thumb ov217
 *   func_021BC708 0x021BC708 thumb ov217
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj14733.h"
#include "../include/Obj25882.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Arg { s16 x,y,z; u8 a,b; };
struct Entry { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };
extern const struct Entry d_021C320C[];
extern u32 func_021BC714(void *,u32);
extern u32 func_021BC708(void *,u32);
struct Obj;
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B3DC(struct Obj *,unsigned int);
void func_021BCFD0(u8 *p)
{
    struct Arg arg;
    const struct Entry *q;
    u8 *dest;
    int i;
    u32 a,b,c,d;
    for (i=0;i<3;i++) {
        q=&d_021C320C[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=func_021BC714(p,q->c);
        b=func_021BC708(p,q->d);
        c=func_021BC708(p,q->e);
        d=func_021BC708(p,q->f);
        dest=p+i*4;
        ((struct Obj14733 *)dest)->f120=(u32)func_0204B294((void *)a,b,c,d,&arg,q->g,((struct Obj25882 *)p)->f8);
        func_0204B3DC((struct Obj *)((struct Obj14733 *)dest)->f120,0);
    }
}
