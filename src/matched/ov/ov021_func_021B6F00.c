/*
 * function: SCRCMD_POKEMON_FLD_CheckGiftMonCanReceive
 * address:  0x021B6F00
 * packet:   pkt_ov021_021B6F00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *);

int SCRCMD_POKEMON_FLD_CheckGiftMonCanReceive(void *a, void *b)
{
    if ((int)POKEPARTY_GetCount(GAME_DATA_GetMyParty(b)) < 6) {
        return 1;
    }
    return 0;
}
