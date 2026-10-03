/*
 * function: func_02164978
 * address:  0x02164978
 * packet:   pkt_02164978
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021F558C  0x021F558C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern int func_021F558C();

int func_02164978(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_02164982:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_02164988:
    v2 = func_0201210C(v1);
loc_0216498C:
    a0 = func_021F558C(v2);
loc_02164990:
a0 = 0;
    return a0;}
