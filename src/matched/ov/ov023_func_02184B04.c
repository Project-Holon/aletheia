/*
 * function: func_02184B04
 * address: 0x02184B04
 * packet: pkt_ov023_02184B04
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj09768.h"
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
void func_02184B04(char *p)
{
    int i;
    func_020307B0(((struct Obj09768 *)p)->f4288);
    for (i = 0; i < 5; i++)
        func_02045808(*(void **)(p + 0x18 + i * 4));
    func_02045808(((struct Obj09768 *)p)->f30);
    func_02045808(((struct Obj09768 *)p)->f2C);
}
