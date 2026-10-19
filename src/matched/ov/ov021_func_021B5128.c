/*
 * function: SCRCMD_PROC_FLD_StoreEffectEncountItemId
 * address:  0x021B5128
 * packet:   pkt_ov021_021B5128
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_GetItemId  0x021AAB48  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern u16 EFFECT_ENCOUNT_GetItemId(char *p);

int SCRCMD_PROC_FLD_StoreEffectEncountItemId(u32 a, u32 b)
{
    void *w = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b));
    u16 *o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);

    *o = EFFECT_ENCOUNT_GetItemId((char *)FIELDMAP_GetEncount(w));
    return 0;
}
