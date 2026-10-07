/*
 * file:     beacon_view_p02.c
 * unit:     yes
 * function: func_021F067C, func_021F0684, func_021F06E0, func_021F079C, func_021F07D4, func_021F0820, func_021F086C, func_021F0884
 * address:  0x021F067C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F0E24 0x021F0E24 thumb ov032
 *   func_02165AC4  0x02165AC4  thumb  ov010
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165C48  0x02165C48  thumb  ov010
 *   func_02165C50  0x02165C50  thumb  ov010
 *   _u32_div_f     0x0209C2B0  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   d_021F3554    0x021F3554  data  a4
 */
#include "../../matched/include/Obj04310.h"
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj07629.h"

struct Queue;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021F0E24(char *p);
extern int func_02165AC4(struct Queue *q, struct Rec *out, u16 *tag, int delta);
extern u8 func_02165D08(struct Rec *r);
extern u32 func_02165C48(u32 rec);
extern u32 func_02165C50(u32 x);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
void func_021F067C(char *p);
void func_021F0684(u8 *p, u8 *a, u8 *b);
void func_021F06E0(u8 *p, u32 x, int y);
void func_021F079C(u8 *p,int v);
u32 func_021F07D4(u8 *p);
int func_021F0820(u32 x);
int func_021F086C(int *a, int *b);
void func_021F0884(int *a, int *b, int *c);
extern u32 d_021F3554[];


void func_021F067C(char *p)
{
    func_021F0E24(p);
}


void func_021F0684(u8 *p, u8 *a, u8 *b)
{
    int i = 0;
    u16 tag;

    *a = 0;
    *b = 0;
    for (; i < p[0x7b]; i++) {
        func_02165AC4((struct Queue *)(((struct Obj04310 *)p)->f3C), (struct Rec *)(((struct Obj04310 *)p)->f44), &tag, i);
        if (p[0x30] != func_02165D08((struct Rec *)(((struct Obj04310 *)p)->f44)))
            (*a)++;
        if (p[0x32] != func_02165C48(((struct Obj04310 *)p)->f44))
            (*b)++;
    }
}


void func_021F06E0(u8 *p, u32 x, int y)
{
    u8 v[2];

    v[1] = 0;
    v[0] = 0;
    func_021F0684(p, &v[0], &v[1]);
    if (func_02165C50(x) != 2)
        func_021F079C(p, 1);
    if (p[0x59] != v[1] && v[1] == 0x14)
        func_021F079C(p, 2);
    if (((struct Obj00007 *)p)->f2D4 % 100 == 0)
        func_021F079C(p, 3);
    if (y == 0x1d && p[0x7b] == 0x1e)
        func_021F079C(p, 4);
    if (p[0x58] != v[0] && v[0] == 0x14)
        func_021F079C(p, 5);
    if (func_021F0820(((struct Obj00007 *)p)->f2D4) != 0)
        func_021F079C(p, 6);
    p[0x58] = v[0];
    p[0x59] = v[1];
}

/*
 * volatile: count byte at +0x8c re-read at 021F07A2 and 021F07BE.
 */
void func_021F079C(u8 *p,int v) { int n,i; n=*(volatile u8 *)&((struct Obj07629 *)p)->f8C; for(i=0;i<n;i++) if(v==p[i+0x8d]) return; *(volatile u8 *)&((struct Obj07629 *)p)->f8C=*(volatile u8 *)&((struct Obj07629 *)p)->f8C+1; (p+n)[0x8d]=v; }


u32 func_021F07D4(u8 *p)
{
    u32 n = p[0x8d];

    if (n == 0)
        return 0x30;
    p[0x8c] = p[0x8c] - 1;
    MI_CpuCopy8(p + 0x8e, p + 0x8d, p[0x8c]);
    (p + p[0x8c])[0x8d] = 0;
    return d_021F3554[n - 1];
}


int func_021F0820(u32 x)
{
    u32 d;

    if (x / 100 == 0)
        return 0;
    d = x % 10;
    x = x / 10;
    do {
        if ((u8)(x % 10) != d)
            return 0;
        x = x / 10;
    } while (x != 0);
    return 1;
}

int func_021F086C(int *a, int *b) { return a[0]*b[1] - a[1]*b[0]; }

void func_021F0884(int *a, int *b, int *c) { c[0]=a[0]-b[0]; c[1]=a[1]-b[1]; }
