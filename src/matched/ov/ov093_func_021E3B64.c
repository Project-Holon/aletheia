/*
 * function: func_021E3B64
 * address:  0x021E3B64
 * packet:   pkt_ov093_021E3B64
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021E8624  0x021E8624  thumb  ov093
 *   d_021F2856     0x021F2856  data   a1
 */

typedef unsigned char u8;

extern int func_021D775C(int);
typedef unsigned int   u32;
extern void *func_021C7CF4(int *p, int i);
extern unsigned char func_021D69AC(unsigned char *base, int idx);
extern u32 func_021D78AC(u32 range);
extern int func_021D76BC(int key, u32 val);
extern int func_021E8624(int a, int b);
extern const u8 d_021F2856[];

void func_021E3B64(int u, void *a, int c)
{
    unsigned x;

    if (c == func_021D775C(2)) {
        x = func_021D69AC(func_021C7CF4(a, c), 3);
        if (x != 0) {
            if (x >= 10)
                x = 9;
            if (func_021D78AC(d_021F2856[x]) != 0) {
                func_021D76BC(0x22, 0x1a);
                return;
            }
        }
        if (func_021E8624((int)a, c) != 0)
            func_021D76BC(0x22, 0x1a);
    }
}
