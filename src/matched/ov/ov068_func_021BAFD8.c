/*
 * function: func_021BAFD8
 * address: 0x021BAFD8
 * packet: pkt_ov068_021BAFD8
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BB704 0x021BB704 data a4
 *   func_021BAFA8 0x021BAFA8 thumb ov068
 */

#include "../include/G__anon_Entry.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern struct _anon_Entry d_021BB704[];
extern void func_021BAFA8(u8 *);
void func_021BAFD8(u8 *p, int i)
{
    if (p[d_021BB704[i].offset] != d_021BB704[i].value) {
        p[d_021BB704[i].offset] = d_021BB704[i].value;
        p[5] = i;
        func_021BAFA8(p);
    }
}
