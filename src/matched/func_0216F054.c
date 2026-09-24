/*
 * function: func_0216F054
 * address:  0x0216F054
 * packet:   pkt_0216F054
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020130B4  0x020130B4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020130B4();

int func_0216F054(int a0, int a1)
{

a1 = *(int *)((char *)a0 + 0x20);
    if (a1 != 0) goto loc_0216F062;
loc_0216F05C:
a0 = *(int *)((char *)a0 + 8);
    a0 = func_020130B4(a0);
loc_0216F062:
    return a0;}
