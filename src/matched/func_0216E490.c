/*
 * function: func_0216E490
 * address:  0x0216E490
 * packet:   pkt_0216E490
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



int func_0216E490(int a0, int a1, int a2)
{

a1 = 0;
a2 = *(int *)((char *)a0);
a1 = ~a1;
    if (a2 != a1) goto loc_0216E4A6;
loc_0216E49A:
a2 = *(int *)((char *)a0 + 4);
    if (a2 != a1) goto loc_0216E4A6;
loc_0216E4A0:
a0 = *(int *)((char *)a0 + 8);
    if (a0 == a1) goto loc_0216E4AA;
loc_0216E4A6:
a0 = 1;
    return a0;
loc_0216E4AA:
a0 = 0;
    return a0;}
