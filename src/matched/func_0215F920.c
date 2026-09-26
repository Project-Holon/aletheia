/*
 * function: func_0215F920
 * address:  0x0215F920
 * packet:   pkt_0215F920
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  listing 40 compiled 38
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02012EBC();
extern int func_0200873C();
extern int func_020083E4();

int func_0215F920(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 8);
    if (a0 != 1) goto loc_0215F92E;
loc_0215F92A:
a0 = 1;
    goto loc_0215F930;
loc_0215F92E:
a0 = 0;
loc_0215F930:
*(int *)((char *)t4 + 0x28) = a0;
a0 = *(int *)((char *)t4 + 4);
    a0 = func_02012EBC(a0);
loc_0215F938:
    a0 = func_0200873C(a0);
loc_0215F93C:
    a0 = func_020083E4(a0);
loc_0215F940:
*(int *)((char *)t4 + 0x2c) = a0;
*(int *)((char *)t4 + 0x30) = a0;
    return a0;}
