/*
 * function: func_0219CE60
 * address:  0x0219CE60
 * packet:   pkt_ov021_0219CE60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Claims the first free 0x14-byte slot of the table at *(*(+0x1c)+0x10).
 *
 * symbols:
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_02046E24  0x02046E24  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03579.h"
#include "../include/Obj03580.h"
#include "../include/Obj12673.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0216D518(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);

int func_0219CE60(u8 *o, u32 a, u32 b, u32 c, u16 e, u32 w)
{
    u8 *ctx = *(u8 * *)&((struct Obj03579 *)o)->f1C;
    u8 *p = *(u8 * *)&((struct Obj12673 *)ctx)->f10;
    u32 i;
    for (i = 0; i < ((struct Obj12673 *)ctx)->f6; i++, p += 0x14) {
        if (((struct Obj03580 *)p)->f10 == 0) {
            ((struct Obj03580 *)p)->f0 = 0;
            ((struct Obj03580 *)p)->f8 = a;
            ((struct Obj03580 *)p)->fA = b;
            ((struct Obj03580 *)p)->fB = c;
            ((struct Obj03580 *)p)->f4 = w;
            ((struct Obj03580 *)p)->f10 = (u32)func_02046E24(func_0216D518((u8 *)(((struct Obj03579 *)o)->f10)), e);
            ((struct Obj03580 *)p)->f0 = 1;
            return 1;
        }
    }
    return 0;
}
