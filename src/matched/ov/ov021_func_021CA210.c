/*
 * function: BSUBWAY_SCR_GetParty
 * address:  0x021CA210
 * packet:   pkt_ov021_021CA210
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the object at +0x6c's handle unless the query on +0x70 is set, then the cached +0x7c8.
 *
 * symbols:
 *   func_0200D884  0x0200D884  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00116.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk3C;
extern u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);

void *BSUBWAY_SCR_GetParty(u8 *p)
{
    if (func_0200D884((struct Blk3C *)(((struct Obj00116 *)p)->f70), 10, 0) == 0)
        return GAME_DATA_GetMyParty(((struct Obj00116 *)p)->f6C);
    return ((struct Obj00116 *)p)->f7C8;
}
