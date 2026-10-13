/*
 * function: UNION_COMMAND_SendAppNotice
 * address: 0x0217410C
 * packet: pkt_ov012_0217410C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Handed label 0217410E omits the first push; &b is the r1 home slot.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D4D0 0x0203D4D0 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D4D0(u32, u32, u32, u32, u32, u32, u32, u32);
void UNION_COMMAND_SendAppNotice(u32 a, u8 b)
{
    func_0203D4D0((u32)func_020399A8(), a, 0x1414, 1, (u32)&b, 1, 0, 0);
}
