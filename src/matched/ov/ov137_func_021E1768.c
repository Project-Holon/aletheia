/*
 * function: func_021E1768
 * address:  0x021E1768
 * packet:   pkt_021E1768
 * region:   ov137
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The `&` operand order names the temporary: `field & (1 << i)` (field into
 * r2, mask into r0) reproduces the original; `(1 << i) & field` rotates them.
 */
#include "../include/Obj03304.h"
#include "../include/Obj23808.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int func_021E1768(char *p, int i)
{
    if (i != 0 && (((struct Obj23808 *)(*(char * *)&((struct Obj03304 *)p)->fDC))->f42 & (1 << i)) == 0)
        return 0;
    return 1;
}
