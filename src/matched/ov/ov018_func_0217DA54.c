/*
 * function: INTRUDE_SUBDISP_ClactActorCreate
 * address: 0x0217DA54
 * packet: pkt_ov018_0217DA54
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_SUBDISP_CreateTownActors 0x0217DAA8 thumb ov018
 *   INTRUDE_SUBDISP_CreatePlayerMarkActors 0x0217DB4C thumb ov018
 *   INTRUDE_SUBDISP_CreateTownMarkActors 0x0217DBAC thumb ov018
 *   INTRUDE_SUBDISP_CreateMyPlayerActor 0x0217DC14 thumb ov018
 *   INTRUDE_SUBDISP_CreatePlayerIconActors 0x0217DC9C thumb ov018
 *   INTRUDE_SUBDISP_CreateInfoIconActor 0x0217DCFC thumb ov018
 *   INTRUDE_SUBDISP_CreateButtonActors 0x0217DD48 thumb ov018
 * interface: r1 is visibly restored before every call; preserve incoming bg.
 * Callees' matched definitions omit this unused input; no callee edits.
 */
extern void INTRUDE_SUBDISP_CreateTownActors(int *p, void *a1);
extern void INTRUDE_SUBDISP_CreatePlayerMarkActors(int *p, void *a1);
extern void INTRUDE_SUBDISP_CreateTownMarkActors(int *p, void *a1);
extern void INTRUDE_SUBDISP_CreateMyPlayerActor(int *p, void *a1);
extern void INTRUDE_SUBDISP_CreatePlayerIconActors(int *p, void *a1);
extern void INTRUDE_SUBDISP_CreateInfoIconActor(int *p, void *a1);
extern void INTRUDE_SUBDISP_CreateButtonActors(void *, void *);
void INTRUDE_SUBDISP_ClactActorCreate(void *p, void *bg)
{
    INTRUDE_SUBDISP_CreateTownActors(p, bg);
    INTRUDE_SUBDISP_CreatePlayerMarkActors(p, bg);
    INTRUDE_SUBDISP_CreateTownMarkActors(p, bg);
    INTRUDE_SUBDISP_CreateMyPlayerActor(p, bg);
    INTRUDE_SUBDISP_CreatePlayerIconActors(p, bg);
    INTRUDE_SUBDISP_CreateInfoIconActor(p, bg);
    INTRUDE_SUBDISP_CreateButtonActors(p, bg);
}
