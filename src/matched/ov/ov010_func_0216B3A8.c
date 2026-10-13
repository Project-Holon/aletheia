/*
 * function: FIELD_G3D_MAP_StartSymbolEntry
 * address:  0x0216B3A8
 * packet:   pkt_ov010_0216B3A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FIELD_G3D_MAP_GetEdgePosition  0x0216B2E4  thumb  ov010
 *   FIELD_G3D_MAP_CreateSymbolEntryEvent  0x0216B340  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Desc;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *FIELDMAP_GetFieldPlayer(u8 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void *FLDMMDL_GetPosPtr(void *p);
extern void FIELD_G3D_MAP_GetEdgePosition();
extern struct Desc *FIELD_G3D_MAP_CreateSymbolEntryEvent(int a0, int a1, void *a2, int a3, int a4);

struct Desc *FIELD_G3D_MAP_StartSymbolEntry(int a0, int a1, int a2)
{
    int buf[3];
    void *t;

    t = GAMESYSTEM_GetFieldMap((void *)a0);
    GAMESYSTEM_GetGameData((const struct Ctx *)a0);
    FIELD_G3D_MAP_GetEdgePosition(FLDMMDL_GetPosPtr(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(t))), a1, buf);
    return FIELD_G3D_MAP_CreateSymbolEntryEvent(a0, a1 != 9, buf, a1, a2);
}
