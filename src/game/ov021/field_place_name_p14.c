/*
 * file:     field_place_name_p14.c
 * unit:     yes
 * function: func_021BD1EC, func_021BD1F4, func_021BD1FC, func_021BD204, func_021BD20C, func_021BD214, func_021BD22C, func_021BD234, func_021BD250, func_021BD264, func_021BD278, func_021BD2A4, func_021BD2B8
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
 *   func_021BD2F4  0x021BD2F4  thumb  ov021
 *   func_021BD2FC  0x021BD2FC  thumb  ov021
 *   func_021BD2DC  0x021BD2DC  thumb  ov021
 *   func_021BD2E8  0x021BD2E8  thumb  ov021
 *   func_021BD2D8  0x021BD2D8  thumb  ov021
 *   d_021DE368     0x021DE368  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_020437AC  0x020437AC  arm
 */
#include "../../matched/include/Obj06054.h"
#include "../../matched/include/Obj18217.h"

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

extern u8 func_021BD2F4(u8 *p);
extern u8 func_021BD2FC(u8 *p);
extern void func_021BD2DC(u32 *p);
extern void func_021BD2E8(u32 *p);
extern u32 func_021BD2D8(u8 *p);
extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *p, int v, int n);
extern u16 func_02045A98(void);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(struct Obj020437AC *p);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_0202570C(struct Grid *g);
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
