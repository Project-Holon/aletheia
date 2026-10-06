/*
 * function: func_021E6DAC
 * address:  0x021E6DAC
 * packet:   pkt_ov093_021E6DAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021B8C20  0x021B8C20  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C7D00(u8 *p, int b);
extern int func_021C815C(int *p);
extern u8 func_021B8C20(int kind, u32 flags, u32 v);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern void *func_021C7CF4(int *p, int i);
struct QL;
extern u16 func_021D67A8(struct QL *p);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern int func_021D76BC(int key, u32 val);

void func_021E6DAC(int x, int a, int c, u8 *d)
{
    u8 k;
    u16 t;
    u32 fl;

    if (c == func_021D775C(2)) {
        k = func_021D775C(0xe);
        if (k == 6) {
            fl = func_021C7D00((u8 *)a, c);
            k = func_021B8C20(func_021C815C((int *)a), fl, 0);
        }
        if (func_021C7F68((int *)a, k, d) != 0) {
            t = func_021D67A8(func_021C7CF4((int *)a, *d));
            if (t == 0 || func_0201BEB8(t, 6) == 0) {
                func_021D76BC(0x41, 1);
                return;
            }
            func_021D76BC(0x12, t);
            func_021D76BC(0xd, k);
        }
    }
}
