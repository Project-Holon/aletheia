/*
 * function: func_021EA6B0
 * address:  0x021EA6B0
 * packet:   pkt_ov093_021EA6B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202A298  0x0202A298  thumb
 *   func_0202A310  0x0202A310  thumb
 *   func_021EA730  0x021EA730  thumb  ov093
 */
#include "../include/Obj07846.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0202A298(u16 key, u16 want, u32 heap);
extern void func_0202A310(u16 key, u16 want, void *dest, u32 heap);
extern void func_021EA730(char *p, u32 a, u16 b, u32 c);

int func_021EA6B0(char *p, u16 a, u16 b)
{
    if (func_0202A298(a, b, ((struct Obj07846 *)p)->f184) != 0) {
        func_0202A310(a, b, ((struct Obj07846 *)p)->fAC, ((struct Obj07846 *)p)->f184);
        func_021EA730(p, *(int *)&((struct Obj07846 *)p)->fAC, 0x50, 0);
    } else {
        return 0;
    }
    return 1;
}
