/*
 * file:     script_work_p12.c
 * unit:     yes
 * function: func_02158DE8, func_02158E38, func_02158E54, func_02158E7C, func_02158F18, func_02158F50, func_02158F54, func_02158F58, func_02158F6C, func_02158F74, func_02158F78, func_02158F7C, func_02158F80, func_02158F84, func_02158F88, func_02158F8C, func_02158F90
 * address:  0x02158DE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5D4  0x0215A5D4  thumb  ov010
 *   func_0215A5D8  0x0215A5D8  thumb  ov010
 *   func_02158DBC  0x02158DBC  thumb  ov010
 *   d_02170374     0x02170374  data  ov010
 *   func_02011324 0x02011324 thumb
 *   func_02011328 0x02011328 thumb
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02082A7C  0x02082A7C  arm
 *   func_02188C54  0x02188C54  thumb
 *   func_02030734  0x02030734  arm
 *   func_02158DB0  0x02158DB0  thumb  ov010
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0215A514  0x0215A514  thumb  ov010
 *   func_02159130  0x02159130  thumb  ov010
 *   d_0217289C     0x0217289C  data  ov010  a1
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045808  0x02045808  arm
 *   func_0215A554  0x0215A554  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj00105.h"
#include "../../matched/include/Obj17628.h"
#include "../../matched/include/Obj17629.h"
#include "../../matched/include/Obj17630.h"
#include "../../matched/include/Obj17631.h"
#include "../../matched/include/Obj17632.h"
#include "../../matched/include/Obj17633.h"
#include "../../matched/include/Obj17634.h"
#include "../../matched/include/Obj18753.h"
#include "../../matched/include/Obj17635.h"
#include "../../matched/include/Obj17636.h"

struct Ctx;
struct ScriptVm;
struct WordSet;
struct U16Vec;
typedef unsigned char u8;

struct Bits { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; };

typedef unsigned int   u32;

typedef unsigned short u16;

struct O {
    int f0; u16 f4; int f8; u16 fc; int f10, f14, f18[3];
    int f24;
    int f20, f28, f2c, f30, f34;
};

typedef signed short   s16;

extern void *func_0201210C(const struct Ctx *p);
extern u32 func_0215A5D4(void *p);
extern u32 func_0215A5D8(void *p);
extern int func_02158DBC(void);
extern void *func_02011324(struct ScriptVm *vm);
extern void *func_0215A5DC(void *a0);
extern void func_02011328(void *, int (*)(int, void *, void *, int), void *);
extern int func_02082A7C();
extern int func_02188C54();
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02158DB0(int);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_0215A514(int a, int heap);
extern void func_02159130(void);
extern int func_0201ED04();
extern int func_02045808();
extern int func_0215A554();
extern int func_020307B0();
int func_02158DE8(int a, int b, int c, int idx);
void func_02158E38(void *a);
int func_02158E54(int a0, int a1);
int *func_02158E7C(u16 a, int b, int c, int d, int e, int f);
int func_02158F18(int a0);
void *func_02158F50(void *p);
void *func_02158F54(void *p);
int func_02158F58(int a0);
u32 func_02158F6C(void *p);
void *func_02158F74(void *p);
u32 func_02158F78(u8 *p);
u32 func_02158F7C(u8 *p);
void func_02158F80(u8 *p, u32 v);
u32 func_02158F84(u8 *p);
u8 *func_02158F88(void *p);
u16 func_02158F8C(u8 *p);
void *func_02158F90(void *p);
extern struct Bits d_02170374[];
extern char d_0217289C[];


int func_02158DE8(int a, int b, int c, int idx)
{
    int m, r;
    func_0201210C((void *)c);
    func_0215A5D4((void *)b);
    m = func_0215A5D8((void *)b);
    r = 0;
    switch (m) {
    case 0: r = d_02170374[idx].b0; break;
    case 1: r = d_02170374[idx].b1; break;
    case 2: r = d_02170374[idx].b2; break;
    }
    if (r == 0)
        func_02158DBC();
    return r;
}

/*
 * ARM9 interface evidence: 02011324 reads +0x20; 02011328 stores r1/r2 at +0x24/+0x28.
 */
void func_02158E38(void *a) {
    void *b = func_0215A5DC(func_02011324(a));
    func_02011328(a, (int (*)(int,  void *, void *, int))func_02158DE8, b);
}


int func_02158E54(int a0, int a1)
{
    int a2;
    void *t4;
    int t5;

t5 = a0 + 0;
a0 = a1 + 0;
    t4 = func_0201210C((const struct Ctx *)a0);
loc_02158E5E:
a0 = 0;
a1 = t5 + 0;
a2 = 8;
    a0 = func_02082A7C(a0, a1, a2);
loc_02158E6A:
((struct Obj00020 *)t5)->f4 = t4;
    if (t4 == 0) goto loc_02158E78;
loc_02158E70:
a0 = (int)t4 + 0; /* int-typed on purpose: pointer local changes codegen */
    a0 = func_02188C54(a0);
loc_02158E76:
((struct Obj00020 *)((char *)t5))->f0 = a0;
loc_02158E78:
    return a0;}


int *func_02158E7C(u16 a, int b, int c, int d, int e, int f)
{
    int *p = func_02030734(a, 0x14C, 1, d_0217289C, 0xAF);
    p[0] = 0x3643F;
    *(u16 *)(p + 3) = a;
    p[4] = b;
    p[5] = c;
    ((struct Obj00105 *)p)->f4 = d;
    p[2] = 0;
    p[8] = e;
    p[10] = f;
    p[9] = func_02158DB0(f);
    if (p[9] == 0) {
        p[11] = (int)func_0201EC74(0x1C, 0x40, a);
        p[12] = (int)func_020457B0(0x500, a);
        p[13] = (int)func_020457B0(0x500, a);
    } else {
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
    }
    p[0x52] = (int)func_0215A514((int)p, a);
    func_02158E54((int)(p + 6), b);
    if (p[9] == 0)
        func_02159130();
    return p;
}


int func_02158F18(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = 0;
*(int *)((char *)t4) = a0;
a0 = ((struct Obj00105 *)t4)->f2C;
    if (a0 == 0) goto loc_02158F2A;
loc_02158F26:
    a0 = func_0201ED04(a0);
loc_02158F2A:
a0 = ((struct Obj00105 *)t4)->f30;
    if (a0 == 0) goto loc_02158F34;
loc_02158F30:
    a0 = func_02045808(a0);
loc_02158F34:
a0 = ((struct Obj00105 *)t4)->f34;
    if (a0 == 0) goto loc_02158F3E;
loc_02158F3A:
    a0 = func_02045808(a0);
loc_02158F3E:
a0 = 0x52;
a0 = a0 << 2;
a0 = *(int *)((char *)t4 + a0);
    a0 = func_0215A554(a0);
loc_02158F48:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_02158F4E:
    return a0;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F50.c \
 *       --func func_02158F50 --addr 0x02158F50 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158F50(void *p) { return ((struct Obj17628 *)p)->f14; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F54.c \
 *       --func func_02158F54 --addr 0x02158F54 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158F54(void *p) { return ((struct Obj17629 *)p)->f10; }


int func_02158F58(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
a1 = ((struct Obj17630 *)t4)->f10;
a0 = a0 + 0x18;
    a0 = func_02158E54(a0, a1);
loc_02158F64:
t4 = t4 + 0x18;
a0 = t4 + 0;
    return a0;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F6C.c \
 *       --func func_02158F6C --addr 0x02158F6C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02158F6C(void *p) { return ((struct Obj17631 *)p)->f148; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158F74.c \
 *       --func func_02158F74 --addr 0x02158F74 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_02158F74(void *p) { return ((struct Obj00020 *)p)->f2C; }



/*
 * Reads the word field at +0x30.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02158F78(u8 *p)
{
    return ((struct Obj17632 *)p)->f30;
}



/*
 * Reads the word field at +0x34.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02158F7C(u8 *p)
{
    return ((struct Obj17633 *)p)->f34;
}



/*
 * Stores the word field at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void func_02158F80(u8 *p, u32 v)
{
    ((struct Obj17634 *)p)->f38 = v;
}


u32 func_02158F84(u8 *p)
{
    return ((struct Obj18753 *)p)->f38;
}


/*
 * Unlabelled leaf, blocker of ov021 func_021AF1E8..func_021AF26C: address of the field at +0x40.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02158F88(void *p)
{
    return (u8 *)p + 0x40;
}



/*
 * Reads the halfword field at +0x4.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02158F8C(u8 *p)
{
    return ((struct Obj17635 *)p)->f4;
}



/*
 * Reads the word field at +0x8.
 *
 * Addresses are Black-image addresses.
 */
void *func_02158F90(void *p)
{
    return ((struct Obj17636 *)p)->f8;
}
