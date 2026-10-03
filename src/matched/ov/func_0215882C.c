/*
 * function: func_0215882C
 * address:  0x0215882C
 * packet:   pkt_0215882C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011298  0x02011298  thumb
 *   func_02158CB4  0x02158CB4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02011298();
extern int func_02158CB4(int a0);

int func_0215882C(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t4 = 0;
loc_02158832:
a0 = t4 << 2;
t7 = t5 + a0;
t6 = *(int *)((char *)t7 + 4);
    if (t6 == 0) goto loc_02158856;
loc_0215883C:
a0 = t6 + 0;
    a0 = func_02011298(a0);
loc_02158842:
    if (a0 != 0) goto loc_02158856;
loc_02158846:
a0 = 0;
*(int *)((char *)t7 + 4) = a0;
a0 = *(u8 *)((char *)t5 + 2);
a0 = a0 - 1;
*(u8 *)((char *)t5 + 2) = a0;
a0 = t6 + 0;
    a0 = func_02158CB4(a0);
loc_02158856:
t4 = t4 + 1;
    if (t4 < 3) goto loc_02158832;
loc_0215885C:
a0 = *(u8 *)((char *)t5 + 2);
    if (a0 == 0) goto loc_02158866;
loc_02158862:
a0 = 1;
    return a0;
loc_02158866:
a0 = 0;
    return a0;}
