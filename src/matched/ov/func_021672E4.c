/*
 * function: func_021672E4
 * address:  0x021672E4
 * packet:   pkt_021672E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EC0  0x02012EC0  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *func_02012EC0(struct Big *p);
extern void *func_0200C0E8(void *sys);
extern int func_0200C1DC();

int func_021672E4(int a0)
{
    void *big;
    void *sys;


a0 = *(int *)((char *)a0 + 8);
    big = func_02012EC0((struct Big *)a0);
loc_021672EC:
    sys = func_0200C0E8(big);
loc_021672F0:
    a0 = func_0200C1DC(sys);
loc_021672F4:
    return a0;}
