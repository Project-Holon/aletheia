/*
 * function: UNION_COMMAND_GetRecvBuffer
 * address: 0x02173984
 * packet: pkt_ov012_02173984
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02175624 0x02175624 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02175624[];
u8 *UNION_COMMAND_GetRecvBuffer(int a, u8 *b, int c)
{
    if (c > 0x800) func_02034714(d_02175624, 0, d_02175624);
    return b + 4 + a * 0x800;
}
