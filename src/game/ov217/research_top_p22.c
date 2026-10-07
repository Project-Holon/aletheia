/*
 * file:     research_top_p22.c
 * unit:     yes
 * function: func_021BE8FC, func_021BE90C, func_021BE91C
 * address:  0x021BE8FC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "../../matched/include/Obj14736.h"

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed char    s8;

typedef signed short   s16;

extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int _s32_div_f(int, int);
void func_021BE8FC(void);
void func_021BE90C(void);
void func_021BE91C(char *p, int a);


void func_021BE8FC(void)
{
    func_0204E720(3, 0x10, 0, 0);
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE90C(void)
{
    func_0204E720(3, 0, 16, 0);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BE91C(char *p, int a)
{
    ((struct Obj14736 *)p)->f34 = (((struct Obj14736 *)p)->f34 + a + 5) % 5;
}
