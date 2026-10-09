/*
 * file:     symbol_map_p01.c
 * unit:     yes
 * function: func_0216630C
 * address:  0x0216630C
 * packet:   pkt_0216630C
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



int func_0216630C(int a0, int a1, int a2, int a3)
{

a3 = 0;
loc_0216630E:
a2 = *(u8 *)((char *)a0 + a3);
    if (a1 != a2) goto loc_0216631A;
loc_02166314:
a0 = a3 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;
loc_0216631A:
a3 = a3 + 1;
    if (a3 < 0x1e) goto loc_0216630E;
loc_02166320:
a0 = 1;
    return a0;}
