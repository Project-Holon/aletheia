/*
 * function: BTL_POKEPARAM_GetFoughtPokeId
 * address: 0x021D6E0C
 * packet: pkt_ov093_021D6E0C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: left-associated pointer addition preserves base-plus-index then +0xD1.
 */
typedef unsigned char u8;
typedef unsigned int u32;
u8 BTL_POKEPARAM_GetFoughtPokeId(u8 *p, u32 i)
{
    if (i < p[0xd0]) return *(p + i + 0xd1);
    return 0x1f;
}
