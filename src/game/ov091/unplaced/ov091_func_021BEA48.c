/*
 * function: func_021BEA48
 * address:  0x021BEA48
 * packet:   pkt_021BEA48
 * region:   ov091
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The sixth parameter is passed as the callee's narrow fourth parameter, so
 * mwcc truncates it at the call site; see
 * docs/idioms/a-narrow-callee-parameter-truncates-at-the-call-site.md.
 *
 * symbols:
 *   NATSUKI_CalcUseItem  0x0201B7B4  thumb
 */

typedef unsigned short u16;

struct PokemonParam;
void NATSUKI_CalcUseItem(struct PokemonParam *mon, int item, u16 zoneId, u16 heapId);

/*
 * Friendship change of an item use: nothing happens when the friendship is
 * already at its limit in the direction of the change (255 and a rise, or 0
 * and a fall). The band delta comes from the item record.
 */
int func_021BEA48(struct PokemonParam *mon, int friendship, int delta, int item, u16 zoneId, int heapId)
{
    if (friendship == 0xff && delta > 0)
        return 0;
    if (friendship == 0 && delta < 0)
        return 0;
    NATSUKI_CalcUseItem(mon, item, zoneId, heapId);
    return 1;
}
