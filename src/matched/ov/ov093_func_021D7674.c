/*
 * function: BTL_EVENT_SetVarRanged
 * address:  0x021D7674
 * packet:   pkt_ov093_021D7674
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlEventVarStack     0x021F3ECC  data
 *   BTL_EVENT_FindVarSlot  0x021D77C4  thumb  ov093
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
extern u32 BTL_EVENT_FindVarSlot(Tbl *p, int key);

void BTL_EVENT_SetVarRanged(int key, u32 val, u32 x, u32 y)
{
    u32 i = BTL_EVENT_FindVarSlot(((Tbl *)&gBtlEventVarStack), key);
    gBtlEventVarStack.keys[i] = key;
    gBtlEventVarStack.vals[i] = val;
    gBtlEventVarStack.b[i] = x;
    gBtlEventVarStack.a[i] = y;
    gBtlEventVarStack.c[i] = 3;
}
