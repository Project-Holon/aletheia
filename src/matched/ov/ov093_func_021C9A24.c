/*
 * function: func_021C9A24
 * address: 0x021C9A24
 * packet: pkt_ov093_021C9A24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: const source pointer hoists the id load before the outgoing
 * stack-argument store; mutable source gave 16 scheduling bytes different.
 * symbols:
 *   func_021C9A50 0x021C9A50 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Cmd { u32 a:8; u32 id:5; u32 pad:19; u32 w4; u8 b8; u8 pad9[3]; u8 data[16]; u8 b28; };
extern int func_021C9A50(u32, u8, u8, const void *, u8);
u8 func_021C9A24(void *p, const struct Cmd *q)
{
    int r;
    if (func_021C9A50(q->w4, q->b8, q->id, q->data, q->b28)) r = 1;
    else r = 0;
    return r;
}
