/*
 * file:     unit_021BFFC8_p03.c
 * unit:     yes
 * function: func_021C03D0, func_021C03EC, func_021C0408
 * address:  0x021C03D0
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
 *   func_0204B1CC  0x0204B1CC  arm
 *   d_021C37FC 0x021C37FC data a4
 *   func_021BF9FC 0x021BF9FC thumb ov217
 *   func_021BF9F0 0x021BF9F0 thumb ov217
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../../matched/include/Obj14752.h"
#include "../../matched/include/Obj25962.h"

struct Bank;
struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef signed short s16;

struct Arg { s16 x,y,z; u8 a,b; };

struct Entry { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };

extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_021BF9FC(void *,u32);
extern u32 func_021BF9F0(void *,u32);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *,u32);
void func_021C03D0(int *p);
void func_021C03EC(void *p);
void func_021C0408(u8 *p);
extern const struct Entry d_021C37FC[];


/*
 * Addresses are Black-image addresses.
 */
void func_021C03D0(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_0204B1CC((struct Bank *)p[i + 0xE1]);
}


/*
 * Clear four u32 slots at +0x394.
 *
 * Addresses are Black-image addresses.
 */
void func_021C03EC(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x394) = 0;
}

/*
 * prototype: 0204B294 result observed in r0 despite legacy matched void return.
 */
void func_021C0408(u8 *p)
{
    struct Arg arg;
    const struct Entry *q;
    u8 *dest;
    int i;
    u32 a,b,c,d;
    for(i=0;i<4;i++) {
        q=&d_021C37FC[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=func_021BF9FC(p,q->c);
        b=func_021BF9F0(p,q->d);
        c=func_021BF9F0(p,q->e);
        d=func_021BF9F0(p,q->f);
        dest=p+i*4;
        *(u32 *)&((struct Obj14752 *)dest)->f394=(u32)func_0204B294((void *)a,b,c,d,&arg,q->g,((struct Obj25962 *)p)->f4);
        func_0204B3DC(*(struct Obj * *)&((struct Obj14752 *)dest)->f394,0);
    }
}
