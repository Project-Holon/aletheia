/*
 * function: SCRCMD_FIELD_GIMMICK_FLAG_ANIME_GetFlag
 * address:  0x021B240C
 * packet:   pkt_ov021_021B240C
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
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELD_GIMMICK_FLAG_ANIME_GetFlag  0x021F37C8  thumb  ov040
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int FIELD_GIMMICK_FLAG_ANIME_GetFlag(u8 *p);

int SCRCMD_FIELD_GIMMICK_FLAG_ANIME_GetFlag(u32 a, u32 b)
{
    void *w;
    u16 *o;

    SCRCMD_WORK_GetScriptWork((void *)b);
    w = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b));
    o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    if (FIELD_GIMMICK_FLAG_ANIME_GetFlag(w) != 0) {
        *o = 1;
    } else {
        *o = 0;
    }
    return 0;
}
