/*
 * function: FLDMMDL_G3DOBJ_AddResEntry
 * address:  0x0219D524
 * packet:   pkt_ov021_0219D524
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj09515.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; } E4;

u16 FLDMMDL_G3DOBJ_AddResEntry(u32 *s, u32 b, u32 a)
{
    int i;
    E4 *e = *(E4 * *)&((struct Obj09515 *)s)->fC;
    int n = ((struct Obj09515 *)s)->f8;
    for (i = 0; i < n; i++, e++) {
        if (e->b == 0xFFFF) {
            e->b = b;
            e->a = a;
            return i;
        }
    }
    return 0;
}
