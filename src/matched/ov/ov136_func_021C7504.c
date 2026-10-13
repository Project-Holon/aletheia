/*
 * function: func_021C7504
 * address:  0x021C7504
 * packet:   pkt_ov136_021C7504
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202138C  0x0202138C  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   func_021C3CC0  0x021C3CC0  thumb
 *   d_021C7D5C 0x021C7D5C data a4
 */
#include "../include/Obj06532.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};
extern const u8 d_021C7D5C[];
extern u8 func_0202138C(u16 v);
extern void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
extern void PROCSYS_Push(void *, u32, const void *, void *);
int func_021C7504(u8 *p)
{
    ((struct Obj06532 *)p)->f10 = (void *)func_021C3CC0(**(void ** *)&((struct Obj06532 *)p)->f4, 2, ((struct Bf7 *)(p + 0x21))->v, func_0202138C(((struct Obj06532 *)p)->f22), 0x65);
    PROCSYS_Push(((struct Obj06532 *)p)->f30, (u32)-1, d_021C7D5C, ((struct Obj06532 *)p)->f10);
    return 0;
}
