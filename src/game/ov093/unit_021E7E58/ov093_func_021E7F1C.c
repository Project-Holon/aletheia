/*
 * function: func_021E7F1C
 * address:  0x021E7F1C
 * packet:   pkt_ov093_021E7F1C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
struct QF;
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D76BC(int key, u32 val);

void func_021E7F1C(int a, void *b, int c)
{
    void *m;
    int r;
    if (c == func_021D775C(3)) {
        u8 k = func_021D775C(4);
        m = func_021C7CF4(b, k);
        r = func_021D5444(m);
        if (r == 0x32 || r == 0x33 || func_021D62C4(m, 0x1f) != 0
            || func_021D62C4(m, 0x15) != 0)
            func_021D76BC(0x40, 1);
    }
}
