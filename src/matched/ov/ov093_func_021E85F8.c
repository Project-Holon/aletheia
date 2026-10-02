/*
 * function: func_021E85F8
 * address:  0x021E85F8
 * packet:   pkt_ov093_021E85F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);

int func_021E85F8(int v)
{
    u32 i;
    u32 n;

    n = func_021D775C(5);
    i = 0;
    if (n != 0) {
        do {
            if (v == func_021D775C(i + 6))
                return 1;
            i++;
        } while (i < n);
    }
    return 0;
}
