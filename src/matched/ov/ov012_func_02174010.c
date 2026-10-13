/*
 * function: UNION_COMMAND_SendAppData
 * address: 0x02174010
 * packet: pkt_ov012_02174010
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D4D0 0x0203D4D0 arm
 */
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D4D0(u32, u32, u32, u32, u32, u32, u32, u32);
u32 UNION_COMMAND_SendAppData(u32 a, void *p)
{
    return func_0203D4D0((u32)func_020399A8(), a, 0x1412, 0x28, (u32)p, 1, 0, 0);
}
