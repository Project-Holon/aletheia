/*
 * function: func_021B0BAC
 * address:  0x021B0BAC
 * packet:   pkt_ov021_021B0BAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B0BAC  0x021B0BAC  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_02045CAC  0x02045CAC  arm
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0215A63C  0x0215A63C  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191348  0x02191348  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_0215A654  0x0215A654  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021B0A40  0x021B0A40  thumb  ov021
 *   func_021B09EC  0x021B09EC  thumb  ov021
 *   func_0215A660  0x0215A660  thumb  ov010
 *   func_0215A678  0x0215A678  thumb  ov010
 *   func_021B0B08  0x021B0B08  thumb  ov021
 *   func_021B0ADC  0x021B0ADC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct V3 {
    int x, y, z;
} V3;

typedef struct S {
    u16 id;
    u16 flag;
    V3 sum;
    V3 a;
    V3 b;
} S;

extern void *func_0215A5F4(void *p);
extern u32 func_0215A60C(u32);
extern u32 *func_02158F58(void *);
extern u32 func_0215A5EC(u32);
extern u32 func_0216DE94(u32, int);
extern u32 func_02158F78(u8 *p);
extern u32 func_02158F74(void *);
extern u32 func_02158F7C(u8 *p);
extern void func_02045CAC(u32, u32, u32);
extern u32 func_0215A5CC(u32);
extern u32 func_02045B38(u32, u32, u32, u32);
extern void func_02045C04(u32);
extern void func_0201F250(u32, u32, u32);
extern S *func_0215A63C(u32);
extern int func_02159190(int a0);
extern int func_0215A61C(int a0);
extern u32 func_02191348(u32, u32);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_0215A654(u32);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern int func_021B0A40(u32, V3 *);
extern void func_021B09EC(int, int *, int *);
extern void func_0215A660(u32, u8);
extern void func_0215A678(u32, u8);
extern void func_021B0B08(u32, int);
extern void func_021B0ADC(u32, u32, int, V3 *, u32, int, int);

int func_021B0BAC(u32 b, u16 id, u16 c, u16 d, u16 e, int f)
{
    u32 s28;
    void *o;
    u32 *q;
    u32 t, m20, m1c, r7, r18, r5, h;
    int sel;
    S *s;
    V3 v;
    int oa, ob;

    sel = e;
    o = func_0215A5F4((void *)b);
    s28 = func_0215A60C(b);
    q = func_02158F58(o);
    t = func_0215A5EC(b);
    m20 = func_0216DE94(t, 0xff);
    m1c = func_0216DE94(t, id);
    if (m1c == 0) {
        return 0;
    }
    r7 = func_02158F78(o);
    r18 = func_02158F74(o);
    r5 = func_02158F7C(o);
    if (c == 0x400) {
        func_02045CAC(s28, d, r5);
    } else {
        h = func_02045B38(0, 3, c, func_0215A5CC(b));
        func_02045CAC(h, d, r5);
        func_02045C04(h);
    }
    func_0201F250(r18, r7, r5);
    s = func_0215A63C(b);
    if (func_02159190(2) != 0) {
        func_02191348(func_0215A61C(b), r7);
    } else {
        func_02082BCC(s, 0, 0x28);
        s->id = id;
        if (e == 0) {
            func_0215A654(b);
            func_0216D88C((const struct Actor *)m1c, (struct VecFx32 *)&v);
            sel = func_021B0A40(m20, &v);
        }
        func_021B09EC(sel, &oa, &ob);
        s->flag = oa;
        func_0215A660(b, sel);
        func_0215A678(b, e);
        func_021B0B08(b, 1);
        func_021B0ADC(b, *q, oa, &s->sum, r7, f, ob);
    }
    return 1;
}
