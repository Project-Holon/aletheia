/*
 * function: func_020334E8
 * address:  0x020334E8
 * packet:   pkt_020334E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146994    0x02146994  data
 *   func_02031EAC 0x02031EAC  arm
 *   func_02033B68 0x02033B68  arm
 *   func_020335E8 0x020335E8  arm
 */
#include "../include/Obj15882.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *g_02146994;
extern u32 func_02031EAC(u32 *p, u32 sel);
extern u32 func_02033B68(u8 *p, u32 i);
extern int func_020335E8(u32 a0, u32 a1, u32 a2, void (*a3)(void));

int func_020334E8(u8 *p, u32 b, u32 c, u32 d, u32 e)
{
    u32 n = func_02031EAC((u32 *)p, c + 1);
    u32 m = func_02033B68(*(u8 * *)&((struct Obj15882 *)p)->f2C, b);

    return func_020335E8(n + m, d, e, (void (*)(void))*(u32 *)(g_02146994 + 0x204));
}
