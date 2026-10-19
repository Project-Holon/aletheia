/*
 * file:     console_stamp.c
 * unit:     yes
 * function: CONSOLE_STAMP_GetSize, CONSOLE_STAMP_Init, CONSOLE_STAMP_GetFromSave, CONSOLE_STAMP_GetDailyClock, CONSOLE_STAMP_SetIdentity, CONSOLE_STAMP_IsThisConsole, CONSOLE_STAMP_IsRtcOffsetCurrent, CONSOLE_STAMP_GetBirthdayMonth, CONSOLE_STAMP_GetBirthdayDay, DAILY_CLOCK_Init, DAILY_CLOCK_HasAllowance, DAILY_CLOCK_Spend, DAILY_CLOCK_Refill
 * address:  0x02008AEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mail.c by tools/splitfile.py.
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   GF_STANDARD_CopyCachedRtc                 0x0203F49C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   OS_GetMacAddress      0x02087C6C  arm
 *   OS_GetOwnerInfo       0x02087C88  arm
 *   OS_GetOwnerRtcOffset  0x02087D08  arm
 *   RTC_ConvertDateToDay         0x02088F58  arm
 */
#include "trcard_sign_shared_types.h"

typedef signed   short s16;

typedef signed long long   s64;

/* The daily play allowance is one day of minutes. */
#define DAILY_MINUTES_MAX 0x5A0

#define SAVE_BLOCK_CONSOLE_STAMP          0x25

/* SDK owner information; the tail is padding that only fixes the frame size. */
struct OSOwnerInfo {
    u8  language;
    u8  favoriteColor;
    u8  birthdayMonth;
    u8  birthdayDay;
    u16 nickname[10];
    s16 nicknameLength;
    u16 comment[26];
    s16 commentLength;
    u8  padding[4];
};

/* ---- Save block 0x25: console identity and daily play allowance (0x5C) ---- */
struct DailyClock {
    u32 started;                    /* 1 once a session was started */
    struct RTCDate date;
    struct RTCTime time;
    u32 dayCount;                   /* the date as a day number */
    u64 startSecond;                /* date and time as a second count */
    u32 usedMinutes;
    u32 carriedMinutes;
    u32 remainingMinutes;           /* clamped to DAILY_MINUTES_MAX */
};

struct ConsoleStamp {
    s64 rtcOffset;                  /* owner RTC offset of the console */
    u8  mac[6];
    u8  birthdayMonth;
    u8  birthdayDay;
    struct DailyClock clock;
    u8  reserved[0x14];
};

extern u64 RTC_ConvertDateTimeToSecond(const struct RTCDate *date,
                                       const struct RTCTime *time);

extern u32 RTC_ConvertDateToDay(const struct RTCDate *date);

extern void OS_GetMacAddress(u8 *mac);

extern void OS_GetOwnerInfo(struct OSOwnerInfo *info);

extern s64  OS_GetOwnerRtcOffset(void);

extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *control, u32 blockId);

extern void GF_STANDARD_CopyCachedRtc(struct RTCDate *date, struct RTCTime *time);

/* Forward declarations of functions defined further down. */
void DAILY_CLOCK_Init(struct DailyClock *clock);

/*
 * Save block 0x25, 0x5C bytes: the console's identity plus a daily play
 * allowance clock.  The original file runs 0x02008AEC..0x02008C20, closed by
 * the size getters of both neighbours.
 *
 *   +0x00  s64    owner RTC offset (OS_GetOwnerRtcOffset)
 *   +0x08  u8[6]  MAC address
 *   +0x0E  u8     owner birthday month, +0x0F the day
 *   +0x10  0x38   DailyClock
 *   +0x48  0x14   untouched here
 *
 * The u64 at +0x24 of the clock is four-aligned: this front end aligns long
 * long to four inside a struct.  DAILY_CLOCK_Spend tests < and assigns zero in the
 * taken branch; the other spelling inverts the condition and swaps the arms.
 *
 * CONSOLE_STAMP_SetIdentity and CONSOLE_STAMP_IsRtcOffsetCurrent are the only callers of OS_GetOwnerRtcOffset
 * in the ROM; the attestation rule is described in docs/MATCHING.md.
 */
u32 CONSOLE_STAMP_GetSize(void)
{
    return sizeof(struct ConsoleStamp);
}

void CONSOLE_STAMP_Init(struct ConsoleStamp *stamp)
{
    MIi_CpuClearFast(0, stamp, sizeof(struct ConsoleStamp));
    DAILY_CLOCK_Init(&stamp->clock);
}

struct ConsoleStamp *CONSOLE_STAMP_GetFromSave(struct SaveControl *control)
{
    return SAVE_CONTROL_GetBlock(control, SAVE_BLOCK_CONSOLE_STAMP);
}

struct DailyClock *CONSOLE_STAMP_GetDailyClock(struct SaveControl *control)
{
    struct ConsoleStamp *stamp = SAVE_CONTROL_GetBlock(control, SAVE_BLOCK_CONSOLE_STAMP);

    return &stamp->clock;
}

/* Stamp the block with this console's identity. */
void CONSOLE_STAMP_SetIdentity(struct ConsoleStamp *stamp)
{
    struct OSOwnerInfo info;

    stamp->rtcOffset = OS_GetOwnerRtcOffset();
    OS_GetMacAddress(stamp->mac);
    OS_GetOwnerInfo(&info);
    stamp->birthdayMonth = info.birthdayMonth;
    stamp->birthdayDay = info.birthdayDay;
}

/* Is the stamped MAC address this console's. */
int CONSOLE_STAMP_IsThisConsole(const struct ConsoleStamp *stamp)
{
    u8 mac[6];
    int i;

    OS_GetMacAddress(mac);
    for (i = 0; i < 6; i++) {
        if (mac[i] != stamp->mac[i]) {
            return 0;
        }
    }
    return 1;
}

/* Is the stamped RTC offset this console's. */
int CONSOLE_STAMP_IsRtcOffsetCurrent(const struct ConsoleStamp *stamp)
{
    if (OS_GetOwnerRtcOffset() != stamp->rtcOffset) {
        return 0;
    }
    return 1;
}

u8 CONSOLE_STAMP_GetBirthdayMonth(const struct ConsoleStamp *stamp)
{
    return stamp->birthdayMonth;
}

u8 CONSOLE_STAMP_GetBirthdayDay(const struct ConsoleStamp *stamp)
{
    return stamp->birthdayDay;
}

void DAILY_CLOCK_Init(struct DailyClock *clock)
{
    clock->started = 1;
    GF_STANDARD_CopyCachedRtc(&clock->date, &clock->time);
    clock->dayCount = RTC_ConvertDateToDay(&clock->date);
    clock->startSecond = RTC_ConvertDateTimeToSecond(&clock->date, &clock->time);
    clock->usedMinutes = 0;
    clock->carriedMinutes = 0;
    clock->remainingMinutes = 0;
}

/* Is any allowance left. */
int DAILY_CLOCK_HasAllowance(const struct DailyClock *clock)
{
    if (clock->remainingMinutes == 0) {
        return 0;
    }
    return 1;
}

/* Spend `minutes` of the allowance, clamping it to a day first. */
void DAILY_CLOCK_Spend(struct DailyClock *clock, u32 minutes)
{
    if (clock->remainingMinutes > DAILY_MINUTES_MAX) {
        clock->remainingMinutes = DAILY_MINUTES_MAX;
    }
    if (clock->remainingMinutes < minutes) {
        clock->remainingMinutes = 0;
    } else {
        clock->remainingMinutes = clock->remainingMinutes - minutes;
    }
}

/* Refill the allowance and restamp the date. */
void DAILY_CLOCK_Refill(struct DailyClock *clock)
{
    clock->remainingMinutes = DAILY_MINUTES_MAX;
    GF_STANDARD_CopyCachedRtc(&clock->date, &clock->time);
    clock->dayCount = RTC_ConvertDateToDay(&clock->date);
}
