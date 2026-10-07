/*
 * function: func_020606A8
 * address:  0x020606A8
 * packet:   pkt_020606A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146B64       0x02146B64  data
 *   func_02060640    0x02060640  arm
 */

#include "../include/G_NNSFndList.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct DList;
struct Elem;
extern struct Elem *func_02060640(struct DList *list, u32 val);
extern struct NNSFndList g_02146B64;

void *func_020606A8(u32 a)
{
    void *r = &(*(u32 *)&g_02146B64);
    u32 v = (u32)func_02060640((struct DList *)(&(*(u32 *)&g_02146B64)), a);

    if (v != 0) {
        r = (void *)(v + 0xc);
    }
    return r;
}
