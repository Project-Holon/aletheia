/*
 * function: func_021C6B4C
 * address: 0x021C6B4C
 * packet: pkt_ov136_021C6B4C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C7D68 0x021C7D68 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Row { int (*a)(u8 *); int (*b)(u8 *); };
extern const struct Row d_021C7D68[];
extern void func_02027974(void *);
extern u32 func_020279E8(void *);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(void *);
int func_021C6B4C(u8 *p)
{
    func_02027974(*(void **)(*(u8 **)(p + 8) + 0x310));
    if (func_020279E8(*(void **)(*(u8 **)(p + 8) + 0x310)) == 0) return 4;
    switch (func_02027A04(*(u8 **)(*(u8 **)(p + 8) + 0x310))) {
    case 0:
        func_02027858(*(void **)(*(u8 **)(p + 8) + 0x310));
        return d_021C7D68[*(int *)(*(u8 **)(p + 8) + 0x1E0)].a(p);
    case 1:
        func_02027858(*(void **)(*(u8 **)(p + 8) + 0x310));
        return d_021C7D68[*(int *)(*(u8 **)(p + 8) + 0x1E0)].b(p);
    }
    return 4;
}
