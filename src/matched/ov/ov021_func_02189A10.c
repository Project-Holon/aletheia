/*
 * function: FIELDMAP_GetMapEff
 * address:  0x02189A10
 * packet:   pkt_ov021_02189A10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf accessor (prints as .word in the listing): returns the pointer at +0xA0.
 * Sole blocker of ov010 MOVE_POKEMON_FlashEventMain's MATCH.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Obj {
    u8 pad00[0xA0];
    void *fa0;          /* 0xA0 */
} Obj;

void *FIELDMAP_GetMapEff(Obj *p)
{
    return p->fa0;
}
