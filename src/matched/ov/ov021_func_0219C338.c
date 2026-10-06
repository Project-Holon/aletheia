/*
 * function: func_0219C338
 * address:  0x0219C338
 * packet:   pkt_ov021_0219C338
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D5384     0x021D5384  data   a4
 *   d_021D5454     0x021D5454  data   ov021  a4
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_0219C314  0x0219C314  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_0216DA44  0x0216DA44  thumb
 *   func_021642A4  0x021642A4  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 d_021D5384[];
extern u32 d_021D5454[][2];

extern u16 func_0216D608(void *p);
extern int func_0219C314(int a, int *s, u32 c);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(int a0, int a1);
extern void func_0216DA44(int a);
extern u16 func_021642A4(int i);

int func_0219C338(int a, u32 *s, u32 c)
{
    u32 t;
    u32 k;
    u32 v;
    int r;

    k = s[2];
    t = func_0216D608((void *)a);
    r = func_0219C314(a, (int *)(&t), k);
    if (t == 9) {
        t = func_0216D608((void *)a);
        func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
        return 0;
    }
    if (r == 0) {
        v = (u32)func_02197E7C((u16)t, (u16)c);
        func_0216DA44(a);
        func_0216D438(a, (u16)v);
        return 1;
    }
    if ((1 & r) && s[1] == 2) {
        t = func_021642A4(func_0216D608((void *)a));
        k = d_021D5384[k];
        s[2] = k;
        r = func_0219C314(a, (int *)(&t), k);
        if (t == 9) {
            t = func_0216D608((void *)a);
            func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
            return 0;
        }
        if (r == 0) {
            v = (u32)func_02197E7C((u16)t, (u16)c);
            func_0216DA44(a);
            func_0216D438(a, (u16)v);
            return 1;
        }
    }
    if (r & 2) {
        t = d_021D5454[t][k];
        r = func_0219C314(a, (int *)(&t), k);
        if (t == 9) {
            t = func_0216D608((void *)a);
            func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
            return 0;
        }
        if (r == 0) {
            v = (u32)func_02197E7C((u16)t, (u16)c);
            func_0216DA44(a);
            func_0216D438(a, (u16)v);
            return 1;
        }
    }
    t = func_0216D608((void *)a);
    func_0216D438(a, (u16)((u32)func_02197E7C((u16)t, (u16)0x1c)));
    return 0;
}
