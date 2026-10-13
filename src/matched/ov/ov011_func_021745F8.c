/*
 * function: func_021745F8
 * address: 0x021745F8
 * packet: pkt_ov011_021745F8
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
int func_021745F8(u32 a, u32 b)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), a, 0x222, 0x14, b, 0, 0, 0);
}
