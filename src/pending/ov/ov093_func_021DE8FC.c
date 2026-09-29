/*
 * unit:     yes
 * function: func_021DE8FC, func_021DE93C
 * address:  0x021DE8FC
 * packet:   pkt_ov093_021DE8FC
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
 *   d_021F18D4     0x021F18D4  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int k);
extern void *func_021C7CF4(int a, int b);
extern u16 func_021D5444(void *p);
extern int func_0201C1E8(u16 x);
extern void func_021D7704(int key, int m);
extern int d_021F18D4;

void func_021DE8FC(int u, int a, int b)
{
    if (b == func_021D775C(3)) {
        if ((u32)func_021D5444(func_021C7CF4(a, b)) - 0x68 <= 1) {
            if (func_0201C1E8(func_021D775C(0x12)) == 1)
                func_021D7704(0x35, 2 << 12);
        }
    }
}

int *func_021DE93C(int *p)
{
    *p = 3;
    return &d_021F18D4;
}
