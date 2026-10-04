/*
 * function: func_0219D2F4
 * address:  0x0219D2F4
 * packet:   pkt_ov021_0219D2F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02050468  0x02050468  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj04225.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u32 p; u16 id; u16 pad; u32 x; } Slot;
struct BbActSys;
extern void func_02050468(struct BbActSys *o, u32 first, u32 count);
extern void func_020307B0(void *p);

void func_0219D2F4(u8 *s)
{
    Slot *e = *(Slot * *)&((struct Obj04225 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0) {
                func_02050468((struct BbActSys *)(((struct Obj04225 *)s)->f4), e->id, 1);
                e->p = 0;
            }
        }
        func_020307B0(((struct Obj04225 *)s)->f20);
    }
}
