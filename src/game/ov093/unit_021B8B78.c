/*
 * file:     unit_021B8B78.c
 * unit:     yes
 * function: func_021B8B78, func_021B8B9C, func_021B8BC4, func_021B8BD0, func_021B8BEC, func_021B8C20, func_021B8C38, func_021B8C50, func_021B8C5C
 * address:  0x021B8B78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj20968.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

unsigned int func_021B8B78(unsigned char *p, int k);
int func_021B8B9C(unsigned char *p,unsigned char k);
unsigned char func_021B8BC4(int unused, unsigned int b);
int func_021B8BD0(unsigned char *p,unsigned char k);
u8 func_021B8BEC(u8 *p, u32 k, u8 n);
u8 func_021B8C20(int kind, u32 flags, u32 v);
u8 func_021B8C38(u32 flags, u32 v);
u8 func_021B8C50(char **p, u32 v, int k);
u8 func_021B8C5C(int kind, u32 flags);

unsigned int func_021B8B78(unsigned char *p, int k) { unsigned int n,i; i=0; n=0; for(;i<6;i++) { if(k==p[i+0x428]) n++; } return n; }

int func_021B8B9C(unsigned char *p,unsigned char k) { unsigned int i; if(k<4) { for(i=0;i<6;i++) if(k==p[i+0x428]) return 1; } return 0; }

unsigned char func_021B8BC4(int unused, unsigned int b)
{
    (void)unused;
    return b & 1;
}

int func_021B8BD0(unsigned char *p,unsigned char k) { if(k==func_021B8BC4((int)p,p[0x46c])) return 1; return 0; }


u8 func_021B8BEC(u8 *p, u32 k, u8 n)
{
    u8 i;
    for (i = 0; i < 6; i++) {
        if (k == p[0x428 + i]) {
            if (n == 0) return i;
            n--;
        }
    }
    return 6;
}


u8 func_021B8C20(int kind, u32 flags, u32 v)
{
    if ((flags & 1) == 0) return v * 2 + 1;
    return v * 2;
}


u8 func_021B8C38(u32 flags, u32 v)
{
    if ((flags & 1) == 0) return v * 2;
    return v * 2 + 1;
}


u8 func_021B8C50(char **p, u32 v, int k)
{
    return func_021B8C20(((struct Obj20968 *)(*p))->f4, v, k);
}


u8 func_021B8C5C(int kind, u32 flags)
{
    u8 x;
    switch (kind) {
    default:
    case 0:
        return func_021B8C20(kind, flags, 0);
    case 1:
        x = flags >> 1;
        return func_021B8C20(kind, flags, (u8)(1 ^ x));
    case 2:
        x = flags >> 1;
        if (x == 0) {
            x = 2;
        } else if (x == 2) {
            x = 0;
        }
        return func_021B8C20(kind, flags, x);
    case 3:
        return func_021B8C20(kind, flags, 0);
    }
}
