/*
 * file:     mailtool_p01.c
 * unit:     yes
 * function: func_021C3CC0, func_021C3D44, func_021C3DA4, func_021C3E00, func_021C3E04, func_021C3E24, func_021C3E3C, func_021C3E9C, func_021C3F98
 * address:  0x021C3CC0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02008FEC 0x02008FEC thumb
 *   func_02030734 0x02030734 arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008F08 0x02008F08 thumb
 *   func_02008EAC 0x02008EAC thumb
 *   func_02008F48 0x02008F48 thumb
 *   d_021C7EE0 0x021C7EE0 data a1
 *   func_02017E1C 0x02017E1C thumb
 *   func_02008FA8 0x02008FA8 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_021C409C 0x021C409C thumb ov136
 *   func_02031324 0x02031324 arm
 *   func_02031330 0x02031330 arm
 *   func_02031348 0x02031348 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0202411C 0x0202411C thumb
 *   func_02024134 0x02024134 thumb
 *   func_02024124 0x02024124 thumb
 *   func_020240FC 0x020240FC thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_021C414C 0x021C414C thumb ov136
 *   func_021C3FC8 0x021C3FC8 thumb ov136
 *   ov136_id 0x0000006E data
 *   D_021C7750 0x021C7750 data
 *   D_021C775C 0x021C775C data
 *   func_021C4134 0x021C4134 thumb
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../../matched/include/Obj01163.h"
#include "../../matched/include/Obj14181.h"
#include "../../matched/include/Obj08196.h"
#include "../../matched/include/Obj08197.h"
#include "../../matched/include/Obj23488.h"

struct Sub02008F80Obj;
struct Big;
struct Sub02008EACObj;
struct Sub02008EACObjLayout;
struct Obj0203159C;
struct Sub02008C20Obj;
struct S020314B8;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082AC0(unsigned, void *, unsigned);
extern void *func_02012EBC(struct Big *p);
extern void *func_02008F08(int a0);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern void func_02008F48(struct Sub02008EACObjLayout *obj, u8 kind, u32 unused, void *p);
extern unsigned func_02017E1C(void *, unsigned, unsigned);
extern void func_02008FA8(struct Sub02008F80Obj *obj, u32 value);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_020307B0(void *p);
extern void func_0203064C(unsigned, unsigned, unsigned);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_021C409C(void *, unsigned);
extern void *func_02031324(int a0);
extern u32 func_02031330(void *p);
extern void func_02031348(void *h, u32 id, void *a, void *b);
extern int func_02034AC4(int handle);
extern void func_02034A5C(int handle);
extern int func_0202411C(unsigned char *p);
extern void func_02024134(char *a, void *b);
extern unsigned int func_02024124(unsigned short *p);
extern void func_020240FC(void *a);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_021C414C(void *a, u8 *p);
extern void func_021C3FC8(u8 *ctx, u8 *arg);
extern void func_0203133C(struct S020314B8 *v);
extern void func_021C4134(u8 *p);
extern void func_020315D4(struct S020315D4 *v);
extern void *func_0203084C(u32 heapId);
extern void func_020306F0(u32 v);
void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
void *func_021C3D44(void *a, void *b, unsigned heap);
void *func_021C3DA4(void *a, void *b, unsigned heap);
u32 func_021C3E00(u32 *p);
int func_021C3E04(u32 *p, void *q);
void func_021C3E24(u8 *p);
int func_021C3E3C(void *a, void *b, u8 *p);
int func_021C3E9C(int unused, u32 *state, u16 *msg, u8 *ctx);
int func_021C3F98(u32 a, void *b, void *c, u32 *p);
extern const char d_021C7EE0[];
extern u8 ov136_id[];
extern u8 D_021C7750[];
extern u8 D_021C775C[];

void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap)
{
    u8 *p;
    unsigned v;
    v = (unsigned int)func_02008FEC(a);
    p = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0x43);
    func_02082AC0(0, p, 0x1C);
    p[0xF] = d;
    p[0xE] = c;
    ((struct Obj01163 *)p)->f18 = v;
    ((struct Obj01163 *)p)->f0 = 1;
    ((struct Obj01163 *)p)->f8 = b;
    ((struct Obj01163 *)p)->fC = 0;
    ((struct Obj01163 *)p)->f10 = func_02012EBC(a);
    ((struct Obj01163 *)p)->f14 = func_02008F08((unsigned)((u16)heap));
    func_02008EAC(((struct Obj01163 *)p)->f14);
    func_02008F48(((struct Obj01163 *)p)->f14, 0xFF, c, a);
    return p;
}

void *func_021C3D44(void *a, void *b, unsigned heap)
{
    u8 *p;
    p = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0x97);
    func_02082AC0(0, p, 0x1C);
    ((struct Obj01163 *)p)->f0 = 0;
    ((struct Obj01163 *)p)->f10 = func_02012EBC(a);
    ((struct Obj01163 *)p)->f14 = func_02008F08((unsigned)((u16)heap));
    func_02017E1C(b, 0xA7, (u32)((struct Obj01163 *)p)->f14);
    return p;
}

void *func_021C3DA4(void *a, void *b, unsigned heap)
{
    u8 *p;
    p = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0xB9);
    func_02082AC0(0, p, 0x1C);
    ((struct Obj01163 *)p)->f0 = 0;
    ((struct Obj01163 *)p)->f10 = func_02012EBC(a);
    ((struct Obj01163 *)p)->f14 = func_02008F08((unsigned)((u16)heap));
    func_02008FA8(((struct Obj01163 *)p)->f14, (u32)b);
    return p;
}

u32 func_021C3E00(u32 *p)
{
    return p[1];
}

int func_021C3E04(u32 *p, void *q)
{
    if (func_021C3E00(p) == 0) return 0;
    func_02017E40(q, 0xa7, p[5]);
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C3E24(u8 *p)
{
    if (((struct Obj14181 *)p)->f14)
        func_020307B0(((struct Obj14181 *)p)->f14);
    func_020307B0(p);
}

/*
 * tail: 021C3E9A..021C3E9C zero alignment padding.
 */
int func_021C3E3C(void *a, void *b, u8 *p)
{
    u8 *q;
    func_0203064C(1, 0x63, 0x1000);
    q = func_0203159C(a, 0x20, 0x63);
    func_02082AC0(0, q, 0x20);
    ((struct Obj08197 *)q)->f0 = 0x63;
    *(u8 * *)&((struct Obj08197 *)q)->f10 = func_021C409C(((struct Obj08196 *)p)->f14, 0x63);
    if (((struct Obj08196 *)p)->f0 == 1) (*(u8 **)(q + 0x10))[0xB] = p[0xF];
    if ((*(u8 **)(q + 0x10))[0xB] >= 0xC) (*(u8 **)(q + 0x10))[0xB] = 0;
    ((struct Obj23488 *)(*(u8 * *)&((struct Obj08197 *)q)->f10))->f0 = ((struct Obj08196 *)p)->f0;
    ((struct Obj08197 *)q)->f1C = func_02031324(0x63);
    return 1;
}

/*
 * note 2026-10-05 (wD7 lane15): closed. func_021C414C takes a second argument (u8 *p, its matched
 *   definition reads r1), so case 2 keeps the ctx+0x10 pointer in r1 for that call.
 */
int func_021C3E9C(int unused, u32 *state, u16 *msg, u8 *ctx)
{
    u32 ret = func_02031330(*(void **)(ctx + 0x1C));
    switch (*state) {
    case 0:
        **(u16 **)(ctx + 0x10) = *msg;
        func_02031348(*(void **)(ctx + 0x1C), (u32)-1, D_021C7750, *(void **)(ctx + 0x10));
        *state = 1;
        break;
    case 1: {
        u16 v;
        if (ret == 1)
            break;
        v = **(u16 **)(ctx + 0x10);
        if (v != 4) {
            if (v == 0xFFFF)
                *state = 2;
            else
                goto s3;
        } else
            *state = 2;
        break;
    s3:
        *state = 3;

        break;
    }
    case 2:
        if (*msg == 1) {
            u32 r;
            u8 *p = *(u8 **)(ctx + 0x10);
            if (*(u16 *)p == 4) {
                func_021C414C(*(void **)(msg + 10), p);
                func_02008DF0(func_02008C58(*(void **)(msg + 8)), 0x1D);
                r = 1;
            } else {
                r = 0;
            }
            *(u32 *)(msg + 2) = r;
        }
        return 1;
    case 3:
        func_02034AC4((int)ov136_id);
        func_021C3FC8(ctx, (u8 *)msg);
        func_02031348(*(void **)(ctx + 0x1C), (u32)-1, D_021C775C, *(void **)(ctx + 8));
        *state = 4;
        break;
    case 4:
        if (ret == 1)
            break;
        if (func_0202411C(*(void **)(ctx + 8)) == 0) {
            u8 *q = *(u8 **)(ctx + 0x10);
            void *h = *(void **)(ctx + 8);
            if (q[2] < 3)
                func_02024134(h, q + 0x16 + q[2] * 8);
            else
                *(u16 *)(*(u8 **)(ctx + 0x10) + 0x32) = func_02024124(*(u16 **)(ctx + 8));
        }
        func_020240FC(*(void **)(ctx + 8));
        func_02034A5C((int)ov136_id);
        *state = 0;
        break;
    }
    return 0;
}

int func_021C3F98(u32 a, void *b, void *c, u32 *p)
{
    u32 h;
    func_0203133C((struct S020314B8 *)p[7]);
    func_021C4134((void *)p[4]);
    h = (u16)p[0];
    func_020315D4((struct S020315D4 *)a);
    func_0203084C(h);
    func_020306F0(h);
    return 1;
}
