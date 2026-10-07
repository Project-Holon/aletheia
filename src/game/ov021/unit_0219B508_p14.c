/*
 * file:     unit_0219B508_p14.c
 * unit:     yes
 * function: func_0219C150, func_0219C164
 * address:  0x0219C150
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
 *   func_0219C338  0x0219C338  thumb  ov021
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb
 */
#include "../../matched/include/Obj17966.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_0219C338(char *a, u32 *s, u32 c);
extern u32 func_0216DA50(u32);
extern u32 func_02197EDC(u8 *p);
int func_0219C150(char *a, u8 *s);
int func_0219C164(u32 a, u32 b, u32 c, u32 d);


int func_0219C150(char *a, u8 *s)
{
    func_0219C338(a, (u32 *)s, 12);
    s[0]++;
    return 1;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216DA50 (0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219C164(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    func_0216DA50(a);
    ((struct Obj17966 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}
