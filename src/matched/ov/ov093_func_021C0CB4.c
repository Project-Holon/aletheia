/*
 * function: func_021C0CB4
 * address: 0x021C0CB4
 * packet: pkt_ov093_021C0CB4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Record shape follows the matched unpacker func_021C0CE8.
 * The byte count admits multiple four-byte trailing records (q+4+i*4);
 * a flexible array models that extent without imposing a one-record bound.
 * The original narrows the five-bit field to u8 before the call.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
struct Ent {
    u16 v;
    u16 lo:5;
    u16 b:4;
    u16 c:4;
    u16 d:1;
    u16 e:1;
    u16 f:1;
};
struct Q { u8 pad0[2]; u8 n; u8 pad3; struct Ent e[]; };
u32 func_021C0CB4(u8 *p, const struct Q *q, u32 *out)
{
    u32 i = 0;
    for (; i < q->n; i++)
        out[i] = (u32)func_021B9934(*(char **)(p + 8), (u8)q->e[i].lo);
    return q->n;
}
