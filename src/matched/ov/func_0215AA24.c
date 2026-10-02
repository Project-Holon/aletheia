/*
 * function: func_0215AA24
 * address:  0x0215AA24
 * packet:   pkt_0215AA24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215909C  0x0215909C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215909C(u8 *a);

void *func_0215AA24(int a0)
{
    int t4;
    void *p;
    void *v0;

t4 = a0 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215AA2C:
    p = func_0215909C((u8 *)v0);
loc_0215AA30:
*(void **)((char *)t4 + 0x1c) = p;
    return p;}
