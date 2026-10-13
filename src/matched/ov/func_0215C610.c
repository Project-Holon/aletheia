/*
 * function: func_0215C610
 * address:  0x0215C610
 * packet:   pkt_0215C610
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
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern int func_0215897C();

int func_0215C610(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215C61A:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215C622:
    v2 = func_0201210C(v1);
loc_0215C628:
    a0 = FIELD_STATUS_CreateFieldCloseEvent((int)v1, (int)v2);
loc_0215C630:
a1 = a0 + 0;
    a0 = func_0215897C(v0, a1);
loc_0215C638:
a0 = 1;
    return a0;}
