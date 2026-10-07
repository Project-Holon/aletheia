/*
 * file:     unit_021743B4_p03.c
 * unit:     yes
 * function: func_021746AC, func_021746EC, func_02174734
 * address:  0x021746AC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_02026478  0x02026478  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_021583EC  0x021583EC  thumb ov010
 *   func_021861F4  0x021861F4  thumb ov020
 *   func_02082D44  0x02082D44  arm
 *   func_02012800  0x02012800  thumb
 *   func_0203D578  0x0203D578  arm
 *   func_0203D4D0  0x0203D4D0  arm
 */
#include "../../matched/include/Obj12421.h"

struct Entry;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

int func_021736D8(void);
extern struct Entry *func_020399A8(void);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_02026478(void *obj);
u8 *func_020127D0(u8 *o, u32 idx);
int func_021583EC(void *a0, int a1);
void func_021861F4(u16 *p, int x);
void func_02082D44(void *d, void *s, int n);
void func_02012800(u8 *obj, void *dst);
int func_0203D578(int a, int b);
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int func_021746AC(char *a, int b);
void func_021746EC(int a, int b, void *c, char *d);
int func_02174734(char *p, int b, void *c);


int func_021746AC(char *a, int b)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    r = func_0203D3F8((u32)func_020399A8(), b, 0x224, 0, 0, 0, 0, 0);
    if (r == 1) {
        a[0x90c] = 0;
    }
    return r;
}


void func_021746EC(int a, int b, void *c, char *d)
{
    int h;
    int s;

    h = func_02026478((void *)(((struct Obj12421 *)d)->f4));
    s = (int)func_020127D0((u8 *)h, 0);
    func_021861F4(c, func_021583EC((void *)h, a));
    func_02082D44(c, (void *)s, 0x1E8);
    func_02012800((u8 *)h, c);
    d[0x90C] = 1;
}


int func_02174734(char *p, int b, void *c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x225) == 1) {
        return 0;
    }
    func_02082D44(c, p + 0x460, 0x1E8);
    return func_0203D4D0((int)func_020399A8(), b & 0xFF, 0x225, 0x1E8, (u32)c, 0, 0, 1);
}
