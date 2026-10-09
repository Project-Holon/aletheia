/*
 * file:     pokemontrade_demo_up_p02.c
 * unit:     yes
 * function: func_021D4C20, func_021D4C40, func_021D54F0, func_021D55AC, func_021D5628, func_021D5694, func_021D56E0, func_021D56E4, func_021D56F0, func_021D56FC, func_021D572C
 * address:  0x021D4C20
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_021E3208  0x021E3208  thumb  ov119
 *   func_021D4480  0x021D4480  thumb  ov118
 *   func_021D434C  0x021D434C  thumb  ov118
 *   func_021D43C8  0x021D43C8  thumb  ov118
 *   func_021D49C4  0x021D49C4  thumb  ov118
 *   func_021D49F4  0x021D49F4  thumb  ov118
 *   func_021D4A48  0x021D4A48  thumb  ov118
 *   func_02015F50  0x02015F50  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_02015EB0  0x02015EB0  thumb
 *   func_02015E4C  0x02015E4C  thumb
 *   func_02015C30  0x02015C30  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015C94  0x02015C94  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   func_020515CC  0x020515CC  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFB84  0x021DFB84  thumb  ov119
 *   func_021DFA60  0x021DFA60  thumb  ov119
 *   func_021DFB4C  0x021DFB4C  thumb  ov119
 *   func_021D4A34  0x021D4A34  thumb  ov118
 *   func_021D4A94  0x021D4A94  thumb  ov118
 *   _dflt          0x0209B750  arm
 *   _dmul          0x0209B2E8  arm
 *   _dfix          0x0209C508  arm
 *   func_02015E04  0x02015E04  thumb
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_021E3034  0x021E3034  thumb  ov119
 *   func_021E2F2C  0x021E2F2C  thumb  ov119
 *   func_021DFDA0  0x021DFDA0  thumb  ov119
 */
#include "../../matched/include/Obj22664.h"
#include "../../matched/include/Obj03254.h"
#include "../../matched/include/Obj22665.h"
#include "../../matched/include/Obj22666.h"
#include "../../matched/include/Obj22667.h"
#include "../../matched/include/Obj22668.h"
#include "../../matched/include/Obj03769.h"
#include "../../matched/include/Obj22669.h"
#include "../../matched/include/Obj01724.h"
#include "../../matched/include/Obj22670.h"
#include "../../matched/include/Obj22671.h"
#include "../../matched/include/Obj22672.h"
#include "../../matched/include/Obj22673.h"
#include "../../matched/include/Obj22674.h"
#include "../../matched/include/Obj10351.h"

#define FRAME (*(s32_021D4C40 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define WORK (*(u32 **)(p + 0xc))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define SLOT1 (*(u32 *)(p + 0x860))
struct Personal;
struct Sub0200852CObj;
struct Obj;
struct Actor;
typedef unsigned int u32;

typedef unsigned char u8;

typedef int s32_021D4C20;

typedef unsigned short u16;

typedef int s32_021D4C40;

typedef struct {
    s32_021D4C40 x, y, z;
} Vec;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef signed int     s32_021D5628;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_021D8E84(void *p, int next);
extern void func_021E3230(void *p);
extern void func_021E3208(void *p, int a);
extern int func_021D4480(int);
extern void func_021D434C(void *);
extern void func_021D43C8(void *);
extern void func_021D49C4(void *);
extern void func_021D49F4(void *obj, int on);
extern void func_021D4A48(void *, int);
extern void func_02015F50(u32, u32, u32, s32_021D4C40, u32);
extern void func_02015EA0(u32);
extern void func_02015EB0(u32);
extern void func_02015E4C(void *p);
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(u32, Vec *);
extern void func_02015C94(u32, Vec *);
extern void func_02015CAC(u32, void *);
extern int func_020515CC(u32, int, void *, void *);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020307B0(u32);
extern void func_021E71F0(void *, int);
extern void func_021E7208(void *, int);
extern void func_021DFD24(u32);
extern u32 func_021DFB84(u32, int, Vec *, u32);
extern void func_021DFA60(u32 key);
extern void func_021DFB4C(u32, int, void *);
extern void func_021D4A34(void *p);
extern void func_021D4A94(void *p);
extern void func_021DFC68(u32, void *);
extern int func_021D8AA8(void *p);
extern void *func_021D8FA4(void *p, int which);
extern u32 func_02017E1C(void *mon, u32 id, u32 arg);
extern void *func_0201ADE4(u32 a, int b, u32 heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B9A0(struct Actor *a);
extern void *func_020490F4(u32 id, u32 heap);
extern s32_021D5628 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021D5628 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021D5628 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_021E3034(u32 *p, int a1);
extern void func_021E2F2C(void *);
extern void func_021DFDA0(void *p);
void func_021D4C20(u8 *p);
void func_021D4C40(u8 *p);
void func_021D54F0(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
void func_021D55AC(void *p);
void func_021D5628(void *p);
void func_021D5694(void *p);
void func_021D56E0(void);
void func_021D56E4(u8 *p, u32 v);
void func_021D56F0(u8 *p);
void func_021D56FC(void *p);
void func_021D572C(u8 *p, int idx);



/*
 * Addresses are Black-image addresses.
 */
void func_021D4C20(u8 *p)
{
    func_021E3230(p);
    func_021E3208(p, 3);
    func_021D8E84(p, (int)func_021D4C40);
}



void func_021D4C40(u8 *p)
{
    Vec v1, v2, v3, v4, v5, v6, v7, v8;

    func_021DFA60(FRAME);
    if (FRAME == func_021D4480(1)) {
        func_02015F50(OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == func_021D4480(2)) {
        func_02015F50(OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == func_021D4480(3)) {
        func_021D43C8(p);
        func_021D434C(p);
    }
    if (FRAME == func_021D4480(4)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0x18);
    }
    if (FRAME == func_021D4480(4)) {
        func_02015EA0(OBJ(0));
    }
    if (FRAME == func_021D4480(0x356)) {
        func_020515CC(WORK[0], 10, 0, p);
    }
    if (FRAME == func_021D4480(0x65)) {
        func_020515CC(WORK[1], 1, 0, p);
    }
    if (FRAME == func_021D4480(0x9A)) {
        func_020515CC(WORK[2], 2, 0, p);
    }
    if (FRAME == func_021D4480(0x356)) {
        func_020515CC(WORK[8], 2, 0, p);
    }
    if (FRAME == func_021D4480(0xE)) {
        func_020515CC(WORK[3], 3, 0, p);
    }
    if (FRAME == func_021D4480(0x483)) {
        func_020515CC(WORK[7], 3, 0, p);
    }
    if (FRAME == func_021D4480(0x9A)) {
        func_020515CC(WORK[4], 4, func_021D4A34, p);
    }
    if (FRAME == func_021D4480(0x152)) {
        func_020515CC(WORK[5], 5, 0, p);
    }
    if (FRAME == func_021D4480(0x2BC)) {
        func_020515CC(WORK[6], 6, func_021D4A94, p);
    }
    if (FRAME == func_021D4480(0x47F)) {
        func_021D434C(p);
    }
    if (FRAME == func_021D4480(0x10A)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D4480(0x14), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x12D) - 2) {
        if (SLOT0 != 0) {
            func_020307B0(SLOT0);
            SLOT0 = 0;
        }
        if (SLOT1 != 0) {
            func_020307B0(SLOT1);
            SLOT1 = 0;
        }
        func_021E3230(p);
        func_021D8E84(p, (int)func_021D49C4);
    }
    if (FRAME == func_021D4480(0x14A)) {
        func_02015EB0(OBJ(2));
        v1.x = -0x32000;
        v1.y = -0x96000;
        v1.z = 0xA000;
        func_02015C48(OBJ(2), &v1);
        v1.x = -0x32000;
        v1.y = -0x37000;
        v1.z = 0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(2), func_021D4480(0xF), &v1, HEAP);
        func_02015E04(OBJ(2));
        func_02015C94(OBJ(2), &v1);
        v1.x *= 1.2;
        v1.y *= 1.2;
        func_02015CAC(OBJ(2), &v1);
    }
    if (FRAME == func_021D4480(0x14B)) {
        func_02015EB0(OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x50000;
        v2.z = -0xA000;
        func_02015C48(OBJ(3), &v2);
        v2.x = 0x3C000;
        v2.y = 0x5000;
        v2.z = -0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(3), func_021D4480(0xF), &v2, HEAP);
        func_02015E04(OBJ(3));
        func_02015C94(OBJ(3), &v2);
        v2.x *= 1.2;
        v2.y *= 1.2;
        func_02015CAC(OBJ(3), &v2);
    }
    if (FRAME == func_021D4480(0x154)) {
        v3.x = -0x32000;
        v3.y = -0x37000;
        v3.z = 0xA000;
        func_021DFB4C(SLOT0, func_021D4480(0x1C), &v3);
        v3.x = 0x3C000;
        v3.y = 0x5000;
        v3.z = -0xA000;
        func_021DFB4C(SLOT1, func_021D4480(0x1C), &v3);
    }
    if (FRAME == func_021D4480(0x170)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        v4.x = -0x96000;
        v4.y = -0x37000;
        v4.z = 0;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(2), func_021D4480(0x2E), &v4, HEAP);
        v4.x = 0x96000;
        v4.y = 0x5000;
        v4.z = 0;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(3), func_021D4480(0x2E), &v4, HEAP);
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D4480(0x1B2)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_02015EB0(OBJ(0));
        func_02015F50(OBJ(0), 0, 0, 0, 0x7FFF);
        v5.x = -0x96000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        func_02015C48(OBJ(0), &v5);
        v5.x = 0x3C000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(0), func_021D4480(0x67), &v5, HEAP);
        func_02015C94(OBJ(0), &v5);
        v5.x *= 1.2;
        v5.y *= 1.2;
        func_02015CAC(OBJ(0), &v5);
        func_020307B0(SLOT1);
        SLOT1 = 0;
        func_02015EB0(OBJ(1));
        v6.x = 0x96000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        func_02015C48(OBJ(1), &v6);
        v6.x = -0x2D000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(1), func_021D4480(0x67), &v6, HEAP);
        func_02015C94(OBJ(1), &v6);
        v6.x *= 1.2;
        v6.y *= 1.2;
        func_02015CAC(OBJ(1), &v6);
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D4480(0x1F8)) {
        func_021DFB4C(SLOT0, func_021D4480(0x80), (void *)(SLOT0 + 0x28));
        func_021DFB4C(SLOT1, func_021D4480(0x80), (void *)(SLOT1 + 0x28));
    }
    if (FRAME == func_021D4480(0x27D)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        v7.x = 0x3C000;
        v7.y = 0x64000;
        v7.z = -0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(0), func_021D4480(7), &v7, HEAP);
        v7.x = -0x2D000;
        v7.y = -0xA0000;
        v7.z = 0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(1), func_021D4480(7), &v7, HEAP);
    }
    func_021D4480(0x48B);
    if (FRAME == func_021D4480(0x48B + 3)) {
        func_02015EB0(OBJ(3));
        v8.x = 0;
        v8.y = -0x17000;
        v8.z = 0xA000;
        func_02015C48(OBJ(3), &v8);
        func_02015E04(OBJ(3));
        func_02015F50(OBJ(3), 0x10, 0x10, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x48F)) {
        func_02015F50(OBJ(3), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x490)) {
        func_02015F50(OBJ(3), 0, 0, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x28B)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D4480(0xA), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x2B5)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D4480(0x19), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x380)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D4480(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x3CA)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D4480(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x4C1)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        func_021E3230(p);
        func_021D8E84(p, (int)func_021D49C4);
    }
    func_021DFC68(SLOT0, p);
    func_021DFC68(SLOT1, p);
}



void func_021D54F0(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy)
{
    int which;
    void *mon;
    u32 id;
    u32 a;
    u32 b;
    u32 egg;
    u32 h;
    u32 flag;

    if (enemy != 0) {
        if (func_021D8AA8(p) != 0) {
            which = 1;
        } else {
            which = 0;
        }
    } else {
        if (func_021D8AA8(p) != 0) {
            which = 0;
        } else {
            which = 1;
        }
    }
    mon = func_021D8FA4(p, which);
    id = func_02017E1C(mon, 7, 0);
    a = func_02017E1C(mon, 0xAB, 0);
    b = func_02017E1C(mon, 0x6F, 0);
    egg = func_02017E1C(mon, 0x4C, 0);
    if (egg == 0) {
        h = (u32)func_0201ADE4((u16)a, (u16)b, ((struct Obj22664 *)p)->f5F4);
        flag = func_0201AE1C((const struct Personal *)h, 0x10);
        func_0201AE14((void *)h);
    }
    if (egg != 0) {
        *outFlag = 1;
    } else if (flag != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (id != func_02008530((const struct Sub0200852CObj *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}



void func_021D55AC(void *p)
{
    u32 v = ((struct Obj22665 *)((char *)((struct Obj03254 *)p)->fC))->fB0;
    if (v == 0) {
        Local s;
        s.a = 0x80;
        s.b = 0x63;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        ((struct Obj22666 *)((char *)((struct Obj03254 *)p)->fC))->fB0 =
            (u32)func_0204B294((void *)((struct Obj03254 *)p)->f9C4,
                          ((struct Obj03254 *)p)->f8A8,
                          ((struct Obj03254 *)p)->f88C,
                          ((struct Obj03254 *)p)->f8BC,
                          &s, 0, ((struct Obj03254 *)p)->f5F4);
        func_0204B92C((struct Obj *)((struct Obj22667 *)((char *)((struct Obj03254 *)p)->fC))->fB0, 1);
        func_0204B3DC((struct Obj *)((struct Obj22668 *)((char *)((struct Obj03254 *)p)->fC))->fB0, 1);
    } else {
        func_0204B9A0((struct Actor *)v);
    }
}



void func_021D5628(void *p)
{
    void *h = func_020490F4(0x67, ((struct Obj03769 *)p)->f5F4);
    ((struct Obj03769 *)p)->f8A8 = func_0204A6C8(h, 2, 0, 0, ((struct Obj03769 *)p)->f5F4);
    ((struct Obj03769 *)p)->f88C = func_0204AC18(h, 3, 0, 0xE0, 0, 1, ((struct Obj03769 *)p)->f5F4);
    ((struct Obj03769 *)p)->f8BC = func_0204AF28(h, 1, 0, ((struct Obj03769 *)p)->f5F4);
    func_02049238(h);
    ((struct Obj22669 *)((char *)((struct Obj03769 *)p)->fC))->fB0 = 0;
}



/*
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * func_021D5694 callers' targets; this is the first callee of func_021D6C78.
 *
 * Addresses are Black-image addresses.
 */
void func_021D5694(void *p)
{
    u8 *b = p;

    if (((struct Obj22670 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0 != 0)
        func_0204B3B4(((struct Obj22671 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0);
    if (((struct Obj01724 *)b)->f8A8 != 0) {
        func_0204A8D4((u32)(((struct Obj01724 *)b)->f8A8));
        func_0204ADA4((u32)(((struct Obj01724 *)b)->f88C));
        func_0204AFD8((u32)(((struct Obj01724 *)b)->f8BC));
    }
    ((struct Obj01724 *)b)->f8A8 = 0;
    ((struct Obj01724 *)b)->f88C = 0;
    ((struct Obj01724 *)b)->f8BC = 0;
    ((struct Obj22672 *)((u8 *)((struct Obj01724 *)b)->fC))->fB0 = 0;
}



void func_021D56E0(void) { }



void func_021D56E4(u8 *p, u32 v) { ((struct Obj22673 *)p)->fF2C = v; }



void func_021D56F0(u8 *p) { ((struct Obj22674 *)p)->f1094 = 1; }



void func_021D56FC(void *p)
{
    func_021D5694(p);
    func_021E3034(((struct Obj01724 *)p)->fC, 6);
    func_021E2F2C(((struct Obj01724 *)p)->fC);
    func_020307B0((u32)(((struct Obj01724 *)p)->fC));
    ((struct Obj01724 *)p)->fC = 0;
    func_021D8E84(p, (int)func_021DFDA0);
}



void func_021D572C(u8 *p, int idx)
{
    if (((struct Obj10351 *)p)->f85C != 0) {
        func_020307B0((u32)((void *)(((struct Obj10351 *)p)->f85C)));
        ((struct Obj10351 *)p)->f85C = 0;
    }
}
