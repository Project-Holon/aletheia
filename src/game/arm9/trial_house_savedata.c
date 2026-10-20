/*
 * file:     trial_house_savedata.c
 * unit:     yes
 * function: TRIAL_HOUSE_SAVE_GetSize, TRIAL_HOUSE_SAVE_Clear, TRIAL_HOUSE_SAVE_GetFromSave
 * address:  0x0200E8E8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from misc_savedata_2.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 */
#include "../types.h"
#include "greeting_savedata_shared_types.h"

#include "mi_memory.h"
struct SaveControl;

#include "save_control.h"


u32 TRIAL_HOUSE_SAVE_GetSize(void);

void TRIAL_HOUSE_SAVE_Clear(void *dest);

void *TRIAL_HOUSE_SAVE_GetFromSave(void *sys);

u32 TRIAL_HOUSE_SAVE_GetSize(void)
{
    return 0x5c;
}

void TRIAL_HOUSE_SAVE_Clear(void *dest)
{
    MI_CpuFill8(dest, 0, 0x5c);
}

void *TRIAL_HOUSE_SAVE_GetFromSave(void *saveData)
{
    return SAVE_CONTROL_GetBlock(saveData, 0x41);
}
