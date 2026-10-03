/*
 * function: func_021DB4E8
 * address:  0x021DB4E8
 * packet:   pkt_ov093_021DB4E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8290  0x021C8290  thumb  ov093
 *   func_021DB550  0x021DB550  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C8290(int a, int k, int c, int t);
extern int func_021DB550(int t);
extern int func_021D76BC(int key, u32 val);

int func_021DB4E8(int a, int b, int c, int d)
{
    u8 k;
    u16 t;
    u8 n;

    k = func_021D775C(3);
    if (k != b && d == func_021D775C(0x16)) {
        t = func_021D775C(0x12);
        if (func_021C8290(a, k, b, t) == 0 && func_021DB550(t) == 0) {
            n = func_021D775C(4);
            if (func_021D76BC(4, b) != 0 && n != b)
                return 1;
        }
    }
    return 0;
}
