/*
 * function: SWEET_SCENT_CreateEventNoPokemon
 * address: 0x021C6068
 * packet: pkt_ov021_021C6068
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_g3dobj.c and filed here.
 *
 * symbols:
 *   SWEET_SCENT_CreateEvent 0x021C6078 thumb
 */

typedef unsigned char u8;
void *SWEET_SCENT_CreateEventNoPokemon(void *a, void *b);
void *SWEET_SCENT_CreateEvent(void *a, void *b, u8 c);

void *SWEET_SCENT_CreateEventNoPokemon(void *a, void *b) { return SWEET_SCENT_CreateEvent(b, a, 0xff); }
