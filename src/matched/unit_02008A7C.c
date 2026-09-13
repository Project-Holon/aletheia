/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008A7C
 * packet:   pkt_02008A34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02008A7C, sub_02008ACC, sub_02008ADC
 *
 * symbols:
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   sub_02008A34                 0x02008A34  thumb
 *   sub_0203F49C                 0x0203F49C  arm
 *
 * alias: the tail of the id 0x21 save block's file; see
 * src/matched/unit_020089A8.c for the object layout and the block identity.
 * This is not a translation unit boundary.  The original file runs
 * 0x020089A8..0x02008AEC in one piece and this range is the part of it after
 * sub_02008A54, which is a near miss: see the note in unit_020089A8.c.  The
 * two files are kept separate for the same reason unit_0200894C.c once was,
 * and should be merged the day that function closes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008A7C.c \
 *       --addr 0x02008A7C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

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

extern u64 RTC_ConvertDateTimeToSecond(const struct RTCDate *date,
                                       const struct RTCTime *time);

/* Fills the date and time it is handed; ARM, and in another packet's
 * territory. */
extern void sub_0203F49C(struct RTCDate *date, struct RTCTime *time);

struct Sub020089A8Rec {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
};

struct Sub020089A8Obj {
    u32 unk000[384];
    u16 unk600;
    u8  unk602;
    u8  unk603;
    struct Sub020089A8Rec unk604[8];
    union {
        u64 whole;
        struct {
            u32 lo;
            u32 hi;
        } half;
    } unk624;
    u8  unk62C[0xC];
    u16 unk638[16];
};

/* In unit_020089A8.c; attested by the branch from ov111 at 0x021C81E6 as well
 * as by the call below. */
extern void sub_02008A34(struct Sub020089A8Obj *obj, u32 lo, u32 hi);

/* Stamp record `i` with three bytes, mark its parallel entry 0xF0, and record
 * the wall clock as a second count in the object's 64 bit field.  The fifth
 * argument arrives on the stack and is loaded as a whole word, so it is an
 * `int`-width parameter that the `strb` truncates, not a `u8`. */
void sub_02008A7C(struct Sub020089A8Obj *obj, u32 i, u32 a, u32 b, u32 c)
{
    struct RTCDate date;
    struct RTCTime time;
    u64 sec;

    sub_0203F49C(&date, &time);
    sec = RTC_ConvertDateTimeToSecond(&date, &time);

    obj->unk604[i].unk00 = a;
    obj->unk604[i].unk01 = b;
    obj->unk604[i].unk02 = c;
    obj->unk638[i] = 0xF0;

    sub_02008A34(obj, (u32)sec, (u32)(sec >> 32));
}

u16 sub_02008ACC(const struct Sub020089A8Obj *obj, u32 i)
{
    return obj->unk638[i];
}

void sub_02008ADC(struct Sub020089A8Obj *obj, u32 i, u16 value)
{
    obj->unk638[i] = value;
}
