/*
 * function: FIELD_FLASH_GetState
 * address:  0x021C7E54
 * packet:   pkt_ov021_021C7E54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor (prints as .word in the listing): returns the u16 at +0x1C (FIELD_FLASH_SetPendingCommand sets +0x1E).
 * Sole blocker of ov010 MOVE_POKEMON_FlashEventMain's MATCH.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Obj {
    u8 pad00[0x1C];
    u16 f1c;            /* 0x1C */
} Obj;

u16 FIELD_FLASH_GetState(Obj *p)
{
    return p->f1c;
}
