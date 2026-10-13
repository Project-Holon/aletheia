/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x0200857C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PLAYTIME_Create, PLAYTIME_Init, PLAYTIME_AddSeconds, PLAYTIME_Copy,
 *           PLAYTIME_GetHours, PLAYTIME_GetMinutes, PLAYTIME_GetSeconds, PLAYTIME_SetStampNow,
 *           PLAYTIME_GetStampYear, PLAYTIME_GetStampMonth, PLAYTIME_GetStampDay, PLAYTIME_GetStampHour,
 *           PLAYTIME_GetStampMinute, PLAYTIME_GetStamp, PLAYTIME_SetStamp
 *
 * symbols:
 *   _u32_div_f          0x0209C2B0  arm
 *   MI_CpuCopy8         0x02082D44  arm
 *   RTC_GetDate         0x02088864  arm
 *   RTC_GetTime         0x0208890C  arm
 *   sub_0200857C_File   0x020A70B8  data
 *
 * alias: the original source file is named in the image.  The function at
 * 0x0200857C, immediately before this range, loads 0x020A70B8 into its literal
 * pool as an argument to the debug allocator at 0x02030734, and the bytes at
 * 0x020A70B8 spell "playtime.c".  So this is the play-time counter: an eight
 * byte object holding an hours/minutes/seconds running total and a packed
 * calendar stamp of when the save was started.  The names below stay
 * sub_<address> because the individual entry points are not attested by
 * anything; the file identity is.
 *
 * Object layout, read off the accessors:
 *
 *   +0  u16  hours    saturating at 999 (0x3E7)
 *   +2  u8   minutes  0..59
 *   +3  u8   seconds  0..59
 *   +4  u32  a packed date/time: year:7, month:4, day:5, hour:5, minute:6,
 *            leaving the top five bits unused.  The five widths are readable
 *            three ways over and they agree: the AND masks 0xFFFFF87F,
 *            0xFFFF07FF, 0xFFE0FFFF and 0xF81FFFFF in PLAYTIME_Init, the
 *            shift pairs in the five getters at 0x020086C8 and on, and the
 *            RTCDate / RTCTime fields PLAYTIME_SetStampNow feeds them from.
 *
 * Two things in this unit were new for the project and are worth naming:
 *
 *  - the four unsigned divisions in PLAYTIME_AddSeconds compile to calls to the
 *    compiler's own runtime helper, which mwccarm emits as an undefined
 *    reference named `_u32_div_f`.  The relocation carries that name, so it
 *    can be pinned in the symbols: block like any other extern even though no
 *    line of this file mentions it; 0x0209C2B0 is attested as a label by 57
 *    callers elsewhere in the image.  `a / b` and `a % b` on the same operands
 *    produce two separate calls: the helper returns the quotient in r0 and the
 *    remainder in r1, but the compiler does not know that and does not common
 *    them up, which is why the original calls it twice in a row with identical
 *    arguments.
 *  - the packed field is a nested four-byte struct of bitfields, not five
 *    bitfields inlined into the outer object.  PLAYTIME_GetStamp and PLAYTIME_SetStamp
 *    copy it whole with a single ldr/str pair, which is a struct assignment;
 *    with the bitfields flattened into PlayTime there is no lvalue of the
 *    right type to assign and the natural spellings all cost extra
 *    instructions.
 *
 * The unit starts at 0x0200857C, where the original file begins: the
 * constructor below is the function that names the file.  It passes
 * 0x020A70B8 to the debug allocator, and the bytes there spell "playtime.c".
 * That pool word is the only place in the image that names the string, so it
 * used to be unresolvable and the unit had to start at 0x020085A0 instead.
 * The `string` attestation class closes it: "mystatus.c" ends with its NUL at
 * 0x020A70B6, which fixes where the next string begins without reading the
 * pool word under test.  See "The string class" in docs/MATCHING.md.  This
 * file supersedes src/matched/unit_020085A0.c, which covered all of it but
 * the first 36 bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200857C.c \
 *       --addr 0x0200857C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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

extern void RTC_GetDate(struct RTCDate *date);
extern void RTC_GetTime(struct RTCTime *time);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

struct PlayTimeStamp {
    u32 year   : 7;
    u32 month  : 4;
    u32 day    : 5;
    u32 hour   : 5;
    u32 minute : 6;
};

struct PlayTime {
    u16 hours;
    u8  minutes;
    u8  seconds;
    struct PlayTimeStamp stamp;
};

/* The debug allocator: heap, size, alignment, __FILE__, __LINE__.  The last
 * two arrive as a pointer into the packed string area and the constant 32. */
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char sub_0200857C_File[];

void PLAYTIME_Init(struct PlayTime *p);

/* playtime.c's constructor, and the function that gives the file its name. */
void *PLAYTIME_Create(u32 heap)
{
    struct PlayTime *p = sub_02030734(heap, sizeof(struct PlayTime), 1,
                                      sub_0200857C_File, 32);
    PLAYTIME_Init(p);
    return p;
}

void PLAYTIME_Init(struct PlayTime *p)
{
    p->hours        = 0;
    p->minutes      = 0;
    p->seconds      = 0;
    p->stamp.year   = 0;
    p->stamp.month  = 0;
    p->stamp.day    = 0;
    p->stamp.hour   = 0;
    p->stamp.minute = 0;
}

/* Add `delta` seconds, carrying into minutes and hours and saturating at
 * 999:59:59.  The leading guard is the saturation test, and it returns
 * without touching the object once the counter is full. */
void PLAYTIME_AddSeconds(struct PlayTime *p, u32 delta)
{
    u32 h, m, s;

    h = p->hours;
    if (h == 999 && p->minutes == 59 && p->seconds == 59) {
        return;
    }
    s = p->seconds + delta;
    m = p->minutes;
    if (s > 59) {
        m += s / 60;
        s = s % 60;
        if (m > 59) {
            h += m / 60;
            m = m % 60;
            if (h >= 999) {
                h = 999;
                m = 59;
                s = 59;
            }
        }
    }
    p->hours   = h;
    p->minutes = m;
    p->seconds = s;
}

void PLAYTIME_Copy(struct PlayTime *dest, const struct PlayTime *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct PlayTime));
}

u16 PLAYTIME_GetHours(const struct PlayTime *p)
{
    return p->hours;
}

u8 PLAYTIME_GetMinutes(const struct PlayTime *p)
{
    return p->minutes;
}

u8 PLAYTIME_GetSeconds(const struct PlayTime *p)
{
    return p->seconds;
}

/* Stamp the object with the wall clock. */
void PLAYTIME_SetStampNow(struct PlayTime *p)
{
    struct RTCDate date;
    struct RTCTime time;

    RTC_GetDate(&date);
    RTC_GetTime(&time);

    p->stamp.year   = date.year;
    p->stamp.month  = date.month;
    p->stamp.day    = date.day;
    p->stamp.hour   = time.hour;
    p->stamp.minute = time.minute;
}

u32 PLAYTIME_GetStampYear(const struct PlayTime *p)
{
    return p->stamp.year;
}

u32 PLAYTIME_GetStampMonth(const struct PlayTime *p)
{
    return p->stamp.month;
}

u32 PLAYTIME_GetStampDay(const struct PlayTime *p)
{
    return p->stamp.day;
}

u32 PLAYTIME_GetStampHour(const struct PlayTime *p)
{
    return p->stamp.hour;
}

u32 PLAYTIME_GetStampMinute(const struct PlayTime *p)
{
    return p->stamp.minute;
}

void PLAYTIME_GetStamp(const struct PlayTime *p, struct PlayTimeStamp *out)
{
    *out = p->stamp;
}

void PLAYTIME_SetStamp(struct PlayTime *p, const struct PlayTimeStamp *in)
{
    p->stamp = *in;
}
