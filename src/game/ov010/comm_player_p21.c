/*
 * file:     comm_player_p21.c
 * unit:     yes
 * function: func_021694F8, func_021694FC, func_02169500
 * address:  0x021694F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj17742.h"
#include "../../matched/include/Obj17743.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef struct S12 { u32 a, b, c; } S12;

void func_021694F8(u8 *p, u16 v);
u16 func_021694FC(u8 *p);
void func_02169500(u8 *p, u8 *q);



/*
 * Stores the halfword at p.
 *
 * Addresses are Black-image addresses.
 */
void func_021694F8(u8 *p, u16 v)
{
    ((struct Obj17742 *)p)->f0 = v;
}



/*
 * Reads the halfword at p.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021694FC(u8 *p)
{
    return ((struct Obj17743 *)p)->f0;
}



/*
 * Copies a 12-byte record from q into p + 0x4.
 *
 * Addresses are Black-image addresses.
 */
void func_02169500(u8 *p, u8 *q)
{
    *(S12 *)(p + 0x4) = *(S12 *)q;
}
