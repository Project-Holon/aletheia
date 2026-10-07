/*
 * function: func_021BB0AC
 * address: 0x021BB0AC
 * packet: pkt_ov068_021BB0AC
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BB704 0x021BB704 data a4
 */

#include "../include/G__anon_Entry.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern struct _anon_Entry d_021BB704[];
int func_021BB0AC(u8 *p, int i)
{
    if (p[d_021BB704[i].offset] == d_021BB704[i].value) return 1;
    return 0;
}
