/*
 * function: SCRCMD_PROC_CallDaycarePartyMenu
 * address:  0x0215CF00
 * packet:   pkt_ov010_0215CF00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   DAYCARE_GetFromSave  0x0200BDB0  thumb
 *   SCRCMD_SODATEYA_Create  0x0215D2A4  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Big;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *DAYCARE_GetFromSave(void *);
extern void *SCRCMD_SODATEYA_Create(void *a, u32 b, u32 c);
extern void SCRIPT_SYS_CallEvent(void *, void *);

int SCRCMD_PROC_CallDaycarePartyMenu(void *a, void *b)
{
    void *t = SCRCMD_WORK_GetScriptWork(b);
    unsigned short *v = SCRIPT_WORK_ReadWorkPointer(a, b);
    void *p = SCRCMD_WORK_GetGameData(b);
    void *h = SCRCMD_WORK_GetGameSystem(b);
    void *s = GAMESYSTEM_GetFieldMap(h);
    GAME_DATA_GetMyParty(p);
    DAYCARE_GetFromSave(GAME_DATA_GetSaveControl(p));
    SCRIPT_SYS_CallEvent(t, SCRCMD_SODATEYA_Create(h, (u32)s, (u32)v));
    return 1;
}
