/*
 * function: func_021E10D8
 * address:  0x021E10D8
 * packet:   pkt_ov093_021E10D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F286C     0x021F286C  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern u32 func_021D78AC(u32 range);
extern Word func_021D7D18(int x);
extern int func_021D76BC(int key, u32 val);
extern u32 d_021F286C[];

void func_021E10D8(int unused, void *q, int id)
{
    u32 v;
    Word w;
    int k;

    k = 3;
    if (id == func_021D775C(3)) {
        v = d_021F286C[(u8)func_021D78AC(k)];
        w = func_021D7D18(v);
        func_021D76BC(0x1d, v);
        func_021D76BC(0x1e, w.v);
        func_021D76BC(0x26, 0x14);
    }
}
