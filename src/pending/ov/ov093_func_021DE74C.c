/*
 * unit:     yes
 * function: func_021DE74C, func_021DE790
 * address:  0x021DE74C
 * packet:   pkt_ov093_021DE74C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * BLOCKER: func_0201C1E8 (arm9 unlabelled tail-call stub, Ilias's) has no
 * witness outside this range; every other byte is identical. Verified C for
 * the arm9 leaf (match.py one --thumb, no --region, EXACT):
 *     int func_0201BD28(int a, int b);   // symbols: func_0201BD28 0x0201BD28 thumb
 *     int func_0201C1E8(int a) { return func_0201BD28(a, 2); }
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F139C     0x021F139C  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int k);
extern void *func_021C7CF4(int a, int b);
extern u16 func_021D5444(void *p);
extern int func_0201C1E8(u16 x);
extern void func_021D7704(int key, int m);
extern int d_021F139C;

void func_021DE74C(int u, int a, int b)
{
    if (b == func_021D775C(3)) {
        if (func_021D5444(func_021C7CF4(a, b)) == 0x16e) {
            if (func_0201C1E8(func_021D775C(0x12)) == 2)
                func_021D7704(0x35, 2 << 12);
        }
    }
}

int *func_021DE790(int *p)
{
    *p = 1;
    return &d_021F139C;
}
