/*
 * function: BTL_POSPOKE_GetFieldPos
 * address: 0x0689D59C
 * packet: pkt_ov095_0689D59C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POSPOKE_SearchPosByPokeId 0x0689D5C8 thumb ov095
 *   func_0689D5B8 0x0689D5B8 thumb ov095
 */
typedef unsigned char u8;
extern u8 BTL_POSPOKE_SearchPosByPokeId(u8 *, u8);
extern int func_0689D5B8(void *, int);
int BTL_POSPOKE_GetFieldPos(u8 *p, void *q, u8 key)
{
    int i;
    i = BTL_POSPOKE_SearchPosByPokeId(p, key);
    if (i != 6) return func_0689D5B8(q, i);
    return 0;
}
