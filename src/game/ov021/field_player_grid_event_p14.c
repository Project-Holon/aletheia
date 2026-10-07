/*
 * file:     field_player_grid_event_p14.c
 * unit:     yes
 * function: func_021C0628, func_021C0674, func_021C0688, func_021C068C, func_021C06A8, func_021C06B4, func_021C06C0
 * address:  0x021C0628
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
 *   func_021C0598  0x021C0598  thumb  ov021
 */
#include "../../matched/include/Obj18267.h"
#include "../../matched/include/Obj18268.h"
#include "../../matched/include/Obj18269.h"
#include "../../matched/include/Obj18270.h"

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int used;
    int f18;
} Slot;

typedef struct {
    int n;
    Slot *e;
} SlotTable;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    int pad[4];
    int v;
    int pad2[2];
} E;

extern u32 func_020307B0(void *p);
extern u32 func_021C0598(u32, u32, u32, u32);
void func_021C0628(int i, int a, int b, int c, int d, int e, int f, SlotTable *t);
void func_021C0674(void **p);
u32 func_021C0688(u8 *p);
int func_021C068C(int a, int b, int c, u8 d);
int func_021C06A8(u8 a, int b);
int func_021C06B4(u8 a, int b);
void func_021C06C0(u8 i, int v, int *p);


/*
 * Unlabelled leaf of ov043 func_021F36C0: fills slot i of a table of
 * 0x1C-byte entries when it is in range and not yet in use.
 */
void func_021C0628(int i, int a, int b, int c, int d, int e, int f, SlotTable *t)
{
    if (i < t->n && t->e[i].used == 0) {
        t->e[i].f0 = a;
        t->e[i].f4 = b;
        t->e[i].f8 = c;
        t->e[i].fc = d;
        t->e[i].f10 = e;
        t->e[i].f18 = f;
        t->e[i].used = 1;
    }
}


/*
 * Frees the sub-object at +4, then the object (EXACT*: trailing pad).
 */
void func_021C0674(void **p)
{
    func_020307B0(p[1]);
    func_020307B0(p);
}


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0688(u8 *p)
{
    return ((struct Obj18267 *)p)->f0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C068C(int a, int b, int c, u8 d)
{
if (func_021C0598(a, b, (((struct Obj18268 *)((u8 *)(c)))->f4 + (d * 28)), d) != 0) {
    return 1;
}
return 0;
}


int func_021C06A8(u8 a, int b)
{
return *(u32 *)((u8 *)((((struct Obj18269 *)((u8 *)(b)))->f4 + (a * 28))) + 16);
}


int func_021C06B4(u8 a, int b)
{
return *(u32 *)((u8 *)((((struct Obj18270 *)((u8 *)(b)))->f4 + (a * 28))) + 24);
}


/*
 * Unlabelled leaf; called from ov043 func_021F3AC0.
 */
void func_021C06C0(u8 i, int v, int *p)
{
    ((E *)p[1])[i].v = v;
}
