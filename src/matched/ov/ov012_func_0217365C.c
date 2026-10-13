/*
 * function: UNION_COMM_InitChatLog
 * address:  0x0217365C
 * packet:   pkt_ov012_0217365C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj09359.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void MI_CpuFill8(void *p, u32 v, u32 n);

void UNION_COMM_InitChatLog(u8 *p)
{
    int i;
    int v;

    MI_CpuFill8(p, 0, 0x448);
    for (i = 0; i < 30; i++) {
        MI_CpuFill8(p + i * 0x24 + 0x1a, 0xff, 6);
    }
    v = -1;
    ((struct Obj09359 *)p)->f43C = v;
    ((struct Obj09359 *)p)->f440 = v;
    ((struct Obj09359 *)p)->f444 = v;
}
