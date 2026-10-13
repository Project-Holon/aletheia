/*
 * function: INTRUDE_COMM_NormalizeVersion
 * address:  0x021584F4
 * packet:   pkt_021584F4
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



int INTRUDE_COMM_NormalizeVersion(int a0, int a1)
{

    if (a0 == 0x15) goto loc_0215850A;
loc_021584F8:
    if (a0 == 0x14) goto loc_0215850A;
loc_021584FC:
a0 = 1;
a0 = a0 << 0x10;
    if ((a0 & a1) == 0) goto loc_02158508;
loc_02158504:
a0 = 0x14;
    return a0;
loc_02158508:
a0 = 0x15;
loc_0215850A:
    return a0;}
