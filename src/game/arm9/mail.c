/*
 * file:     mail.c
 * unit:     yes
 * function: sub_020089A8, sub_020089B0, sub_020089C0, sub_020089CC, func_02008A54, func_02008A7C, func_02008ACC, func_02008ADC, sub_02008AEC, func_02008AF0, func_02008B08, func_02008B14, func_02008B20, func_02008B4C, func_02008B78, func_02008B94, func_02008B98, func_02008B9C, func_02008BD0, func_02008BE0, func_02008C00, func_02008C20, func_02008C28, func_02008C58, func_02008C64, func_02008C94, func_02008CB4, func_02008CD4, func_02008CF8, func_02008D1C, func_02008D58, func_02008DAC, func_02008DF0, func_02008DFC, func_02008E30, func_02008E68, func_02008E78, func_02008E88, func_02008EAC, func_02008EF8, MAIL_Create, func_02008F3C, func_02008F48, func_02008F80, func_02008F84, func_02008F88, func_02008F9C, func_02008FA0, func_02008FA4, func_02008FA8, func_02008FB0, func_02008FB4, func_02008FB8, func_02008FBC, func_02008FC0, func_02008FC4, func_02008FC8, func_02008FD8, func_02008FEC, func_02008FFC, func_02009004, MAIL_FindEmptySlot, func_0200902C, func_0200903C, func_02009050, func_02009074, func_020090A0, func_020090B0, func_020090B4, func_020090D8, func_020090E0, func_020090E8, func_020090F0, func_020090F8, func_02009108, func_0200910C, sub_02009110, sub_02009134
 * address:  0x020089A8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   sub_0203F49C                 0x0203F49C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   OS_GetMacAddress      0x02087C6C  arm
 *   OS_GetOwnerInfo       0x02087C88  arm
 *   OS_GetOwnerRtcOffset  0x02087D08  arm
 *   RTC_ConvertDateToDay         0x02088F58  arm
 *   func_02082A7C  0x02082A7C  arm
 *   sub_0203F2FC  0x0203F2FC  arm
 *   sub_0203F328  0x0203F328  arm
 *   sub_0203F37C  0x0203F37C  arm
 *   mystatus_file_name      0x020A70AC  data
 *   RECORD_CeilingRowTable      0x020A70C4  data
 *   RECORD_CeilingTable      0x0209DDB4  data
 *   MAIL_FileName      0x020A716C  data
 *   RECORD_FoldPairTable      0x0209DDA0  data
 *   GAME_LANGUAGE_Code   0x0209DF0C  data
 *   GAME_VERSION_Code   0x0209DF08  data
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   MIi_CpuClear16 0x02082A48  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   sub_02012EBC  0x02012EBC  thumb
 *   sub_02024570  0x02024570  thumb
 *   CGEAR_SAVE_DefaultPanels      0x020A7174  data
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;
typedef signed   short s16;
typedef signed long long   s64;

/* Word the ARM7 keeps current in the shared region (the VBlank counter). */
#define SHARED_VBLANK_COUNT (*(volatile u32 *)0x02FFFC3C)

/* The mail box holds twenty letters. */
#define MAIL_BOX_CAPACITY 20
/* Mail designs are numbered 0..11; any other value marks an empty letter. */
#define MAIL_DESIGN_COUNT 12
/* The daily play allowance is one day of minutes. */
#define DAILY_MINUTES_MAX 0x5A0

/* Save block ids. */
#define SAVE_BLOCK_TRAINER_CARD_SIGNATURE 0x21
#define SAVE_BLOCK_CONSOLE_STAMP          0x25
#define SAVE_BLOCK_RECORD                 0x26
#define SAVE_BLOCK_MAIL_BOX               0x28

struct GameData;
struct SaveControl;
struct MyStatus;

/* SDK date and time as filled by the RTC wrapper. */
struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
};

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

/* ---- Save block 0x21: trainer card signature and badge dates (0x658) ---- */

/* The date a badge was won; the fourth byte is read back with the other three
 * as one word but never written here. */
struct BadgeDate {
    u8 year;
    u8 month;
    u8 day;
    u8 reserved;
};

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

/* ---- Save block 0x26: counters with ceilings, sealed by a checksum (0x1E0) ---- */

struct RecordBlock {
    u32 wordCounters[0x47];         /* counters 0x00..0x46 */
    u16 halfCounters[0x60];         /* counters 0x47..0xA6 */
    u16 checksum;                   /* over +4..+0x1DC */
    u16 cryptSeed;                  /* high half of the seal key */
};

/* Counter pair: the source counter is folded into the target and cleared. */
struct CounterPair {
    u16 target;
    u16 source;
};

/* ---- Mail ---- */

/* Easy-chat phrase (PMS data), eight bytes. */
struct PmsData {
    u16 sentenceType;
    u16 sentenceId;
    u16 word[2];
};

struct Mail {
    u32 writerId;
    u8  gender;
    u8  language;
    u8  version;
    u8  design;                     /* 0..11, 0xFF when empty */
    u16 writerName[8];
    u16 icon[3];
    u16 messageId;
    struct PmsData message[3];
};

struct MailBox {
    struct Mail mail[MAIL_BOX_CAPACITY];
};

/* ---- Save block with the C-Gear settings (0x2C) ---- */

struct CGearSave {
    u8  panel[9][4];                /* low nibble: value, bit 7: flag */
    u16 gsyncId;
    u8  gsyncState;
    u8  isObtained;
    u8  powerSetting;
    u8  reserved[3];
};

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void MIi_CpuClear16(u16 data, void *dest, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u64 RTC_ConvertDateTimeToSecond(const struct RTCDate *date,
                                       const struct RTCTime *time);
extern u32 RTC_ConvertDateToDay(const struct RTCDate *date);
extern void OS_GetMacAddress(u8 *mac);
extern void OS_GetOwnerInfo(struct OSOwnerInfo *info);
extern s64  OS_GetOwnerRtcOffset(void);
extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);
extern void func_02082A7C(u32 value, void *dest, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *control, u32 blockId);
extern void sub_0203F49C(struct RTCDate *date, struct RTCTime *time);
/* The checksum pair over a byte range: sub_0203F2FC computes it, sub_0203F328
 * encodes the range with a key, sub_0203F37C decodes it again. */
extern u32 sub_0203F2FC(const u8 *data, u32 length);
extern void sub_0203F328(u16 *data, u32 size, u32 key);
extern void sub_0203F37C(void *data, u32 size, u32 key);
extern u16  STRBUF_GetEosChar(void);
extern void PMSI_PARAM_ClearSentence(struct PmsData *pms);
extern void sub_02024570(struct PmsData *dest, const struct PmsData *src);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site,
                           u16 tag);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern const u16 *MYSTATUS_GetName(const struct MyStatus *status);
extern u32 MYSTATUS_GetId(const struct MyStatus *status);
extern u8  MYSTATUS_GetOutfitVariant(const struct MyStatus *status);
extern struct SaveControl *sub_02012EBC(struct GameData *gameData);

extern unsigned char RECORD_CeilingRowTable[];
extern int RECORD_CeilingTable[];
extern struct CounterPair RECORD_FoldPairTable[5];
extern const u8 GAME_LANGUAGE_Code;
extern const u8 GAME_VERSION_Code;
extern char MAIL_FileName[];
extern const u8 CGEAR_SAVE_DefaultPanels[0x24];

/* Forward declarations of functions defined further down. */
void sub_02008B9C(struct DailyClock *clock);
void sub_02008C64(struct RecordBlock *record, int enable);
int MAIL_FindEmptySlotInRange(struct Mail *box, int count);
struct Mail *MAIL_GetSlot(struct Mail *box, u32 boxKind, int index);

/*
 * Save block 0x21, 0x658 bytes.  The original file opens with the four bytes
 * that return the block size and ends where the next such function returns
 * 0x5C (0x02008AEC).
 *
 *   +0x000  u32[384]  signature bitmap, summed whole by sub_020089D0
 *   +0x600  u16       signature colour
 *   +0x602  u8        read by sub_020089F4, only ever set to 1
 *   +0x603  u8        signature style
 *   +0x604  8 x 4     badge dates; three bytes written by sub_02008A7C and
 *                     read back as one little endian word by sub_02008A54
 *   +0x624  u64       RTC second count at the last badge (4-aligned)
 *   +0x638  u16[16]   per-badge timer, stamped with 0xF0 by sub_02008A7C
 *
 * sub_02008A44 returns the pair at +0x624 as one u64: the compiler loads the
 * low half into a scratch register first, then moves it into place.
 * sub_02008A54 assembles a word out of four bytes; the pool constant is 0x605
 * (the second byte is loaded first, the other offsets derive from it).
 * sub_020089D0 compares its counter with blt, so the loop variable is a signed
 * int.  The bound 384 is built as movs r1, #6 / lsls r1, r1, #6.
 */
u32 sub_020089A8(void)
{
    return sizeof(struct TrainerCardSignature);
}

void sub_020089B0(struct TrainerCardSignature *card)
{
    MI_CpuFill8(card, 0, sizeof(struct TrainerCardSignature));
}

struct TrainerCardSignature *sub_020089C0(struct SaveControl *control)
{
    return SAVE_CONTROL_GetBlock(control, SAVE_BLOCK_TRAINER_CARD_SIGNATURE);
}

u32 *sub_020089CC(struct TrainerCardSignature *card)
{
    return card->signatureBitmap;
}

/* Is any word of the signature bitmap non zero. */
int sub_020089D0(const struct TrainerCardSignature *card)
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

u8 sub_020089F4(const struct TrainerCardSignature *card)
{
    return card->seenBefore;
}

struct TrainerCardSignature *sub_02008A00(struct TrainerCardSignature *card)
{
    card->seenBefore = 1;
    return card;
}

u16 sub_02008A0C(const struct TrainerCardSignature *card)
{
    return card->signatureColor;
}

void sub_02008A14(struct TrainerCardSignature *card, u16 color)
{
    card->signatureColor = color;
}

void sub_02008A1C(struct TrainerCardSignature *card, u8 style)
{
    card->signatureStyle = style;
}

u8 sub_02008A28(const struct TrainerCardSignature *card)
{
    return card->signatureStyle;
}

void sub_02008A34(struct TrainerCardSignature *card, u32 lo, u32 hi)
{
    card->lastBadgeTime.half.lo = lo;
    card->lastBadgeTime.half.hi = hi;
}

u64 sub_02008A44(const struct TrainerCardSignature *card)
{
    return card->lastBadgeTime.whole;
}

/*
 * Returns badge date `badge` by value.  The byte-by-byte assembly into r0,
 * the 1, 0, 2, 3 load order and the 0x605 pool constant are what the compiler
 * emits for returning a byte-aligned four-byte struct.
 */
struct BadgeDate sub_02008A54(struct TrainerCardSignature *card, int badge)
{
    return card->badgeDate[badge];
}

/* Record the date of badge `badge`, mark its timer 0xF0 and store the wall
 * clock as a second count.  The fifth argument arrives on the stack and is
 * loaded as a whole word, so it is int-width and truncated by the strb. */
void sub_02008A7C(struct TrainerCardSignature *card, u32 badge, u32 year,
                  u32 month, u32 day)
{
    struct RTCDate date;
    struct RTCTime time;
    u64 second;

    sub_0203F49C(&date, &time);
    second = RTC_ConvertDateTimeToSecond(&date, &time);

    card->badgeDate[badge].year = year;
    card->badgeDate[badge].month = month;
    card->badgeDate[badge].day = day;
    card->badgeTimer[badge] = 0xF0;

    sub_02008A34(card, (u32)second, (u32)(second >> 32));
}

u16 sub_02008ACC(const struct TrainerCardSignature *card, u32 badge)
{
    return card->badgeTimer[badge];
}

void sub_02008ADC(struct TrainerCardSignature *card, int badge, int timer)
{
    card->badgeTimer[badge] = timer;
}

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
 * long to four inside a struct.  sub_02008BE0 tests < and assigns zero in the
 * taken branch; the other spelling inverts the condition and swaps the arms.
 *
 * sub_02008B20 and sub_02008B78 are the only callers of OS_GetOwnerRtcOffset
 * in the ROM; the attestation rule is described in docs/MATCHING.md.
 */
u32 sub_02008AEC(void)
{
    return sizeof(struct ConsoleStamp);
}

void func_02008AF0(struct ConsoleStamp *stamp)
{
    MIi_CpuClearFast(0, stamp, sizeof(struct ConsoleStamp));
    sub_02008B9C(&stamp->clock);
}

struct ConsoleStamp *sub_02008B08(struct SaveControl *control)
{
    return SAVE_CONTROL_GetBlock(control, SAVE_BLOCK_CONSOLE_STAMP);
}

struct DailyClock *sub_02008B14(struct SaveControl *control)
{
    struct ConsoleStamp *stamp = SAVE_CONTROL_GetBlock(control, SAVE_BLOCK_CONSOLE_STAMP);

    return &stamp->clock;
}

/* Stamp the block with this console's identity. */
void sub_02008B20(struct ConsoleStamp *stamp)
{
    struct OSOwnerInfo info;

    stamp->rtcOffset = OS_GetOwnerRtcOffset();
    OS_GetMacAddress(stamp->mac);
    OS_GetOwnerInfo(&info);
    stamp->birthdayMonth = info.birthdayMonth;
    stamp->birthdayDay = info.birthdayDay;
}

/* Is the stamped MAC address this console's. */
int sub_02008B4C(const struct ConsoleStamp *stamp)
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
int sub_02008B78(const struct ConsoleStamp *stamp)
{
    if (OS_GetOwnerRtcOffset() != stamp->rtcOffset) {
        return 0;
    }
    return 1;
}

u8 sub_02008B94(const struct ConsoleStamp *stamp)
{
    return stamp->birthdayMonth;
}

u8 sub_02008B98(const struct ConsoleStamp *stamp)
{
    return stamp->birthdayDay;
}

void sub_02008B9C(struct DailyClock *clock)
{
    clock->started = 1;
    sub_0203F49C(&clock->date, &clock->time);
    clock->dayCount = RTC_ConvertDateToDay(&clock->date);
    clock->startSecond = RTC_ConvertDateTimeToSecond(&clock->date, &clock->time);
    clock->usedMinutes = 0;
    clock->carriedMinutes = 0;
    clock->remainingMinutes = 0;
}

/* Is any allowance left. */
int sub_02008BD0(const struct DailyClock *clock)
{
    if (clock->remainingMinutes == 0) {
        return 0;
    }
    return 1;
}

/* Spend `minutes` of the allowance, clamping it to a day first. */
void sub_02008BE0(struct DailyClock *clock, u32 minutes)
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
void sub_02008C00(struct DailyClock *clock)
{
    clock->remainingMinutes = DAILY_MINUTES_MAX;
    sub_0203F49C(&clock->date, &clock->time);
    clock->dayCount = RTC_ConvertDateToDay(&clock->date);
}

/*
 * Save block 0x26, 0x1E0 bytes: a flat table of counters with two element
 * widths and its own checksum.
 *
 *   +0x000  u32[0x47]   counters 0x00..0x46
 *   +0x11C  u16[0x60]   counters 0x47..0xA6
 *   +0x1DC  u16         checksum over +4..+0x1DC (0x1D8 bytes)
 *   +0x1DE  u16         high half of the key that seals the range
 *
 * The seal key is checksum + (cryptSeed << 16), added not or-ed (the image
 * uses adds).  sub_02008C64 stores the checksum and encodes the range with
 * the key; sub_02008C94 decodes it again.  sub_02008CB4 and sub_02008CD4 read
 * and write the split index space; both answer 0 for an index of 0xA7 or more.
 * The setter returns what the getter would, through a real call.
 *
 * 0x1E0 has no Thumb immediate, so the size is built as movs 0x1E / lsls 4.
 */
u32 sub_02008C20(void)
{
    return sizeof(struct RecordBlock);
}

/*
 * The block constructor: wipes 0x1E0 bytes, seeds the key from the shared
 * VBlank word (read twice, so the 0x02FFFC3C constant is volatile, and
 * combined as first << 8 | second with two named u32 locals, which puts the
 * pool address in r1 and the first value in r0 as the original does), then
 * seals the block.
 */
void func_02008C28(struct RecordBlock *record)
{
    u32 first;
    u32 second;

    func_02082A7C(0, record, sizeof(struct RecordBlock));
    first = SHARED_VBLANK_COUNT;
    second = SHARED_VBLANK_COUNT;
    record->cryptSeed = first << 8 | second;
    sub_02008C64(record, 1);
}

struct RecordBlock *sub_02008C58(struct SaveControl *control)
{
    return SAVE_CONTROL_GetBlock(control, SAVE_BLOCK_RECORD);
}

/* Store the checksum and encode the counters.  Callers below pass the counter
 * index as `enable`, so nothing happens for counter 0. */
void sub_02008C64(struct RecordBlock *record, int enable)
{
    if (enable) {
        record->checksum = sub_0203F2FC((const u8 *)(&record->wordCounters[1]),
                                        0x1D8);
        sub_0203F328((u16 *)(&record->wordCounters[1]), 0x1D8,
                     record->checksum + (record->cryptSeed << 16));
    }
}

/* Decode the counters. */
void sub_02008C94(struct RecordBlock *record, int enable)
{
    if (enable) {
        sub_0203F37C(&record->wordCounters[1], 0x1D8,
                     record->checksum + (record->cryptSeed << 16));
    }
}

u32 sub_02008CB4(const struct RecordBlock *record, int index)
{
    if (index < 0x47) {
        return record->wordCounters[index];
    }
    if (index < 0xA7) {
        return record->halfCounters[index - 0x47];
    }
    return 0;
}

u32 sub_02008CD4(struct RecordBlock *record, int index, u32 value)
{
    if (index < 0x47) {
        record->wordCounters[index] = value;
    } else if (index < 0xA7) {
        record->halfCounters[index - 0x47] = value;
    }
    return sub_02008CB4(record, index);
}

/*
 * The ceiling of counter `index`.  RECORD_CeilingRowTable maps a counter to a row of the
 * ceiling table RECORD_CeilingTable (999999999, 999999, 65535, 9999, 999, 6); an index
 * of 0xA7 or more, or a row of 6 or more, has no ceiling and gives 0.
 */
int func_02008CF8(int index)
{
    int row = RECORD_CeilingRowTable[index];

    if (row >= 0xa7) return 0;
    if (row >= 6) return 0;
    return RECORD_CeilingTable[row];
}

/*
 * Clamped read-modify-write layer over the block.  Each function takes the
 * block and a counter index, looks up the ceiling with func_02008CF8, decodes
 * with sub_02008C94, writes through sub_02008CD4 and re-seals with
 * sub_02008C64.
 */

/* Set the counter to `value`, at most the ceiling. */
u32 sub_02008D1C(struct RecordBlock *record, int index, u32 value)
{
    u32 ceiling = func_02008CF8(index);
    u32 result;

    sub_02008C94(record, index);
    if (value < ceiling) {
        result = sub_02008CD4(record, index, value);
    } else {
        result = sub_02008CD4(record, index, ceiling);
    }
    sub_02008C64(record, index);
    return result;
}

/* Raise the counter to `minimum` (itself clamped to the ceiling); a counter
 * already above the ceiling is lowered to it. */
u32 sub_02008D58(struct RecordBlock *record, int index, u32 minimum)
{
    u32 ceiling = func_02008CF8(index);
    u32 result;

    sub_02008C94(record, index);
    result = sub_02008CB4(record, index);
    if (minimum > ceiling) {
        minimum = ceiling;
    }
    if (result < minimum) {
        result = sub_02008CD4(record, index, minimum);
    } else if (result > ceiling) {
        result = sub_02008CD4(record, index, ceiling);
    }
    sub_02008C64(record, index);
    return result;
}

/* Add `delta`, at most the ceiling.  The sum needs a named local: written
 * inline in either operand order the compiler emits adds r2, r7, r0 instead
 * of adds r2, r0, r7
 * (docs/idioms/commutative-operand-order-names-the-temporary.md). */
u32 sub_02008DAC(struct RecordBlock *record, int index, u32 delta)
{
    u32 ceiling = func_02008CF8(index);
    u32 result;
    u32 current;

    sub_02008C94(record, index);
    current = sub_02008CB4(record, index);
    result = current + delta;
    if (result < ceiling) {
        result = sub_02008CD4(record, index, result);
    } else {
        result = sub_02008CD4(record, index, ceiling);
    }
    sub_02008C64(record, index);
    return result;
}

/* Add one: twelve bytes, no label. */
u32 sub_02008DF0(struct RecordBlock *record, int index)
{
    return sub_02008DAC(record, index, 1);
}

/* Read the counter, at most the ceiling. */
u32 sub_02008DFC(struct RecordBlock *record, int index)
{
    u32 ceiling = func_02008CF8(index);
    u32 result;

    sub_02008C94(record, index);
    result = sub_02008CB4(record, index);
    sub_02008C64(record, index);
    if (result <= ceiling) {
        ceiling = result;
    }
    return ceiling;
}

/* Fold each pair of the table RECORD_FoldPairTable (1A 1B, 51 52, 53 54, 55 56,
 * 57 58): raise the target to the source's value, then clear the source.
 * The table is read as halfwords, so no string witness can attest its
 * address. */
void func_02008E30(struct RecordBlock *record)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        u16 source = RECORD_FoldPairTable[i].source;

        sub_02008D58(record, RECORD_FoldPairTable[i].target,
                     sub_02008DFC(record, source));
        sub_02008D1C(record, source, 0);
    }
}

/* Counter 0x7B has a ceiling of 6 and counter 0x7C one of 9999; the writers
 * check their argument against that ceiling first.  Counter 0x7B is the Trial
 * House rank and 0x7C its score (callers: trial_house, trcard_sys). */
void sub_02008E68(struct RecordBlock *record, u32 rank)
{
    if (rank < 7) {
        sub_02008D58(record, 0x7B, rank);
    }
}

u8 sub_02008E78(struct RecordBlock *record)
{
    return sub_02008DFC(record, 0x7B);
}

void sub_02008E88(struct RecordBlock *record, u32 score)
{
    if (score < 9999) {
        sub_02008D58(record, 0x7C, score);
    }
}

/* Twelve bytes, no label. */
u32 sub_02008EA0(struct RecordBlock *record)
{
    return sub_02008DFC(record, 0x7C);
}

/*
 * Mail.  The 0x38-byte letter is allocated with "mail.c" as the debug site
 * (MAIL_FileName, line 135).
 */
static inline void MI_CpuFill16(void *dest, u16 data, u32 size)
{
    MIi_CpuClear16(data, dest, size);
}

/* MI_CpuFill16 is the SDK header's inline wrapper: a direct blx MIi_CpuClear16
 * with the data and destination swapped.  The 0xFFFF at +0x1E is a pool word
 * (the Thumb immediate stops at 255); the 0xFF at +7 is a movs. */
void MAIL_Init(struct Mail *mail)
{
    int i;

    mail->writerId = 0;
    mail->gender = 0;
    mail->language = GAME_LANGUAGE_Code;
    mail->version = GAME_VERSION_Code;
    mail->design = 0xFF;
    MI_CpuFill16(mail->writerName, STRBUF_GetEosChar(), sizeof(mail->writerName));
    mail->messageId = 0xFFFF;
    for (i = 0; i < 3; i++) {
        PMSI_PARAM_ClearSentence(&mail->message[i]);
    }
}

/* Is the design one of the 12 valid ones.  bhi, not bgt, is the only
 * evidence of an unsigned compare. */
int MAIL_IsDesignValid(const struct Mail *mail)
{
    if (mail->design <= MAIL_DESIGN_COUNT - 1) {
        return 1;
    }
    return 0;
}

struct Mail *MAIL_Create(int heapId)
{
    struct Mail *mail = func_02030734((unsigned short)((heapId & 0x7fff) | 0x8000),
                                      sizeof(struct Mail), 0, MAIL_FileName, 0x87);

    MAIL_Init(mail);
    return mail;
}

/* Copy a whole letter.  Both pointers are already in the registers MI_CpuCopy8
 * wants; the bx r3 is a tail call to an ARM function through a pool word. */
void MAIL_Copy(const struct Mail *src, struct Mail *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Mail));
}

/* Fill a blank letter for the player.  The third parameter is dead.
 * MYSTATUS_GetName is an identity accessor on its argument, declared with the
 * type this call needs. */
void MAIL_InitForPlayer(struct Mail *mail, u8 design, u32 unused,
                  struct GameData *gameData)
{
    struct MyStatus *status;

    MAIL_Init(mail);
    mail->design = design;
    status = func_02012944(gameData);
    MI_CpuCopy8(MYSTATUS_GetName(status), mail->writerName, sizeof(mail->writerName));
    mail->gender = MYSTATUS_GetOutfitVariant(status);
    mail->writerId = MYSTATUS_GetId(status);
}

/*
 * Accessors of the letter.  MAIL_SetWriterName copies *into* the letter (the
 * argument shuffle builds the field address in r2, then puts the caller's
 * pointer in the source register).  MAIL_GetMessage tests index < 3 first and
 * falls out of range to entry 0; the other spelling inverts the branch and
 * swaps the arms.
 */
u32 MAIL_GetWriterId(const struct Mail *mail)
{
    return mail->writerId;
}

u16 *MAIL_GetWriterName(struct Mail *mail)
{
    return mail->writerName;
}

void MAIL_SetWriterName(struct Mail *mail, const void *name)
{
    MI_CpuCopy8(name, mail->writerName, sizeof(mail->writerName));
}

u8 MAIL_GetGender(const struct Mail *mail)
{
    return mail->gender;
}

void MAIL_SetGender(struct Mail *mail, u8 gender)
{
    mail->gender = gender;
}

u8 MAIL_GetDesign(const struct Mail *mail)
{
    return mail->design;
}

void MAIL_SetDesign(struct Mail *mail, u32 design)
{
    if (design < MAIL_DESIGN_COUNT) {
        mail->design = design;
    }
}

u8 MAIL_GetLanguage(const struct Mail *mail)
{
    return mail->language;
}

void MAIL_SetLanguage(struct Mail *mail, u8 language)
{
    mail->language = language;
}

u8 MAIL_GetVersion(const struct Mail *mail)
{
    return mail->version;
}

void MAIL_SetVersion(struct Mail *mail, u8 version)
{
    mail->version = version;
}

u16 MAIL_GetMessageId(const struct Mail *mail)
{
    return mail->messageId;
}

void MAIL_SetMessageId(struct Mail *mail, u16 messageId)
{
    mail->messageId = messageId;
}

struct PmsData *MAIL_GetMessage(struct Mail *mail, u32 index)
{
    if (index < 3) {
        return &mail->message[index];
    }
    return &mail->message[0];
}

void MAIL_SetMessage(struct Mail *mail, struct PmsData *pms, u32 index)
{
    if (index < 3) {
        sub_02024570(&mail->message[index], pms);
    }
}

struct MailBox *MAIL_GetBox(struct GameData *gameData)
{
    return SAVE_CONTROL_GetBlock(sub_02012EBC(gameData), SAVE_BLOCK_MAIL_BOX);
}

/*
 * The mail box: twenty letters, save block 0x28.  The size getter returns
 * 0x460, twenty times 0x38.  0x38 is not a power of two, so every index costs
 * a muls with the element size hoisted out of the loop.
 *
 * MAIL_SetSlot and MAIL_CreateSlotCopy are the only callers of MAIL_Copy in the
 * ROM, so matched in one range they attest each other's call site away; the
 * old split into separate files is the same trick as at sub_02008B20.
 * MAIL_GetSlot ignores its second argument (a box kind): no instruction reads
 * r1, and the callers pass their own second argument straight through.
 */
u32 MAIL_GetBoxSize(void)
{
    return sizeof(struct MailBox);
}

void MAIL_InitBox(struct Mail *box)
{
    int i;

    for (i = 0; i < MAIL_BOX_CAPACITY; i++) {
        MAIL_Init(&box[i]);
    }
}

/* Index of the first empty letter in the box, or -1. */
int MAIL_FindEmptySlot(struct Mail *box)
{
    return MAIL_FindEmptySlotInRange(box, MAIL_BOX_CAPACITY);
}

/* Empty the letter at `index`. */
void MAIL_ClearSlot(struct Mail *box, u32 boxKind, int index)
{
    struct Mail *mail = MAIL_GetSlot(box, boxKind, index);

    if (mail != 0) {
        MAIL_Init(mail);
    }
}

/* Store a copy of `src` at `index`. */
void MAIL_SetSlot(struct Mail *box, u32 boxKind, int index,
                  const struct Mail *src)
{
    struct Mail *mail = MAIL_GetSlot(box, boxKind, index);

    if (mail != 0) {
        MAIL_Copy(src, mail);
    }
}

/* Return a new allocated copy of the letter at `index`. */
struct Mail *MAIL_CreateSlotCopy(struct Mail *box, u32 boxKind, int index, u32 heapId)
{
    struct Mail *mail = MAIL_GetSlot(box, boxKind, index);
    struct Mail *copy = MAIL_Create(heapId);

    if (mail != 0) {
        MAIL_Copy(mail, copy);
    }
    return copy;
}

/* The index of the first of `count` letters that is not valid, or -1. */
int MAIL_FindEmptySlotInRange(struct Mail *box, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        if (MAIL_IsDesignValid(&box[i]) == 0) {
            return i;
        }
    }
    return -1;
}

/* The letter at `index`, or 0 when the index is outside the box. */
struct Mail *MAIL_GetSlot(struct Mail *box, u32 boxKind, int index)
{
    if (index < MAIL_BOX_CAPACITY) {
        return &box[index];
    }
    return 0;
}

/*
 * C-Gear settings block, 0x2C bytes, in the next original file.  The
 * constructor clears the object and copies 0x24 bytes of initial panel state
 * over it from 0x020A7174.
 *
 * Six of the eight scalar accessors cost an extra adds r0, #imm before the
 * load or store, because ldrb and strb reach only +31 and the fields are at
 * +0x26..+0x28; the two u16 accessors at +0x24 need none (ldrh reaches +62;
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 */
u32 sub_020090B0(void)
{
    return sizeof(struct CGearSave);
}

void func_020090B4(struct CGearSave *save)
{
    MI_CpuFill8(save, 0, sub_020090B0());
    MI_CpuCopy8(CGEAR_SAVE_DefaultPanels, save, 0x24);
}

void sub_020090D8(struct CGearSave *save, u8 isObtained)
{
    save->isObtained = isObtained;
}

u8 sub_020090E0(const struct CGearSave *save)
{
    return save->isObtained;
}

void sub_020090E8(struct CGearSave *save, u8 powerSetting)
{
    save->powerSetting = powerSetting;
}

u8 sub_020090F0(const struct CGearSave *save)
{
    return save->powerSetting;
}

void sub_020090F8(struct CGearSave *save, u8 gsyncState)
{
    save->gsyncState = gsyncState;
}

u8 sub_02009100(const struct CGearSave *save)
{
    return save->gsyncState;
}

void sub_02009108(struct CGearSave *save, u16 gsyncId)
{
    save->gsyncId = gsyncId;
}

u16 sub_0200910C(const struct CGearSave *save)
{
    return save->gsyncId;
}

u32 sub_02009110(const struct CGearSave *save, int row, int col)
{
    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    return save->panel[row][col] & 0xF;
}

int sub_02009134(const struct CGearSave *save, int row, int col)
{
    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    if ((save->panel[row][col] & 0x80) != 0) {
        return 1;
    }
    return 0;
}
