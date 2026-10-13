/*
 * function: SCRCMD_IAIGIRI_StartOnPlayer
 * address:  0x021C4678
 * packet:   pkt_ov021_021C4678
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Refreshes the field object from the day-care state (EXACT*: pad).
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_IAIGIRI_Start  0x021C9550  thumb  ov021
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb  arm9
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern void FLDEFF_IAIGIRI_Start(u32 a, u32 b);

int SCRCMD_IAIGIRI_StartOnPlayer(void *a, void *b)
{
    void *g = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(b));
    void *h = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)g));

    FLDEFF_IAIGIRI_Start((u32)h, FIELDMAP_GetEffect(g));
    return 0;
}
