/*
 * function: func_021BE3CC
 * address:  0x021BE3CC
 * packet:   pkt_ov099_021BE3CC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * note: 2026-10-05 (wD7 lane09): EXACT*. The column offset is written inline in the index, (base + (d & 0xF) * 2)[...], so mwcc hoists it as its own temp (no ptr local: that local swapped p and base). The call result t is used inline as (t << 12) (a named x local took the higher spill slot). The (u32) on the u16 width read is real: without it the shift is asrs, the image has lsrs.
 * symbols:
 *   func_021BE4EC  0x021BE4EC  thumb  ov099
 *   func_02042FB0  0x02042FB0  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BE4EC(u32 a);
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
extern void func_02041B6C(u32 bit);

void func_021BE3CC(char *p, u32 a, u8 b, u8 c, u32 d, int e)
{
    int row;
    u32 stride;
    u16 *base;
    int i, j;
    int t;

    base = (u16 *)(*(char **)(p + 4) + 0xC);
    t = func_021BE4EC(a);
    row = (d >> 4) * 2;
    stride = (u32)**(u16 **)(p + 4) >> 3;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            func_02042FB0(a, j + b, i + c, (t << 12) + (base + (d & 0xF) * 2)[(row + i) * stride + j]);
        }
    }
    func_02041B6C((u8)a);
}
