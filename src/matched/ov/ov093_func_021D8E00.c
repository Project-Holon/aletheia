/*
 * function: BTL_ABILITY_IsCherrim
 * address: 0x021D8E00
 * packet: pkt_ov093_021D8E00
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 * Caller uses the forwarder's live pointer return and forwards r1.
 */
typedef unsigned short u16;
struct QF;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
int BTL_ABILITY_IsCherrim(void *a, int b)
{
    if (BTL_POKEPARAM_GetSpecies(func_021C7CF4(a, b)) == 0x1a5) return 1;
    return 0;
}
