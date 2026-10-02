/*
 * function: func_021589DC
 * address:  0x021589DC
 * packet:   pkt_021589DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_020124E8  0x020124E8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02158F50();
extern int func_020124E8();

int func_021589DC(int a0)
{

    a0 = func_02158F50(a0);
loc_021589E2:
    if (a0 != 0) goto loc_021589EA;
loc_021589E6:
a0 = 0;
    return a0;
loc_021589EA:
    a0 = func_020124E8(a0);
loc_021589EE:
a0 = *(int *)((char *)a0 + 4);
    return a0;}
