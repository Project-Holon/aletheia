/*
 * unit:     yes
 * function: func_021DE70C, func_021DE740
 * address:  0x021DE70C
 * packet:   pkt_ov093_021DE70C
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
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021DD008  0x021DD008  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F13EC     0x021F13EC  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int k);
extern int func_0201C1E8(u16 x);
extern int func_021DD008(int a);
extern void func_021D7704(int key, int m);
extern int d_021F13EC;

void func_021DE70C(int a, int b, int c)
{
    if (c == func_021D775C(3)) {
        if (func_0201C1E8(func_021D775C(0x12)) == 2)
            func_021D7704(0x31, func_021DD008(a));
    }
}

int *func_021DE740(int *p)
{
    *p = 1;
    return &d_021F13EC;
}
