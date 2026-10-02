/*
 * function: func_0215CEE8
 * address:  0x0215CEE8
 * packet:   pkt_0215CEE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_021C335C  0x021C335C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern int func_02188D50(void *a0);
extern int func_021C335C(int a0);

int func_0215CEE8(int a0, int a1)
{
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215CEF0:
    v1 = func_0201210C(v0);
loc_0215CEF4:
    a0 = func_02188D50(v1);
loc_0215CEF8:
    a0 = func_021C335C(a0);
loc_0215CEFC:
a0 = 0;
    return a0;}
