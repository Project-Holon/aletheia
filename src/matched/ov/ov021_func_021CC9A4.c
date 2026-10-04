/*
 * function: func_021CC9A4
 * address:  0x021CC9A4
 * packet:   pkt_ov021_021CC9A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 */
#include "../include/Obj06097.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0201AA18(void *p);
extern void func_0204A8D4(u32 v);
extern void func_0204AFD8(u32 v);
extern void func_0204ADA4(u32 v);

void func_021CC9A4(u8 *p)
{
    int i;
    int n;

    if (((struct Obj06097 *)p)->f8) {
        n = func_0201AA18(((struct Obj06097 *)p)->f8);
        for (i = 0; i < n; i++)
            func_0204A8D4(*(u16 *)(p + i * 2 + 0x8c));
    }
    n = func_0201AA18(((struct Obj06097 *)p)->f4);
    for (i = 0; i < n; i++)
        func_0204A8D4(*(u16 *)(p + i * 2 + 0x80));
    func_0204AFD8(((struct Obj06097 *)p)->f7E);
    func_0204ADA4(((struct Obj06097 *)p)->f7C);
}
