/*
 * function: func_021B6EE0
 * address: 0x021B6EE0
 * packet: pkt_ov172_021B6EE0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0203064C 0x0203064C arm
 *   func_0204A380 0x0204A380 arm
 *   func_021BE010 0x021BE010 thumb ov172
 *   func_021BE100 0x021BE100 thumb ov172
 *   func_021B6100 0x021B6100 thumb ov172
 *   func_021B6950 0x021B6950 thumb ov172
 *   func_021B69BC 0x021B69BC thumb ov172
 *   func_021B674C 0x021B674C thumb ov172
 *   func_021B6744 0x021B6744 thumb ov172
 *   func_021B6814 0x021B6814 thumb ov172
 *   func_021B7888 0x021B7888 thumb ov172
 *   func_021B78A0 0x021B78A0 thumb ov172
 *   func_021B75AC 0x021B75AC thumb ov172
 *   d_021C71E0 0x021C71E0 data a4
 */
#include "../include/Obj00439.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0203064C(unsigned int, unsigned int, unsigned int);
extern void *func_0204A380(void *, u32, u32, u32);
extern u32 func_021BE010(void *);
extern int func_021BE100(int);
extern char *func_021B6100(int);
extern void func_021B6950(char *, int);
extern void func_021B69BC(void *p, u32 v);
extern void func_021B674C(char *, int, u16);
extern void func_021B6744(void *p, u32 a, u32 b);
extern void func_021B6814(void *a0);
extern void func_021B7888(void *p, u16 a, u16 b, u16 c, u16 d);
extern void func_021B78A0(void *p, u16 a, u16 b, u16 c, u16 d);
extern void func_021B75AC(char *src, void *p);
extern const char d_021C71E0[];

char *func_021B6EE0(void *a, int b)
{
    char *p;
    u32 r6;
    void *r0;
    char *q;
    u8 i;
    int off;

    p = func_02030734(b, 0xB4, 1, d_021C71E0, 0x67);
    r6 = func_021BE010(a);
    if (func_021BE100(r6) == 1) {
        ((struct Obj00439 *)p)->f0 = 0x6E;
        func_0203064C(1, 0x6E, 0x80000);
        *(char * *)&((struct Obj00439 *)p)->fA4 = func_021B6100(((struct Obj00439 *)p)->f0);
        func_021B6950(*(char * *)&((struct Obj00439 *)p)->fA4, 5);
        func_021B69BC(*(char * *)&((struct Obj00439 *)p)->fA4, 1);
        func_021B674C(*(char * *)&((struct Obj00439 *)p)->fA4, 2, (u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000));
        func_021B6744(*(char * *)&((struct Obj00439 *)p)->fA4, (u32)((void *)func_021B75AC), (u32)a);
        func_021B6814(*(char * *)&((struct Obj00439 *)p)->fA4);
        ((struct Obj00439 *)p)->fA8 = func_02030734((u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x76);
        ((struct Obj00439 *)p)->fAC = func_02030734((u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x77);
        ((struct Obj00439 *)p)->fB0 = func_02030734((u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x78);
        ((struct Obj00439 *)p)->f8 = func_0204A380((void *)r6, 0x19, 0, ((struct Obj00439 *)p)->f0);
        r0 = func_0204A380((void *)r6, 0x1A, 0, ((struct Obj00439 *)p)->f0);
    } else {
        ((struct Obj00439 *)p)->f8 = func_0204A380((void *)r6, 0x19, 0, b);
        r0 = func_0204A380((void *)r6, 0x1A, 0, b);
    }
    ((struct Obj00439 *)p)->fC = r0;
    i = 0;
    ((struct Obj00439 *)p)->f10 = i;
    ((struct Obj00439 *)p)->f2C = i;
    ((struct Obj00439 *)p)->f14 = i;
    ((struct Obj00439 *)p)->f2D = 0xC0;
    ((struct Obj00439 *)p)->f18 = i;
    ((struct Obj00439 *)p)->f1C = i;
    ((struct Obj00439 *)p)->f20 = i;
    ((struct Obj00439 *)p)->f30 = i;
    ((struct Obj00439 *)p)->f24 = i;
    ((struct Obj00439 *)p)->f28 = i;
    ((struct Obj00439 *)p)->f4 = func_02030734((u16)((b & 0x7FFF) | 0x8000), 0x18000, 1, d_021C71E0, 0x8C);
    q = p + 0x34;
    for (i = 0; i < 4; i++) {
        off = i * 0x1C;
        func_021B7888(q + off, 0, 0, 0, 0);
        func_021B78A0(q + off, 0, 0, 0, 0);
        *(int *)(p + off + 0x34) = 0;
        *(int *)(p + off + 0x38) = 1;
        *(int *)(p + off + 0x3C) = 1;
    }
    return p;
}
