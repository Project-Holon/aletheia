/*
 * function: SYMBOL_MAP_GetEntryPage0Second
 * address:  0x02167444
 * packet:   pkt_02167444
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SYMBOL_MAP_CopyEntryRange  0x021673E0  thumb  ov010
 */
#include "../include/Obj17733.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Entry32;
extern u8 SYMBOL_MAP_CopyEntryRange(struct Entry32 *list, struct Entry32 *out, u32 cap, u32 start, int count);

int SYMBOL_MAP_GetEntryPage0Second(int a0, int a1, int a2, int a3)
{
    unsigned char fr[4];
    int t4;
    int o4;
t4 = a3 + 0;
a3 = 0xa;
    o4 = a3;
a3 = 0xa;
    a0 = SYMBOL_MAP_CopyEntryRange((struct Entry32 *)a0, (struct Entry32 *)a1, a2, a3, o4);
loc_02167454:
((struct Obj17733 *)((char *)t4))->f0 = a0;
a0 = 0xa;
    return a0;
}
