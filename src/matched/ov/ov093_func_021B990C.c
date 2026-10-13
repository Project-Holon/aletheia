/*
 * function: BTL_SIDE_GetClientPokeParam
 * address: 0x021B990C
 * packet: pkt_ov093_021B990C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SLOT_GetPoke 0x021B9BF0 thumb ov093
 */
typedef unsigned int   u32;
struct S2;
extern u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i);
void *BTL_SIDE_GetClientPokeParam(char *p, unsigned int i, unsigned int j)
{
    return (void *)BTL_SLOT_GetPoke((void *)((unsigned int)p + 4 + i * 28), j);
}
