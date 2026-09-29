/*
 * function: func_021D8D40
 * address:  0x021D8D40
 * packet:   pkt_ov093_021D8D40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * BLOCKER: func_0201C1E8 (arm9 unlabelled tail-call stub, Ilias's) has no
 * witness outside this range: every other byte is EXACT*-identical.
 * Verified C for the arm9 leaf (match.py one --thumb, no --region, EXACT):
 *     int func_0201BD28(int a, int b);   // symbols: func_0201BD28 0x0201BD28 thumb
 *     int func_0201C1E8(int a) { return func_0201BD28(a, 2); }
 * func_021D8D9C (my lane, DIFF, note docs/notes/pkt_ov093_021D8D9C.c.txt)
 * resolves here as sole-ref.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D8D9C  0x021D8D9C  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D8D9C(int a, int b, int c, int d);
extern int func_0201C1E8(u16 x);
extern void func_021D7704(int a, int b);

void func_021D8D40(int u, int a, int b, int c)
{
    if (b == func_021D775C(3)) {
        if (func_021D8D9C(a, b, c, 0x39) != 0 || func_021D8D9C(a, b, c, 0x3a) != 0) {
            if (func_0201C1E8(func_021D775C(0x12)) == 2)
                func_021D7704(0x35, 6 << 10);
        }
    }
}
