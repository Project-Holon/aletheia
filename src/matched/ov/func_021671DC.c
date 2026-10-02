/*
 * function: func_021671DC
 * address:  0x021671DC
 * packet:   pkt_021671DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201EC64  0x0201EC64  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct WordSet;

extern struct WordSet *func_0201EC64(u32 heap);

struct WordSet *func_021671DC(int a0)
{
    int t4;
    struct WordSet *ws;

t4 = a0 + 0;
a0 = *(u16 *)((char *)t4);
    ws = func_0201EC64(a0);
loc_021671E6:
*(struct WordSet **)((char *)t4 + 0x1c) = ws;
    return ws;}
