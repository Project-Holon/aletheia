/*
 * function: func_021EAC98
 * address:  0x021EAC98
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm  arm9
 *
 * Call func_02045B38 with fixed arguments.
 */

typedef unsigned int   u32;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

void func_021EAC98(void)
{
    func_02045B38(0, 2, 0xa, 0x4c);
}

