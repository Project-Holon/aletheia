/*
 * function: func_0216F088
 * address:  0x0216F088
 * packet:   pkt_0216F088
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02031330  0x02031330  arm
 *   func_0203133C  0x0203133C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02031330();
extern int func_0203133C();

int func_0216F088(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4);
    if (a0 == 0) goto loc_0216F0A8;
loc_0216F092:
    a0 = func_02031330(a0);
loc_0216F096:
    if (a0 != 0) goto loc_0216F0A8;
loc_0216F09A:
a0 = *(int *)((char *)t4);
    a0 = func_0203133C(a0);
loc_0216F0A0:
a0 = 0;
*(int *)((char *)t4) = a0;
a0 = 1;
    return a0;
loc_0216F0A8:
a0 = 0;
    return a0;}
