/*
 * file:     wipe_sub_p15.c
 * unit:     yes
 * function: func_0202411C, func_02024120, func_02024124, func_02024128, func_02024134, func_02024144, func_02024148, func_0202414C, func_02024150, func_02024158, func_02024160, func_02024168, func_0202419C, func_020241E0
 * address:  0x0202411C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02024570  0x02024570  thumb
 */
#include "../../matched/include/Obj15744.h"

struct Rec8;
struct Data;
struct Obj;
typedef unsigned char u8;

struct Src02024128 {
    unsigned char pad[0x18];
    unsigned short a;
    unsigned short b;
};

typedef unsigned int u32;

typedef struct {unsigned char pad[3];unsigned char flag:1;unsigned char rest:7;} Bits_02024150;

typedef struct {unsigned char pad[3];unsigned char rest:3;unsigned char flag:1;unsigned char last:4;} Bits_02024160;

typedef unsigned short u16;

typedef struct Pair { u16 x,y; } Pair;

typedef struct Input {
    u8 mode; u8 pad01[15]; u16 values10[4]; u16 values18[2];
} Input;

struct Obj {
    u8  f0;
    u8  pad1[0x17];
    u16 f18;    /* 0x18 */
    u16 f1A;    /* 0x1A */
};

struct T {
    u8  pad00[1];
    u8  f01;
    u8  f02;
    u8  pad03[0xd];
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1a;
};

extern void sub_02024570(struct Rec8 *dst, const struct Rec8 *src);
void func_02024134(char *a, void *b);
u32 func_02024144(const u8 *p);
void *func_02024148(char *p);
void *func_0202414C(char *p);
int func_02024150(Bits_02024150 *p);
u32 func_02024158(const u8 *p);
int func_02024160(Bits_02024160 *p);
extern int func_02024534(const struct Data *p1, const struct Data *p2);
extern u32 func_0202419C(struct Obj *p, u16 *q, u32 a);
int func_0202411C(unsigned char *p);
int func_02024120(u8 *p);
unsigned int func_02024124(unsigned short *p);
void func_02024168(const Input *p,u16 *a,u16 *b);




/*
 * Unlabelled Thumb leaf accessor: byte at +1.
 */
int func_0202411C(unsigned char *p)
{
    return p[1];
}




/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
int func_02024120(u8 *p) { return p[2]; }




/*
 * Unlabelled Thumb leaf accessor: halfword at +0x18.
 */
unsigned int func_02024124(unsigned short *p)
{
    return p[12];
}





/*
 * Unlabelled Thumb leaf accessor: copy the halfwords at +0x18 and +0x1a to out. __restrict on out makes both loads precede both stores.
 */
void func_02024128(struct Src02024128 *p, unsigned short *__restrict out)
{
    out[0] = p->a;
    out[1] = p->b;
}


/*
 * Unlabelled Thumb tail-call thunk: sub_02024570(b, a + 0x10), where sub_02024570 copies a halfword pair.
 */
void func_02024134(char *a, void *b)
{
    sub_02024570(b, (const struct Rec8 *)(a + 0x10));
}


u32 func_02024144(const u8 *p) { return p[0]; }


void *func_02024148(char *p){return *(void **)(p+8);}


void *func_0202414C(char *p){return *(void **)(p+12);}


int func_02024150(Bits_02024150 *p){return p->flag;}



/*
 * Unlabelled Thumb leaf in the ARM9 module: extracts bit 2 of the byte at
 * +3. Pairs with func_02024160, which extracts bit 3.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02024158(const u8 *p)
{
    return ((u32)*(const u8 *)&((struct Obj15744 *)p)->f3 << 29) >> 31;
}


int func_02024160(Bits_02024160 *p){return p->flag;}


void func_02024168(const Input *p,u16 *a,u16 *b) {
    Pair v;
    switch(p->mode) {
    case 0: a[0]=p->values18[0]; break;
    case 1:
        v=*(const Pair *)p->values18; *(Pair *)a=v; break;
    case 2:
        b[0]=p->values10[0]; b[1]=p->values10[1];
        v=*(const Pair *)(p->values10+2); *(Pair *)(b+2)=v; break;
    }
}



u32 func_0202419C(struct Obj *p, u16 *q, u32 a)
{
    switch (p->f0) {
    case 0:
        if (*q == p->f18) {
            return 1;
        }
        return 0;
    case 1:
        if (q[0] == p->f18 && q[1] == p->f1A) {
            return 1;
        }
        return 0;
    case 2:
        break;
    }

    return func_02024534((const struct Data *)((u8 *)p + 0x10), (const struct Data *)a);
}


void func_020241E0(struct T *p, u16 *a1, u16 *a2)
{
    int i;

    p->f02 = (func_0202419C((struct Obj *)p, a1, (u32)a2) == 0);
    p->f01 = 0;
    for (i = 0; i < 2; i++) {
        *(u16 *)((char *)p + i * 2 + 0x18) = a1[i];
    }
    p->f10 = a2[0];
    p->f12 = a2[1];
    p->f14 = a2[2];
    p->f16 = a2[3];
}
