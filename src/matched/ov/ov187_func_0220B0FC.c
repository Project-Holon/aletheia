/*
 * function: func_0220B0FC
 * address: 0x0220B0FC
 * packet: pkt_ov187_0220B0FC
 * region: ov187
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_0220B2E4 0x0220B2E4 data a1
 */
#include "../include/Obj24884.h"
typedef struct { int state, mode; void *data, *owner; } Work;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, unsigned, unsigned);
extern const char d_0220B2E4[];
Work *func_0220B0FC(unsigned short heap, char *p, int mode)
{
    Work *w;
    w = func_02030734(heap, 16, 0, d_0220B2E4, 0x1e7);
    func_02082BCC(w, 0, 16);
    w->owner = ((struct Obj24884 *)p)->f17F0;
    w->data = p + 0x28;
    if (mode == 1) w->mode = 1;
    else w->mode = 0;
    return w;
}
