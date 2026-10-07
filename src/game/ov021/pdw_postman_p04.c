/*
 * file:     pdw_postman_p04.c
 * unit:     yes
 * function: func_021B79AC, func_021B79C4, func_021B79CC, func_021B79D4, func_021B79E4
 * address:  0x021B79AC
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
 *   func_021B9164  0x021B9164  thumb  ov021
 *   func_021B8028  0x021B8028  thumb ov021
 */
#include "../../matched/include/Obj01358.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_021B9164(u32, u32, u32, u32);
extern void func_021B8028(void *, void *);
int func_021B79AC(u32 a, u32 b, u32 c, u32 d);
void func_021B79C4(u32 *p, u32 v);
void func_021B79CC(u32 *p);
void func_021B79D4(void **o, void *out);
void func_021B79E4(unsigned short *p);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B79AC(u32 a, u32 b, u32 c, u32 d)
{
func_021B9164(b, (a + 32), a, d);
((struct Obj01358 *)((u8 *)(b)))->f2 = 0;
return 0;
}


/*
 * Unlabelled leaf: stores v at +0x14 and 1 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021B79C4(u32 *p, u32 v)
{
    p[5] = v;
    p[6] = 1;
}


/*
 * Unlabelled leaf: clears the word at +0x14.
 *
 * Addresses are Black-image addresses.
 */
void func_021B79CC(u32 *p)
{
    p[5] = 0;
}


void func_021B79D4(void **o, void *out)
{
    if (o[5] != 0) {
        func_021B8028(o[5], out);
    }
}

void func_021B79E4(unsigned short *p)
{
    if (p[1] == 0)
        return;
    if (p[2])
        return;
}
