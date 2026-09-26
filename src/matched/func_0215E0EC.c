/*
 * function: func_0215E0EC
 * address:  0x0215E0EC
 * packet:   pkt_0215E0EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02012F80  0x02012F80  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_0215A5E4();
extern int func_02012138();
extern int func_02012F80();
extern int func_02026454();
extern int func_02026474();

int func_0215E0EC(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_0215E0F6:
a0 = t4 + 0;
    a0 = func_0215A5DC(a0);
loc_0215E0FC:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5E4(a0);
loc_0215E104:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012138(a0);
loc_0215E10C:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_02012F80(a0);
loc_0215E114:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02026454(a0);
loc_0215E11C:
    if (a0 != 4) goto loc_0215E12C;
loc_0215E120:
a0 = t5 + 0;
    a0 = func_02026474(a0);
loc_0215E126:
*(int *)((char *)t4 + 4) = a0;
a0 = 1;
    return a0;
loc_0215E12C:
a0 = 0;
    return a0;}
