/*
 * file:     research_top_p25.c
 * unit:     yes
 * function: func_021BEA54, func_021BEA8C, func_021BEAEC
 * address:  0x021BEA54
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
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021BF7CC 0x021BF7CC thumb ov217
 *   func_021C11D0 0x021C11D0 thumb ov217
 *   func_021C26AC 0x021C26AC thumb ov217
 *   func_021BF7E0 0x021BF7E0 thumb ov217
 *   func_021BF7F4 0x021BF7F4 thumb ov217
 *   func_021C11C8 0x021C11C8 thumb ov217
 */
#include "../../matched/include/Obj25910.h"
#include "../../matched/include/Obj25911.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern u8 *func_021BF76C(void *p);
extern u32 func_021BF7CC(void *p);
extern u8 func_021C11D0(u8 *p, u8 n);
extern u32 func_021C26AC(const u8 *p, u8 unused, u8 key);
extern u32 func_021BF7E0(void *);
extern u32 func_021BF7F4(void *);
extern u8 func_021C11C8(u8 *p, u8 key);
void func_021BEA54(char *p);
void func_021BEA8C(u8 *p, int step);
void func_021BEAEC(u8 *a0);

void func_021BEA54(char *p)
{
    u8 *o = func_021BF76C(p);

    u32 k = func_021BF7CC(p);
    int v = func_021C11D0(o, 0);
    ((struct Obj25910 *)p)->f2B9 = func_021C26AC((const u8 *)(p + 0x38), (u8)k, (u8)v);
}

/*
 * Prototypes: original loads r0/r1 and reads return at 021C11C8/11D0;
 * narrow argument truncations are explicit in the caller.
 */
void func_021BEA8C(u8 *p, int step)
{
    u8 *object;
    int kind;
    int count;
    int index;
    object = func_021BF76C(p);
    kind = func_021BF7CC(p);
    count = func_021BF7E0(p);
    index = func_021BF7F4(p);
    index = func_021C11C8(object, index);

    index = (count + (index + step)) % count;
    index = func_021C11D0(object, index);
    p[697] = func_021C26AC(p + 56, kind, index);
}



void func_021BEAEC(u8 *a0)
{
    ((struct Obj25911 *)(((u8*)a0)))->f2B9 = 0;
}
