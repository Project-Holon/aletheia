/*
 * function: EVENT_FIELD_PROCLINK_InitReturnHeader
 * address:  0x02161F00
 * packet:   pkt_02161F00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj17710.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void MI_CpuFill8(void *dst, u8 data, u32 size);

void EVENT_FIELD_PROCLINK_InitReturnHeader(void *p)
{
    MI_CpuFill8(p, 0, 4);
    ((struct Obj17710 *)p)->f2 = 10;
}
