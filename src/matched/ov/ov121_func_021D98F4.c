/*
 * function: func_021D98F4
 * address: 0x021D98F4
 * packet: pkt_ov121_021D98F4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021D9580 0x021D9580 thumb ov121
 *   d_021DF574 0x021DF574 data a4
 *   d_021DF58C 0x021DF58C data a4
 *   d_021DF580 0x021DF580 data a4
 */
typedef unsigned int u32;
extern void func_021D9580(void *);
extern void func_02046440(int, int, int, int, int, u32, void (*)(void *));
extern void *func_02048A24(int, int, int, int, int, int, int, int, const void *, const void *, const void *, u32);
extern const u32 d_021DF574[];
extern const u32 d_021DF58C[];
extern const u32 d_021DF580[];
void func_021D98F4(u32 *p, u32 heap)
{
    func_02046440(0, 1, 0, 1, 0, heap, func_021D9580);
    p[0] = (u32)func_02048A24(2, 0x18000, -0x18000, -0x20000, 0x20000, 0x1000, 0x400000, 0,
                         d_021DF574, d_021DF58C, d_021DF580, heap);
    p[1] = 1;
}
