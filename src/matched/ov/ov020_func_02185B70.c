/*
 * function: EVENT_MAPCHANGE_DeleteAllMmdlOfSystem
 * address: 0x02185B70
 * packet: pkt_ov020_02185B70
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   EVENT_MAPCHANGE_DeleteAllMmdl 0x021859F0 thumb ov020
 * interface: 021859F0 forwards incoming r0 to 02012964.
 */
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void EVENT_MAPCHANGE_DeleteAllMmdl(int a);
void EVENT_MAPCHANGE_DeleteAllMmdlOfSystem(void *p)
{
    void *q = GAMESYSTEM_GetGameData(p);
    GAMESYSTEM_GetFieldMap(p);
    EVENT_MAPCHANGE_DeleteAllMmdl((int)q);
}
