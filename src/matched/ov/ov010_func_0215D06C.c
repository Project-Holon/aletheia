/*
 * function: SCRCMD_PROC_GetDaycareMonGender
 * address: 0x0215D06C
 * packet: pkt_ov010_0215D06C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * interface: SODATEYA_GetPokemon has two observed inputs. Its full ov021 body
 * and 0200BCA8/0200BC2C read r0/r1 only; legacy trailing r2/r3 are omitted.
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetSodateya 0x02188D50 thumb ov021
 *   SODATEYA_GetPokemon 0x021C34F8 thumb ov021
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 */
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Ctx;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetSodateya(unsigned char *);
extern void *SODATEYA_GetPokemon(void *, unsigned int);
extern unsigned int POKE_TOOL_GetPartyValue(void *, unsigned int, unsigned int);

int SCRCMD_PROC_GetDaycareMonGender(void *a, void *b)
{
    u16 *p = SCRIPT_WORK_ReadWorkPointer(a, b);
    int v = SCRIPT_WORK_ReadWorkValue(a, b);
    void *q = SODATEYA_GetPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(b))), v);
    *p = POKE_TOOL_GetPartyValue(q, 110, 0);

    return 0;
}
