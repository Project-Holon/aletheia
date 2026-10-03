/*
 * function: func_021E84B8
 * address:  0x021E84B8
 * packet:   pkt_ov093_021E84B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);

void func_021E84B8(int a, int b, int c, int *d)
{
    int k;

    if (c == func_021D775C(2)) {
        if (d[0] != 0) {
            k = 0;
            switch (d[1]) {
            case 1:
                k = 0x206;
                break;
            case 2:
                k = 0x207;
                break;
            case 3:
                k = 0x208;
                break;
            }
            func_021D76BC(0x13, k);
        }
    }
}
