/*
 * function: func_0216C888
 * address:  0x0216C888
 * packet:   pkt_0216C888
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02031324  0x02031324  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
extern int func_0203159C();
extern int func_02031324();

int func_0216C888(int a0, int a1, int a2)
{
    int t4;

a2 = 1;
t4 = a0 + 0;
a0 = 1;
a1 = 0x76;
a2 = a2 << 0xe;
    func_0203064C(a0, a1, a2);
loc_0216C898:
a0 = t4 + 0;
a1 = 4;
a2 = 0x76;
    a0 = func_0203159C(a0, a1, a2);
loc_0216C8A2:
t4 = a0 + 0;
a0 = 0x76;
    a0 = func_02031324(a0);
loc_0216C8AA:
*(int *)((char *)t4) = a0;
a0 = 1;
    return a0;}
