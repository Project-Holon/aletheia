/*
 * file:     field_flash_p05.c
 * unit:     yes
 * function: func_021C72AC, func_021C72F8, func_021C734C, func_021C73B4, func_021C7418
 * address:  0x021C72AC
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021C7500  0x021C7500  thumb  ov021
 *   d_021DAAC0  0x021DAAC0  data  ov021  a2
 *   _fmul  0x0209C77C  arm
 *   _fdiv  0x0209CE10  arm
 *   _ffix  0x0209C494  arm
 *   d_021DAAB8  0x021DAAB8  data  ov021  a2
 *   d_021DAAC8     0x021DAAC8  data  ov021  a2
 *   func_0209C5E0  0x0209C5E0  arm
 *   _f2d           0x0209BD38  arm
 *   _d2f           0x0209B64C  arm
 *   _ffltu         0x0209BE04  arm
 *   func_0216D410  0x0216D410  thumb  ov010
 */
#include "../../matched/include/Obj05089.h"

struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u16 v[4]; } T4;

typedef struct {
    u32 w0;
    u32 w4;
    u16 h8;
    u16 ha;
    u8  bc;
    u8  pad;
    u16 he;
} Ctl;

extern u16 func_02188C84(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern void *func_021C6C70(u32 h, int size, void *fn);
extern u32 func_021C6CCC(u8 *p);
extern void func_021C7500(void);
extern double func_0209C5E0(double x);
extern void func_0216D410(u32 a, int b);
void *func_021C72AC(u32 a, u16 b, int c, int d);
u16 func_021C72F8(float a, float b, float c);
u16 func_021C734C(float a, float b, float c);
u16 func_021C73B4(float a, float b, float c);
int func_021C7418(Ctl *o);
extern T4 d_021DAAC0;
extern T4 d_021DAAB8;
extern T4 d_021DAAC8;


void *func_021C72AC(u32 a, u16 b, int c, int d)
{
    void *o;
    u8 *p;
    u32 h;
    void *q;

    h = func_02188C84((u8 *)a);
    q = func_02188CB4((void *)a);
    o = func_021C6C70(h, 0x10, (void *)func_021C7500);
    p = (u8 *)func_021C6CCC(o);
    ((struct Obj05089 *)p)->f0 = a;
    ((struct Obj05089 *)p)->f4 = func_021A3074((void *)q);
    ((struct Obj05089 *)p)->f8 = 0;
    ((struct Obj05089 *)p)->fA = b;
    p[0xc] = c;
    ((struct Obj05089 *)p)->fE = d;
    return o;
}


/*
 * Picks one of four halfwords from a table by (int)(4*c/b*a) % 4, in soft float.
 * The last multiply keeps its operand order only through a named float local;
 * inline it and the compiler swaps to a * f.
 */
u16 func_021C72F8(float a, float b, float c)
{
    T4 t = d_021DAAC0;
    float f = 4.0f * c / b;
    int n = (int)(f * a);

    return t.v[n % 4];
}


u16 func_021C734C(float a, float b, float c)
{
    T4 t = d_021DAAB8;
    float f = 4.0f * c / (b * b);
    float g = f * a;
    int n = (int)(a * g);

    return t.v[n % 4];
}


u16 func_021C73B4(float a, float b, float c)
{
    T4 t = d_021DAAC8;
    float x = 4.0f * c;
    float f = x * x / b;
    int n = (int)(float)func_0209C5E0((double)(f * a));

    return t.v[n % 4];
}


int func_021C7418(Ctl *o)
{
    u32 s;
    int k;

    s = o->w4;
    func_0216D410(s,func_021C72F8((float)(u32)o->h8, (float)(u32)o->ha, (float)(u32)o->bc));
    o->h8 = o->h8 + 1;
    if (o->ha < o->h8) {
        switch (o->he) {
        default:
        case 0: k = 0; break;
        case 1: k = 1; break;
        case 2: k = 2; break;
        case 3: k = 3; break;
        }
        func_0216D410(s, k);
        return 1;
    }
    return 0;
}
