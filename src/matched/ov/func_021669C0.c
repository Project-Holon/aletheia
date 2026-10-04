/*
 * function: func_021669C0
 * address:  0x021669C0
 * packet:   pkt_021669C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 64 compiled 62
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02166834  0x02166834  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;

extern void *func_020120F4(const struct Ctx *p);
extern int func_02012F38();
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02166834(int a0, int a1);

int func_021669C0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    void *ctx;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_021669CC:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_021669D2:
    ctx = func_020120F4((const struct Ctx *)v1);
loc_021669D6:
    a0 = func_02012F38(ctx);
loc_021669DA:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_021669E4:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_021669EE:
a0 = t6 + 0;
a1 = t7 + 0;
    a0 = func_02166834(a0, a1);
loc_021669F8:
*q = a0;
a0 = 0;
    return a0;}
