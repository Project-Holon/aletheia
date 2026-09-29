/*
 * unit:     yes
 * function: func_021D9934, func_021D996C
 * address:  0x021D9934
 * packet:   pkt_ov093_021D9934
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  func_0201C1E8 (arm9 thumb, no witness): an unlabelled arm9 leaf, Ilias's.
 *           Verified C (one, no --region, --thumb, cc dsi/1.1p1, -O4,p: EXACT):
 *             typedef unsigned int u32;
 *             extern u32 sub_0201BD28(void *p, u32 id);   (symbols: sub_0201BD28 0x0201BD28 thumb)
 *             u32 sub_0201C1E8(void *p) { return sub_0201BD28(p, 2); }
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F0930     0x021F0930  data   ov093  a4
 */

typedef unsigned short u16;

extern int func_021D775C(int);
extern int func_021C8288(int);
extern int func_0201C1E8(u16);
extern int func_021D7704(int, int);
extern int d_021F0930[];

void func_021D9934(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021C8288(b) == 1) {
        if (func_0201C1E8(func_021D775C(0x12)) == 2)
            func_021D7704(0x35, 0x1800);
    }
}

int *func_021D996C(int *p)
{
    *p = 2;
    return d_021F0930;
}
