/*
 * file:     research_top_p28.c
 * unit:     yes
 * function: func_021BEBA4, func_021BEBC0, func_021BEBE4, func_021BEC00, func_021BEC0C, func_021BEC34, func_021BEC64, func_021BEC84, func_021BED10, func_021BED9C, func_021BEDC4, func_021BEDEC, func_021BEEA4, func_021BEF30
 * address:  0x021BEBA4
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
 *   func_021BF594  0x021BF594  thumb  ov217
 *   func_021BF5BC  0x021BF5BC  thumb  ov217
 *   func_021C09D8 0x021C09D8 thumb ov217
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021BF77C 0x021BF77C thumb ov217
 *   func_021C11A4 0x021C11A4 thumb ov217
 *   func_021BF7E0 0x021BF7E0 thumb ov217
 *   func_021C10E8 0x021C10E8 thumb ov217
 *   func_021C1124 0x021C1124 thumb ov217
 *   func_021C112C 0x021C112C thumb ov217
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021C2654 0x021C2654 thumb ov217
 *   func_021C2664 0x021C2664 thumb ov217
 *   func_021C2674 0x021C2674 thumb ov217
 *   func_021C20D8 0x021C20D8 thumb ov217
 *   func_021BF7F4 0x021BF7F4 thumb ov217
 *   func_021C11DC 0x021C11DC thumb ov217
 *   func_021C11FC 0x021C11FC thumb ov217
 *   func_021C20B4 0x021C20B4 thumb ov217
 *   func_021C20CC 0x021C20CC thumb ov217
 *   func_021C11E8 0x021C11E8 thumb ov217
 *   func_021C1224 0x021C1224 thumb ov217
 *   func_021C272C 0x021C272C thumb ov217
 *   func_021C271C 0x021C271C thumb ov217
 */
#include "../../matched/include/Obj25915.h"
#include "../../matched/include/Obj25916.h"
#include "../../matched/include/Obj25917.h"
#include "../../matched/include/Obj01180.h"
#include "../../matched/include/Obj00021.h"
#include "../../matched/include/Obj25921.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Item { u8 id,pad[3]; u32 value; u8 x,y,z,a,b,c,pad2[2]; };

struct Input { u16 id; u8 x,y,z,pad; u16 a; u32 b; };

extern void func_02025A54(u8 *g, u32 a);
extern u32 func_021BF594();
extern void func_021BF5BC(u8 *a0, u32 a1);
extern void func_021C09D8(u8 *p, u32 i);
extern u32 func_0209C0A4();
extern u8 *func_021BF76C(void *p);
extern u8 *func_021BF77C(void *p);
extern void func_021C11A4(u8 *p, int a1);
extern u32 func_021BF7E0(void *);
extern void func_021C10E8(u8 *p, u8 *tab, int n);
extern void func_021C1124(u8 *p);
extern void func_021C112C(u8 *p);
extern u32 func_021BF810(void *p);
extern unsigned func_021C2654(void *,unsigned,unsigned);
extern unsigned func_021C2664(void *,unsigned,unsigned);
extern unsigned func_021C2674(void *,unsigned,unsigned);
extern unsigned func_021C20D8(unsigned);
extern unsigned func_021BF7F4(void *);
extern u8 func_021C11DC(u8 *p, u8 key);
extern void func_021C11FC(u8 *h, u8 key, s32 *px, s32 *py);
extern void func_021C20B4(int a0, int a1, int a2, int a3, int a4);
extern void func_021C20CC(unsigned);
extern u8 func_021C11E8(u8 *p, u8 n);
extern void func_021C1224(u8 *h, u8 n, s32 *px, s32 *py);
extern unsigned func_021C272C(unsigned,unsigned);
extern unsigned func_021C271C(unsigned,unsigned,unsigned);
u32 func_021BEBA4(u32 a0);
u32 func_021BEBC0(u32 a0);
u32 func_021BEBE4(u32 a0);
void func_021BEC00(u32 *p);
void func_021BEC0C(void *p);
void func_021BEC34(u32 a0);
void func_021BEC64(void *p);
void func_021BEC84(u8 *p,int mode);
void func_021BED10(u8 *p, u32 mode);
void func_021BED9C(char *p);
void func_021BEDC4(char *p);
void func_021BEDEC(char *p);
void func_021BEEA4(char *p);
void func_021BEF30(char *p);

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BEBA4(u32 a0)
{
    func_02025A54((u8 *)(((struct Obj25915 *)(((u8*)a0)))->f3AC), 0);
    return func_021BF594(a0, 4);
}

u32 func_021BEBC0(u32 a0)
{
    func_02025A54((u8 *)(((struct Obj25916 *)(((u8*)a0)))->f3AC), 1);
    func_021BF5BC((u8 *)a0, 5);
    return func_021BF594(a0, 6);
}

u32 func_021BEBE4(u32 a0)
{
    func_02025A54((u8 *)(((struct Obj25917 *)(((u8*)a0)))->f3AC), 1);
    return func_021BF594(a0, 5);
}

void func_021BEC00(u32 *p)
{
    func_021C09D8((u8 *)(*p), 0);
}


/*
 * Swap the u32 pairs at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BEC0C(void *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        u32 t = *(u32 *)((char *)p + i * 4 + 0x2bc);
        *(u32 *)((char *)p + i * 4 + 0x2bc) = *(u32 *)((char *)p + i * 4 + 0x2c4);
        *(u32 *)((char *)p + i * 4 + 0x2c4) = t;
    }
}

void func_021BEC34(u32 a0)
{
    u32 v1 = func_0209C0A4(((struct Obj01180 *)(((u8*)a0)))->f9 + 62, 3);
    u32 v2 = func_0209C0A4(((struct Obj01180 *)(((u8*)a0)))->fA + 62, 3);
    ((struct Obj01180 *)(((u8*)a0)))->fB = func_0209C0A4(((struct Obj01180 *)(((u8*)a0)))->f8 + 62, 3);
    ((struct Obj01180 *)(((u8*)a0)))->fC = v1;
    ((struct Obj01180 *)(((u8*)a0)))->fD = v2;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BEC64(void *p)
{
    func_021C11A4(func_021BF76C(p), 0xFFFFE000);
    func_021C11A4(func_021BF77C(p), 0);
}

void func_021BEC84(u8 *p,int mode)
{
    struct Item items[17];
    struct Input *base;
    u32 object;
    int count;
    int i;
    object=*(u32 *)(p+700+mode*4);
    count=func_021BF7E0(p);
    base=(struct Input *)(p+60+p[696]*212);
    for(i=0;i<count;i++) {
        struct Input *q=(struct Input *)((u8 *)base+8+i*12);
        struct Item *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        func_021BEC34((u32)t);
        switch(mode) { case 0: t->value=q->a; break; case 1: t->value=q->b; break; }
    }
    func_021C10E8((u8 *)object,(u8 *)items,count);
}

void func_021BED10(u8 *p, u32 mode)
{
    struct Item items[17];
    struct Input *base;
    u32 object;
    int count;
    int i;
    object=*(u32 *)(p+708+mode*4);
    count=func_021BF7E0(p);
    base=(struct Input *)(p+60+p[696]*212);
    for(i=0;i<count;i++) {
        struct Input *q=(struct Input *)((u8 *)base+8+i*12);
        struct Item *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        func_021BEC34((u32)t);
        switch(mode) { case 0: t->value=q->a; break; case 1: t->value=q->b; break; }
    }
    func_021C10E8((u8 *)object,(u8 *)items,count);
}

void func_021BED9C(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_021C1124(*(u8 **)(p + i * 4 + 0x2bc));
        func_021C1124(*(u8 **)(p + i * 4 + 0x2c4));
    }
}

void func_021BEDC4(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_021C112C(*(u8 **)(p + i * 4 + 0x2bc));
        func_021C112C(*(u8 **)(p + i * 4 + 0x2c4));
    }
}

void func_021BEDEC(char *p)
{
    unsigned r,g,b;
    void *color;
    if (((struct Obj00021 *)p)->f3C8==0 || ((struct Obj00021 *)p)->f3D0==1 || func_021BF810(p)==0) return;
    color=p+56;
    r=func_021C2654(color,((struct Obj00021 *)p)->f2B8,((struct Obj00021 *)p)->f2B9);
    g=func_021C2664(color,((struct Obj00021 *)p)->f2B8,((struct Obj00021 *)p)->f2B9);
    b=func_021C2674(color,((struct Obj00021 *)p)->f2B8,((struct Obj00021 *)p)->f2B9);
    *(volatile unsigned *)0x040004a4=0x001f00c0;
    *(volatile unsigned *)0x04000500=1;
    *(volatile unsigned *)0x04000480=(u16)(r | (g<<5) | (b<<10));
    *(volatile unsigned *)0x0400048c=0x096cfc68;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x0a7afc68;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x0a7afda1;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x096cfda1;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x04000504=0;
}

/*
 * C11DC forwards r0/r1 through C1AC0; caller's narrowed index remains in its prototype.
 * C20CC overwrites incoming r1 with 1 before forwarding to C218C; legacy unused trailing parameter omitted.
 */
void func_021BEEA4(char *p)
{
    u8 *object;
    unsigned index;
    s32 x,y;
    func_021C20D8(*(unsigned *)&((struct Obj00021 *)p)->f2D0);
    if (((struct Obj00021 *)p)->f3D0==1) return;
    if (((struct Obj00021 *)p)->f3C8==0) return;
    if (func_021BF810(p)==0) return;
    object=func_021BF76C(p);
    index=func_021BF7F4(p);
    if (func_021C11DC(object,index)==0) return;
    if (((struct Obj00021 *)p)->f3C8!=0) {
        object=func_021BF76C(p);
        index=func_021BF7F4(p);
        func_021C11FC(object,index,&x,&y);

        func_021C20B4(*(unsigned *)&((struct Obj00021 *)p)->f2D0,104,34,x,y);
        func_021C20CC(*(unsigned *)&((struct Obj00021 *)p)->f2D0);
    }
}

/*
 * lever: unsigned output counter i; initialize before decrementing the signed reverse counter.
 * C11E8 forwards original r0/r1 to C1AB4's two-input record lookup.
 * C271C forwards original r1/r2 to C288C's two-field setter.
 */
void func_021BEF30(char *p)
{
    int n,id;
    unsigned i;
    u8 *object;
    s32 x,y;
    unsigned slot;
    n=func_021BF7E0(p);
    object=func_021BF76C(p);
    i=0;
    n--;
    for (;n>=0;n--) {
        id=func_021C11E8(object,n);
        func_021C1224(object,n,&x,&y);

        if (id>=10) {
            slot=*(unsigned *)(p+i*4+0x2d4);
            func_021C272C(slot,id);
            func_021C271C(slot,x,y);
            i++;
        }
    }
    ((struct Obj25921 *)p)->f2FC=i;
}
