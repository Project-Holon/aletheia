/*
 * file:     trcard_sign.c
 * unit:     yes
 * function: TRCARD_SIGN_GetSize, TRCARD_SIGN_Init, TRCARD_SIGN_GetFromSave, TRCARD_SIGN_GetBitmap, TRCARD_SIGN_HasAnySignature, TRCARD_SIGN_GetSeenBefore, TRCARD_SIGN_SetSeenBefore, TRCARD_SIGN_GetColor, TRCARD_SIGN_SetColor, TRCARD_SIGN_SetStyle, TRCARD_SIGN_GetStyle, TRCARD_SIGN_SetLastBadgeTime, TRCARD_SIGN_GetLastBadgeTime, TRCARD_SIGN_GetBadgeDate, TRCARD_SIGN_SetBadgeDate, TRCARD_SIGN_GetBadgeTimer, TRCARD_SIGN_SetBadgeTimer
 * address:  0x020089A8
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
 *   MI_CpuFill8   0x02082BCC  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   GF_STANDARD_CopyCachedRtc                 0x0203F49C  arm
 */
#include "trcard_sign_shared_types.h"

/* Save block ids. */
#define SAVE_BLOCK_TRAINER_CARD_SIGNATURE 0x21

/* ---- Save block 0x21: trainer card signature and badge dates (0x658) ---- */

struct TrainerCardSignature {
    u32 signatureBitmap[384];       /* 0x600 bytes of drawn bitmap */
    u16 signatureColor;
    u8  seenBefore;                 /* set to 1 once the card was shown */
    u8  signatureStyle;
    struct BadgeDate badgeDate[8];
    union {
        u64 whole;
        struct {
            u32 lo;
            u32 hi;
        } half;
    } lastBadgeTime;                /* RTC second count at the last badge */
    u8  reserved[0xC];
    u16 badgeTimer[16];
};

#include "mi_memory.h"

#include "convert.h"

#include "save_control.h"

#include "gf_standard.h"

/*
 * Save block 0x21, 0x658 bytes.  The original file opens with the four bytes
 * that return the block size and ends where the next such function returns
 * 0x5C (0x02008AEC).
 *
 *   +0x000  u32[384]  signature bitmap, summed whole by TRCARD_SIGN_HasAnySignature
 *   +0x600  u16       signature colour
 *   +0x602  u8        read by TRCARD_SIGN_GetSeenBefore, only ever set to 1
 *   +0x603  u8        signature style
 *   +0x604  8 x 4     badge dates; three bytes written by TRCARD_SIGN_SetBadgeDate and
 *                     read back as one little endian word by TRCARD_SIGN_GetBadgeDate
 *   +0x624  u64       RTC second count at the last badge (4-aligned)
 *   +0x638  u16[16]   per-badge timer, stamped with 0xF0 by TRCARD_SIGN_SetBadgeDate
 *
 * TRCARD_SIGN_GetLastBadgeTime returns the pair at +0x624 as one u64: the compiler loads the
 * low half into a scratch register first, then moves it into place.
 * TRCARD_SIGN_GetBadgeDate assembles a word out of four bytes; the pool constant is 0x605
 * (the second byte is loaded first, the other offsets derive from it).
 * TRCARD_SIGN_HasAnySignature compares its counter with blt, so the loop variable is a signed
 * int.  The bound 384 is built as movs r1, #6 / lsls r1, r1, #6.
 */
u32 TRCARD_SIGN_GetSize(void)
{
    return sizeof(struct TrainerCardSignature);
}

void TRCARD_SIGN_Init(struct TrainerCardSignature *card)
{
    MI_CpuFill8(card, 0, sizeof(struct TrainerCardSignature));
}

struct TrainerCardSignature *TRCARD_SIGN_GetFromSave(struct SaveControl *control)
{
    return SAVE_CONTROL_GetBlock(control, SAVE_BLOCK_TRAINER_CARD_SIGNATURE);
}

u32 *TRCARD_SIGN_GetBitmap(struct TrainerCardSignature *card)
{
    return card->signatureBitmap;
}

/* Is any word of the signature bitmap non zero. */
int TRCARD_SIGN_HasAnySignature(const struct TrainerCardSignature *card)
{
    u32 sum;
    int i;

    sum = 0;
    for (i = 0; i < 384; i++) {
        sum += card->signatureBitmap[i];
    }
    if (sum == 0) {
        return 0;
    }
    return 1;
}

u8 TRCARD_SIGN_GetSeenBefore(const struct TrainerCardSignature *card)
{
    return card->seenBefore;
}

struct TrainerCardSignature *TRCARD_SIGN_SetSeenBefore(struct TrainerCardSignature *card)
{
    card->seenBefore = 1;
    return card;
}

u16 TRCARD_SIGN_GetColor(const struct TrainerCardSignature *card)
{
    return card->signatureColor;
}

void TRCARD_SIGN_SetColor(struct TrainerCardSignature *card, u16 color)
{
    card->signatureColor = color;
}

void TRCARD_SIGN_SetStyle(struct TrainerCardSignature *card, u8 style)
{
    card->signatureStyle = style;
}

u8 TRCARD_SIGN_GetStyle(const struct TrainerCardSignature *card)
{
    return card->signatureStyle;
}

void TRCARD_SIGN_SetLastBadgeTime(struct TrainerCardSignature *card, u32 lo, u32 hi)
{
    card->lastBadgeTime.half.lo = lo;
    card->lastBadgeTime.half.hi = hi;
}

u64 TRCARD_SIGN_GetLastBadgeTime(const struct TrainerCardSignature *card)
{
    return card->lastBadgeTime.whole;
}

/*
 * Returns badge date `badge` by value.  The byte-by-byte assembly into r0,
 * the 1, 0, 2, 3 load order and the 0x605 pool constant are what the compiler
 * emits for returning a byte-aligned four-byte struct.
 */
struct BadgeDate TRCARD_SIGN_GetBadgeDate(struct TrainerCardSignature *card, int badge)
{
    return card->badgeDate[badge];
}

/* Record the date of badge `badge`, mark its timer 0xF0 and store the wall
 * clock as a second count.  The fifth argument arrives on the stack and is
 * loaded as a whole word, so it is int-width and truncated by the strb. */
void TRCARD_SIGN_SetBadgeDate(struct TrainerCardSignature *card, u32 badge, u32 year,
                  u32 month, u32 day)
{
    struct RTCDate date;
    struct RTCTime time;
    u64 second;

    GF_STANDARD_CopyCachedRtc((RTCDate *)&date, (RTCTime *)&time);
    second = RTC_ConvertDateTimeToSecond(&date, &time);

    card->badgeDate[badge].year = year;
    card->badgeDate[badge].month = month;
    card->badgeDate[badge].day = day;
    card->badgeTimer[badge] = 0xF0;

    TRCARD_SIGN_SetLastBadgeTime(card, (u32)second, (u32)(second >> 32));
}

u16 TRCARD_SIGN_GetBadgeTimer(const struct TrainerCardSignature *card, u32 badge)
{
    return card->badgeTimer[badge];
}

void TRCARD_SIGN_SetBadgeTimer(struct TrainerCardSignature *card, int badge, int timer)
{
    card->badgeTimer[badge] = timer;
}
