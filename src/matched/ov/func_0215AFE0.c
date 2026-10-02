/*
 * function: func_0215AFE0
 * address:  0x0215AFE0
 * packet:   pkt_0215AFE0
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
 *   func_0200CA28  0x0200CA28  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
extern void *func_0200CA1C(void *a);
extern int func_0200CA28();

int func_0215AFE0(int a0, int a1)
{
    void *p;
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AFE8:
    p = func_0200CA1C(v0);
loc_0215AFEC:
    a0 = func_0200CA28(p);
loc_0215AFF0:
a0 = 0;
    return a0;}
