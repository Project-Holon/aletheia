/*
 * file:     field_effect_p39.c
 * unit:     yes
 * function: func_021AB768, func_021AB780, func_021AB798, func_021AB7C0
 * address:  0x021AB768
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj12093.h"
#include "../../matched/include/Obj12094.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int (*Fn_021AB798)(int a, int b, int c);

typedef struct {
    Fn_021AB798 *f0;
    Fn_021AB798 *f4;
} S;

typedef void (*Fn_021AB7C0)(int a, int b, int c);

int func_021AB768(u32 a, u32 b);
int func_021AB780(u32 a, u32 b);
int func_021AB798(S *s, int i, int a, int b, int c);
void func_021AB7C0(S *s, int i, int a, int b, int c);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AB768(u32 a, u32 b)
{
if (((struct Obj12093 *)((u8 *)(a)))->f8 > b) {
    if (*(u32 *)((u8 *)(((struct Obj12093 *)((u8 *)(a)))->f0) + ((b << 2))) != 0) {
        return 1;
    }
}
return 0;
}


int func_021AB780(u32 a, u32 b)
{
if (((struct Obj12094 *)((u8 *)(a)))->fA > b) {
    if (*(u32 *)((u8 *)(((struct Obj12094 *)((u8 *)(a)))->f4) + ((b << 2))) != 0) {
        return 1;
    }
}
return 0;
}


int func_021AB798(S *s, int i, int a, int b, int c)
{
    if (func_021AB768((u32)s, i)) {
        return s->f0[i](a, b, c);
    }
    return 0;
}


void func_021AB7C0(S *s, int i, int a, int b, int c)
{
    if (func_021AB780((u32)s, i)) {
        s->f4[i](a, b, c);
    }
}
