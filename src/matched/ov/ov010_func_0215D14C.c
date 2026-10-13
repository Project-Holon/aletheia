/*
 * function: SCRCMD_PROC_GetDaycareMonGenderKindIfFirst
 * address:  0x0215D14C
 * packet:   pkt_ov010_0215D14C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetSodateya  0x02188D50  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SODATEYA_GetPokemon  0x021C34F8  thumb
 *   SCRCMD_PROC_GetDaycareGenderKind  0x0215D198  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetSodateya(u8 *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SODATEYA_GetPokemon(void *, u32);
extern int SCRCMD_PROC_GetDaycareGenderKind(void *);

int SCRCMD_PROC_GetDaycareMonGenderKindIfFirst(void *a, void *b)
{
    int f;
    u16 *p;
    void *r;
    void *s = FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(b)));
    p = SCRIPT_WORK_ReadWorkPointer(a, b);
    f = SCRIPT_WORK_ReadWorkValue(a, b);
    r = SODATEYA_GetPokemon(s, SCRIPT_WORK_ReadWorkValue(a, b));
    if (f == 0)
        *p = SCRCMD_PROC_GetDaycareGenderKind(r);
    else
        *p = 0;
    return 0;
}
