/*
 * function: INTRUDE_COMM_SendReturnResult
 * address:  0x021747A8
 * packet:   pkt_ov011_021747A8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned int   u32;
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int INTRUDE_COMM_SendReturnResult(int a, int b)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), b, 0x226, 8, a, 0, 0, 0);
}
