/*
 * function: func_021BE2DC
 * address: 0x021BE2DC
 * packet: pkt_ov099_021BE2DC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021BE382.
 * symbols:
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049E74 0x02049E74 arm
 *   func_02049EF4 0x02049EF4 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02049B68(u32, u32, u32, u32, u32, u16);
extern u32 func_02049740(u32, u32, u32, u32, u32, u16);
extern void *func_02049E74(u32, u32, u32, u32, u16);
extern void *func_02049EF4(u32, u32, u32, u32, u16);
void func_021BE2DC(char *p, u32 a, int b)
{
    func_02049B68(a, 4, 0, 0x100, 0x80, b);
    func_02049B68(a, 4, 4, 0x100, 0x80, b);
    *(u32 *)(p + 0x10) = func_02049740(a, 13, 1, 0, 0, b);
    *(u32 *)(p + 0x14) = func_02049740(a, 13, 6, 0, 0, b);
    if (*(void **)(p + 8) == 0) {
        *(void **)(p + 8) = func_02049E74(a, 13, 0, (u32)(p + 12), b);
    }
    if (*(void **)p == 0) {
        *(void **)p = func_02049EF4(a, 21, 0, (u32)(p + 4), b);
    }
}
