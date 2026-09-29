/*
 * function: func_0219A6CC
 * address:  0x0219A6CC
 * packet:   pkt_ov021_0219A6CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021D5024     0x021D5024  data  a4
 *   d_021D5038     0x021D5038  data  a4
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 */

typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int v[5]; } Arr;
extern const Arr d_021D5024;
extern const Arr d_021D5038;
extern int func_0216D5F8(u32);
extern void func_0216D5E0(u32, u16);

int func_0219A6CC(u32 a, s8 *b)
{
    Arr ta = d_021D5024;
    Arr tb = d_021D5038;
    int *t;
    int i;
    int cur;
    t = ta.v;
    if (b[0] != 2)
        t = tb.v;
    cur = func_0216D5F8(a);
    i = 0;
    if (t[0] != 9) {
        do {
            if (cur == t[i])
                break;
            i++;
        } while (t[i] != 9);
    }
    i++;
    if (t[i] == 9)
        i = 0;
    func_0216D5E0(a, t[i]);
    b[2] = 0;
    return 1;
}
