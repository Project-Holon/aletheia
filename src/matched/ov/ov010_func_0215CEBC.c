/*
 * function: SCRCMD_PROC_DaycareInitFromParty
 * address: 0x0215CEBC
 * packet: pkt_ov010_0215CEBC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetSodateya 0x02188D50 thumb ov021
 *   SODATEYA_ReceiveEgg 0x021C32F4 thumb ov021
 */
typedef unsigned short u16;
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
struct Ctx;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetSodateya(unsigned char *);
extern void SODATEYA_ReceiveEgg(unsigned int *, unsigned int);

int SCRCMD_PROC_DaycareInitFromParty(void *a, void *b)
{
    void *p = SCRCMD_WORK_GetGameSystem(b);
    void *q = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(b));
    SODATEYA_ReceiveEgg(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(p)), (unsigned int)q);
    return 0;
}
