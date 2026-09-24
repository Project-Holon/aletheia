/*
 * function: func_02163010
 * address:  0x02163010
 * packet:   pkt_02163010
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  
 *
 * symbols:
 *   func_0216D6F4  0x0216D6F4  thumb  ov010
 *   func_0219B414  0x0219B414  thumb
 *   func_0216D548  0x0216D548  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D6F4();
extern int func_0219B414();
extern int func_0216D548();

int func_02163010(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216D6F4();
loc_02163018:
a0 = t4 + 0;
    a0 = func_0219B414(a0);
loc_0216301E:
a0 = t4 + 0;
a1 = 2;
    a0 = func_0216D548(a0, a1);
loc_02163026:
    return a0;}
