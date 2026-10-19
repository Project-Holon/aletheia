/*
 * file:     event_trainer.c
 * unit:     yes
 * function: EVENT_TRAINER_SetScriptTrainerEntry, EVENT_TRAINER_GetTrainerIdFromScriptId, EVENT_TRAINER_GetPrimaryScriptId, EVENT_TRAINER_GetSecondaryScriptId, EVENT_TRAINER_IsSecondaryScriptId, EVENT_TRAINER_IsDoubleBattle, EVENT_TRAINER_GetBattleType, EVENT_TRAINER_CheckDefeatedFlag, EVENT_TRAINER_SetDefeatedFlag, EVENT_TRAINER_ClearDefeatedFlag
 * address:  0x0215A438
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from event_poke_status.c by tools/splitfile.py.
 *
 * symbols:
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   SCRIPT_SYS_GetEventScriptWork  0x021589D0  thumb  ov010
 *   SCRIPT_WORK_GetTrainerEntry  0x02159124  thumb  ov010
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb
 */
#include "event_poke_status_shared_types.h"

typedef signed int     s32;

typedef struct RecordHead24 {
    int word[6];
} RecordHead24;

extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);

extern void ZONEDATA_SetEventFlag(char *, int);

extern void ZONEDATA_ResetEventFlag(char *ev, int flagId);

extern int SCRIPT_SYS_GetEventScriptWork(int);

extern char *SCRIPT_WORK_GetTrainerEntry(char *p, int i);

extern u32 TPOKE_DATA_GetRecordField(void *a, u32 idx);

void EVENT_TRAINER_SetScriptTrainerEntry(int scrcmdWork, int index, RecordHead24 *src)
{
    int *entry = (int *)SCRIPT_WORK_GetTrainerEntry((char *)SCRIPT_SYS_GetEventScriptWork(scrcmdWork), index);

    *(RecordHead24 *)entry = *src;
    entry[6] = 0;
}

/*
 * Map a tick count onto a 3000/5000 ms window, truncated to 16 bits.
 *
 * Addresses are Black-image addresses.
 */
u32 EVENT_TRAINER_GetTrainerIdFromScriptId(u32 ticks)
{
    if (ticks < 5000)
        return (u16)(ticks - 3000);
    return (u16)(ticks - 5000);
}

u16 EVENT_TRAINER_GetPrimaryScriptId(unsigned id) { return id + 3000; }

/*
 * extent: includes unlabelled range-test EVENT_TRAINER_IsSecondaryScriptId; function-start seed.
 */
u16 EVENT_TRAINER_GetSecondaryScriptId(unsigned id) { return id + 5000; }

int EVENT_TRAINER_IsSecondaryScriptId(unsigned id) { if (id >= 5000) return 1; return 0; }

int EVENT_TRAINER_IsDoubleBattle(int saveData)
{
    if (TPOKE_DATA_GetRecordField((void *)saveData, 2) == 1)
        return 1;
    return 0;
}

int EVENT_TRAINER_GetBattleType(int saveData)
{
    return (u8)TPOKE_DATA_GetRecordField((void *)saveData, 2);
}

/*
 * interface: original narrows r1 by shift pairs; u16 extern preserves this.
 */
unsigned EVENT_TRAINER_CheckDefeatedFlag(void *flagSet, unsigned flagOffset) { return ZONEDATA_CheckEventFlag(flagSet, (u16)(flagOffset + 1420)); }

void EVENT_TRAINER_SetDefeatedFlag(char *flagSet, unsigned flagOffset) { ZONEDATA_SetEventFlag(flagSet, (u16)(flagOffset + 1420)); }

void EVENT_TRAINER_ClearDefeatedFlag(char *flagSet, unsigned flagOffset) { ZONEDATA_ResetEventFlag(flagSet, (u16)(flagOffset + 1420)); }
