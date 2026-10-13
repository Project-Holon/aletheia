/*
 * function: UNION_COMMAND_RecvTrainerCard
 * address: 0x02173B78
 * packet: pkt_ov012_02173B78
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   MI_CpuCopy8 0x02082D44 arm
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 * Enum-typed local offset keeps 0x2830 and the +0x5d field add separate;
 * raw/nested pointer arithmetic and an inline setter folded to 0x288d.
 */
#include "../include/Obj19253.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Link;
typedef struct { u8 pad[0x5d]; u8 flag; } Sub;
typedef struct { u8 pad[0x2830]; Sub sub; } Work;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void MI_CpuCopy8(void *src, void *dst, u32 n);
void UNION_COMMAND_RecvTrainerCard(u32 a, u32 b, const void *c, u8 *p)
{
    if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
        enum { OFFSET = 0x2830 } off = OFFSET;
        Sub *q = (Sub *)(p + off);
        q->flag = 1;
        MI_CpuCopy8((void *)c, ((struct Obj19253 *)p)->f3544, b);
    }
}
