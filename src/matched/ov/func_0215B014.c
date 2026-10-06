/*
 * function: func_0215B014
 * address:  0x0215B014
 * packet:   pkt_0215B014
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA40  0x0200CA40  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
extern void *func_0200CA1C(void *a);
struct Blk37;
extern struct Blk37 *func_0200CA40(struct Blk37 *p);

int func_0215B014(int a0, int a1)
{
    void *p;
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B01C:
    p = func_0200CA1C(v0);
loc_0215B020:
    a0 = (int)func_0200CA40(p);
loc_0215B024:
a0 = 0;
    return a0;}
