/*
 * function: SCRCMD_PROC_DepositDaycareMon
 * address: 0x0215CF54
 * packet: pkt_ov010_0215CF54
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   SCRCMD_WORK_GetGameData 0x0215A5E4 thumb ov010
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetSodateya 0x02188D50 thumb ov021
 *   SODATEYA_DepositPokemon 0x021C3204 thumb ov021
 */
typedef unsigned short u16;
struct BigObj;
struct Ctx;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetSodateya(unsigned char *);
extern void SODATEYA_DepositPokemon(unsigned int *, unsigned int, unsigned int);

int SCRCMD_PROC_DepositDaycareMon(void *a, void *b)
{
    int v = SCRIPT_WORK_ReadWorkValue(a, b);
    void *q = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(b));
    SODATEYA_DepositPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(b))), (unsigned int)q, v);
    return 0;
}
