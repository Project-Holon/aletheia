/*
 * file:     unit_02192CF0_p01.c
 * unit:     yes
 * function: func_02192CF0, func_02192E0C, func_02192EB8, func_02192EE0, func_02192F74, func_02192FA4, func_02192FEC
 * address:  0x02192CF0
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
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02194670  0x02194670  thumb  ov021
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   d_021D3ED8     0x021D3ED8  data  a4
 *   d_021D3EF8     0x021D3EF8  data  a4
 *   d_021D3EB8     0x021D3EB8  data  a4
 *   func_02005C8C  0x02005C8C  thumb  arm9
 *   func_02030EAC  0x02030EAC  arm  arm9
 *   func_02194704  0x02194704  thumb  ov021
 *   func_0204047C  0x0204047C  arm
 *   d_021D3F18     0x021D3F18  data  a4
 *   func_020403F4  0x020403F4  arm  arm9
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_021929E8  0x021929E8  thumb  ov021
 */
#include "../../matched/include/Obj01031.h"
#include "../../matched/include/Obj01654.h"
#include "../../matched/include/Obj12614.h"

struct BgTemplate;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int w[8]; } B32;

typedef struct { u16 a; int b; int c; u16 d; int e; u8 f; u8 g; } Req;

typedef unsigned int   u32;

typedef short          s16;

typedef struct W {
    u16 f00;
    u16 f02;
    u16 f04;
    u8  pad[0x16A];
    u8  f170;
} W;

extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void *func_02194670(u16 *a);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_02005C8C(void);
extern void func_02194704(char *a0);
extern void func_02030EAC(struct Node *n);
extern void func_0204047C(int idx, unsigned short val);
extern void func_020403F4(u32 a);
extern void func_02049B40(int, int, int, int, int, int);
extern void func_0201F5BC(int, int, int, int, int);
extern void func_021929E8(u32 heap);
void func_02192CF0(char *p, int flag);
void func_02192E0C(u32 *p);
void func_02192EB8(u32 a, u8 *b);
void func_02192EE0(int a);
void func_02192F74(W *w);
void func_02192FA4(int a, int b);
void func_02192FEC(int a, int b, int c);
extern const B32 d_021D3ED8;
extern const B32 d_021D3EF8;
extern const B32 d_021D3EB8;
extern const B32 d_021D3F18;


/*
 * Two-layer twin of func_02192E0C.
 *
 * Addresses are Black-image addresses.
 */
void func_02192CF0(char *p, int flag)
{
    B32 tmp1;
    B32 tmp2;
    Req r;

    ((struct Obj01031 *)p)->f2 = 1;
    tmp1 = d_021D3ED8;
    func_0203FCA0(((struct Obj01031 *)p)->f2 & 0xff, (const struct BgTemplate *)(&tmp1), 0);
    ((struct Obj01031 *)p)->f4 = 2;
    tmp2 = d_021D3EF8;
    func_0203FCA0(((struct Obj01031 *)p)->f4 & 0xff, (const struct BgTemplate *)(&tmp2), 0);
    func_02040C14(((struct Obj01031 *)p)->f2, 0, 1, 0);
    func_02041300(((struct Obj01031 *)p)->f2 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(((struct Obj01031 *)p)->f4 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(((struct Obj01031 *)p)->f2 & 0xff);
    func_020409B4(((struct Obj01031 *)p)->f4 & 0xff);
    if (flag)
        func_02192FA4(((struct Obj01031 *)p)->f2, ((struct Obj01031 *)p)->f0);
    if (((struct Obj01031 *)p)->f168 != 0) {
        r.a = ((struct Obj01031 *)p)->f0;
        r.b = ((struct Obj01031 *)p)->f168;
        r.c = ((struct Obj01031 *)p)->f8;
        r.d = 0xb;
        r.e = 1;
        r.f = 0xc;
        r.g = 0xb;
        ((struct Obj01031 *)p)->f15C = (int)func_02194670((u16 *)(&r));
    }
    func_0207D63C(0x04000050, 4, 0x1b, 0x10, 4);
    func_02040588(((struct Obj01031 *)p)->f2 & 0xff, 1);
    func_02040588(((struct Obj01031 *)p)->f4 & 0xff, 1);
    ((struct Obj01031 *)p)->f6 = 0xe;
}


void func_02192E0C(u32 *p)
{
    B32 tmp;
    Req r;

    ((struct Obj01654 *)p)->f2 = 1;
    tmp = d_021D3EB8;
    func_0203FCA0(((struct Obj01654 *)p)->f2 & 0xff, (const struct BgTemplate *)(&tmp), 0);
    func_02040C14(((struct Obj01654 *)p)->f2, 0, 1, 0);
    func_02041300(((struct Obj01654 *)p)->f2 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(((struct Obj01654 *)p)->f2 & 0xff);
    func_02192FA4(((struct Obj01654 *)p)->f2, ((struct Obj01654 *)p)->f0);
    if (((struct Obj01654 *)p)->f168 != 0) {
        r.a = ((struct Obj01654 *)p)->f0;
        r.b = ((struct Obj01654 *)p)->f168;
        r.c = ((struct Obj01654 *)p)->f8;
        r.d = 0xb;
        r.e = 1;
        r.f = 0xc;
        r.g = 0xb;
        ((struct Obj01654 *)p)->f15C = (int)func_02194670((u16 *)(&r));
    }
    func_02040588(((struct Obj01654 *)p)->f2 & 0xff, 1);
    ((struct Obj01654 *)p)->f6 = 0xe;
}


/*
 * Addresses are Black-image addresses.
 */
void func_02192EB8(u32 a, u8 *b)
{
    if (func_02005C8C() == 0) {
        func_02194704((char *)(((struct Obj12614 *)b)->f15C));
        ((struct Obj12614 *)b)->f16C = 0;
        func_02030EAC((struct Node *)a);
    }
}


void func_02192EE0(int a)
{
    B32 tmp;

    func_02040588(2, 0);
    if (a == 1) {
        tmp = d_021D3F18;
        func_0203FCA0(2, (const struct BgTemplate *)(&tmp), 0);
    } else {
        *(volatile u16 *)0x0400000C = (*(volatile u16 *)0x0400000C & 0x43) | 0x1F10;
    }
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(2);
    func_0207D63C(0x04000050, 4, 0x1b, 0x10, 4);
    func_0204047C(2, 2);
    func_02040588(2, 1);
}


void func_02192F74(W *w)
{
    if (w->f170 != 0) {
        w->f170 = 0;
        if (w->f04 == 0xFF) {
            func_020403F4(2);
            func_02192EE0(1);
            w->f04 = 2;
        } else {
            func_02192EE0(0);
        }
    }
}


void func_02192FA4(int a, int b)
{
    func_02049B40(0x17, 5, 0, 0x160, 0x20, b);
    func_02049B40(0x17, 7, 0, 0x1c0, 0x20, b);
    func_0201F5BC(a & 0xff, 1, 0xd, 0, b);
    func_021929E8(b);
}


void func_02192FEC(int a, int b, int c)
{
    if (c == 0) {
        func_02049B40(0x17, 5, 0, 0x160, 0x20, b);
        func_02049B40(0x17, 7, 0, 0x1c0, 0x20, b);
    } else if (c == 1) {
        func_0201F5BC(a & 0xff, 1, 0xd, 0, b);
    } else if (c == 2) {
        func_021929E8(b);
    }
}
