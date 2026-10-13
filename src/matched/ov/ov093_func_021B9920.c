/*
 * function: BTL_SIDE_GetClientPoke
 * address: 0x021B9920
 * packet: pkt_ov093_021B9920
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct S2;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
u8 *BTL_SIDE_GetClientPoke(void *p, u32 i, u8 j)
{
    return BTL_SLOT_GetPokeParam((void *)((unsigned int)p + 4 + i * 28), j);
}
