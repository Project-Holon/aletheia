/*
 * file:     bsubway_scr_p09.c
 * unit:     yes
 * function: func_021C8E68, func_021C8E8C, func_021C8EA0, func_021C8F38
 * address:  0x021C8E68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021DE544  0x021DE544  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   d_021DAB6C     0x021DAB6C  data  a4
 *   d_021DAB7C     0x021DAB7C  data  a4
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 */
#include "../../matched/include/Obj09714.h"

struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Tagged;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;

typedef signed int     s32;

typedef struct A4 { u32 v[4]; } A4;

typedef struct A5 { u32 v[5]; } A5;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
u32 *func_021C8E68(u32 a, u32 heap);
void func_021C8E8C(u32 a, u8 *p);
void func_021C8EA0(u32 *p);
void func_021C8F38(u8 *p);
extern char d_021DE544[];
extern const A4 d_021DAB6C;
extern const A5 d_021DAB7C;

u32 *func_021C8E68(u32 a, u32 heap)
{
    u32 *q = func_02030734(heap, 0x34, 1, d_021DE544, 0xa9);
    q[0] = a;
    func_021C8EA0(q);
    return q;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C8E8C(u32 a, u8 *p)
{
    func_021C8F38(p);
    func_020307B0(p);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C8EA0(u32 *p)
{
    A4 a;
    A5 b;
    u32 r6;
    u32 i;

    a = d_021DAB6C;
    b = d_021DAB7C;
    r6 = func_021ABE24((u8 *)p[0]);
    for (i = 0; i < 4; i++) {
        p[1 + i] = (u32)func_02046E24(r6, a.v[i]);
        func_02046FF8((int *)p[1 + i]);
    }
    for (i = 0; i < 5; i++) {
        p[5 + i] = (u32)func_02046E24(r6, b.v[i]);
    }
    p[11] = (u32)func_02047400((void *)p[1], 0, (void *)p[1]);
    p[10] = (u32)func_02047564((struct G3dOwner *)p[11], (const struct G3dOwner *)p[5], 0);
    p[12] = (u32)func_0204767C(p[11], p + 10, 1);
    func_020477A4((struct G3dSys *)p[12], 0);
}


void func_021C8F38(u8 *p)
{
    u32 i;

    func_0204762C((struct Rec *)(((struct Obj09714 *)p)->f28));
    func_02047738((struct Rec *)(((struct Obj09714 *)p)->f30));
    func_02047504((struct Rec *)(((struct Obj09714 *)p)->f2C));
    for (i = 0; i < 4; i++) {
        func_020470D0((u32 *)(*(u32 *)(p + i * 4 + 4)));
        func_02046EFC((struct Tagged *)(*(u32 *)(p + i * 4 + 4)));
    }
    for (i = 0; i < 5; i++) {
        func_02046EFC((struct Tagged *)(*(u32 *)(p + i * 4 + 0x14)));
    }
}
