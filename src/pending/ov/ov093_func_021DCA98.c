/*
 * function: func_021DCA98
 * address:  0x021DCA98
 * packet:   pkt_ov093_021DCA98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocked: func_0201C1E8 (arm9 unlabelled leaf, Ilias's; 12-byte tail stub,
 *   no witness outside this range). Verified C, one --thumb (no --region),
 *   EXACT at 0x0201C1E8:
 *     extern int func_0201BD28(int, int);   // symbols: func_0201BD28 0x0201BD28 thumb
 *     int func_0201C1E8(int a) { return func_0201BD28(a, 2); }
 *   The rest of this function is byte-correct (MATCH*, one wildcard).
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_0201C1E8(u16 a);
extern int func_021D76BC(int a, int b);

void func_021DCA98(int a, int b, int c)
{
    u8 v;

    if (c == func_021D775C(3) && func_0201C1E8(func_021D775C(0x12)) == 0) {
        v = func_021D775C(0x18);
        func_021D76BC(0x18, v + 1);
    }
}
