/*
 * function: func_0219D558
 * address:  0x0219D558
 * packet:   pkt_ov021_0219D558
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj09517.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; } E4;

u16 func_0219D558(u8 *s, u16 k)
{
    int i;
    E4 *e = *(E4 * *)&((struct Obj09517 *)s)->fC;
    int n = ((struct Obj09517 *)s)->f8;
    for (i = 0; i < n; i++, e++) {
        if (e->b == k) {
            return e->a;
        }
    }
    return 0xFFFF;
}
