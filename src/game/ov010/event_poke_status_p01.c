/*
 * file:     event_poke_status_p01.c
 * unit:     yes
 * function: func_0215932C, func_02159340
 * address:  0x0215932C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj12274.h"

typedef unsigned char u8;

typedef unsigned int u32;

int func_0215932C(unsigned int a, unsigned int b);
int func_02159340(u8 *p);

int func_0215932C(unsigned int a, unsigned int b)
{
    if (a < b) return 0;
    if (a == b) return 1;
    return 2;
}

static inline int ReadByte(u8 *p)
{
    int v = **(u8 * *)&((struct Obj12274 *)p)->f14;
    (*(u8 * *)&((struct Obj12274 *)p)->f14)++;
    return v;
}

/*
 * extent: two-byte zero alignment padding follows the 46-byte function.
 * lever: inline byte reader binds the load before incrementing the cursor;
 * a postincrement expression schedules the cursor store before the load.
 */
int func_02159340(u8 *p)
{
    u8 a, b;
    a = (*(u32 **)(p + 28))[ReadByte(p)];
    b = (*(u32 **)(p + 28))[ReadByte(p)];
    p[14] = func_0215932C(a, b);
    return 0;
}
