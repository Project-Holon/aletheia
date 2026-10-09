/*
 * file:     fld3d_ci_p05.c
 * unit:     yes
 * function: func_021C3248, func_021C3250, func_021C3270, func_021C32BC, func_021C32F4, func_021C335C, func_021C3378, func_021C33A4, func_021C33E0, func_021C3400, func_021C340C, func_021C341C
 * address:  0x021C3248
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
 *   func_0201B9F0  0x0201B9F0  thumb
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_0200BCD8  0x0200BCD8  thumb
 *   func_021C3530  0x021C3530  thumb  ov021
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BC88  0x0200BC88  thumb
 *   func_021C36B0  0x021C36B0  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020173F0  0x020173F0  thumb
 *   func_0200BCA0  0x0200BCA0  thumb
 *   func_0216556C  0x0216556C  thumb  ov010
 *   func_021C3898  0x021C3898  thumb  ov021
 *   func_0200BC20  0x0200BC20  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0216AAE4  0x0216AAE4  thumb  ov010
 *   func_0200BD48  0x0200BD48  thumb
 *   func_021C385C  0x021C385C  thumb  ov021
 *   func_0200BC10  0x0200BC10  thumb
 *   func_0200BCB8  0x0200BCB8  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021C3510  0x021C3510  thumb  ov021
 *   func_0201850C  0x0201850C  thumb
 */
#include "../../matched/include/Obj03142.h"
#include "../../matched/include/Obj18300.h"
#include "../../matched/include/Obj18301.h"

struct Obj;
struct Party;
struct PartyMon;
struct Blk37;
struct Ctx;
struct BigObj;
struct Obj11233;
struct Obj11232;
struct Obj06851;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32_021C3248;

typedef unsigned long long u64;

typedef int s32_021C3400;

typedef signed short   s16;

typedef signed char    s8;

extern void func_0201B9F0(void *mon);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_02017988(void *p, u32 a);
extern int func_0200BCA8(u32, u32);
extern u32 func_0200BC2C(u32, u32);
extern u32 func_0200BCD8(struct Obj *p, u32 i);
extern void func_021C3530(void *mon, u32 b);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_0200BC88(struct Obj *p, s32_021C3248 i);
extern void func_021C36B0(void *e);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0200CA1C(void *p);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void *func_020173F0(u16 species, u16 level, unsigned long long id, u16 heap);
extern int func_0200BCA0(struct Obj11233 *p);
extern void func_0216556C(void);
extern void func_021C3898(u32 *, u32);
extern void func_0200BC20(struct Obj11232 *p);
extern u32 func_020307B0(void *p);
extern u8 func_02012984(const struct BigObj *p);
extern void func_0216AAE4(void *sys, void *party, int season);
extern void func_0200BD48(void *a, int b);
extern int func_021C385C(void **p);
extern void func_0200BC10(struct Obj06851 *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern u32 func_0201AA14(void *p);
extern u32 func_020143CC(u32 a, u32 b);
extern u32 func_0200BCB8(u32, u32, u32, u32);
extern u32 func_021C3510(u32, u32);
extern u32 func_0201850C(u16 species, u16 form, u32 exp);
void func_021C3248(void *a0);
void func_021C3250(void *mon);
void func_021C3270(u32 *p, u32 b, u32 c);
void func_021C32BC(void **p, void *mon);
void func_021C32F4(u32 *p, u32 b);
void func_021C335C(void **p);
int func_021C3378(void **p);
void func_021C33A4(void *a);
void func_021C33E0(void *a);
int func_021C3400(void *a);
int func_021C340C(u32 a, u32 b, u32 c, u32 d);
int func_021C341C(u32 *p, u32 b);





/*
 * Tail-call thunk: forwards to func_0201B9F0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C3248(void *a0)
{
    func_0201B9F0(a0);
}






void func_021C3250(void *mon)
{
    if (func_02017E1C(mon, 5, 0) == 0x1EC)
        func_02017988(mon, 0);
}






/*
 * Addresses are Black-image addresses.
 */
void func_021C3270(u32 *p, u32 b, u32 c)
{
    u32 m;

    if (func_0200BCA8(p[2], b) == 1) {
        m = func_0200BC2C(p[2], b);
        func_021C3530((void *)m, func_0200BCD8((struct Obj *)p[2], b));
        func_021C32BC((void **)p, (void *)m);
        func_0201A98C((void *)c, (void *)m);
        func_0200BC88((struct Obj *)p[2], b);
        func_021C36B0((void *)p[2]);
    }
}






/*
 * Returns the Pokemon's held item to the bag when it fits.
 */
void func_021C32BC(void **p, void *mon)
{
    void *bag = func_0200CA1C(func_020120F4(func_02188C80(p[1])));

    if (func_0200CED4(bag, func_02017E1C(mon, 5, 0)) == 0)
        func_0200CDE0(bag, mon);
}





void func_021C32F4(u32 *p, u32 b)
{
    u32 m = (u32)func_020173F0(1, 1, 1, ((struct Obj03142 *)p)->f0);
    u32 w;

    if (func_0200BCA0((struct Obj11233 *)p[2]) == 1) {
        func_0216556C();
        func_021C33E0((void *)p[1]);
        func_021C3898(p, m);
        func_0201A98C((void *)b, (void *)m);
        func_0200BC20((struct Obj11232 *)p[2]);
        func_020307B0((void *)m);
        w = (u32)func_020120F4(func_02188C80((void *)p[1]));
        func_0216AAE4((void *)w, (void *)b, func_02012984((const struct BigObj *)w));
    }
}





/*
 * Stops the running timer and closes the record.
 */
void func_021C335C(void **p)
{
    if (func_0200BCA0(p[2]) == 1) {
        func_0200BC20(p[2]);
        func_021C33E0(p[1]);
    }
}





int func_021C3378(void **p)
{
    func_0200BD48(p[2], 1);
    if (func_021C385C(p) == 1) {
        func_0200BC10(p[2]);
        func_021C33A4(p[1]);
        return 1;
    }
    return 0;
}





/*
 * Sets event flag 0x4139 when the party is not full.
 */
void func_021C33A4(void *a)
{
    void *g = func_020120F4(func_02188C80(a));
    void *ev = (void *)func_0201296C(g);
    void *party = func_02012934(g);

    if ((int)func_0201AA18(party) < (int)func_0201AA14(party))
        *((u16 *)func_020143CC((u32)ev, 0x4139)) = 1;
}





/*
 * Clears event flag 0x4139 (EXACT*: unlabelled follower).
 */
void func_021C33E0(void *a)
{
    *((u16 *)func_020143CC(func_0201296C(func_020120F4(func_02188C80(a))), 0x4139)) = 0;
}




/*
 * Unlabelled leaf in ov021 (the listing prints it as a `.word` run at
 * 0x021C3400, next to ov010's field-VM code); ov010's func_0215CE98 reaches
 * it across the overlay pair.  Eight-byte thunk: load [a+8] and tail-call
 * the ARM9 helper.
 */
int func_021C3400(void *a)
{
    return func_0200BCA0((struct Obj11233 *)(((struct Obj18300 *)a)->f8));
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C340C(u32 a, u32 b, u32 c, u32 d)
{
return ((func_0200BCB8(((struct Obj18301 *)((u8 *)(a)))->f8, b, c, d) << 24) >> 24);
}


int func_021C341C(u32 *p, u32 b)
{
    u32 m;
    u32 s0;
    u32 s1;
    u32 s2;

    if (func_0200BCA8(p[2], b) != 1)
        return 1;
    m = func_0200BC2C(p[2], b);
    s2 = func_02017E1C((void *)m, 5, 0);
    s0 = func_02017E1C((void *)m, 0x6F, 0);
    s1 = func_02017E1C((void *)m, 8, 0);
    func_02017E1C((void *)m, 0x9E, 0);
    return func_0201850C(s2, s0, func_021C3510(s1, func_0200BCD8((struct Obj *)p[2], b)));
}
