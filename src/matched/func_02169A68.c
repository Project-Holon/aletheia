/*
 * function: func_02169A68
 * address:  0x02169A68
 * packet:   pkt_02169A68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02046F48  0x02046F48  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02046F48();

int func_02169A68(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = a0 + 0x88;
a0 = *(int *)((char *)a0);
    a0 = func_02046F48(a0);
loc_02169A74:
    if (a0 != 0) goto loc_02169A82;
loc_02169A78:
a0 = t4 + 0;
a0 = a0 + 0x94;
a0 = *(int *)((char *)a0);
    if (a0 != 0) goto loc_02169A86;
loc_02169A82:
t4 = t4 + 0x88;
a0 = *(int *)((char *)t4);
loc_02169A86:
    return a0;}
