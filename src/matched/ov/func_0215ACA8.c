/*
 * function: func_0215ACA8
 * address:  0x0215ACA8
 * packet:   pkt_0215ACA8
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
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C258  0x0200C258  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_02012F08(int *p);
extern int func_0200C258();

int func_0215ACA8(int a0, int a1)
{
    u16 *t4;
    int t5;
    void *p;
    void *v0;

t5 = a1 + 0;
    t4 = func_02159AE8((void *)a0, (void *)a1);
loc_0215ACB0:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215ACB8:
    p = func_02012F08((int *)v0);
loc_0215ACBC:
    a0 = func_0200C258(p);
loc_0215ACC0:
*t4 = a0;
a0 = 0;
    return a0;}
