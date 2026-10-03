/*
 * function: func_021DEC70
 * address:  0x021DEC70
 * packet:   pkt_ov093_021DEC70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021DED0C  0x021DED0C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D679C  0x021D679C  thumb  ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _s32_div_f     0x0209C0A4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void func_021D7704(int a, int b);
extern int func_021DED0C(u16 v);
struct QL;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D679C(void *m);
extern u16 func_021D67A8(struct QL *p);
extern int func_021DCFF8(int a, int b);

void func_021DEC70(int a, void *b, int c)
{
    void *m;
    u16 n;
    u16 v;
    u16 id;
    int t;
    float x;

    if (c == func_021D775C(3)) {
        if (func_021DED0C(func_021D775C(0x12)) == 0) {
            m = func_021C7CF4(b, c);
            n = func_021D679C(m);
            if (n >= 1) {
                id = func_021D775C(0x12);
                if (id == func_021D67A8(m)) {
                    v = n * func_021DCFF8(a, 2) + 100;
                    if (v > 200)
                        v = 200;
                    if (v != 0)
                        x = 0.5f + (float)(v << 12);
                    else
                        x = (float)(v << 12) - 0.5f;
                    t = (int)x;
                    func_021D7704(0x35, t / 100);
                }
            }
        }
    }
}
