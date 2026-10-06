/*
 * function: func_0219CC80
 * address:  0x0219CC80
 * packet:   pkt_ov021_0219CC80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02046EFC  0x02046EFC  arm

 * Addresses are Black-image addresses.
 */
#include "../include/Obj02698.h"
#include "../include/Obj04225.h"
#include "../include/Obj06000.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Tagged;
extern u32 func_020307B0(void *p);
extern void func_02046EFC(struct Tagged *p);

void func_0219CC80(u8 *o)
{
    u8 *c = *(u8 * *)&((struct Obj04225 *)o)->f1C;
    u32 i;
    u32 n;
    u8 *p;
    if (c == 0) return;
    i = 0;
    ((struct Obj02698 *)c)->f0 = i;
    func_020307B0((void *)(((struct Obj02698 *)c)->fC));
    p = *(u8 * *)&((struct Obj02698 *)c)->f10;
    if (i < ((struct Obj02698 *)c)->f6) {
        for (; i < ((struct Obj02698 *)c)->f6; i++, p += 0x14) {
            if (((struct Obj06000 *)p)->f10 != 0)
                func_02046EFC((struct Tagged *)(((struct Obj06000 *)p)->f10));
        }
    }
    func_020307B0((void *)(*(u32 *)&((struct Obj02698 *)c)->f10));
    i = 0;
    p = *(u8 * *)&((struct Obj02698 *)c)->f14;
    if (i < ((struct Obj02698 *)c)->f8) {
        for (; i < ((struct Obj02698 *)c)->f8; i++, p += 0x28) {
            if (((struct Obj06000 *)p)->f0 != 0 && ((struct Obj06000 *)p)->f10 != 0)
                func_02046EFC((struct Tagged *)(((struct Obj06000 *)p)->f10));
        }
    }
    func_020307B0((void *)(*(u32 *)&((struct Obj02698 *)c)->f14));
    func_020307B0((void *)((u32)c));
    *(u32 *)&((struct Obj04225 *)o)->f1C = 0;
}
