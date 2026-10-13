/*
 * function: GFL_NET_QUEUE_Init
 * address:  0x02036AF4
 * packet:   pkt_020369F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   str_020A79C4  0x020A79C4  data
 *   MI_CpuFill8 0x02082BCC  arm
 *   func_02030734 0x02030734  arm
 */
#include "../include/Obj08826.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef unsigned short u16;

extern u8 str_020A79C4[];
extern void MI_CpuFill8(void *dst, u32 val, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void GFL_NET_QUEUE_Init(u8 *p, u32 n, u32 a, u32 b)
{
    MI_CpuFill8(p, 0, 0x28);
    ((struct Obj08826 *)p)->f18 = (u32)func_02030734(b, n * 0x14, 1, (const char *)str_020A79C4, 0x173);
    ((struct Obj08826 *)p)->f1C = n;
    ((struct Obj08826 *)p)->f14 = a;
}
