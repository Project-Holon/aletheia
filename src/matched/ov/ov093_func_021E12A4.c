/*
 * function: func_021E12A4
 * address:  0x021E12A4
 * packet:   pkt_ov093_021E12A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: the constant 6 lives in r5 across the calls (movs r5,#6 before the
 * func_021D5844 bl); an int local folds it into each use, an enum local keeps it.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021C7ED8  0x021C7ED8  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021D7DC0  0x021D7DC0  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef enum { K_SIX = 6 } K;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *p, int k);
extern u16 func_021D5444(void *p);
extern u32 func_021C7ED8(void *a, int b);
extern u32 func_021D5844(void *m);
extern void func_021D7DC0(int a, void *b, void *out);
extern int func_021D76BC(int key, u32 val);

void func_021E12A4(int unused, void *q, int id)
{
    void *m;
    u32 n;
    K a;
    int b;
    u32 out;

    if (id == func_021D775C(3)) {
        m = func_021C7CF4(q, id);
        if (func_021D5444(m) == 0x1b9) {
            n = func_021C7ED8(q, id);
            if (n != 0) {
                a = K_SIX;
                func_021D5844(m);
                if (n > 2)
                    b = 0x1e;
                else
                    b = 10;
                func_021D7DC0(a, m, &out);
                func_021D76BC(0x1d, a);
                func_021D76BC(0x1e, out);
                func_021D76BC(0x26, b);
            }
        }
    }
}
