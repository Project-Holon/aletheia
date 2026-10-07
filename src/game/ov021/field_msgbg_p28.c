/*
 * file:     field_msgbg_p28.c
 * unit:     yes
 * function: func_0218C88C, func_0218C89C, func_0218C8B0, func_0218C8D8, func_0218C8FC, func_0218C910, func_0218C924, func_0218C934, func_0218C944, func_0218C990, func_0218C9A4, func_0218C9C4, func_0218C9E8, func_0218CA4C
 * address:  0x0218C88C
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
 *   func_0218C3B0  0x0218C3B0  thumb  ov021
 *   func_0218C43C  0x0218C43C  thumb  ov021
 *   func_02047A60  0x02047A60  arm
 *   d_021D3D88     0x021D3D88  data   a2
 *   d_021D3D8A     0x021D3D8A  data   a2
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DD9EC     0x021DD9EC  data  ov021  a4
 *   func_0218B754  0x0218B754  thumb
 *   func_021938AC  0x021938AC  thumb ov021
 *   func_021C05D4  0x021C05D4  thumb ov021
 *   func_021C0674  0x021C0674  thumb  ov021
 *   func_0218D05C  0x0218D05C  thumb  ov021
 *   func_021938D4  0x021938D4  thumb  ov021
 *   func_0218B7F8  0x0218B7F8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj19538.h"
#include "../../matched/include/Obj19539.h"
#include "../../matched/include/Obj19540.h"
#include "../../matched/include/Obj19541.h"
#include "../../matched/include/Obj19544.h"
#include "../../matched/include/Obj19545.h"
#include "../../matched/include/Obj01115.h"
#include "../../matched/include/Obj05856.h"

struct Arg;
typedef unsigned int   u32;

typedef struct { unsigned short a, b; } E;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
    int d;
} Rect;

typedef signed short   s16;

typedef signed char    s8;

void func_0218C3B0(unsigned char *p, int i, int c);
int func_0218C43C(u32 *st, int i);
void func_02047A60(void *a0, struct Arg *a1);
int func_02006148(u32 a0);
int func_02006224(u32 a0);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern int func_0218B754(int a, void *p, int b);
extern void *func_021938AC(u32 heap);
extern int func_021C05D4(int a, int b);
extern u32 func_020307B0(void *p);
extern void func_0218B7F8(char *p);
extern void func_0218D05C(char *p);
extern u32 func_021938D4(void *a);
extern void func_021C0674(void **p);
void func_0218C88C(unsigned char *p, int v, int c);
void func_0218C89C(unsigned char *p, int v);
int func_0218C8B0(void *p, int v);
int func_0218C8D8(void *p);
int func_0218C8FC(unsigned char *p, int i);
int func_0218C910(unsigned char *p);
unsigned short func_0218C924(unsigned char *p);
void func_0218C934(unsigned char *p);
int func_0218C944(void *p, u32 idx, u16 *out);
int func_0218C990(unsigned char *p, int v);
int func_0218C9A4(void *p);
void func_0218C9C4(Rect *out, int *__restrict pos);
char *func_0218C9E8(int heap, int b);
int func_0218CA4C(void *a);
extern u8 d_021D3D88[];
extern u8 d_021D3D8A[];
extern int d_021DD9EC;


void func_0218C88C(unsigned char *p, int v, int c)
{
    if (p != 0) {
        ((struct Obj19538 *)p)->f4 = v;
        func_0218C3B0(p + 0xC, v, c);
    }
}


void func_0218C89C(unsigned char *p, int v)
{
    if (p != 0)
        func_0218C3B0(p + 0xC, ((struct Obj19539 *)p)->f4, v);
}


int func_0218C8B0(void *p, int v)
{
    if (p == 0)
        return 1;
    if (func_0218C8FC(p, v) == 1) {
        func_0218C88C(p, v, 3);
        return 1;
    }
    return 0;
}


int func_0218C8D8(void *p)
{
    if (p == 0)
        return 1;
    if (func_0218C910(p) == 1) {
        func_0218C89C(p, 3);
        return 1;
    }
    return 0;
}


int func_0218C8FC(unsigned char *p, int i)
{
    if (p == 0)
        return 0;
    return func_0218C43C((u32 *)(p + 0xC), i);
}


int func_0218C910(unsigned char *p)
{
    if (p == 0)
        return 0;
    return func_0218C43C((u32 *)(p + 0xC), ((struct Obj19540 *)p)->f4);
}


unsigned short func_0218C924(unsigned char *p)
{
    if (p == 0)
        return 0;
    return (**(E ** *)&((struct Obj19541 *)p)->f10)->b;
}


void func_0218C934(unsigned char *p)
{
    if (p != 0)
        func_02047A60((void *)(((struct Obj19544 *)p)->fC), (struct Arg *)(p + 0x24));
}


/*
 * Looks up a 10-byte-stride table row by key and reads column idx.
 *
 * Addresses are Black-image addresses.
 */
int func_0218C944(void *p, u32 idx, u16 *out)
{
    u32 key;
    u32 j;

    if (p == 0)
        return 0;
    key = func_0218C924(p);
    *out = 0;
    if (idx >= 4)
        return 0;
    for (j = 0; j < 6; j++) {
        if (key == *(u16 *)(d_021D3D88 + j * 10)) {
            *out = *(u16 *)(d_021D3D8A + j * 10 + idx * 2);
            return 1;
        }
    }
    return 0;
}


int func_0218C990(unsigned char *p, int v)
{
    if (p == 0)
        return 0;
    return func_0218C944(p, ((struct Obj19545 *)p)->f4, (u16 *)v);
}


int func_0218C9A4(void *p)
{
    unsigned short v;
    if (func_0218C990(p, (int)(&v)) == 0)
        return 0;
    return func_02006224(func_02006148(v));
}


/*
 * `__restrict` on pos lets mwcc keep pos[2] in a register across the
 * out->a/out->b stores and sink the out->a store past the pos[0] load
 * (see docs/idioms/a-restrict-position-parameter-sinks-a-store-past-the-next-load.md).
 */
void func_0218C9C4(Rect *out, int *__restrict pos)
{
    out->a = pos[2] - 0x30000;
    out->b = pos[2] + 0x30000;
    out->c = pos[0] - 0x20000;
    out->d = pos[0] + 0x20000;
}


char *func_0218C9E8(int heap, int b)
{
    char *p = func_02030734(heap, 0x74, 1, (const char *)&d_021DD9EC, 0xf9);
    int z = 0;
    ((struct Obj01115 *)p)->f0 = heap;
    ((struct Obj01115 *)p)->f34 = z;
    ((struct Obj01115 *)p)->f38 = z;
    ((struct Obj01115 *)p)->f3C = z;
    ((struct Obj01115 *)p)->f14 = z;
    ((struct Obj01115 *)p)->f16 = z;
    ((struct Obj01115 *)p)->f18 = z;
    ((struct Obj01115 *)p)->f1C = z;
    ((struct Obj01115 *)p)->f4 = z;
    ((struct Obj01115 *)p)->f8 = z;
    ((struct Obj01115 *)p)->fC = 1;
    ((struct Obj01115 *)p)->f10 = -1;
    ((struct Obj01115 *)p)->f40 = z;
    ((struct Obj01115 *)p)->f68 = z;
    ((struct Obj01115 *)p)->f64 = func_0218B754(((struct Obj01115 *)p)->f0, p, b);
    ((struct Obj01115 *)p)->f6C = (int)func_021938AC(heap);
    ((struct Obj01115 *)p)->f70 = func_021C05D4(0x10, (u8)heap);
    return p;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218CA4C(void *a)
{
func_021C0674((void **)(((struct Obj05856 *)((u8 *)(a)))->f70));
func_0218D05C((char *)a);
func_021938D4((void *)(((struct Obj05856 *)((u8 *)(a)))->f6C));
if (((struct Obj05856 *)((u8 *)(a)))->f64 != 0) {
    func_0218B7F8((char *)(((struct Obj05856 *)((u8 *)(a)))->f64));
    ((struct Obj05856 *)((u8 *)(a)))->f64 = 0;
}
return func_020307B0(a);
}
