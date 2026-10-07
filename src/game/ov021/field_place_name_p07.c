/*
 * file:     field_place_name_p07.c
 * unit:     yes
 * function: func_021BC7B0, func_021BC7BC, func_021BC7D4, func_021BC7F8, func_021BC810, func_021BC824, func_021BC838, func_021BC848, func_021BC910, func_021BC92C, func_021BC948, func_021BC970, func_021BC998
 * address:  0x021BC7B0
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
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_021BD148  0x021BD148  thumb  ov021
 *   func_021BD184  0x021BD184  thumb  ov021
 *   func_021BD090  0x021BD090  thumb  ov021
 *   func_02049238  0x02049238  arm
 *   func_021BD134  0x021BD134  thumb  ov021
 *   func_021BD1EC  0x021BD1EC  thumb  ov021
 *   func_021BD19C  0x021BD19C  thumb  ov021
 *   func_02045A38  0x02045A38  arm
 *   sub_0201DC6C   0x0201DC6C  thumb
 *   d_021D9B88     0x021D9B88  data  a4
 *   _ffltu         0x0209BE04  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   func_021BD138  0x021BD138  thumb  ov021
 *   func_021BD1E4  0x021BD1E4  thumb  ov021
 *   func_021BD1D4  0x021BD1D4  thumb  ov021
 *   func_021BD1CC  0x021BD1CC  thumb  ov021
 */
#include "../../matched/include/Obj18191.h"
#include "../../matched/include/Obj00575.h"

struct Bank;
struct U16Vec;
struct Font;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    char pad[0x34];
    void *f34[1];
    void *f38;
} Obj_021BC7BC;

typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x1E];
    void *f2C;
    void *f30;
    char pad3[0x1C];
    void *f50[0x1E];
} Obj_021BC7D4;

typedef struct {
    char pad[0x50];
    void *f50[0x1E];
} Obj_021BC7F8;

typedef struct {
    char pad[0x10];
    void *f10;
} Obj_021BC810;

typedef signed int     s32;

typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    float x;
    float f14;
    float f18;
    float f1C;
    u32 f20;
    u16 ch;
    u16 pad;
} Params;

typedef struct {
    u8 pad0[0x18];
    u32 f18;
    u8 pad1C[0x50 - 0x1C];
    u32 f50[30];
    u32 fC8[32];
    u8 count;
    u8 pad149[2];
    u8 skip;
} Obj_021BC848;

typedef struct {
    char pad[0x148];
    u8 b148;
} Obj_021BC910;

typedef struct {
    char pad[0x50];
    void *f50[0x1E];
} Obj_021BC92C;

typedef struct {
    char pad[0xC8];
    void *fC8[0x20];
    char pad2[0x149 - 0xC8 - 0x80];
    u8 b149;
} Obj_021BC948;

typedef struct {
    char pad[0xC8];
    void *fC8[0x20];
} Obj_021BC970;

typedef struct {
    char pad[0x30];
    void *f30;
    void *f34;
} Obj_021BC998;

extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *func_021BD148(int a0, int a1, int a2, int a3);
extern void func_021BD184(void *a);
extern u16 func_021BD090(u8 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(u32 v);
extern u32 func_021BD134(u8 *p);
extern int func_021BD1EC(u8 *a0);
extern int func_021BD19C(u32 a, u32 b);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern u32 sub_0201DC6C(struct Font *p, u16 ch);
extern u8 func_021BD138(u8 *p);
extern void func_021BD1E4(void *a, unsigned int b);
extern void func_021BD1D4(void *a);
extern void func_021BD1CC(void *a);
extern void *func_02025538(unsigned int a0, void *a1);
void func_021BC7B0(u8 *p);
void func_021BC7BC(Obj_021BC7BC *p, int i);
void func_021BC7D4(Obj_021BC7D4 *p);
void func_021BC7F8(Obj_021BC7F8 *p);
void func_021BC810(Obj_021BC810 *p);
void func_021BC824(u8 *p);
void func_021BC838(char *p);
void func_021BC848(Obj_021BC848 *p);
int func_021BC910(Obj_021BC910 *p);
void func_021BC92C(Obj_021BC92C *p);
void func_021BC948(Obj_021BC948 *p);
void func_021BC970(Obj_021BC970 *p);
void func_021BC998(Obj_021BC998 *p);
extern const Params d_021D9B88;


/*
 * Tail-call thunk: the object's word at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC7B0(u8 *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj18191 *)p)->f34));
}


void func_021BC7BC(Obj_021BC7BC *p, int i)
{
    if (p->f38 != 0) {
        func_0204B258(p->f34[i], p->f38);
    }
}


void func_021BC7D4(Obj_021BC7D4 *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        p->f50[i] = func_021BD148(p->hC, (int)p->f30, 0, (int)p->f2C);
    }
}


void func_021BC7F8(Obj_021BC7F8 *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        func_021BD184(p->f50[i]);
    }
}


void func_021BC810(Obj_021BC810 *p)
{
    p->f10 = func_020490F4(0x54, func_021BD090((u8 *)p));
}


void func_021BC824(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f10;
    if (v != 0) {
        func_02049238(v);
        ((struct Obj00575 *)p)->f10 = 0;
    }
}

/*
 * Unlabelled leaf: clears bytes +0x148 and +0x14B.
 */
void func_021BC838(char *p)
{
    p[0x148] = 0;
    p[0x14b] = 0;
}


/*
 * The x accumulation is a compound add inside each if/else arm (the two arms
 * cross-jump into one shared `ldr x; _fadd; str x` tail), then `+= 1.0f`
 * after the join, which is why the original re-loads x it has just stored:
 * a single `x += w` after the if/else forwards the value instead.
 * The call argument is the assignment itself: `f(p->fC8[n] = v, &prm)`
 * gives the `str r0, [r2, r1]` with the fC8 base hoisted.
 */
void func_021BC848(Obj_021BC848 *p)
{
    int n;
    int i;
    u16 buf[32];
    Params prm;

    n = p->count;
    func_02045A38((struct U16Vec *)func_021BD134((u8 *)p), buf, 32);
    prm = d_021D9B88;
    prm.f20 = p->f18;
    prm.ch = buf[n];
    for (i = 0; i < n; i++) {
        if (p->fC8[i] == 0) {
            prm.x += sub_0201DC6C((struct Font *)p->f18, 0x20);
        } else {
            prm.x += func_021BD1EC((u8 *)p->fC8[i]);
        }
        prm.x += 1.0f;
    }
    if (prm.ch == 0x20) {
        p->fC8[n] = 0;
        p->skip++;
    } else {
        func_021BD19C(p->fC8[n] = p->f50[n - p->skip], (u32)(&prm));
    }
    p->count++;
}


int func_021BC910(Obj_021BC910 *p)
{
    if (func_021BD138((u8 *)p) <= p->b148) {
        return 1;
    }
    return 0;
}


void func_021BC92C(Obj_021BC92C *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        func_021BD1E4(p->f50[i], 0);
    }
}


void func_021BC948(Obj_021BC948 *p)
{
    u8 i = p->b149++;

    if (p->fC8[i] != 0) {
        func_021BD1D4(p->fC8[i]);
        func_021BD1E4(p->fC8[i], 1);
    }
}


void func_021BC970(Obj_021BC970 *p)
{
    int n = func_021BD138((u8 *)p);
    int i;

    for (i = 0; i < n; i++) {
        if (p->fC8[i] != 0) {
            func_021BD1CC(p->fC8[i]);
        }
    }
}


void func_021BC998(Obj_021BC998 *p)
{
    p->f30 = func_02025538(func_021BD090((u8 *)p), p->f34);
}
