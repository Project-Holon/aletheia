/*
 * function: func_0215F318
 * address:  0x0215F318
 * packet:   pkt_0215F318
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215911C  0x0215911C  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02159114  0x02159114  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern u32 func_0215911C(void *p);
extern int func_020307B0();
extern int func_02159114();

int func_0215F318(int a0, int a1)
{    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215F320:
    a0 = func_0215911C(v0);
loc_0215F326:
    if (a0 == 0) goto loc_0215F336;
loc_0215F32A:
    a0 = func_020307B0(a0);
loc_0215F32E:
a1 = 0;
    a0 = func_02159114(v0, a1);
loc_0215F336:
a0 = 0;
    return a0;}
