/*
 * function: func_020621FC
 * address:  0x020621FC
 * packet:   pkt_02061D0C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146B94     0x02146B94  data
 *   g_02146B98     0x02146B98  data
 *   g_02146B9C     0x02146B9C  data
 *   func_0206207C  0x0206207C  arm
 */

#include "../include/G_Cfg.h"

typedef unsigned int u32;

extern struct Cfg g_02146B94;
extern u32 g_02146B98, g_02146B9C;
extern int func_0206207C(void *headp, void *freep, int a2, int a3);

u32 func_020621FC(u32 h)
{
    u32 a2 = (h << 16) >> 13;
    u32 a3 = ((h & 0x7fff0000) >> 16) << 4;
    u32 flag = (h & 0x80000000) >> 31;
    u32 r;

    if (a3 != 0) {
        if (flag != 0) {
            r = func_0206207C((void *)((u32)&g_02146B98), (void *)((u32)&g_02146B9C), a2, a3);
        } else {
            r = func_0206207C((void *)((u32)&(*(u32 *)&g_02146B94)), (void *)((u32)&g_02146B9C), a2, a3);
        }
        if (r != 0) return 0;
        return 1;
    }
    return 2;
}
