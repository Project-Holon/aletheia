/*
 * function: func_021CF940
 * address:  0x021CF940
 * packet:   pkt_ov021_021CF940
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Counts the 30 slots whose value func_021CFA04 accepts.
 *
 * symbols:
 *   func_0201293C  0x0201293C  thumb
 *   func_020079BC  0x020079BC  thumb
 *   func_021CFA04  0x021CFA04  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0201293C(void *p);
extern u32   func_020079BC(void *a, void *b, int i, u32 id, u32 v);
extern int   func_021CFA04(void *a, u32 b, int c);

int func_021CF940(void *a, void *src, void *b, int c)
{
    void *h = func_0201293C(src);
    int n = 0;
    int i;

    for (i = 0; i < 30; i++) {
        if (func_020079BC(h, b, i, 0xa9, 0) != 0) {
            if (func_020079BC(h, b, i, 0x4c, 0) == 0) {
                u32 v = func_020079BC(h, b, i, 7, 0);
                if (func_021CFA04(a, v, c) != 0) {
                    n++;
                }
            }
        }
    }
    return n;
}
