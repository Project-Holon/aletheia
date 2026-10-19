/*
 * function: SCRCMD_PROC_GetDaycareSlotLevel
 * address: 0x0215D0A4
 * packet: pkt_ov010_0215D0A4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetSodateya 0x02188D50 thumb ov021
 *   SODATEYA_GetCurrentLevel 0x021C341C thumb ov021
 */
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Ctx;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetSodateya(unsigned char *);
extern int SODATEYA_GetCurrentLevel(unsigned int *, unsigned int);

int SCRCMD_PROC_GetDaycareSlotLevel(void *a, void *b)
{
    u16 *p = SCRIPT_WORK_ReadWorkPointer(a, b);
    int v = SCRIPT_WORK_ReadWorkValue(a, b);
    *p = SODATEYA_GetCurrentLevel(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(b))), v);

    return 0;
}
