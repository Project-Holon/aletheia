/*
 * function: UNION_COMMAND_SendAppQuitRequest
 * address:  0x02173E1C
 * packet:   pkt_ov012_02173E1C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 UNION_COMMAND_SendAppQuitRequest(void)
{
    return func_0203D3F8((u32)func_020399A8(), 0, 0x140D, 0, 0, 1, 0, 0);
}
