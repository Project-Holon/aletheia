/*
 * function: func_02165E24
 * address:  0x02165E24
 * packet:   pkt_02165E24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none: no relocation site)
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_02165E24(int a0)
{

a0 = *(u16 *)((char *)a0 + 0x30);
    if (a0 == 0) goto loc_02165E2E;
loc_02165E2A:
    if ((unsigned)a0 < (unsigned)0x33) goto loc_02165E30;
loc_02165E2E:
a0 = 1;
loc_02165E30:
    return a0;}
