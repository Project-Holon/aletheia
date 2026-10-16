/*
 * file:     iss_switch_set.c
 * unit:     yes
 * function: ISS_SWITCH_SET_Alloc, ISS_SWITCH_SET_Free, ISS_SWITCH_SET_CreateSwitches, ISS_SWITCH_SET_DeleteSwitches, ISS_SWITCH_SET_LoadData, ISS_SWITCH_SET_UpdateSwitches, ISS_SWITCH_SET_StartSwitchOn, ISS_SWITCH_SET_StartSwitchOff, ISS_SWITCH_SET_ResetSwitches, ISS_SWITCH_SET_ReadBgmNo, ISS_SWITCH_SET_GetZoneCount, ISS_SWITCH_SET_GetZone, ISS_SWITCH_SET_CheckZone, ISS_SWITCH_SET_CheckSwitchOn, ISS_SWITCH_SET_GetSwitch, ISS_SWITCH_SET_ApplySwitchVolumes, ISS_SWITCH_Create, ISS_SWITCH_Delete, ISS_SWITCH_Setup, ISS_SWITCH_IsOn, ISS_SWITCH_On, ISS_SWITCH_Off, ISS_SWITCH_ForceOn, ISS_SWITCH_ForceOff, ISS_SWITCH_Main, ISS_SWITCH_SetVolume
 * address:  0x0202C384
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_switch_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   IssSwitchSetFileName     0x020A776C  data
 *   FSi_ConvertStringSjisToUnicode  0x02048F74  arm
 *   ISS_SWITCH_Alloc 0x0202C590 thumb arm9
 *   ISS_SWITCH_Free 0x0202C5AC thumb arm9
 *   ISS_SWITCH_Init 0x0202C5B4 thumb arm9
 *   ISS_SWITCH_SetParam 0x0202C5C4 thumb arm9
 *   ISS_SWITCH_Update 0x0202C5F0 thumb arm9
 *   ISS_SWITCH_StartFadeIn 0x0202C670 thumb arm9
 *   ISS_SWITCH_StartFadeOut 0x0202C688 thumb arm9
 *   ISS_SWITCH_SetOnState 0x0202C6A0 thumb arm9
 *   ISS_SWITCH_SetOffState 0x0202C6AC thumb arm9
 *   ISS_SWITCH_ApplyVolume 0x0202C710 thumb arm9
 *   ISS_SWITCH_IsOnState 0x0202C72C thumb arm9
 */
#include "iss_switch_sys_shared_types.h"
#include "iss_switch_set_shared_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern u32 FSi_ConvertStringSjisToUnicode(void *dst, u32 term, void *src,
                                           u32 srcOffset, u32 dstSize);

void *ISS_SWITCH_SET_Alloc(void *heapId);

u32 ISS_SWITCH_SET_Free(void *set);

void ISS_SWITCH_SET_CreateSwitches(char *p, int heapId);

void ISS_SWITCH_SET_DeleteSwitches(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_LoadData(struct IssSwitchSet *set, void *datId);

u32 ISS_SWITCH_SET_UpdateSwitches(void *set);

u32 ISS_SWITCH_SET_StartSwitchOn(void *set, u32 switchIdx);

u32 ISS_SWITCH_SET_StartSwitchOff(void *set, u32 switchIdx);

void ISS_SWITCH_SET_ResetSwitches(void *set);

u32 ISS_SWITCH_SET_ReadBgmNo(u32 *set);

u32 ISS_SWITCH_SET_GetZoneCount(struct IssSwitchSet *set);

u32 ISS_SWITCH_SET_GetZone(struct IssSwitchSet *set, u32 idx);

u32 ISS_SWITCH_SET_CheckZone(void *set, u32 zoneId);

u32 ISS_SWITCH_SET_CheckSwitchOn(void *set, u32 switchIdx);

u32 ISS_SWITCH_SET_GetSwitch(struct IssSwitchSet *set, u32 idx);

void ISS_SWITCH_SET_ApplySwitchVolumes(void *set);

void *ISS_SWITCH_Create(u32 heapId);

u32 ISS_SWITCH_Delete(void *sw);

u32 ISS_SWITCH_Setup(void *sw, u16 fadeFrames, u16 trackBits);

u32 ISS_SWITCH_IsOn(void *sw);

u32 ISS_SWITCH_On(void *sw);

u32 ISS_SWITCH_Off(void *sw);

u32 ISS_SWITCH_ForceOn(void *sw);

u32 ISS_SWITCH_ForceOff(void *sw);

void ISS_SWITCH_Main(void *sw);

void ISS_SWITCH_SetVolume(void *sw, u32 maxVolume);

void *ISS_SWITCH_Alloc(u32 heapId);

u32 ISS_SWITCH_Free(void *sw);

void ISS_SWITCH_Init(struct IssSwitch *sw);

u32 ISS_SWITCH_SetParam(struct IssSwitch *sw, u16 fadeFrames, u16 trackBits);

void ISS_SWITCH_Update(void *sw);

u32 ISS_SWITCH_StartFadeIn(void *sw);

u32 ISS_SWITCH_StartFadeOut(void *sw);

u32 ISS_SWITCH_SetOnState(void *sw);

u32 ISS_SWITCH_SetOffState(void *sw);

void ISS_SWITCH_ApplyVolume(struct IssSwitch *sw, s32 maxVolume);

u32 ISS_SWITCH_IsOnState(void *sw);

extern const char IssSwitchSetFileName[];

void *ISS_SWITCH_SET_Alloc(void *heapId)
{
    return GFL_HEAP_Alloc((u32)heapId, 0x3c, 0, IssSwitchSetFileName, 0x12a);
}

u32 ISS_SWITCH_SET_Free(void *set)
{
    return GFL_HEAP_Free(set);
}

void ISS_SWITCH_SET_CreateSwitches(char *p, int heapId)
{
    struct IssSwitchSet *set = (struct IssSwitchSet *)p;
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

u32 ISS_SWITCH_SET_LoadData(struct IssSwitchSet *set, void *datId)
{
    u16 trackBits[9];
    u16 fadeFrames;
    int i;
    u32 offset;
    u32 ret;

    i = 0;
    offset = 0;
    FSi_ConvertStringSjisToUnicode(set, 0x93, datId, offset, 4);
    offset += 4;

    for (; i < 9; i++, offset += 2) {
        FSi_ConvertStringSjisToUnicode(&trackBits[i], 0x93, datId, offset, 2);
    }

    FSi_ConvertStringSjisToUnicode(&fadeFrames, 0x93, datId, offset, 2);
    FSi_ConvertStringSjisToUnicode(&set->zoneCount, 0x93, datId, offset + 2, 1);
    FSi_ConvertStringSjisToUnicode(set->zones, 0x93, datId, offset + 3, set->zoneCount * 2);

    i = 0;
    for (; i < 9; i++) {
        ret = ISS_SWITCH_Setup((void *)ISS_SWITCH_SET_GetSwitch(set, i), fadeFrames, trackBits[i]);
    }

    return ret;
}

u32 ISS_SWITCH_SET_UpdateSwitches(void *set)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        ISS_SWITCH_Main((void *)ISS_SWITCH_SET_GetSwitch(set, i));
    }
}

u32 ISS_SWITCH_SET_StartSwitchOn(void *set, u32 switchIdx)
{
    return ISS_SWITCH_On((void *)ISS_SWITCH_SET_GetSwitch(set, switchIdx));
}

u32 ISS_SWITCH_SET_StartSwitchOff(void *set, u32 switchIdx)
{
    return ISS_SWITCH_Off((void *)ISS_SWITCH_SET_GetSwitch(set, switchIdx));
}

void ISS_SWITCH_SET_ResetSwitches(void *set)
{
    s32 i;

    ISS_SWITCH_ForceOn((void *)ISS_SWITCH_SET_GetSwitch(set, 0));
    for (i = 1; i < 9; i++) {
        ISS_SWITCH_ForceOff((void *)ISS_SWITCH_SET_GetSwitch(set, i));
    }
}

/*
 * An unlabelled leaf sitting in the four bytes between sub_0202C4A4's last
 * instruction and ISS_SWITCH_SET_GetZoneCount's first
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): no
 * register-saving prologue, so disasm.py's sweep never marks it. It is a
 * plain read of the object's first word, reached only through
 * sub_0202C340's pool-word-and-bx tail call
 * (src/matched/unit_0202C318.c, parked at MATCH because this address is
 * its only caller anywhere in the image).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C4C8.c \
 *       --func ISS_SWITCH_SET_ReadBgmNo --addr 0x0202C4C8 --cc 1.1p1 --thumb
 */
u32 ISS_SWITCH_SET_ReadBgmNo(u32 *set)
{
    return ((struct IssSwitchSet *)set)->bgmNo;
}

u32 ISS_SWITCH_SET_GetZoneCount(struct IssSwitchSet *set)
{
    return set->zoneCount;
}

u32 ISS_SWITCH_SET_GetZone(struct IssSwitchSet *set, u32 idx)
{
    return set->zones[idx];
}

u32 ISS_SWITCH_SET_CheckZone(void *set, u32 zoneId)
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

u32 ISS_SWITCH_SET_CheckSwitchOn(void *set, u32 switchIdx)
{
    return ISS_SWITCH_IsOn((void *)ISS_SWITCH_SET_GetSwitch(set, switchIdx));
}

u32 ISS_SWITCH_SET_GetSwitch(struct IssSwitchSet *set, u32 idx)
{
    return (u32)set->switches[idx];
}

void ISS_SWITCH_SET_ApplySwitchVolumes(void *set)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        ISS_SWITCH_SetVolume((void *)ISS_SWITCH_SET_GetSwitch(set, i), 0x7F);
    }
}

void *ISS_SWITCH_Create(u32 heapId)
{
    void *sw = ISS_SWITCH_Alloc(heapId);

    ISS_SWITCH_Init(sw);
    return sw;
}

u32 ISS_SWITCH_Delete(void *sw)
{
    return ISS_SWITCH_Free(sw);
}

u32 ISS_SWITCH_Setup(void *sw, u16 fadeFrames, u16 trackBits)
{
    return ISS_SWITCH_SetParam(sw, fadeFrames, trackBits);
}

u32 ISS_SWITCH_IsOn(void *sw)
{
    return ISS_SWITCH_IsOnState(sw);
}

u32 ISS_SWITCH_On(void *sw)
{
    return ISS_SWITCH_StartFadeIn(sw);
}

u32 ISS_SWITCH_Off(void *sw)
{
    return ISS_SWITCH_StartFadeOut(sw);
}

u32 ISS_SWITCH_ForceOn(void *sw)
{
    return ISS_SWITCH_SetOnState(sw);
}

u32 ISS_SWITCH_ForceOff(void *sw)
{
    return ISS_SWITCH_SetOffState(sw);
}

void ISS_SWITCH_Main(void *sw)
{
    ISS_SWITCH_Update(sw);
}

void ISS_SWITCH_SetVolume(void *sw, u32 maxVolume)
{
    ISS_SWITCH_ApplyVolume(sw, maxVolume);
}
