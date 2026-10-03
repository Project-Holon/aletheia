/*
 * function: func_0218878C
 * address: 0x0218878C
 * packet: pkt_ov096_0218878C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *);
int func_0218878C(struct Cursor *a, u8 *b)
{
    u32 value;
    value = func_0201134C(a);
    *(u32 *)((u32)b + 4 + b[1] * 4) += value;
    if (*(int *)((u32)b + 4 + b[1] * 4) < 0)
        *(int *)((u32)b + 4 + b[1] * 4) = 0;
    return *(int *)(b + 0xc4);
}
