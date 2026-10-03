/*
 * function: func_0215AFF4
 * address:  0x0215AFF4
 * packet:   pkt_0215AFF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_0200CA1C(void *a);
struct Blk37;
extern u32 func_0200CA38(struct Blk37 *p);

int func_0215AFF4(int a0, int a1)
{
    int t5;
    void *p;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AFFC:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B004:
    p = func_0200CA1C(v0);
loc_0215B008:
    a0 = func_0200CA38(p);
loc_0215B00C:
*q = a0;
a0 = 0;
    return a0;}
