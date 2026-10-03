/*
 * function: func_0216B538
 * address:  0x0216B538
 * packet:   pkt_0216B538
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
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C224  0x0200C224  thumb
 *   func_0200C22C  0x0200C22C  thumb
 *   func_02027138  0x02027138  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
struct Blk34;
extern u8 func_0200C224(struct Blk34 *p);
extern int func_0200C22C();
extern int func_02027138();

int func_0216B538(int a0, int a1)
{
    int t4;
    void *t5;
    void *p;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216B542:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0216B548:
    p = func_02012EBC((struct Big *)v1);
loc_0216B54C:
    t5 = func_0200C0F0(p);
loc_0216B550:
    a0 = func_0200C224(t5);
loc_0216B556:
t4 = a0 + 0;
    if (t4 < 5) goto loc_0216B560;
loc_0216B55C:
a0 = 0;
    return a0;
loc_0216B560:
a1 = t4 + 1;
    a0 = func_0200C22C(t5, a1);
loc_0216B568:
a0 = t4 + 1;
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    a0 = func_02027138(a0);
loc_0216B572:
a0 = 0;
    return a0;}
