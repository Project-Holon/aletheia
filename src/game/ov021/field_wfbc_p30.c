/*
 * file:     field_wfbc_p30.c
 * unit:     yes
 * function: func_021966B0, func_021966F0, func_02196768, func_021967BC, func_02196804
 * address:  0x021966B0
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
 *   func_020490F4  0x020490F4  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_02040588  0x02040588  arm
 *   func_0219707C  0x0219707C  thumb  ov021
 *   func_0219630C  0x0219630C  thumb  ov021
 *   func_02051B84  0x02051B84  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_0219649C  0x0219649C  thumb  ov021
 *   func_02196974  0x02196974  thumb  ov021
 *   func_02196A4C  0x02196A4C  thumb  ov021
 *   d_021D4070     0x021D4070  data  a4
 *   d_021D4014     0x021D4014  data  a4
 *   d_021D4024     0x021D4024  data  a4
 *   d_021D404C     0x021D404C  data  a4
 *   d_021DDB84     0x021DDB84  data  a4
 *   func_0201DD68  0x0201DD68  thumb
 *   func_02196454  0x02196454  thumb  ov021
 *   func_02040DA8  0x02040DA8  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045808  0x02045808  arm
 *   func_020221A4  0x020221A4  thumb
 *   func_02155A90  0x02155A90  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_02026400  0x02026400  thumb
 */
#include "../../matched/include/Obj00093.h"
#include "../../matched/include/Obj03578.h"
#include "../../matched/include/Obj12631.h"
#include "../../matched/include/Obj05988.h"

struct Cb;
struct Rec;
struct U16Vec;
struct Ctx;
struct Comm;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u32 w[4]; } Blk;

extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *h);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0219707C(u8 *p);
extern void func_0219630C(u32 a, void *b, void *c, void *d, void *e, void *f);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_02196034(void *p, void *fn, u32 n);
extern void func_0219649C(void *a, int b, struct Cb *c);
extern int func_02196974(u32 s, u8 *p);
extern void func_02196A4C(u8 *a);
extern void func_0201DD68(void);
extern void func_02196454(u8 *p);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_0203FB44(u32 a, u32 b, u32 c);
extern void func_020403F4(u32 a);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020221A4();
extern u32 func_02155A90(u8 *p);
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02026454(void *obj);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_02026400(struct Comm *p);
void func_021966B0(u8 *p, u32 a);
void func_021966F0(u8 *p);
void func_02196768(u8 *p);
void func_021967BC(u8 *p);
void func_02196804(u8 *p);
extern Blk d_021D4070;
extern u8 d_021D4014[];
extern u8 d_021D4024[];
extern u8 d_021D404C[];
extern u8 d_021DDB84[];


void func_021966B0(u8 *p, u32 a)
{
    void *h;

    h = func_020490F4(0x1D, ((struct Obj00093 *)p)->f10);
    func_02049990(h, a, 6, 0, (u16)((struct Obj00093 *)p)->f40, 0, 0, ((struct Obj00093 *)p)->f10);
    func_02049238(h);
    func_02040588(6, 1);
}


void func_021966F0(u8 *p)
{
    Blk t = d_021D4070;

    func_021966B0(p, 0xB);
    func_0219707C(p);
    func_0219630C(4, &t, p, d_021DDB84, d_021D4014, d_021D4024);
    *(u32 *)&((struct Obj00093 *)p)->f24 = (u32)func_02051B84(d_021D404C, (int)((void *)func_0219649C), (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = (void *)func_02196974;
    func_02196034(p, (void *)func_02196A4C, 0x340);
}


void func_02196768(u8 *p)
{
    u32 v;

    func_0201DD68();
    func_02196454(p);
    func_02040DA8(5, 1, 0);
    v = ((struct Obj03578 *)p)->f3C;
    func_0203FB44(5, (u16)v, (u16)(v >> 16));
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04((struct Rec *)(((struct Obj03578 *)p)->f28));
    func_0201D83C((void *)(((struct Obj03578 *)p)->f2C));
    func_02045808((struct U16Vec *)(((struct Obj03578 *)p)->f38));
    func_02040588(5, 0);
}


void func_021967BC(u8 *p)
{
    if (func_020221A4()) {
        if (((struct Obj12631 *)p)->f8 != 0xC) {
            if (func_02026454((void *)func_02012138((const struct Ctx *)
                    func_02155A90((u8 *)((struct Obj12631 *)p)->f2E4))) == 0)
                func_02196034(p, 0, 0x361);
        } else {
            func_02196034(p, 0, 0x365);
        }
    }
}


void func_02196804(u8 *p)
{
    p[0x306] = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, ((struct Obj05988 *)p)->f10);
    if (((struct Obj05988 *)p)->f8 != 0xC) {
        if (func_02026454((void *)func_02012138((const struct Ctx *)func_02155A90((u8 *)((struct Obj05988 *)p)->f2E4))) != 0) {
            func_02026400((struct Comm *)func_02012138((const struct Ctx *)func_02155A90((u8 *)((struct Obj05988 *)p)->f2E4)));
        }
    }
    func_02196034(p, (void *)func_021967BC, 0x37C);
}
