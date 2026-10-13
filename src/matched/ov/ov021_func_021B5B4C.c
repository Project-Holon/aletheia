/*
 * function: SCRCMD_POKEMON_FLD_SelectPartyMon
 * address:  0x021B5B4C
 * packet:   pkt_ov021_021B5B4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   EVENT_POKE_STATUS_CreatePokeSelectEvent  0x0215A07C  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *EVENT_POKE_STATUS_CreatePokeSelectEvent(int a, u16 *b, u16 *c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_POKEMON_FLD_SelectPartyMon(void *a0, void *a1)
{
    u16 *a = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    u16 *b = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    void *r4;

    SCRIPT_WORK_ReadWorkValue(a0, a1);
    r4 = SCRCMD_WORK_GetScriptWork(a1);
    SCRIPT_SYS_CallEvent(r4, EVENT_POKE_STATUS_CreatePokeSelectEvent((int)SCRCMD_WORK_GetGameSystem(a1), a, b));
    return 1;
}
