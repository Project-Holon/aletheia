/*
 * function: SCRCMD_FLDMMDL_SearchMmdlInFrontOfPlayer
 * address:  0x021B1CB0
 * packet:   pkt_ov021_021B1CB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FIELD_PLAYER_SearchFrontMmdlHeight  0x021A32A8  thumb  ov021
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int FIELD_PLAYER_SearchFrontMmdlHeight(void *, u32);
extern u16 FLDMMDL_GetObjId(void *p);

int SCRCMD_FLDMMDL_SearchMmdlInFrontOfPlayer(u32 a, u32 b)
{
    void *h;
    u16 *p;
    u16 *q;
    int r;

    h = FIELDMAP_GetFieldPlayer(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b)));
    p = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    q = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    r = FIELD_PLAYER_SearchFrontMmdlHeight(h, 0x8000);
    if (r != 0) {
        *q = 1;
        *p = FLDMMDL_GetObjId((void *)r);
    } else {
        *q = 0;
    }
    return 0;
}
