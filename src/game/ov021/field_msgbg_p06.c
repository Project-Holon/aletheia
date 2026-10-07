/*
 * file:     field_msgbg_p06.c
 * unit:     yes
 * function: func_0218AECC, func_0218AED4, func_0218AF90, func_0218B0CC, func_0218B13C, func_0218B208, func_0218B24C
 * address:  0x0218AECC
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
 *   func_021626B8  0x021626B8  thumb  ov010
 *   func_0218AE48  0x0218AE48  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0218AE04  0x0218AE04  thumb  ov021
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626EC  0x021626EC  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_0218ADC8  0x0218ADC8  thumb  ov021
 *   func_0218AD80  0x0218AD80  thumb  ov021
 *   func_021BE288  0x021BE288  thumb  ov021
 *   func_021F3A88  0x021F3A88  thumb  ov038
 *   func_021F38A4  0x021F38A4  thumb  ov051
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_0218B630  0x0218B630  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB310  0x021AB310  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021F404C  0x021F404C  thumb  ov039
 *   func_021F37E0  0x021F37E0  thumb  ov041
 *   func_02188CB4  0x02188CB4  thumb
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_02162598  0x02162598  thumb  ov010
 *   func_0218AEAC  0x0218AEAC  thumb
 *   func_0218B2A8  0x0218B2A8  thumb
 *   func_0218B2E8  0x0218B2E8  thumb
 *   func_02188CE8  0x02188CE8  thumb
 *   func_02013DD0  0x02013DD0  thumb
 *   func_0218DC70  0x0218DC70  thumb
 *   func_021AA248  0x021AA248  thumb
 *   func_021A9F40  0x021A9F40  thumb
 *   func_021A2FA4  0x021A2FA4  thumb
 *   func_021BB188  0x021BB188  thumb
 *   func_0219E418  0x0219E418  thumb
 *   func_021C46F8  0x021C46F8  thumb
 */
#include "../../matched/include/Obj00705.h"
#include "../../matched/include/Obj04982.h"
#include "../../matched/include/Obj04983.h"
#include "../../matched/include/Obj09449.h"

struct Obj;
struct Desc;
struct Obj00020;
struct Q;
struct Ctx;
typedef unsigned short u16;

typedef struct Vec { int x, y, z; } Vec;

typedef unsigned int   u32;

typedef unsigned char  u8;

struct FieldInput {
    u16 f0;
    u16 pad02;
    void *sys;
    void *f8;
    void *fC;
    u16 f10;
    u16 pad12;
    u8 *pos;
    void *f18;
    u32 f1C;
    u32 f20;
    u16 f24;
    u16 f26;
};

typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

int func_021626B8(char *a0, int a1);
extern void func_0218AE48(struct Obj *p, struct Vec *out);
extern unsigned int func_02188C98(unsigned char *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F8(u32 attr);
extern u32 func_0218AE04(u8 *p, void *arg);
extern void *func_021625CC(char *p, unsigned i);
extern int func_021626EC(u16 *p);
extern u8 func_021626E8(u8 *p);
extern void func_0218ADC8(u8 *p, int id, u32 *pos);
extern int func_0218AD80(void *p, void *a, int id, Vec *pos);
extern int func_021BE288(u8 *pos, int k);
extern int func_021F3A88(int a0, int a1, int a2);
extern int func_021F38A4(int a, int b);
extern u32 func_021A3098(u8 *p);
extern int func_0218B630(void *p, u32 move);
extern u16 func_021AB0F0(u32 a);
extern int func_021AB310(u16 a);
extern void *func_021A3074(unsigned char *p);
extern void func_02164208(int dir, int *p, int amt);
extern int func_02163E58(void *m, Vec *pos, int *h);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021F404C(void *a);
extern int func_021F37E0(void *a);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_0219E2F4(void *o, void *out);
extern int func_02162598(char *p, struct Q *q);
extern int func_0218AEAC(u8 *p);
extern void func_0218B2A8(char *p, int s, u16 *v);
extern int func_0218B2E8(char *p, void *x, int a, int *b);
extern u32 func_02188CE8(u8 *p);
extern int func_02013DD0(int a0);
extern void *func_0218DC70(u8 *p);
extern int func_021AA248(struct Ctx *ctx, void *b);
extern int func_021A9F40(struct Ctx *ctx, int mode);
extern u16 func_021A2FA4(u8 *p, u32 a1);
extern int func_021BB188(u16 a);
extern int func_0219E418(u32 a, u32 b);
extern u32 func_021C46F8(u32 a, u32 b, u32 c);
int func_0218AECC(char *a0, int a1);
int func_0218AED4(char *p, int unused, void *a);
int func_0218AF90(struct FieldInput *p, void *a, u8 *pos);
int func_0218B0CC(char *p, void *unused, void *x);
int func_0218B13C(char *p, void *unused, void *x, int *alt);
int func_0218B208(struct FieldCtx *p, void *unused, u8 *pos);
int func_0218B24C(char *p, void *q, void *x);


/*
 * Unblocked by matching func_021626B8 (ov010, EXACT): the +0004 ABS32 site now
 * attests as `matched`.
 */
int func_0218AECC(char *a0, int a1)
{
    return func_021626B8(a0, a1);
}


int func_0218AED4(char *p, int unused, void *a)
{
    Vec v;
    int id;
    void *o;

    func_0218AE48((struct Obj *)p, &v);
    if ((func_021AB0F8(func_021AB0D4((void *)func_02188C98(a), &v)) & 1) == 0)
        return 0;
    id = (int)func_0218AE04((u8 *)p, *(Vec * *)&((struct Obj00705 *)p)->f34);
    if (id != 0xFFFF) {
        o = func_021625CC(((struct Obj00705 *)p)->fC, (u16)id);
        if (func_021626EC(o) == 0 && func_021626E8(o) == 1) {
            func_0218ADC8((u8 *)p, id, (u32 *)(*(Vec * *)&((struct Obj00705 *)p)->f34));
            return func_0218AD80(p, a, id, *(Vec * *)&((struct Obj00705 *)p)->f34);
        }
    }
    id = (int)func_0218AE04((u8 *)p, &v);
    if (id != 0xFFFF) {
        if (func_021626EC(func_021625CC(((struct Obj00705 *)p)->fC, (u16)id)) == 0) {
            func_0218ADC8((u8 *)p, id, (u32 *)(*(Vec * *)&((struct Obj00705 *)p)->f34));
            return func_0218AD80(p, a, id, &v);
        }
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_0218AF90(struct FieldInput *p, void *a, u8 *pos)
{
    Vec v;
    Vec w;
    int h;
    u32 attr;
    void *m;

    func_0218AE48((struct Obj *)p, &v);
    if (func_021BE288(pos, 6))
        return func_021F3A88((int)a, v.x / 0x10000, v.z / 0x10000);
    if (func_021BE288(pos, 0x19) || func_021BE288(pos, 0x1A) || func_021BE288(pos, 0x1B))
        return func_021F38A4((int)pos, p->f24);
    attr = func_021AB0D4((void *)func_02188C98(pos), &v);
    if ((func_021AB0F8(attr) & 1) == 0)
        return 0;
    if (func_021A3098(p->f18) == 2 && func_0218B630(p->f8, 0x7F) != 6
        && func_021AB310(func_021AB0F0(attr)) == 1) {
        w = v;
        m = func_021A3074(p->f18);
        func_02164208(p->f24, (int *)(&w), 0x10000);
        if (func_02163E58(m, &w, &h) == 1 && v.y > h)
            return (int)func_02158768((int)p->sys, 0x271F, 0, p->f0);
    }
    if (func_0218AE04((u8 *)p, &v) == 0xFFFF) {
        if (func_021BE288(pos, 2))
            return func_021F404C(a);
        if (func_021BE288(pos, 5))
            return func_021F37E0(a);
    }
    return 0;
}


/*
 * Calls the unlabelled ov010 leaf func_021626EC (filed as pkt_ov010_021626EC).
 *
 * Addresses are Black-image addresses.
 */
int func_0218B0CC(char *p, void *unused, void *x)
{
    int buf[2];
    int r4;
    void *r6;

    func_0219E2F4(func_021A3074(func_02188CB4(x)), buf);
    r4 = func_02162598(((struct Obj04982 *)p)->fC, (struct Q *)buf);
    if (r4 == 0xFFFF)
        return 0;
    r6 = func_021625CC(((struct Obj04982 *)p)->fC, (u16)r4);
    if (func_021626EC(r6) == 1 || func_0218AEAC(r6) == 0)
        return 0;
    func_0218B2A8(p, r4, (u16 *)buf);
    return func_0218B2E8(p, x, r4, buf);
}


int func_0218B13C(char *p, void *unused, void *x, int *alt)
{
    int buf[2];
    int id;
    void *o;

    func_0219E2F4(func_021A3074(func_02188CB4(x)), buf);
    id = func_02162598(((struct Obj04983 *)p)->fC, (struct Q *)buf);
    if (id != 0xFFFF) {
        o = func_021625CC(((struct Obj04983 *)p)->fC, (u16)id);
        if (func_021626EC(o) == 0 && func_0218AECC(o, ((struct Obj04983 *)p)->f24) != 0
            && func_021626E8(o) == 1) {
            func_0218B2A8(p, id, (u16 *)buf);
            return func_0218B2E8(p, x, id, buf);
        }
    }
    id = func_02162598(((struct Obj04983 *)p)->fC, (struct Q *)alt);
    if (id == 0xFFFF)
        return 0;
    o = func_021625CC(((struct Obj04983 *)p)->fC, (u16)id);
    if (func_021626EC(o) == 0 && func_0218AECC(o, ((struct Obj04983 *)p)->f24) != 0) {
        func_0218B2A8(p, id, (u16 *)buf);
        return func_0218B2E8(p, x, id, buf);
    }
    return 0;
}


/*
 * When bit 3 of the flag word is set, runs the object's interaction:
 * func_021AA248 with the map value when func_02013DD0 accepts field 0x10,
 * else func_021A9F40(obj, 0).
 *
 * is an unlabelled Thumb veneer (ldr r1, [pc, #4]; ldr r3, [pc, #8]; movs r2,
 * #4; bx r3) with no witness; it closes once arm9 0x02013DD0 is labelled.
 *
 * Addresses are Black-image addresses.
 */
int func_0218B208(struct FieldCtx *p, void *unused, u8 *pos)
{
    void *obj = (void *)func_02188CE8(pos);

    if (!p->b3)
        return 0;
    if (func_02013DD0(p->f10))
        return func_021AA248(obj, func_0218DC70((u8 *)func_02188C98(pos)));
    return func_021A9F40(obj, 0);
}


int func_0218B24C(char *p, void *q, void *x)
{
    void *a = func_02188CB4(x);
    void *o = func_021A3074(a);
    int r = func_021A2FA4(a, ((struct Obj09449 *)p)->f2C);

    if (r == 1) {
        int t = ((struct Obj09449 *)p)->f1C;
        if (t == 0 || t == 3) {
            if (func_021BB188(func_021AB0F0(((struct Obj09449 *)p)->f38))) {
                if (func_0219E418((u32)o, r) & 3)
                    return func_021C46F8((u32)q, (u32)x, r);
            }
        }
    }
    return 0;
}
