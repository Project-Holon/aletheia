/*
 * file:     field_place_name_p05.c
 * unit:     yes
 * function: func_021BD1EC, func_021BD1F4, func_021BD1FC, func_021BD204, func_021BD20C, func_021BD214, func_021BD22C, func_021BD234, func_021BD250, func_021BD264, func_021BD278, func_021BD2A4, func_021BD2B8, func_021BD2BC, func_021BD2C0, func_021BD2C4, func_021BD2C8, func_021BD2D0, func_021BD2D8, func_021BD2DC, func_021BD2E8, func_021BD2F4, func_021BD2FC, func_021BD304, func_021BD308, func_021BD30C, func_021BD340, func_021BD36C, func_021BD394, func_021BD3BC, func_021BD3EC
 * address:  0x021BD1EC
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
 *   d_021DE368     0x021DE368  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_020437AC  0x020437AC  arm
 *   func_0209C494  0x0209C494  arm
 *   func_021BD604  0x021BD604  thumb  ov021
 *   func_021BD430  0x021BD430  thumb  ov021
 *   func_021BD5D4  0x021BD5D4  thumb  ov021
 *   func_021BD47C  0x021BD47C  thumb  ov021
 *   _fdiv          0x0209CE10  arm
 *   _fadd          0x0209C95C  arm
 */
#include "../../matched/include/Obj06054.h"
#include "../../matched/include/Obj18217.h"
#include "../../matched/include/Obj18218.h"
#include "../../matched/include/Obj18219.h"
#include "../../matched/include/Obj18220.h"
#include "../../matched/include/Obj18221.h"
#include "../../matched/include/Obj18222.h"
#include "../../matched/include/Obj18223.h"
#include "../../matched/include/Obj18226.h"
#include "../../matched/include/Obj18227.h"
#include "../../matched/include/Obj18228.h"

struct Bmp;
struct Obj020437AC;
struct Grid;
struct Param;
struct Sys;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    char pad[0x44];
    int f44;
    u16 h48;
} Obj_021BD234;

typedef struct {
    u16 h0;
    char pad[6];
    void *f8;
} Obj_021BD250;

typedef signed int     s32;

typedef struct {
    void *f0;
    u16 h4;
    u16 h6;
    int f8;
    int fC;
    u8 b10;
    u8 b11;
    u16 h12;
    int f14;
} Desc;

typedef struct {
    char pad[8];
    void *f8;
    void *fC;
} Obj_021BD278;

typedef struct {
    char pad[0xC];
    void *fC;
} Obj_021BD2A4;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    char pad[0x28];
    int f;
} Inner_021BD36C;

typedef struct {
    char pad[0x2C];
    int f;
} Inner_021BD394;

typedef struct {
    float f00;
    char pad04[4];
    float f08;
    char pad0c[4];
    float f10;
    char pad14[4];
    float f18;
    char pad1c[0xc];
    int f28;
} T;

typedef struct {
    char pad00[0x10];
    T t;
} S;

extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *p, int v, int n);
extern u16 func_02045A98(void);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(struct Obj020437AC *p);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_0202570C(struct Grid *g);
extern void func_0209C494(u32 v);
extern void func_021BD604(void *a, void *b, void *c, void *d, void *e);
extern void func_021BD430(void *p);
typedef struct {
    char pad[0xC];
    void *fC;
} Obj_021BD5D4;

extern void func_021BD5D4(Obj_021BD5D4 *p);
extern void func_021BD47C(u8 *p);
int func_021BD1EC(u8 *a0);
int func_021BD1F4(u8 *a0);
void func_021BD1FC(u32 *a0);
void func_021BD204(u32 *a0);
unsigned int func_021BD20C(char *p);
void *func_021BD214(int a);
u32 func_021BD22C(void *a0);
void func_021BD234(Obj_021BD234 *p);
void func_021BD250(Obj_021BD250 *p);
void func_021BD264(u8 *p);
void func_021BD278(Obj_021BD278 *p, int a, u16 b, int c);
void func_021BD2A4(Obj_021BD2A4 *p);
u16 func_021BD2B8(u8 *p);
void func_021BD2BC(u8 *p, int v);
u32 func_021BD2C0(u8 *p);
void func_021BD2C4(u8 *p, u32 v);
u16 func_021BD2C8(u8 *p);
void func_021BD2D0(u8 *p, u16 v);
u32 func_021BD2D8(u8 *p);
void func_021BD2DC(u32 *p);
void func_021BD2E8(u32 *p);
u8 func_021BD2F4(u8 *p);
u8 func_021BD2FC(u8 *p);
u8 *func_021BD304(u8 *p);
int func_021BD308(u8 *p);
void func_021BD30C(char *p);
int func_021BD340(void *a);
int func_021BD36C(void *p);
int func_021BD394(void *p);
void func_021BD3BC(void *p);
void func_021BD3EC(S *p);
extern int d_021DE368;






int func_021BD1EC(u8 *a0)
{
    return func_021BD2F4(a0);
}






/*
 * Tail-call thunk: forwards to func_021BD2FC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021BD1F4(u8 *a0)
{
    return func_021BD2FC(a0);
}






/*
 * Tail-call thunk: forwards to func_021BD2DC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD1FC(u32 *a0)
{
    func_021BD2DC(a0);
}






/*
 * Tail-call thunk: forwards to func_021BD2E8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD204(u32 *a0)
{
    func_021BD2E8(a0);
}






/*
 * Unlabelled leaf: tail call to func_021BD2D8 (loads +0x44).
 */
unsigned int func_021BD20C(char *p)
{
    return func_021BD2D8((u8 *)p);
}






void *func_021BD214(int a)
{
    return func_02030734(a, 0x4C, 0, (const char *)&d_021DE368, 0x170);
}






/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD22C(void *a0)
{
    return func_020307B0(a0);
}






void func_021BD234(Obj_021BD234 *p)
{
    func_02082BCC(p, 0, 0x4C);
    p->f44 = 0;
    p->h48 = func_02045A98();
}






void func_021BD250(Obj_021BD250 *p)
{
    p->f8 = func_02043678(2, 2, 0x20, p->h0);
}






void func_021BD264(u8 *p)
{
    u32 v = ((struct Obj06054 *)p)->f8;
    if (v != 0) {
        func_020437AC((struct Obj020437AC *)v);
        ((struct Obj06054 *)p)->f8 = 0;
    }
}






void func_021BD278(Obj_021BD278 *p, int a, u16 b, int c)
{
    Desc d;

    d.f0 = p->f8;
    d.h4 = 0;
    d.h6 = 0;
    d.f8 = c;
    d.fC = 0;
    d.b10 = 0;
    d.b11 = 0;
    d.h12 = b;
    d.f14 = 0;
    p->fC = func_020255A0((struct Sys *)a, (const struct Param *)(&d));
}






void func_021BD2A4(Obj_021BD2A4 *p)
{
    if (p->fC != 0) {
        func_0202570C(p->fC);
        p->fC = 0;
    }
}






/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021BD2B8(u8 *p)
{
    return ((struct Obj18217 *)p)->f0;
}






/*
 * Field setter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD2BC(u8 *p, int v)
{
    ((struct Obj18218 *)p)->f0 = v;
}






/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021BD2C0(u8 *p)
{
    return ((struct Obj18219 *)p)->f4;
}






void func_021BD2C4(u8 *p, u32 v)
{
    ((struct Obj18220 *)p)->f4 = v;
}






/*
 * Loads the halfword at byte +0x48 of the object.
 */
u16 func_021BD2C8(u8 *p)
{
    return ((struct Obj18221 *)p)->f48;
}






/*
 * Field setter at +0x48 through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD2D0(u8 *p, u16 v)
{
    ((struct Obj18222 *)p)->f48 = v;
}






/*
 * Loads the 32-bit word at byte +0x44 of the object.
 */
u32 func_021BD2D8(u8 *p)
{
    return ((struct Obj18223 *)p)->f44;
}






/*
 * Unlabelled tail-call thunk on the word at +0x10; callee of func_021BD1FC.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD2DC(u32 *p)
{
    func_0209C494(p[4]);
}






/*
 * Unlabelled tail-call thunk on the word at +0x14; callee of func_021BD204.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD2E8(u32 *p)
{
    func_0209C494(p[5]);
}






u8 func_021BD2F4(u8 *p)
{
    return ((struct Obj18226 *)p)->f40;
}






/*
 * Unlabelled leaf byte getter at +0x41.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021BD2FC(u8 *p)
{
    return ((struct Obj18227 *)p)->f41;
}






/*
 * Returns the object pointer advanced by 0x10 bytes.
 */
u8 *func_021BD304(u8 *p)
{
    return p + 0x10;
}






int func_021BD308(u8 *p)
{
    return ((struct Obj18228 *)p)->f8;
}






void func_021BD30C(char *p)
{
    void *a;
    void *b;

    a = (void *)func_021BD2C0((u8 *)p);
    b = (void *)func_021BD2C8((u8 *)p);
    func_021BD604(a, b, (void *)func_021BD2B8((u8 *)p), p + 0x40, p + 0x41);
}





int func_021BD340(void *a)
{
if (func_021BD2D8((u8 *)a) == 0) {
    return 1;
}
if (func_021BD36C((void *)a) != 0) {
    if (func_021BD394((void *)a) != 0) {
        return 1;
    }
}
return 0;
}





int func_021BD36C(void *p)
{
    Inner_021BD36C *q = (Inner_021BD36C *)func_021BD304(p);

    if (func_021BD2D8(p) == 0) {
        return 1;
    }
    if (q->f <= 0) {
        return 1;
    }
    return 0;
}





int func_021BD394(void *p)
{
    Inner_021BD394 *q = (Inner_021BD394 *)func_021BD304(p);

    if (func_021BD2D8(p) == 0) {
        return 1;
    }
    if (q->f <= 0) {
        return 1;
    }
    return 0;
}



void func_021BD3BC(void *p)
{
    if (func_021BD2D8(p)) {
        func_021BD3EC(p);
        func_021BD430(p);
        func_021BD5D4((Obj_021BD5D4 *)p);
        if (func_021BD340(p) == 1) {
            func_021BD47C(p);
        }
    }
}


void func_021BD3EC(S *p)
{
    T *q;

    if (func_021BD36C(p) == 1) {
        return;
    }
    q = &p->t;
    p->t.f00 = p->t.f00 + (q->f08 + q->f10 / 2.0f);
    q->f08 = q->f08 + q->f10;
    q->f28 = q->f28 - 1;
    if (q->f28 == 0) {
        q->f00 = q->f18;
    }
}
