/*
 * function: func_0216CC30
 * address:  0x0216CC30
 * packet:   pkt_0216CC30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0216CC40  0x0216CC40  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern int func_0216CC40();

int func_0216CC30(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0216CC38:
    a0 = func_0216CC40(v0);
loc_0216CC3C:
a0 = 0;
    return a0;}
