/*
 * function: func_021DB93C
 * address:  0x021DB93C
 * packet:   pkt_ov093_021DB93C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   func_021DB99C  0x021DB99C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021B9A24(u32 a, u32 b);
extern int func_021E85F8(int c);
extern u32 sub_0201C1BC(u16 move);
extern int func_021DB99C(int t);
extern int func_021D76BC(int key, u32 val);

static inline void set8(int k, u8 v)
{
    func_021D76BC(k, v);
}

void func_021DB93C(int a, int b, int x)
{
    int ok;
    u16 t;

    if (func_021B9A24((u8)func_021D775C(3), x) == 0) {
        ok = 0;
        if (func_021E85F8(x) != 0) {
            ok = 1;
        } else {
            t = func_021D775C(0x12);
            if (sub_0201C1BC(t) == 10)
                ok = 1;
            else if (func_021DB99C(t) != 0)
                ok = 1;
        }
        if (ok != 0)
            set8(0x20, func_021D775C(0x20) + 1);
    }
}
