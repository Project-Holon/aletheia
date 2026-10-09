/*
 * file:     field_place_name_p04.c
 * unit:     yes
 * function: func_021BCF1C, func_021BCF20, func_021BCF24, func_021BCF88, func_021BCFA4, func_021BCFD8, func_021BCFE0, func_021BCFF0, func_021BD008, func_021BD01C, func_021BD040, func_021BD054, func_021BD068, func_021BD07C, func_021BD090, func_021BD094, func_021BD098, func_021BD09C, func_021BD0A0, func_021BD0A4, func_021BD0A8, func_021BD0B0, func_021BD0C0, func_021BD0C8, func_021BD0D0, func_021BD0E0, func_021BD0FC, func_021BD118, func_021BD120, func_021BD134, func_021BD138, func_021BD140, func_021BD148, func_021BD184, func_021BD19C, func_021BD1CC, func_021BD1D4, func_021BD1DC, func_021BD1E4
 * address:  0x021BCF1C
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
 *   func_0207D63C  0x0207D63C  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   _fsub          0x0209CB8C  arm
 *   _fadd          0x0209C95C  arm
 *   d_021DE354     0x021DE354  data  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02045808  0x02045808  arm
 *   func_02008998  0x02008998  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_020089A0  0x020089A0  thumb
 *   func_021BD214  0x021BD214  thumb  ov021
 *   func_021BD234  0x021BD234  thumb  ov021
 *   func_021BD2BC  0x021BD2BC  thumb  ov021
 *   func_021BD250  0x021BD250  thumb  ov021
 *   func_021BD278  0x021BD278  thumb  ov021
 *   func_021BD5F8  0x021BD5F8  thumb  ov021
 *   func_021BD2A4  0x021BD2A4  thumb  ov021
 *   func_021BD264  0x021BD264  thumb  ov021
 *   func_021BD22C  0x021BD22C  thumb  ov021
 *   func_021BD2C4  0x021BD2C4  thumb  ov021
 *   func_021BD2D0  0x021BD2D0  thumb  ov021
 *   func_021BD30C  0x021BD30C  thumb  ov021
 *   func_021BD57C  0x021BD57C  thumb  ov021
 *   func_021BD588  0x021BD588  thumb  ov021
 *   func_021BD554  0x021BD554  thumb  ov021
 *   func_021BD3BC  0x021BD3BC  thumb
 *   func_021BD474  0x021BD474  thumb
 *   func_021BD308  0x021BD308  thumb
 */
#include "../../matched/include/Obj20119.h"
#include "../../matched/include/Obj00575.h"
#include "../../matched/include/Obj18206.h"
#include "../../matched/include/Obj18207.h"
#include "../../matched/include/Obj18208.h"
#include "../../matched/include/Obj18209.h"
#include "../../matched/include/Obj20122.h"
#include "../../matched/include/Obj18210.h"
#include "../../matched/include/Obj20124.h"
#include "../../matched/include/Obj18211.h"
#include "../../matched/include/Obj18214.h"
#include "../../matched/include/Obj18215.h"
#include "../../matched/include/Obj12115.h"

struct Ctx;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Rec;
struct Descriptor;
struct Big;
struct Sub02008828Obj;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 f0; u32 f4; u32 pad8[8]; int f28; u32 pad2C[6]; u16 f44; u16 f46; u32 f48; u32 f4C; } X;

typedef unsigned char  u8;

typedef struct {
    char pad[8];
    void *f8;
} Obj_021BCFE0;

typedef struct {
    char pad[0x14];
    void *f14;
} Obj_021BCFF0;

typedef struct {
    char pad[0x1C];
    void *f1C;
} Obj_021BD008;

typedef struct {
    char pad[0x24];
    void *f24;
} Obj_021BD01C;

typedef struct {
    char pad[8];
    void *f8;
} Obj_021BD040;

typedef signed int     s32;

typedef struct {
    char pad[0x24];
    void *f24;
} Obj_021BD07C;

typedef struct {
    char pad[0xC];
    u16 hC;
} Obj_021BD098;

typedef struct {
    char pad[0x3C];
    int f3C;
} Obj_021BD0A0;

typedef struct {
    char pad[0x42];
    u16 h42;
} Obj_021BD0B0;

typedef struct {
    char pad[0x40];
    u8 b40;
} Obj_021BD0D0;

typedef struct {
    void *f0;
    char pad[0x42];
    u16 h46;
} Obj_021BD0E0;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    char pad[0x44];
    u16 h44;
    u16 h46;
} Obj;

extern void func_0207D63C(int, int, int, int, int);
extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
extern void func_02082BCC(void *, int, int);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_020307B0(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 func_02008998(const struct Sub02008828Obj *obj);
extern u32 func_020089A0(u32, u32);
extern u32 func_02013E6C(u32 id);
extern void *func_021BD214(int a);
typedef struct {
    char pad[0x44];
    int f44;
    u16 h48;
} Obj_021BD234;

extern void func_021BD234(Obj_021BD234 *p);
extern void func_021BD2BC(u8 *p, int v);
typedef struct {
    u16 h0;
    char pad[6];
    void *f8;
} Obj_021BD250;

extern void func_021BD250(Obj_021BD250 *p);
extern void func_021BD278(void *p, int a, int b, int c);
extern void func_021BD5F8(void *p, unsigned int a);
extern u32 func_021BD22C(void *a0);
extern void func_021BD264(u8 *p);
extern u32 func_021BD2A4(u32, u32, u32, u32);
extern void func_021BD2C4(u8 *p, u32 v);
extern void func_021BD2D0(u8 *p, u16 v);
extern void func_021BD30C(char *p);
extern u32 func_021BD554(u32, u32);
extern void func_021BD57C(u8 *p);
extern void func_021BD588(u32 *p);
extern void func_021BD3BC(void *p);
extern void func_021BD474();
extern int func_021BD308(u8 *p);
void func_021BCF1C(int a);
void func_021BCF20(int a);
void func_021BCF24(char *p);
void *func_021BCF88(int a);
void func_021BCFA4(X *x, u32 b);
void func_021BCFD8(int a);
void func_021BCFE0(Obj_021BCFE0 *p);
void func_021BCFF0(Obj_021BCFF0 *p);
void func_021BD008(Obj_021BD008 *p);
void func_021BD01C(Obj_021BD01C *p);
void func_021BD040(Obj_021BD040 *p);
void func_021BD054(u8 *p);
void func_021BD068(u8 *p);
void func_021BD07C(Obj_021BD07C *p);
u16 func_021BD090(u8 *p);
u32 func_021BD094(u8 *p);
void func_021BD098(Obj_021BD098 *p, u16 v);
void func_021BD09C(u8 *p, u32 v);
void func_021BD0A0(Obj_021BD0A0 *p, int v);
u32 func_021BD0A4(u8 *p);
void func_021BD0A8(char *p);
void func_021BD0B0(Obj_021BD0B0 *p);
u8 func_021BD0C0(u8 *p);
void func_021BD0C8(char *p);
void func_021BD0D0(Obj_021BD0D0 *p);
void func_021BD0E0(Obj_021BD0E0 *p);
int func_021BD0FC(u32 a);
u16 func_021BD118(u8 *p);
void func_021BD120(Obj *p, u16 v);
u32 func_021BD134(u8 *p);
u8 func_021BD138(u8 *p);
void func_021BD140(void *a, int b, int c);
void *func_021BD148(int a0, int a1, int a2, int a3);
int func_021BD184(void *a, u32 b, u32 c, u32 d);
int func_021BD19C(u32 a, u32 b);
void func_021BD1CC(void *a);
void func_021BD1D4(void *a);
int func_021BD1DC(u8 *a0);
void func_021BD1E4(void *p, unsigned int a);
extern int d_021DE354;


/*
 * Unlabelled leaf (bx lr stub) filed as the blocker of func_021BC4F0.
 */
void func_021BCF1C(int a)
{
}


void func_021BCF20(int a)
{
}



void func_021BCF24(char *p)
{
    float t;
    int a;

    t = (float)(u32)((struct Obj20119 *)p)->f42 / 20.0f;
    a = (int)(16.0f * (1.0f - t));
    func_0207D63C(0x04000050, 8, 0x11, a, (int)(4.0f + 12.0f * t));
}



void *func_021BCF88(int a)
{
    return func_02030734(a, 0x154, 1, (const char *)&d_021DE354, 0x73C);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BCFA4(X *x, u32 b)
{
    func_02082BCC(x, 0, 0x154);
    x->f0 = b;
    x->f4 = (u32)func_020120F4((const struct Ctx *)b);
    x->f28 = -1;
    x->f4C = 0;
    x->f48 = 0;
    x->f44 = 0x1AB;
    x->f46 = 0x1AB;
}



/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BCFD8(int a)
{
    func_020307B0((void *)a);
}



void func_021BCFE0(Obj_021BCFE0 *p)
{
    p->f8 = func_0201EC64(func_021BD090((u8 *)p));
}



void func_021BCFF0(Obj_021BCFF0 *p)
{
    p->f14 = func_02045B38(0, 2, 0x59, func_021BD090((u8 *)p));
}



void func_021BD008(Obj_021BD008 *p)
{
    p->f1C = func_020457B0(0x21, func_021BD090((u8 *)p));
}



void func_021BD01C(Obj_021BD01C *p)
{
    func_021BD090((unsigned char *)p);
    p->f24 = (void *)func_020450F0(3, 0, 1, 0x20, 2, 0, 0);
}



void func_021BD040(Obj_021BD040 *p)
{
    if (p->f8 != 0) {
        func_0201ED04(p->f8);
        p->f8 = 0;
    }
}



/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD054(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f14;
    if (v != 0) {
        func_02045C04((struct Rec *)v);
        ((struct Obj00575 *)p)->f14 = 0;
    }
}



void func_021BD068(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f1C;
    if (v != 0) {
        func_02045808((struct U16Vec *)v);
        ((struct Obj00575 *)p)->f1C = 0;
    }
}



void func_021BD07C(Obj_021BD07C *p)
{
    if (p->f24 != 0) {
        func_020452E8(p->f24);
        p->f24 = 0;
    }
}



/*
 * Loads the 16-bit halfword at +0xc of the object.
 */
u16 func_021BD090(u8 *p)
{
    return ((struct Obj18206 *)p)->fC;
}



u32 func_021BD094(u8 *p)
{
    return ((struct Obj18207 *)p)->f10;
}



void func_021BD098(Obj_021BD098 *p, u16 v)
{
    p->hC = v;
}



/*
 * Field setter at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD09C(u8 *p, u32 v)
{
    ((struct Obj18208 *)p)->f18 = v;
}



void func_021BD0A0(Obj_021BD0A0 *p, int v)
{
    p->f3C = v;
}



u32 func_021BD0A4(u8 *p)
{
    return ((struct Obj18209 *)p)->f3C;
}



void func_021BD0A8(char *p)
{
    ((struct Obj20122 *)p)->f42 = 0;
}



void func_021BD0B0(Obj_021BD0B0 *p)
{
    p->h42++;
}



u8 func_021BD0C0(u8 *p)
{
    return ((struct Obj18210 *)p)->f40;
}



void func_021BD0C8(char *p)
{
    ((struct Obj20124 *)p)->f40 = 0;
}



void func_021BD0D0(Obj_021BD0D0 *p)
{
    p->b40++;
}



void func_021BD0E0(Obj_021BD0E0 *p)
{
    p->h46 = func_02008998(func_02008854(func_02012EBC(func_020120F4(p->f0))));
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BD0FC(u32 a)
{
return func_020089A0((u32)func_02008854(func_02012EBC(func_020120F4((const struct Ctx *)(((struct Obj00575 *)((u8 *)(a)))->f0)))), *(u16 *)((u8 *)((a + 70))));
}



u16 func_021BD118(u8 *p)
{
    return ((struct Obj18211 *)p)->f46;
}



void func_021BD120(Obj *p, u16 v)
{
    p->h44 = p->h46;
    p->h46 = v;
}



u32 func_021BD134(u8 *p)
{
    return ((struct Obj18214 *)p)->f1C;
}



/*
 * Loads the byte at byte +0x20 of the object.
 */
u8 func_021BD138(u8 *p)
{
    return ((struct Obj18215 *)p)->f20;
}



void func_021BD140(void *a, int b, int c)
{
    func_02013E6C((u32)a);
}



void *func_021BD148(int a0, int a1, int a2, int a3)
{
    void *p = func_021BD214(a0);
    func_021BD234((Obj_021BD234 *)p);
    func_021BD2BC(p, a0);
    func_021BD250((Obj_021BD250 *)p);
    func_021BD278(p, a1, a2, a3);
    func_021BD5F8(p, 0);
    return p;
}



int func_021BD184(void *a, u32 b, u32 c, u32 d)
{
func_021BD2A4((u32)a, b, c, d);
func_021BD264((u8 *)a);
return func_021BD22C(a);
}



int func_021BD19C(u32 a, u32 b)
{
func_021BD2C4((u8 *)a, ((struct Obj12115 *)((u8 *)(b)))->f20);
func_021BD2D0((u8 *)a, ((struct Obj12115 *)((u8 *)(b)))->f24);
func_021BD30C((char *)a);
func_021BD57C((u8 *)a);
func_021BD588((u32 *)a);
return func_021BD554(a, b);
}



/*
 * Tail-call thunk: forwards to func_021BD3BC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD1CC(void *a)
{
    func_021BD3BC(a);
}



void func_021BD1D4(void *a)
{
    func_021BD474();
}



/*
 * Tail-call thunk: forwards to func_021BD308 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021BD1DC(u8 *a0)
{
    return func_021BD308(a0);
}



/*
 * Tail-call thunk: forwards to func_021BD5F8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD1E4(void *p, unsigned int a)
{
func_021BD5F8(p, a);
}
