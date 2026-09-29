/*
 * function: func_021D8FCC
 * address:  0x021D8FCC
 * packet:   pkt_ov093_021D8FCC
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
 * Lever: the u8 argument to func_021B9A24 is a `u8 k` local, not a cast.
 *
 * symbols:
 *   func_021D8E00  0x021D8E00  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D8E00(int a, int b);
extern int func_021C8288(int a);
extern int func_021D775C(int key);
extern int func_021B9A24(int a, int b);
extern int func_0201C1E8(u16 x);
extern void func_021D7704(int a, int b);

void func_021D8FCC(int u, int a, int b)
{
    u8 k;

    if (func_021D8E00(a, b) != 0 && func_021C8288(a) == 1) {
        k = func_021D775C(3);
        if (func_021B9A24(b, k) != 0) {
            if (func_0201C1E8(func_021D775C(0x12)) == 1)
                func_021D7704(0x35, 3 << 11);
        }
    }
}
