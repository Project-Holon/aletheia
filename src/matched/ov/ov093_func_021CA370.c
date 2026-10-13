/*
 * function: func_021CA370
 * address: 0x021CA370
 * packet: pkt_ov093_021CA370
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero bytes at 021CA392 are alignment padding.
 * symbols:
 *   BTL_SERVER_FLOW_PromoteActionOfPoke 0x021BD148 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_SERVER_FLOW_PromoteActionOfPoke(void *, u8);
struct Msg;
extern int func_021C99A0(void *, const struct Msg *);
int func_021CA370(u8 *p, const u8 *q)
{
    if (BTL_SERVER_FLOW_PromoteActionOfPoke(p, q[4])) {
        func_021C99A0(p, (const struct Msg *)(q + 8));
        return 1;
    }
    return 0;
}
