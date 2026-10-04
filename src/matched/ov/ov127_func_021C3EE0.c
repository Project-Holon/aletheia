/*
 * function: func_021C3EE0
 * address: 0x021C3EE0
 * packet: pkt_ov127_021C3EE0
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021C42FC 0x021C42FC thumb ov127
 *   d_021C6100 0x021C6100 data a1
 */
#include "../include/Obj02839.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_021C42FC(void *, int, u32);
extern const char d_021C6100[];
typedef struct { u32 mode, handle, owner, a, b; } Entry;
typedef struct { void *a, *b, *items; u32 count; Entry entries[18]; u8 gap[384]; void *h0, *h1; u8 rest[52]; } Context;
Context *func_021C3EE0(void *a, void *b, u32 count, u32 heap)
{
    Context *p;
    int i;
    p = func_02030734(heap, 820, 1, d_021C6100, 339);
    p->a = a;
    p->b = b;
    p->h0 = func_020490F4(31, heap);
    p->h1 = func_020490F4(32, heap);
    for (i = 0; i < 18; i++) p->entries[i].handle = -1;
    ((struct Obj02839 *)p)->f2E0 = -1;
    ((struct Obj02839 *)p)->f2F4 = -1;
    func_021C42FC(p, 0, heap);
    p->count = count;
    p->items = func_02030734(heap, 24 * p->count, 1, d_021C6100, 379);
    return p;
}
