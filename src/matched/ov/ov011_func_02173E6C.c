/*
 * function: INTRUDE_CMD_SendJoinReply
 * address:  0x02173E6C
 * packet:   pkt_ov011_02173E6C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int INTRUDE_COMM_IsLinked(void);
typedef unsigned int   u32;
u32 func_0203D1C0(u32 index);
struct Entry;
struct Entry *func_020399A8(void);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int INTRUDE_CMD_SendJoinReply(int a, int b, int c)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    if (func_0203D1C0(c & 0xFF) == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), (unsigned char)c, 0x211, 0x38, b, 0, 0, 0);
}
