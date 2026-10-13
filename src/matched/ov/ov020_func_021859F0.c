/*
 * function: EVENT_MAPCHANGE_DeleteAllMmdl
 * address:  0x021859F0
 * packet:   pkt_021859F0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FLDMMDL_DeleteAllMmdl  0x0216CF6C  thumb
 */

typedef unsigned int   u32;
struct BigObj;
u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
void FLDMMDL_DeleteAllMmdl(int x);

void EVENT_MAPCHANGE_DeleteAllMmdl(int a)
{
    FLDMMDL_DeleteAllMmdl(GAME_DATA_GetOccupyInfo((const struct BigObj *)a));
}
