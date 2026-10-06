/*
 * function: func_021ED988
 * address:  0x021ED988
 * packet:   pkt_ov093_021ED988
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED9C8  0x021ED9C8  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct E;
extern void func_021ED9C8(struct E *e);
void func_021ED988(u8 *p)
{
    u32 i;
    for (i = 0; i < 6; i++)
        func_021ED9C8((struct E *)(p + 0x48 + i * 12));
}
