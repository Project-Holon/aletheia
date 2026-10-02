/*
 * function: func_0215E6F8
 * address:  0x0215E6F8
 * packet:   pkt_0215E6F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D488  0x0200D488  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *sys);
extern int func_0200D488();

int func_0215E6F8(int a0, int a1)
{
    int t4;
    void *p;
    void *t5;

    p = func_02012EBC((struct Big *)a0);
loc_0215E6FE:
    t5 = func_0200D418(p);
loc_0215E702:
a1 = 0;
t4 = 0;
    a0 = func_0200D488(t5, a1);
loc_0215E70C:
    if (a0 != 0) goto loc_0215E71C;
loc_0215E710:
a1 = 1;
    a0 = func_0200D488(t5, a1);
loc_0215E718:
    if (a0 == 0) goto loc_0215E720;
loc_0215E71C:
a0 = 1;
    return a0;
loc_0215E720:
a0 = t4 + 0;
    return a0;}
