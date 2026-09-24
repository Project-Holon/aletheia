/*
 * function: func_0216CF2C
 * address:  0x0216CF2C
 * packet:   pkt_0216CF2C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216D76C  0x0216D76C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D71C  0x0216D71C  thumb  ov010
 *   func_0216DFAC  0x0216DFAC  thumb  ov010
 *   func_0216D508  0x0216D508  thumb  ov010
 *   func_0216E180  0x0216E180  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D67C();
extern int func_0216D948();
extern int func_0216D76C();
extern int func_0216D55C();
extern int func_0216D71C();
extern int func_0216DFAC();
extern int func_0216D508();
extern int func_0216E180();

int func_0216CF2C(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216D67C();
loc_0216CF34:
    a0 = func_0216D948();
loc_0216CF38:
    if (a0 != 1) goto loc_0216CF42;
loc_0216CF3C:
a0 = t4 + 0;
    a0 = func_0216D76C(a0);
loc_0216CF42:
a0 = t4 + 0;
a1 = 2;
    a0 = func_0216D55C(a0, a1);
loc_0216CF4A:
    if (a0 == 0) goto loc_0216CF5A;
loc_0216CF4E:
a0 = t4 + 0;
    a0 = func_0216D71C(a0);
loc_0216CF54:
a0 = t4 + 0;
    a0 = func_0216DFAC(a0);
loc_0216CF5A:
a0 = t4 + 0;
a0 = a0 + 0x88;
a0 = *(int *)((char *)a0);
    a0 = func_0216D508(a0);
loc_0216CF64:
a0 = t4 + 0;
    a0 = func_0216E180(a0);
loc_0216CF6A:
    return a0;}
