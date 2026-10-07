/*
 * file:     fld3d_ci_p12.c
 * unit:     yes
 * function: func_021C32F4, func_021C335C, func_021C3378, func_021C33A4, func_021C33E0
 * address:  0x021C32F4
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
 *   func_020173F0  0x020173F0  thumb
 *   func_0200BCA0  0x0200BCA0  thumb
 *   func_0216556C  0x0216556C  thumb  ov010
 *   func_021C3898  0x021C3898  thumb  ov021
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BC20  0x0200BC20  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0216AAE4  0x0216AAE4  thumb  ov010
 *   func_0200BD48  0x0200BD48  thumb
 *   func_021C385C  0x021C385C  thumb  ov021
 *   func_0200BC10  0x0200BC10  thumb
 */
#include "../../matched/include/Obj03142.h"

struct BigObj;
struct Ctx;
struct Obj11233;
struct Party;
struct PartyMon;
struct Obj11232;
struct Obj06851;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned long long u64;

typedef unsigned char  u8;

extern void *func_020173F0(u16 species, u16 level, unsigned long long id, u16 heap);
extern int func_0200BCA0(struct Obj11233 *p);
extern void func_0216556C(void);
extern void func_021C3898(u32 *, u32);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_0200BC20(struct Obj11232 *p);
extern u32 func_020307B0(void *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
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
void func_021C32F4(u32 *p, u32 b);
void func_021C335C(void **p);
int func_021C3378(void **p);
void func_021C33A4(void *a);
void func_021C33E0(void *a);


/*
 * Addresses are Black-image addresses.
 */
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
