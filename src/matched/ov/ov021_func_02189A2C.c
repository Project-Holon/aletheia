/*
 * function: FIELDMAP_IsEventActive
 * address:  0x02189A2C
 * packet:   pkt_ov021_02189A2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail-calls GAMESYSTEM_IsEventActive with the word at offset 4 of its argument.
 *
 * symbols:
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 * Addresses are Black-image addresses.
 */

extern int GAMESYSTEM_IsEventActive(char *a);

int FIELDMAP_IsEventActive(int *a)
{
    return GAMESYSTEM_IsEventActive((char *)a[1]);
}
