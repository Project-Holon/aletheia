/*
 * function: func_021C024C
 * address: 0x021C024C
 * packet: pkt_ov093_021C024C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Wide third extern argument preserves the full r2 passed by the image.
 * symbols:
 *   func_021C02CC 0x021C02CC thumb ov093
 *   func_021C0450 0x021C0450 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021C02CC(u8 *, u8 *, u32, int);
extern void func_021C0450(u8 *, u8 *, u32, int);
int func_021C024C(u8 *p, u8 *a, u32 c)
{
    int result;
    if (c != 0xa5) {
        result = func_021C02CC(p, a, c, 0x1f);
        if (result != 0) {
            func_021C0450(p, a, c, result);
            return 1;
        }
    }
    return 0;
}
