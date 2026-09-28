/*
 * function: func_02163E58
 * address:  0x02163E58
 * packet:   pkt_02163E58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02163E1C  0x02163E1C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02163E1C();

int func_02163E58(int a0, int a1, int a2)
{
    unsigned char fr[16];
    int t4;
    int t5;
t4 = a2 + 0;
t5 = 0;
a2 = (int)(fr + 0);
*(int *)((char *)t4) = t5;
    a0 = func_02163E1C(a0, a1, a2);
loc_02163E68:
    if (a0 != 1) goto loc_02163E76;
loc_02163E6C:
    a0 = *(int *)(fr + 12);
*(int *)((char *)t4) = a0;
a0 = 1;
    return a0;
loc_02163E76:
a0 = t5 + 0;
    return a0;
}
