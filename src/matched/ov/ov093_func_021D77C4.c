/*
 * function: BTL_EVENT_FindVarSlot
 * address:  0x021D77C4
 * packet:   pkt_ov093_021D77C4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlEventVarStack  0x021F3ECC  data
 */

#include "../include/G_Tbl.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
typedef struct {
    u32 count;
    u16 keys[0x60];
    u32 vals[0x60];
    u32 a[0x60];
    u32 b[0x60];
    u8 c[0x60];
} Tbl;

extern struct Tbl gBtlEventVarStack;

u32 BTL_EVENT_FindVarSlot(Tbl *p, int key)
{
    u32 i;
    for (i = p->count; i < 0x60; i++) {
        if (p->keys[i] == 0) break;
        if (key == p->keys[i]) break;
    }
    if (i >= 0x60) i = 0;
    return i;
}
