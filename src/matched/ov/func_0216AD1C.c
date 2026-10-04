/*
 * function: func_0216AD1C
 * address:  0x0216AD1C
 * packet:   pkt_0216AD1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216AED0  0x0216AED0  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0216AF1C  0x0216AF1C  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201EE84  0x0201EE84  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int func_02159B10(void *, void *);
extern void *func_0216AED0(void *p, u32 id);
extern u16 func_0215A5CC(void *a0);
extern int func_0216AF1C();
extern void *func_0215A5F4(void *p);
extern void *func_02158F74(void *p);
struct WordSet;
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern int func_020307B0();

int func_0216AD1C(int a0, int a1, int a2, int a3)
{
    int v0;
    int t4;
    int t5;
    int t6;
    int t7;
    void *obj;
    void *v1;
t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216AD26:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216AD30:
t7 = a0 + 0;
a0 = t4 + 0;
a1 = t6 + 0;
    obj = func_0216AED0((void *)a0, a1);
loc_0216AD3A:
    if (obj == 0) goto loc_0216AD6C;
loc_0216AD3E:
a0 = t4 + 0;
    a0 = func_0215A5CC((void *)a0);
loc_0216AD44:
a2 = a0 + 0;
a0 = t4 + 0;
a3 = (int)&v0;
    a0 = func_0216AF1C(a0, obj, a2, a3);
loc_0216AD50:
t5 = a0 + 0;
    if (t5 == 0) goto loc_0216AD6C;
loc_0216AD54:
a0 = t4 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0216AD5A:
    a0 = (int)func_02158F74(v1);
loc_0216AD5E:
a1 = t7 + 0;
a2 = t5 + 0;
    func_0201EE84((void *)a0, a1, (void *)a2);
loc_0216AD66:
a0 = t5 + 0;
    a0 = func_020307B0(a0);
loc_0216AD6C:
a0 = 0;
    return a0;
}
