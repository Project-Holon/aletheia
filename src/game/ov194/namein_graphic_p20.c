/*
 * file:     namein_graphic_p20.c
 * unit:     yes
 * function: func_021F4BEC, func_021F4BF8
 * address:  0x021F4BEC
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4D1C 0x021F4D1C thumb ov194
 *   func_021F4CA8  0x021F4CA8  thumb  ov194
 *   func_021F4D14  0x021F4D14  thumb  ov194
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern unsigned func_021F4D1C(const unsigned *);
extern void func_021F4CA8(u8 *);
extern void func_021F4D14(u8 *);
unsigned func_021F4BEC(unsigned char *p);
void func_021F4BF8(u32 a, u8 *b);

unsigned func_021F4BEC(unsigned char *p){return func_021F4D1C((const unsigned *)(p+4));}


void func_021F4BF8(u32 a, u8 *b)
{
    func_021F4CA8(b);
    func_021F4D14(b + 4);
}
