/*
 * function: SCRCMD_BufferDaycareMonSpeciesName
 * address:  0x021AF9F0
 * packet:   pkt_ov021_021AF9F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetSodateya  0x02188D50  thumb  ov021
 *   SODATEYA_GetPokemon  0x021C34F8  thumb  ov021
 *   WORDSET_SetSlotMonSpeciesName  0x0201EE84  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct Ctx;
struct WordSet;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetSodateya(u8 *);
extern void *SODATEYA_GetPokemon(void *, u32);
extern void WORDSET_SetSlotMonSpeciesName(struct WordSet *p, u32 i, void *mon);

int SCRCMD_BufferDaycareMonSpeciesName(Script *a, u32 b)
{
    u32 x = (u32)SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    WORDSET_SetSlotMonSpeciesName((void *)x, v, SODATEYA_GetPokemon(FIELDMAP_GetSodateya(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b))), e));
    return 0;
}
