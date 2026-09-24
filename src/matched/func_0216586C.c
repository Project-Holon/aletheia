/*
 * function: func_0216586C
 * address:  0x0216586C
 * packet:   pkt_0216586C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045A38  0x02045A38  arm
 *   func_0202744C  0x0202744C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02045A38();
extern int func_0202744C();

int func_0216586C(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
a2 = 9;
    a0 = func_02045A38(a0, a1, a2);
loc_0216587C:
a0 = 0x31;
*(u16 *)((char *)t4 + 0x30) = a0;
a0 = t4 + 0;
    a0 = func_0202744C(a0);
loc_02165886:
    return a0;}
