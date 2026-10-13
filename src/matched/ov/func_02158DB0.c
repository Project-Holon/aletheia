/*
 * function: SCRIPT_SYS_IsChildScript
 * address:  0x02158DB0
 * packet:   pkt_02158DB0
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



int SCRIPT_SYS_IsChildScript(int a0)
{

    if (a0 == 0) goto loc_02158DB8;
loc_02158DB4:
a0 = 1;
    return a0;
loc_02158DB8:
a0 = 0;
    return a0;}
