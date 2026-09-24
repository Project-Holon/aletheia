/*
 * function: func_0215C870
 * address:  0x0215C870
 * packet:   pkt_0215C870
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_0216F940  0x0216F940  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020307B0();
extern int func_0216F940();

int func_0215C870(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4);
a0 = *(u8 *)((char *)a0 + 0x1a);
    if (a0 == 0) goto loc_0215C880;
loc_0215C87C:
    if (a0 == 1) goto loc_0215C884;
loc_0215C880:
a1 = 0;
    goto loc_0215C886;
loc_0215C884:
a1 = 1;
loc_0215C886:
a0 = *(int *)((char *)t4 + 4);
*(u16 *)((char *)a0) = a1;
a0 = *(int *)((char *)t4);
a0 = *(int *)((char *)a0 + 0x10);
    a0 = func_020307B0(a0);
loc_0215C892:
a0 = *(int *)((char *)t4);
    a0 = func_0216F940(a0);
loc_0215C898:
    return a0;}
