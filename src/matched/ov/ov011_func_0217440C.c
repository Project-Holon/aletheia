/*
 * function: INTRUDE_COMM_SendBusyBegin
 * address: 0x0217440C
 * packet: pkt_ov011_0217440C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_IsLinked 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned int u32;
int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *func_020399A8(void);
u32 func_0203D3F8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 INTRUDE_COMM_SendBusyBegin(void)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), 0, 0x21e, 0, 0, 0, 0, 0);
}
