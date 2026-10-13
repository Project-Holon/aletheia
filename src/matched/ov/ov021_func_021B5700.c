/*
 * function: SCRCMD_FLD_BATTLE_RegisterAllowedSpecies
 * address:  0x021B5700
 * packet:   pkt_ov021_021B5700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames  0x021B57CC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern u16 SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames(void *a0, void *a1, unsigned int a2, int a3);

int SCRCMD_FLD_BATTLE_RegisterAllowedSpecies(void *a0, void *a1)
{
    void *r6 = SCRCMD_WORK_GetScriptWork(a1);
    void *s = SCRCMD_WORK_GetGameData(a1);
    unsigned int r7;
    u16 *r5;

    r6 = SCRIPT_WORK_GetWordSet(r6);
    r7 = SCRIPT_WORK_ReadWorkValue(a0, a1);
    r5 = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    *r5 = SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames(s, r6, r7, SCRCMD_WORK_GetHeapId(a1));
    return 0;
}
