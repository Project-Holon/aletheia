/*
 * file:     btl_net_p12.c
 * unit:     yes
 * function: func_021D4C58, func_021D4C60, func_021D4C6C
 * address:  0x021D4C58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D4CEC   0x021D4CEC  thumb ov093
 *   d_021F3B88  0x021F3B88  data  ov093
 */
#include "../../matched/include/Obj21214.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D4CEC(void);
void func_021D4C58(u32 a);
unsigned char func_021D4C60(void);
u16 func_021D4C6C(u8 **out);
extern unsigned char *d_021F3B88;


/*
 * tail-call thunk to func_021D4CEC
 */
void func_021D4C58(u32 a)
{
    func_021D4CEC();
}


unsigned char func_021D4C60(void)
{
    return d_021F3B88[13];
}

u16 func_021D4C6C(u8 **out)
{
    u8 *p = d_021F3B88 + 0x38;
    *out = p;
    return ((struct Obj21214 *)p)->fBB8;
}
