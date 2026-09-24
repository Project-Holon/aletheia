/*
 * function: func_02161610
 * address:  0x02161610
 * packet:   pkt_02161610
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020120F4();

int func_02161610(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x18);
a0 = *(int *)((char *)a0);
    a0 = func_020120F4(a0);
loc_0216161C:
a0 = *(int *)((char *)t4 + 0x68);
    if (a0 != 3) goto loc_0216162A;
loc_02161622:
a0 = 2;
*(int *)((char *)t4 + 0xc) = a0;
a0 = 4;
    return a0;
loc_0216162A:
    if (a0 != 4) goto loc_02161636;
loc_0216162E:
a0 = 0;
*(int *)((char *)t4 + 0xc) = a0;
a0 = 4;
    return a0;
loc_02161636:
a0 = 0;
    return a0;}
