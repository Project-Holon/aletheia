/*
 * file:     research_top_p15.c
 * unit:     yes
 * function: func_021BCFB4, func_021BCFD0, func_021BD05C, func_021BD078
 * address:  0x021BCFB4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C320C 0x021C320C data a4
 *   func_021BC714 0x021BC714 thumb ov217
 *   func_021BC708 0x021BC708 thumb ov217
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4  0x0204B3B4  arm
 */
#include "../../matched/include/Obj14733.h"
#include "../../matched/include/Obj25882.h"

struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short s16;

struct Arg { s16 x,y,z; u8 a,b; };

struct Entry { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };

extern u32 func_021BC714(void *,u32);
extern u32 func_021BC708(void *,u32);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B3B4(struct Obj *p);
void func_021BCFB4(void *p);
void func_021BCFD0(u8 *p);
void func_021BD05C(int *p);
void func_021BD078(void *p);
extern const struct Entry d_021C320C[];


void func_021BCFB4(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x120) = 0;
}

/*
 * Lever: const source table and destination base without the field offset.
 */
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


void func_021BD05C(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204B3B4((struct Obj *)p[i + 0x48]);
}


void func_021BD078(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x140) = 0;
}
