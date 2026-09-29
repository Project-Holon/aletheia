/*
 * function: func_021CF9AC
 * address:  0x021CF9AC
 * packet:   pkt_ov021_021CF9AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Counts the six entries for which func_021CFA04 accepts the value read from them.
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBEC  0x0200BBEC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_021CFA04  0x021CFA04  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02012EBC(void *p);
extern void *func_0200BAC8(void);
extern void *func_0200BBEC(void *h, int a, int i);
extern u32   func_02017E88(void *p, u32 id, u32 v);
extern int   func_021CFA04(void *a, u32 b, int c);

int func_021CF9AC(void *a, void *heap, int x, int y)
{
    void *h;
    int i;
    int n;

    func_02012EBC(heap);
    h = func_0200BAC8();
    n = 0;
    for (i = 0; i < 6; i++) {
        void *p = func_0200BBEC(h, x, i);
        if (func_02017E88(p, 0xa9, 0) != 0) {
            u32 v = func_02017E88(p, 7, 0);
            if (func_021CFA04(a, v, y) != 0) {
                n++;
            }
        }
    }
    return n;
}
