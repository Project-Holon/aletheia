/*
 * function: func_0216F8C8
 * address:  0x0216F8C8
 * packet:   pkt_0216F8C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021F385C  0x021F385C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5DC();
extern int func_0201210C();
extern int func_021F385C();

int func_0216F8C8(int a0, int a1)
{

a0 = a1 + 0;
    a0 = func_0215A5DC(a0);
loc_0216F8D0:
    a0 = func_0201210C();
loc_0216F8D4:
    a0 = func_021F385C();
loc_0216F8D8:
a0 = 0;
    return a0;}
