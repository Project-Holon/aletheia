/*
 * file:     intrude_subdisp_p12.c
 * unit:     yes
 * function: func_0217F1E8, func_0217F214, func_0217F240, func_0217F284, func_0217F2B4
 * address:  0x0217F1E8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012B70 0x02012B70 thumb
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020410D0  0x020410D0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02012B58 0x02012B58 thumb
 *   func_02158590 0x02158590 thumb ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_021904B0  0x021904B0  thumb  ov021
 */
#include "../../matched/include/Obj00092.h"
#include "../../matched/include/Obj12494.h"

struct BigObj;
struct Ctx;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    u8 f28;
} Ov018Obj;

typedef unsigned short u16;

extern void *func_020120F4(const struct Ctx *p);
extern int func_02012B70(const struct BigObj *p);
extern void func_02041300(unsigned int, int, int, int, u8, u8, u8);
extern void func_02041B6C(unsigned int);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020409B4(u32 layer);
extern u8 func_02012B58(const struct BigObj *p);
extern int func_02158590(void *);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C54(u8 *p);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021904B0(u32 a, u32 b);
int func_0217F1E8(u8 *p);
void func_0217F214(void);
void func_0217F240(u8 *p, int mode);
int func_0217F284(u8 *p);
void func_0217F2B4(Ov018Obj *p, void *a);

/*
 * extent: Two bytes of alignment padding at 0x0217F212.
 */
int func_0217F1E8(u8 *p)
{
    if (func_02012B70(func_020120F4(((struct Obj00092 *)p)->f0)) == 1) {
        switch (((struct Obj00092 *)p)->fDC) {
        case 2: case 3: case 4: return 1;
        }
    }
    return 0;
}

void func_0217F214(void)
{
    func_02041300(6, 0x3001, 0x14, 0x16, 0xc, 2, 0x11);
    func_02041B6C(6);
}


void func_0217F240(u8 *p, int mode)
{
    func_020410D0(6, 0x14, 0x16, 0xC, 2, (u32)(p + 0x138), 0, 0, 0xC, 2);
    if (mode == 1) {
        func_02041B6C(6);
    } else {
        func_020409B4(6);
    }
}

/*
 * extent: Two bytes of alignment padding at 0x0217F2B2.
 */
int func_0217F284(u8 *p)
{
    void *q = func_020120F4(((struct Obj12494 *)p)->f0);
    if (((struct Obj12494 *)p)->fE4 == 0 && func_02012B58(q) == 0 && func_02158590(q) == 0) return 1;
    return 0;
}


void func_0217F2B4(Ov018Obj *p, void *a)
{
    void *r;

    r = (void *)func_02188C54(func_0201210C(a));
    if (p->f00 == 0) {
        p->f00 = func_0201EC74(6, 0x20, 4);
        p->f04 = func_020457B0(0x1F0, 4);
        p->f08 = func_020457B0(0x1D0, 4);
        p->f0C = (void *)func_021904B0((u32)r, 0x44);
        p->f10 = (void *)func_021904B0((u32)r, 0x42);
        p->f14 = (void *)func_021904B0((u32)r, 0x43);
        p->f24 = r;
        p->f28 = 0;
    }
}
