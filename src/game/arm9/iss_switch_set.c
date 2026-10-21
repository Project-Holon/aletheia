/*
 * file:     iss_switch_set.c
 * unit:     yes
 * function: ISS_SWITCH_SET_Create, ISS_SWITCH_SET_Delete, ISS_SWITCH_SET_Load, ISS_SWITCH_SET_Main, ISS_SWITCH_SET_SwitchOn, ISS_SWITCH_SET_SwitchOff, ISS_SWITCH_SET_ResetSwitch, ISS_SWITCH_SET_GetBgmNo, ISS_SWITCH_SET_IsValidZone, ISS_SWITCH_SET_IsSwitchOn, ISS_SWITCH_SET_UpdateVolume, ISS_SWITCH_SET_Init, ISS_SWITCH_SET_Alloc, ISS_SWITCH_SET_Free, ISS_SWITCH_SET_CreateSwitches, ISS_SWITCH_SET_DeleteSwitches, ISS_SWITCH_SET_LoadData, ISS_SWITCH_SET_UpdateSwitches, ISS_SWITCH_SET_StartSwitchOn, ISS_SWITCH_SET_StartSwitchOff, ISS_SWITCH_SET_ResetSwitches, ISS_SWITCH_SET_ReadBgmNo, ISS_SWITCH_SET_GetZoneCount, ISS_SWITCH_SET_GetZone, ISS_SWITCH_SET_CheckZone, ISS_SWITCH_SET_CheckSwitchOn, ISS_SWITCH_SET_GetSwitch, ISS_SWITCH_SET_ApplySwitchVolumes
 * address:  0x0202C2EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_switch_set.c, iss_switch.c by tools/splitfile.py.
 *
 * symbols:
 *   ISS_SWITCH_SET_Alloc 0x0202C384 thumb arm9
 *   ISS_SWITCH_SET_Free 0x0202C3A0 thumb arm9
 *   ISS_SWITCH_SET_CreateSwitches 0x0202C3A8 thumb arm9
 *   ISS_SWITCH_SET_DeleteSwitches 0x0202C3C4 thumb arm9
 *   ISS_SWITCH_SET_LoadData 0x0202C3E0 thumb arm9
 *   ISS_SWITCH_SET_UpdateSwitches 0x0202C470 thumb arm9
 *   ISS_SWITCH_SET_StartSwitchOn 0x0202C48C thumb arm9
 *   ISS_SWITCH_SET_StartSwitchOff 0x0202C498 thumb arm9
 *   ISS_SWITCH_SET_ResetSwitches 0x0202C4A4 thumb arm9
 *   ISS_SWITCH_SET_ReadBgmNo 0x0202C4C8 thumb arm9
 *   ISS_SWITCH_SET_CheckZone 0x0202C4D8 thumb arm9
 *   ISS_SWITCH_SET_CheckSwitchOn 0x0202C504 thumb arm9
 *   ISS_SWITCH_SET_ApplySwitchVolumes 0x0202C518 thumb arm9
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   IssSwitchSetFileName     0x020A776C  data
 *   ARC_TOOL_ReadMemberRange  0x02048F74  arm
 *   ISS_SWITCH_Create 0x0202C538 thumb arm9
 *   ISS_SWITCH_Delete 0x0202C548 thumb arm9
 *   ISS_SWITCH_Setup 0x0202C550 thumb arm9
 *   ISS_SWITCH_IsOn 0x0202C558 thumb arm9
 *   ISS_SWITCH_On 0x0202C560 thumb arm9
 *   ISS_SWITCH_Off 0x0202C568 thumb arm9
 *   ISS_SWITCH_ForceOn 0x0202C570 thumb arm9
 *   ISS_SWITCH_ForceOff 0x0202C578 thumb arm9
 *   ISS_SWITCH_Main 0x0202C580 thumb arm9
 *   ISS_SWITCH_SetVolume 0x0202C588 thumb arm9
 */
#include "iss_switch_sys_shared_types.h"
#include "iss_switch_set_shared_types.h"

struct IssSwitchSet *ISS_SWITCH_SET_Create(u32 heapId);

void ISS_SWITCH_SET_Delete(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_Load(struct IssSwitchSet *set, u32 datId, u32 heapId);

u32 ISS_SWITCH_SET_Main(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_SwitchOn(struct IssSwitchSet *set, u32 switchIdx);

u32 ISS_SWITCH_SET_SwitchOff(struct IssSwitchSet *set, u32 switchIdx);

void ISS_SWITCH_SET_ResetSwitch(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_GetBgmNo(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_IsValidZone(struct IssSwitchSet *set, u32 zoneId);

u32 ISS_SWITCH_SET_IsSwitchOn(struct IssSwitchSet *set, u32 switchIdx);

void ISS_SWITCH_SET_UpdateVolume(struct IssSwitchSet *set);

void ISS_SWITCH_SET_Init(struct IssSwitchSet *set);

void *ISS_SWITCH_SET_Alloc(u32 heapId);

u32 ISS_SWITCH_SET_Free(struct IssSwitchSet *set);

void ISS_SWITCH_SET_CreateSwitches(struct IssSwitchSet *set, int heapId);

void ISS_SWITCH_SET_DeleteSwitches(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_LoadData(struct IssSwitchSet *set, u32 datId);

u32 ISS_SWITCH_SET_UpdateSwitches(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_StartSwitchOn(struct IssSwitchSet *set, u32 switchIdx);

u32 ISS_SWITCH_SET_StartSwitchOff(struct IssSwitchSet *set, u32 switchIdx);

void ISS_SWITCH_SET_ResetSwitches(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_ReadBgmNo(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_CheckZone(struct IssSwitchSet *set, u32 zoneId);

u32 ISS_SWITCH_SET_CheckSwitchOn(struct IssSwitchSet *set, u32 switchIdx);

void ISS_SWITCH_SET_ApplySwitchVolumes(struct IssSwitchSet *set);

/*
 * Closed: ISS_SWITCH_SET_Alloc became an EXACT manifest entry, so the matched class attests the call at 0x0202C2F0.
 */
struct IssSwitchSet *ISS_SWITCH_SET_Create(u32 heapId)
{
    struct IssSwitchSet *set = ISS_SWITCH_SET_Alloc(heapId);

    ISS_SWITCH_SET_Init(set);
    ISS_SWITCH_SET_CreateSwitches(set, heapId);
    return set;
}

void ISS_SWITCH_SET_Delete(struct IssSwitchSet *set)
{
    ISS_SWITCH_SET_DeleteSwitches(set);
    ISS_SWITCH_SET_Free(set);
}

u32 ISS_SWITCH_SET_Load(struct IssSwitchSet *set, u32 datId, u32 heapId)
{
    return ISS_SWITCH_SET_LoadData(set, datId);
}

u32 ISS_SWITCH_SET_Main(struct IssSwitchSet *set)
{
    return ISS_SWITCH_SET_UpdateSwitches(set);
}

u32 ISS_SWITCH_SET_SwitchOn(struct IssSwitchSet *set, u32 switchIdx)
{
    return ISS_SWITCH_SET_StartSwitchOn(set, switchIdx);
}

u32 ISS_SWITCH_SET_SwitchOff(struct IssSwitchSet *set, u32 switchIdx)
{
    return ISS_SWITCH_SET_StartSwitchOff(set, switchIdx);
}

void ISS_SWITCH_SET_ResetSwitch(struct IssSwitchSet *set)
{
    ISS_SWITCH_SET_ResetSwitches(set);
}

u32 ISS_SWITCH_SET_GetBgmNo(struct IssSwitchSet *set)
{
    return ISS_SWITCH_SET_ReadBgmNo(set);
}

u32 ISS_SWITCH_SET_IsValidZone(struct IssSwitchSet *set, u32 zoneId)
{
    return ISS_SWITCH_SET_CheckZone(set, zoneId);
}

u32 ISS_SWITCH_SET_IsSwitchOn(struct IssSwitchSet *set, u32 switchIdx)
{
    return ISS_SWITCH_SET_CheckSwitchOn(set, switchIdx);
}

void ISS_SWITCH_SET_UpdateVolume(struct IssSwitchSet *set)
{
    ISS_SWITCH_SET_ApplySwitchVolumes(set);
}

void ISS_SWITCH_SET_Init(struct IssSwitchSet *set)
{
    int i;

    set->bgmNo = 0;
    set->zoneCount = 0;

    for (i = 0; i < 9; i++) {
        set->zones[i] = 0;
    }

    for (i = 0; i < 9; i++) {
        set->switches[i] = 0;
    }
}

#include "gfl_heap_wrap.h"


#include "arc_tool.h"

u32 ISS_SWITCH_SET_GetZoneCount(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_GetZone(struct IssSwitchSet *set, u32 idx);

struct IssSwitch *ISS_SWITCH_SET_GetSwitch(struct IssSwitchSet *set, u32 idx);

#include "iss_switch.h"










extern const char IssSwitchSetFileName[];

void *ISS_SWITCH_SET_Alloc(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, 0x3c, 0, IssSwitchSetFileName, 0x12a);
}

u32 ISS_SWITCH_SET_Free(struct IssSwitchSet *set)
{
    return GFL_HEAP_Free(set);
}

void ISS_SWITCH_SET_CreateSwitches(struct IssSwitchSet *set, int heapId)
{
    int i;
    for (i = 0; i < 9; i++)
        set->switches[i] = ISS_SWITCH_Create(heapId);
}

void ISS_SWITCH_SET_DeleteSwitches(struct IssSwitchSet *set)
{
    int i;

    for (i = 0; i < 9; i++) {
        ISS_SWITCH_Delete(set->switches[i]);
        set->switches[i] = 0;
    }
}

u32 ISS_SWITCH_SET_LoadData(struct IssSwitchSet *set, u32 datId)
{
    u16 trackBits[9];
    u16 fadeFrames;
    int i;
    u32 offset;
    u32 ret;

    i = 0;
    offset = 0;
    ARC_TOOL_ReadMemberRange(set, (u32)0x93, datId, offset, 4);
    offset += 4;

    for (; i < 9; i++, offset += 2) {
        ARC_TOOL_ReadMemberRange(&trackBits[i], (u32)0x93, datId, offset, 2);
    }

    ARC_TOOL_ReadMemberRange(&fadeFrames, (u32)0x93, datId, offset, 2);
    ARC_TOOL_ReadMemberRange(&set->zoneCount, (u32)0x93, datId, offset + 2, 1);
    ARC_TOOL_ReadMemberRange(set->zones, (u32)0x93, datId, offset + 3, set->zoneCount * 2);

    i = 0;
    for (; i < 9; i++) {
        ret = ISS_SWITCH_Setup(ISS_SWITCH_SET_GetSwitch(set, i), fadeFrames, trackBits[i]);
    }

    return ret;
}

u32 ISS_SWITCH_SET_UpdateSwitches(struct IssSwitchSet *set)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        ISS_SWITCH_Main(ISS_SWITCH_SET_GetSwitch(set, i));
    }
#ifndef __MWERKS__
    return 0; /* the DS returns whatever the last ISS_SWITCH_Main call left in r0 */
#endif
}

u32 ISS_SWITCH_SET_StartSwitchOn(struct IssSwitchSet *set, u32 switchIdx)
{
    return ISS_SWITCH_On(ISS_SWITCH_SET_GetSwitch(set, switchIdx));
}

u32 ISS_SWITCH_SET_StartSwitchOff(struct IssSwitchSet *set, u32 switchIdx)
{
    return ISS_SWITCH_Off(ISS_SWITCH_SET_GetSwitch(set, switchIdx));
}

void ISS_SWITCH_SET_ResetSwitches(struct IssSwitchSet *set)
{
    s32 i;

    ISS_SWITCH_ForceOn(ISS_SWITCH_SET_GetSwitch(set, 0));
    for (i = 1; i < 9; i++) {
        ISS_SWITCH_ForceOff(ISS_SWITCH_SET_GetSwitch(set, i));
    }
}

/*
 * An unlabelled leaf sitting in the four bytes between ISS_SWITCH_SET_ResetSwitches's last
 * instruction and ISS_SWITCH_SET_GetZoneCount's first
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): no
 * register-saving prologue, so disasm.py's sweep never marks it. It is a
 * plain read of the object's first word, reached only through
 * ISS_SWITCH_SET_GetBgmNo's pool-word-and-bx tail call
 * (src/matched/unit_0202C318.c, parked at MATCH because this address is
 * its only caller anywhere in the image).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SET_ReadBgmNo.c \
 *       --func ISS_SWITCH_SET_ReadBgmNo --addr 0x0202C4C8 --cc 1.1p1 --thumb
 */
u32 ISS_SWITCH_SET_ReadBgmNo(struct IssSwitchSet *set)
{
    return set->bgmNo;
}

u32 ISS_SWITCH_SET_GetZoneCount(struct IssSwitchSet *set)
{
    return set->zoneCount;
}

u32 ISS_SWITCH_SET_GetZone(struct IssSwitchSet *set, u32 idx)
{
    return set->zones[idx];
}

u32 ISS_SWITCH_SET_CheckZone(struct IssSwitchSet *set, u32 zoneId)
{
    int count = ISS_SWITCH_SET_GetZoneCount(set);
    int i;

    for (i = 0; i < count; i++) {
        if (zoneId == ISS_SWITCH_SET_GetZone(set, i)) {
            return 1;
        }
    }
    return 0;
}

u32 ISS_SWITCH_SET_CheckSwitchOn(struct IssSwitchSet *set, u32 switchIdx)
{
    return ISS_SWITCH_IsOn(ISS_SWITCH_SET_GetSwitch(set, switchIdx));
}

struct IssSwitch *ISS_SWITCH_SET_GetSwitch(struct IssSwitchSet *set, u32 idx)
{
    return set->switches[idx];
}

void ISS_SWITCH_SET_ApplySwitchVolumes(struct IssSwitchSet *set)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        ISS_SWITCH_SetVolume(ISS_SWITCH_SET_GetSwitch(set, i), 0x7F);
    }
}
