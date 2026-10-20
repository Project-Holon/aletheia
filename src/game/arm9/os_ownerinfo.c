/*
 * file:     os_ownerinfo.c
 * unit:     yes
 * function: OS_GetMacAddress, OS_GetOwnerInfo, OS_GetOwnerRtcOffset
 * address:  0x02087C6C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   MIi_CpuCopy16  0x02082A60  arm
 */
#include "../types.h"

#include "../sdk_os.h"

/* The user settings copy in system work at 0x02FFFC80, as far as the
   reads here reach. */
#include "mi_memory.h"
#include "os_emulator.h"
void OS_GetMacAddress(u8 *macAddress);
void OS_GetOwnerInfo(OSOwnerInfo *info);
long long OS_GetOwnerRtcOffset(void);

void OS_GetMacAddress(u8 *macAddress)
{
    MI_CpuCopy8((const void *)0x02FFFCF4, macAddress, 6);
}

#define OSi_NVRAM_OWNER ((OSiNvramOwner *)0x02FFFC80)

/*
 * sdk:      OS_GetOwnerInfo (os_ownerinfo.o)
 */
void OS_GetOwnerInfo(OSOwnerInfo *info)
{
    OSiNvramOwner *src = OSi_NVRAM_OWNER;

    info->language = (u8)src->language;
    info->favoriteColor = src->favoriteColor;
    info->birthday.month = src->month;
    info->birthday.day = src->day;
    info->nickNameLength = src->nickNameLength;
    info->commentLength = src->commentLength;
    MIi_CpuCopy16(src->nickName, info->nickName, 10 * sizeof(u16));
    MIi_CpuCopy16(src->comment, info->comment, 26 * sizeof(u16));
    info->nickName[10] = 0;
    info->comment[26] = 0;
}

typedef struct OSiOwnerRtc {
    u8 pad[0x68];
    long long rtcOffset;
} OSiOwnerRtc;

long long OS_GetOwnerRtcOffset(void)
{
    OSiOwnerRtc *w = (OSiOwnerRtc *)0x02FFFC80;
    return w->rtcOffset;
}
