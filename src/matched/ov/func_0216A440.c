/*
 * function: func_0216A440
 * address:  0x0216A440
 * packet:   pkt_0216A440
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021D0A74  0x021D0A74  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F50(void *base);
extern int func_02159B10();
extern int func_021D0A74();

int func_0216A440(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A44C:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A452:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A456:
    v2 = func_02012F50(p);
loc_0216A45A:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10(a0, a1);
loc_0216A464:
a1 = a0 + 0;
a0 = *(int *)((char *)v2);
    a0 = func_021D0A74(a0, a1);
loc_0216A46C:
a0 = 0;
    return a0;}
