/*
 * function: func_021E8744
 * address:  0x021E8744
 * packet:   pkt_ov093_021E8744
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
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8434  0x021C8434  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021B9A24(u8 c, int k);
extern u32 sub_0201C1BC(u16 move);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern int func_021D76BC(int a, int b);
extern void func_021C8434(void *a, int b, int c);

void func_021E8744(int u, void *a, int b)
{
    u8 k;
    u16 m;

    k = func_021D775C(2);
    if (func_021B9A24(k, b) == 0) {
        m = func_021D775C(0x12);
        if (sub_0201C1BC(m) == 0xb) {
            if (func_0201BEB8(m, 4) != 0) {
                if (func_021D76BC(0x22, 0x19) != 0)
                    func_021C8434(a, b, k);
            }
        }
    }
}
