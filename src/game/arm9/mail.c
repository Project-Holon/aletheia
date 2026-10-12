/*
 * file:     mail.c
 * unit:     yes
 * function: sub_020089A8, sub_020089B0, sub_020089C0, sub_020089CC, func_02008A54, func_02008A7C, func_02008ACC, func_02008ADC, sub_02008AEC, func_02008AF0, func_02008B08, func_02008B14, func_02008B20, func_02008B4C, func_02008B78, func_02008B94, func_02008B98, func_02008B9C, func_02008BD0, func_02008BE0, func_02008C00, func_02008C20, func_02008C28, func_02008C58, func_02008C64, func_02008C94, func_02008CB4, func_02008CD4, func_02008CF8, func_02008D1C, func_02008D58, func_02008DAC, func_02008DF0, func_02008DFC, func_02008E30, func_02008E68, func_02008E78, func_02008E88, func_02008EAC, func_02008EF8, func_02008F08, func_02008F3C, func_02008F48, func_02008F80, func_02008F84, func_02008F88, func_02008F9C, func_02008FA0, func_02008FA4, func_02008FA8, func_02008FB0, func_02008FB4, func_02008FB8, func_02008FBC, func_02008FC0, func_02008FC4, func_02008FC8, func_02008FD8, func_02008FEC, func_02008FFC, func_02009004, func_02009020, func_0200902C, func_0200903C, func_02009050, func_02009074, func_020090A0, func_020090B0, func_020090B4, func_020090D8, func_020090E0, func_020090E8, func_020090F0, func_020090F8, func_02009108, func_0200910C, sub_02009110, sub_02009134
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
 *   sub_020071CC  0x020071CC  thumb
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   sub_0203F49C                 0x0203F49C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02008B9C  0x02008B9C  thumb
 *   OS_GetMacAddress      0x02087C6C  arm
 *   OS_GetOwnerInfo       0x02087C88  arm
 *   OS_GetOwnerRtcOffset  0x02087D08  arm
 *   RTC_ConvertDateToDay         0x02088F58  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02008C64  0x02008C64  thumb
 *   sub_0203F2FC  0x0203F2FC  arm
 *   sub_0203F328  0x0203F328  arm
 *   sub_0203F37C  0x0203F37C  arm
 *   g_020A70AC      0x020A70AC  data
 *   g_020A70C4      0x020A70C4  data
 *   g_0209DDB4      0x0209DDB4  data
 *   g_020A716C      0x020A716C  data
 *   g_0209DDA0      0x0209DDA0  data
 *   unk_0209DF0C   0x0209DF0C  data
 *   unk_0209DF08   0x0209DF08  data
 *   func_02045A98  0x02045A98  arm
 *   func_0202428C  0x0202428C  thumb
 *   MIi_CpuClear16 0x02082A48  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   sub_02012EBC  0x02012EBC  thumb
 *   sub_02024570  0x02024570  thumb
 *   func_02009074  0x02009074  thumb
 *   sub_02008F08  0x02008F08  thumb
 */
#include "../../matched/include/Obj02635.h"

#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)
#define ENTRY_COUNT 0x14
struct Sub020071CCCtrl;
/* Fills the date and time it is handed; ARM, and in another packet's
 * territory. */
struct RtcDate;
struct RtcTime;
struct Sub02008AECSession;
struct Sub02008C20Obj;
struct Sub02008EACObj;
struct Sub0200852CObj;
struct Big;
struct Rec8;
struct Sub02008F80Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned long long u64;

struct Su8Rec {
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
    struct Su8Rec unk604[8];
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


struct Sub02008A54Obj {
    u32 unk000[384];
    u32 unk600;
    struct Su8Rec unk604[8];
};

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

/* Declared only so that the size below is a `sizeof` rather than a constant;
 * the full declaration is in src/matched/unit_02008B4C.c. */
struct Sub02008AECObj_020089A8 {
    unsigned char unk00[0x5C];
};

typedef signed   short s16;

typedef signed long long   s64;

struct OSOwnerInfo {
    u8  language;
    u8  favoriteColor;
    u8  birthdayMonth;
    u8  birthdayDay;
    u16 nickname[10];
    s16 nicknameLength;
    u16 comment[26];
    s16 commentLength;
    u8  unk50[4];
};

struct Sub02008AECSession {
    u32 unk00;
    struct RTCDate date;
    struct RTCTime time;
    u32 unk20;
    u64 unk24;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
};

struct Sub02008AECObj_02008AF0 {
    s64 rtcOffset;
    u8  mac[6];
    u8  birthdayMonth;
    u8  birthdayDay;
    struct Sub02008AECSession unk10;
    u8  unk48[0x14];
};

struct Sub02008C20Obj {
    u32 unk000[0x47];
    u16 unk11C[0x60];
    u16 unk1DC;
    u16 unk1DE;
};

struct Entry02008E30 {
    u16 a;
    u16 b;
};

struct Sub0202428CObj {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
};

struct Sub02008EACObj {
    u32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u16 unk08[8];
    u16 unk18[3];
    u16 unk1E;
    struct Sub0202428CObj unk20[3];
};

struct Sub02008EACObjLayout {
    u32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08[0x10];
};

struct Sub02008F80Entry {
    u8 unk00[8];
};

struct Sub02008F80Obj {
    u32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08[0x10];
    u8  unk18[6];
    u16 unk1E;
    struct Sub02008F80Entry unk20[3];
};

struct Sub020090B0Obj {
    u8  unk00[9][4];
    u16 unk24;
    u8  unk26;
    u8  unk27;
    u8  unk28;
    u8  unk29[3];
};

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u64 RTC_ConvertDateTimeToSecond(const struct RTCDate *date,
                                       const struct RTCTime *time);
extern void sub_0203F49C(struct RtcDate *date, struct RtcTime *time);
extern void func_02082AC0(u32 val, void *dst, u32 size);
extern void func_02008B9C(struct Sub02008AECSession *s);
extern void OS_GetMacAddress(u8 *mac);
extern void OS_GetOwnerInfo(struct OSOwnerInfo *info);
extern s64  OS_GetOwnerRtcOffset(void);
extern u32  RTC_ConvertDateToDay(const struct RTCDate *date);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02008C64(struct Sub02008C20Obj *obj, int commit);
/* The checksum pair over a byte range: sub_0203F2FC computes it, sub_0203F328
 * writes it back into the range's own trailer. */
extern u32 sub_0203F2FC(const u8 *p, u32 len);
extern void sub_0203F328(u16 *p, u32 size, u32 seed);
extern void sub_0203F37C(void *p, u32 size, u32 sum);
extern int sub_02008CF8(int idx);
extern u32 func_02008DFC(struct Sub02008C20Obj *obj, int i);
extern u32 func_02008D58(struct Sub02008C20Obj *obj, int i, u32 limit);
extern u32 func_02008D1C(struct Sub02008C20Obj *obj, int i, u32 value);
extern u16  func_02045A98(void);
extern void MIi_CpuClear16(u16 data, void *dest, u32 size);
extern void func_0202428C(void *obj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u8 *func_02012944(void *p);
extern const void *sub_020084F4(const void *p);
extern u32 sub_02008530(const struct Sub0200852CObj *obj);
extern u8  sub_02008550(const struct Sub0200852CObj *obj);
extern void *sub_02012EBC(struct Big *p);
extern void sub_02024570(struct Rec8 *dst, const struct Rec8 *src);
extern void *sub_02008F08(int a0);
extern int func_02009074(struct Sub02008F80Obj *arr, int n);
u32 sub_020089A8(void);
void sub_020089B0(struct Sub020089A8Obj *obj);
struct Sub020089A8Obj *sub_020089C0(void *sys);
void sub_020089CC(void);
int sub_020089D0(const struct Sub020089A8Obj *obj);
u8 sub_020089F4(const struct Sub020089A8Obj *obj);
struct Sub020089A8Obj *sub_02008A00(struct Sub020089A8Obj *obj);
u16 sub_02008A0C(const struct Sub020089A8Obj *obj);
void sub_02008A14(struct Sub020089A8Obj *obj, u16 value);
void sub_02008A1C(struct Sub020089A8Obj *obj, u8 value);
u8 sub_02008A28(const struct Sub020089A8Obj *obj);
void sub_02008A34(struct Sub020089A8Obj *obj, u32 lo, u32 hi);
u64 sub_02008A44(const struct Sub020089A8Obj *obj);
struct Su8Rec sub_02008A54(struct Sub02008A54Obj *obj, int i);
void sub_02008A7C(struct Sub020089A8Obj *obj, u32 i, u32 a, u32 b, u32 c);
u16 sub_02008ACC(const struct Sub020089A8Obj *obj, u32 i);
void sub_02008ADC(struct Sub020089A8Obj *obj, int i, int value);
u32 sub_02008AEC(void);
void func_02008AF0(void *obj);
struct Sub02008AECObj_02008AF0 *sub_02008B08(void *sys);
struct Sub02008AECSession *sub_02008B14(void *sys);
void sub_02008B20(struct Sub02008AECObj_02008AF0 *obj);
int sub_02008B4C(const struct Sub02008AECObj_02008AF0 *obj);
int sub_02008B78(const struct Sub02008AECObj_02008AF0 *obj);
u8 sub_02008B94(const struct Sub02008AECObj_02008AF0 *obj);
u8 sub_02008B98(const struct Sub02008AECObj_02008AF0 *obj);
void sub_02008B9C(struct Sub02008AECSession *s);
int sub_02008BD0(const struct Sub02008AECSession *s);
void sub_02008BE0(struct Sub02008AECSession *s, u32 n);
void sub_02008C00(struct Sub02008AECSession *s);
u32 sub_02008C20(void);
void func_02008C28(void *obj);
struct Sub02008C20Obj *sub_02008C58(void *sys);
void sub_02008C64(struct Sub02008C20Obj *obj, int commit);
void sub_02008C94(struct Sub02008C20Obj *obj, int commit);
u32 sub_02008CB4(const struct Sub02008C20Obj *obj, int i);
u32 sub_02008CD4(struct Sub02008C20Obj *obj, int i, u32 value);
int func_02008CF8(int idx);
u32 sub_02008D1C(struct Sub02008C20Obj *obj, int i, u32 value);
u32 sub_02008D58(struct Sub02008C20Obj *obj, int i, u32 limit);
u32 sub_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
u32 sub_02008DF0(struct Sub02008C20Obj *obj, int i);
u32 sub_02008DFC(struct Sub02008C20Obj *obj, int i);
void func_02008E30(void *a0);
void sub_02008E68(struct Sub02008C20Obj *obj, u32 value);
u8 sub_02008E78(struct Sub02008C20Obj *obj);
void sub_02008E88(struct Sub02008C20Obj *obj, u32 value);
u32 sub_02008EA0(struct Sub02008C20Obj *obj);
void sub_02008EAC(struct Sub02008EACObj *obj);
int sub_02008EF8(const struct Sub02008F80Obj *obj);
void *func_02008F08(int a0);
void sub_02008F3C(const struct Sub02008F80Obj *src, struct Sub02008F80Obj *dest);
void sub_02008F48(struct Sub02008EACObjLayout *obj, u8 kind, u32 unused, void *p);
u32 sub_02008F80(const struct Sub02008F80Obj *obj);
u8 *sub_02008F84(struct Sub02008F80Obj *obj);
void sub_02008F88(struct Sub02008F80Obj *obj, const void *src);
u8 sub_02008F9C(const struct Sub02008F80Obj *obj);
void sub_02008FA0(struct Sub02008F80Obj *obj, u8 value);
u8 sub_02008FA4(const struct Sub02008F80Obj *obj);
void sub_02008FA8(struct Sub02008F80Obj *obj, u32 value);
u8 sub_02008FB0(const struct Sub02008F80Obj *obj);
void sub_02008FB4(struct Sub02008F80Obj *obj, u8 value);
u8 sub_02008FB8(const struct Sub02008F80Obj *obj);
void sub_02008FBC(struct Sub02008F80Obj *obj, u8 value);
u16 sub_02008FC0(const struct Sub02008F80Obj *obj);
void sub_02008FC4(struct Sub02008F80Obj *obj, u16 value);
struct Sub02008F80Entry *sub_02008FC8(struct Sub02008F80Obj *obj, u32 i);
void sub_02008FD8(struct Sub02008F80Obj *obj, void *arg, u32 i);
struct Sub02008F80Obj *sub_02008FEC(void *sys);
u32 sub_02008FFC(void);
void sub_02009004(struct Sub02008F80Obj *arr);
void func_02009020(void *table);
void sub_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
void sub_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
struct Sub02008F80Obj *sub_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
int sub_02009074(struct Sub02008F80Obj *arr, int n);
struct Sub02008F80Obj *sub_020090A0(struct Sub02008F80Obj *arr, u32 unused, int i);
u32 sub_020090B0(void);
int func_020090B4(int a0, int a1, int a2, int a3);
void sub_020090D8(struct Sub020090B0Obj *obj, u8 value);
u8 sub_020090E0(const struct Sub020090B0Obj *obj);
void sub_020090E8(struct Sub020090B0Obj *obj, u8 value);
u8 sub_020090F0(const struct Sub020090B0Obj *obj);
void sub_020090F8(struct Sub020090B0Obj *obj, u8 value);
u8 sub_02009100(const struct Sub020090B0Obj *obj);
void sub_02009108(struct Sub020090B0Obj *obj, u16 value);
u16 sub_0200910C(const struct Sub020090B0Obj *obj);
u32 sub_02009110(const struct Sub020090B0Obj *obj, int row, int col);
int sub_02009134(const struct Sub020090B0Obj *obj, int row, int col);
extern unsigned char g_020A70C4[];
extern int g_0209DDB4[];
extern struct Entry02008E30 g_0209DDA0[5];
extern const u8 unk_0209DF0C;
extern const u8 unk_0209DF08;
extern char g_020A716C[];



#define BLOCK_ID 0x21






/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020089D0, sub_020089F4, sub_02008A00, sub_02008A0C,
 *           sub_02008A14, sub_02008A1C, sub_02008A28, sub_02008A34,
 *           sub_02008A44
 *
 * alias: the save block with id 0x21, 0x658 bytes, and its accessors.  The
 * original file is closed the same way unit_02008828.c is: it opens with the
 * four bytes that return the block size (0x658, which is what sub_020089B0
 * clears) and ends where the next such function returns 0x5C, at 0x02008AEC.
 * This file stops short of that, at 0x02008A54, because of the near miss
 * described below; the rest of the file is src/matched/unit_02008A7C.c and
 * the two should be merged the day 0x02008A54 closes.
 *
 * NEAR MISS, 0x02008A54, 40 bytes, 17 concrete bytes wrong, skipped.  It
 * assembles a little endian word out of the four bytes of record `i`.  The
 * shape is settled: the size is right, the four loads come out in the
 * original's order (unk01, unk00, unk02, unk03), the pool constant is the
 * original's 0x605, and the seventeen instructions are the same seventeen.
 * What differs is register allocation.  The original computes the record
 * pointer into `r3` and accumulates the result in `r0` from the first load
 * onwards; every source shape tried computes the pointer into `r0`,
 * accumulates in `r3`, and hoists the last `ldrb` two slots earlier so that
 * `r0` is free for the result at the end.  A generated sweep of 84 source
 * shapes (all 24 term permutations crossed with three statement groupings,
 * plus accumulator type, index type and constness) is flat at 17 wrong bytes
 * and never at 18 or below except for shapes that also lose the load order.
 * Nothing in the source appears to reach the allocator here.
 *
 * Layout, read off the accessors:
 *
 *   +0x000  u32[384]  a word array summed whole by sub_020089D0
 *   +0x600  u16       get/set by sub_02008A0C and sub_02008A14
 *   +0x602  u8        get by sub_020089F4, only ever set to 1
 *   +0x603  u8        get/set by sub_02008A28 and sub_02008A1C
 *   +0x604  8 x 4     a table of four-byte records, three bytes of which
 *                     sub_02008A7C writes and sub_02008A54 reads back as one
 *                     little endian word
 *   +0x624  u32       the low half of an RTC second count
 *   +0x628  u32       ... and its high half
 *   +0x638  u16[]     a parallel table sub_02008A7C stamps with 0xF0
 *
 * Three things in here are worth naming:
 *
 *  - sub_02008A44 returns the pair at +0x624 and +0x628 as one `u64`.  The
 *    field pair is not a `u64` in the object, because 0x624 is not eight
 *    aligned, but the return value is: the compiler loads the low half into a
 *    scratch register because `r0` is still the object pointer it needs for
 *    the second load, and only then moves it into place.  That `adds r0, r2,
 *    #0` at the end is what a 64 bit return of two separately declared words
 *    looks like.
 *  - sub_02008A54 assembles a word out of four bytes and the pool constant it
 *    picks is 0x605, not 0x604: the second byte is the one it loads first, and
 *    the other three offsets are derived from it with subs/adds.  Reading the
 *    pool word as the base of the array gets the record boundary wrong by one.
 *  - sub_020089D0 compares its counter with `blt`, so the loop variable is a
 *    signed `int` even though what it walks is an array of `u32`.  The bound
 *    384 is materialised as `movs r1, #6` / `lsls r1, r1, #6` rather than
 *    loaded from a pool.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020089A8.c \
 *       --addr 0x020089A8 --thumb
 */
u32 sub_020089A8(void)
{
    return sizeof(struct Sub020089A8Obj);
}






void sub_020089B0(struct Sub020089A8Obj *obj)
{
    MI_CpuFill8(obj, 0, sizeof(struct Sub020089A8Obj));
}





struct Sub020089A8Obj *sub_020089C0(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}






void sub_020089CC(void)
{
}






/* Is any word of the 0x600-byte array non zero. */
int sub_020089D0(const struct Sub020089A8Obj *obj)
{
    u32 sum;
    int i;

    sum = 0;
    for (i = 0; i < 384; i++) {
        sum += obj->unk000[i];
    }
    if (sum == 0) {
        return 0;
    }
    return 1;
}





u8 sub_020089F4(const struct Sub020089A8Obj *obj)
{
    return obj->unk602;
}





struct Sub020089A8Obj *sub_02008A00(struct Sub020089A8Obj *obj)
{
    obj->unk602 = 1;
    return obj;
}





u16 sub_02008A0C(const struct Sub020089A8Obj *obj)
{
    return obj->unk600;
}





void sub_02008A14(struct Sub020089A8Obj *obj, u16 value)
{
    obj->unk600 = value;
}





void sub_02008A1C(struct Sub020089A8Obj *obj, u8 value)
{
    obj->unk603 = value;
}





u8 sub_02008A28(const struct Sub020089A8Obj *obj)
{
    return obj->unk603;
}





void sub_02008A34(struct Sub020089A8Obj *obj, u32 lo, u32 hi)
{
    obj->unk624.half.lo = lo;
    obj->unk624.half.hi = hi;
}





u64 sub_02008A44(const struct Sub020089A8Obj *obj)
{
    return obj->unk624.whole;
}







/*
 * alias: record i of the id 0x21 save block's four-byte table at +0x604,
 * returned by value (see src/matched/unit_020089A8.c for the object layout).
 * The ov111 caller 0x021C7B20 receives it as a struct.  The byte-by-byte
 * assembly into r0, the 1, 0, 2, 3 load order and the 0x605 pool constant
 * are what the compiler emits for returning a byte-aligned 4-byte struct;
 * no hand-written shift/or expression reproduces its register allocation.
 * This sits between unit_020089A8.c and unit_02008A7C.c in one original
 * file; the three can be merged into one unit.
 */
struct Su8Rec sub_02008A54(struct Sub02008A54Obj *obj, int i)
{
    return obj->unk604[i];
}






/* Stamp record `i` with three bytes, mark its parallel entry 0xF0, and record
 * the wall clock as a second count in the object's 64 bit field.  The fifth
 * argument arrives on the stack and is loaded as a whole word, so it is an
 * `int`-width parameter that the `strb` truncates, not a `u8`. */
/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
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
void sub_02008A7C(struct Sub020089A8Obj *obj, u32 i, u32 a, u32 b, u32 c)
{
    struct RTCDate date;
    struct RTCTime time;
    u64 sec;

    sub_0203F49C((struct RtcDate *)(&date), (struct RtcTime *)(&time));
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





void sub_02008ADC(struct Sub020089A8Obj *obj, int i, int value)
{
    obj->unk638[i] = value;
}





/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * Original (4 bytes, leaf, no relocations):
 *   movs r0, #0x5c
 *   bx   lr
 *
 * The first function of the save block with id 0x25: it returns the block's
 * own size, which is what the constructor at 0x02008AF0 clears.  The rest of
 * the file is src/matched/unit_02008B08.c and
 * src/matched/unit_02008B4C.c; see the header of the latter for why the file
 * is committed in three pieces and what the block holds.
 */
u32 sub_02008AEC(void)
{
    return sizeof(struct Sub02008AECObj_020089A8);
}





void func_02008AF0(void *obj)
{
    func_02082AC0(0, obj, 0x5C);
    func_02008B9C((struct Sub02008AECSession *)((u8 *)obj + 0x10));
}



#undef BLOCK_ID


#undef BLOCK_ID

#undef BLOCK_ID


#define BLOCK_ID 0x25





/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * The two lookups of the id 0x25 save block and the function that stamps it
 * with the console's identity.  For the block layout and for why the original
 * file is committed in three pieces, see src/matched/unit_02008B4C.c.
 *
 * The `OSOwnerInfo` local is 0x54 bytes, which is what the frame says: 0x54 of
 * stack plus the `push {r3, ...}` this front end adds to keep `sp` eight
 * aligned behind an odd-sized frame.  Only that size and the two byte fields
 * at +2 and +3 that this function reads are attested by the image, so the tail
 * of the declaration below is padding rather than knowledge.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008B08.c \
 *       --addr 0x02008B08 --thumb
 */
struct Sub02008AECObj_02008AF0 *sub_02008B08(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}





struct Sub02008AECSession *sub_02008B14(void *sys)
{
    struct Sub02008AECObj_02008AF0 *obj = sub_020071CC(sys, BLOCK_ID);

    return &obj->unk10;
}





/* Stamp the block with this console's identity. */
void sub_02008B20(struct Sub02008AECObj_02008AF0 *obj)
{
    struct OSOwnerInfo info;

    obj->rtcOffset = OS_GetOwnerRtcOffset();
    OS_GetMacAddress(obj->mac);
    OS_GetOwnerInfo(&info);
    obj->birthdayMonth = info.birthdayMonth;
    obj->birthdayDay = info.birthdayDay;
}





/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02008B9C, sub_02008BD0, sub_02008BE0, sub_02008C00
 *
 * alias: the save block with id 0x25, 0x5C bytes.  The original file runs
 * 0x02008AEC..0x02008C20 in one piece, closed on both sides by the four-byte
 * functions that return a block size: 0x5C here, 0x1E0 at 0x02008C20, which is
 * the next file.  It is committed as three pieces, and the split is forced by
 * the attestation rule rather than by anything in the code:
 *
 *   0x02008AF0                       the constructor, a near miss, see below
 *   src/matched/unit_02008B08.c      0x02008B08..0x02008B4C
 *   this file                        0x02008B4C..0x02008C20
 *
 * sub_02008B20 and sub_02008B78 are the only two callers of
 * OS_GetOwnerRtcOffset anywhere in the ROM, in `arm9_main` and in all 237
 * overlays alike.  Matched as one range they attest each other's call site out
 * of existence: both witnesses are inside the bytes under test, the `label`
 * class discards them, and the whole 306-byte file caps at MATCH with every
 * concrete byte right.  Split so that the two sit in different ranges, each is
 * the other's outside witness and both come out EXACT.  This is the same shape
 * as the pair at 0x0200892C described in docs/MATCHING.md, with the difference
 * that the witness that closes it is the sibling function rather than an
 * overlay.
 *
 * NEAR MISS, 0x02008AF0, 24 bytes, every concrete byte right, skipped.  The
 * constructor calls sub_02008B9C at 0x02008B02, and that `bl` is the only
 * reference to 0x02008B9C in the whole image.  Inside a range that also
 * defines sub_02008B9C the call is `local` and needs no evidence, but such a
 * range necessarily spans 0x02008B20 and 0x02008B78 and so gives the
 * OS_GetOwnerRtcOffset problem above back.  The two constraints cannot both be
 * satisfied by any split, so the constructor is the one function of the file
 * left out.  It closes the day anything else in the image branches to
 * 0x02008B9C, or the day 0x02087D08 acquires a third caller.
 *
 * The block holds the console's identity plus a session clock:
 *
 *   +0x00  s64    the owner's RTC offset, as OS_GetOwnerRtcOffset returns it
 *   +0x08  u8[6]  the MAC address
 *   +0x0E  u8     the owner's birthday month
 *   +0x0F  u8     ... and day
 *   +0x10  0x38   the session record below
 *   +0x48  0x14   untouched here
 *
 *   session +0x00  u32  a flag, set to 1 by sub_02008B9C
 *           +0x04  RTCDate  when the session started
 *           +0x14  RTCTime
 *           +0x20  u32  that date as a day count
 *           +0x24  u64  that date and time as a second count
 *           +0x2C  u32
 *           +0x30  u32
 *           +0x34  u32  a countdown, clamped to 0x5A0 (1440, a day of minutes)
 *
 * Two details pinned this range:
 *
 *  - the `u64` at +0x24 of the session record is four-aligned, not eight.
 *    This front end aligns `long long` to four inside a struct, so the field is
 *    simply declared `u64` and the pair of `str`s falls out of one assignment
 *    from RTC_ConvertDateTimeToSecond.  `sizeof(struct { u32 a; u64 b; })` is
 *    twelve here, not sixteen.
 *  - sub_02008BE0 tests `<` and assigns zero in the taken branch.  Written the
 *    other way round, `if (x >= n) x -= n; else x = 0;`, the compiler keeps the
 *    same instructions but inverts the condition and swaps the two arms, which
 *    is four bytes wrong in the middle of an otherwise clean function.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008B4C.c \
 *       --addr 0x02008B4C --thumb
 */
int sub_02008B4C(const struct Sub02008AECObj_02008AF0 *obj)
{
    u8 mac[6];
    int i;

    OS_GetMacAddress(mac);
    for (i = 0; i < 6; i++) {
        if (mac[i] != obj->mac[i]) {
            return 0;
        }
    }
    return 1;
}




int sub_02008B78(const struct Sub02008AECObj_02008AF0 *obj)
{
    if (OS_GetOwnerRtcOffset() != obj->rtcOffset) {
        return 0;
    }
    return 1;
}




u8 sub_02008B94(const struct Sub02008AECObj_02008AF0 *obj)
{
    return obj->birthdayMonth;
}




u8 sub_02008B98(const struct Sub02008AECObj_02008AF0 *obj)
{
    return obj->birthdayDay;
}




void sub_02008B9C(struct Sub02008AECSession *s)
{
    s->unk00 = 1;
    sub_0203F49C((struct RtcDate *)(&s->date), (struct RtcTime *)(&s->time));
    s->unk20 = RTC_ConvertDateToDay(&s->date);
    s->unk24 = RTC_ConvertDateTimeToSecond(&s->date, &s->time);
    s->unk2C = 0;
    s->unk30 = 0;
    s->unk34 = 0;
}




int sub_02008BD0(const struct Sub02008AECSession *s)
{
    if (s->unk34 == 0) {
        return 0;
    }
    return 1;
}




void sub_02008BE0(struct Sub02008AECSession *s, u32 n)
{
    if (s->unk34 > 0x5A0) {
        s->unk34 = 0x5A0;
    }
    if (s->unk34 < n) {
        s->unk34 = 0;
    } else {
        s->unk34 = s->unk34 - n;
    }
}




void sub_02008C00(struct Sub02008AECSession *s)
{
    s->unk34 = 0x5A0;
    sub_0203F49C((struct RtcDate *)(&s->date), (struct RtcTime *)(&s->time));
    s->unk20 = RTC_ConvertDateToDay(&s->date);
}





/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * Original (6 bytes, leaf, no relocations):
 *   movs r0, #0x1e
 *   lsls r0, r0, #4
 *   bx   lr
 *
 * The first function of the save block with id 0x26: it returns the block's
 * own size, 0x1E0, which is what the constructor at 0x02008C28 clears.  0x1E0
 * has no Thumb immediate encoding, so it arrives as a `movs` of 0x1E and a
 * shift rather than out of a literal pool; a pool would have cost four bytes
 * more and this compiler prefers the shift for any constant it can build in
 * two instructions.
 *
 * The rest of the file is src/matched/unit_02008C58.c; see its header for the
 * block layout and for the near miss that separates the two.
 */
u32 sub_02008C20(void)
{
    return sizeof(struct Sub02008C20Obj);
}





/*
 * The block constructor: MIi_CpuClear32 wipes 0x1E0 bytes, then the checksum
 * high half (+0x1DE) is seeded from the word at 0x02FFFC3C in the shared
 * region, then sub_02008C64 commits.  This is the block whose layout
 * src/matched/unit_02008C58.c describes; that file called it a "NEAR MISS, 48
 * bytes, 3 concrete bytes wrong" and blamed the register numbering of the three
 * loads.  The three bytes are in fact the operand order of the combine, and the
 * spelling that reproduces them is two named u32 locals assigned in order (a
 * first, then b) and combined as `a << 8 | b`, which puts the pool address in r1
 * and the first value in r0 as the original does.  The two reads must not be
 * commoned up, so the 0x02FFFC3C cast constant is `volatile`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02008C28.c \
 *       --func func_02008C28 --addr 0x02008C28 --cc 1.1p1 --thumb
 */
void func_02008C28(void *obj)
{
    u32 a;
    u32 b;

    func_02082A7C(0, obj, 0x1e0);
    a = unk_02FFFC3C;
    b = unk_02FFFC3C;
    ((struct Obj02635 *)obj)->f1DE = a << 8 | b;
    func_02008C64(obj, 1);
}


#undef BLOCK_ID

#undef BLOCK_ID



#define BLOCK_ID 0x26





/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02008CD4
 *
 * alias: the head of the save block with id 0x26, 0x1E0 bytes.  The original
 * file opens at 0x02008C20 with the four bytes that return that size
 * (src/matched/sub_02008C20.c) and this range follows the constructor; the
 * file runs on past 0x02008CF8, where it starts reaching into the static
 * tables at 0x0209DDB4 and 0x020A70C4, which is where this range stops.
 *
 * What the attestation rules say about the run after it, checked with the
 * indexes behind `python tools/match.py tu --suggest-split`:
 *
 *  - sub_02008CF8 itself stays blocked, and not for want of a cut.  It loads
 *    0x020A70C4 and 0x0209DDB4, and each of those two addresses is named by
 *    exactly one pool word in the whole image, its own, at 0x02008D14 and
 *    0x02008D18.  The `literal` class has nothing outside the range, and the
 *    `string` class cannot reach either: 0x020A70C4 is the data table
 *    immediately after "playtime.c", not a string.  It closes the day
 *    anything else in the image loads one of them.
 *  - the four functions after it, 0x02008D1C..0x02008E30, are no longer
 *    blocked by attestation at all, only by not having been written.  Each of
 *    them calls sub_02008C64, sub_02008C94, sub_02008CB4, sub_02008CD4 and
 *    sub_02008CF8, and the callers of each of those five are spread across
 *    several of the four, so any range holding at most two of the four leaves
 *    every one of the five a witness outside it.  0x02008D1C..0x02008DAC and
 *    0x02008DAC..0x02008E30 is such a pair, and the twelve byte thunk at
 *    0x02008DF0 is `local` to the second of them.
 *
 * The block is a flat table with two element widths and its own checksum:
 *
 *   +0x000  u32[0x47]   indices 0x00..0x46
 *   +0x11C  u16[0x60]   indices 0x47..0xA6
 *   +0x1DC  u16         the low half of a checksum over +4..+0x1DC
 *   +0x1DE  u16         ... and its high half
 *
 * sub_02008CB4 and sub_02008CD4 are the getter and setter over that split
 * index space, and both answer 0 for an index at or past 0xA7.  The setter
 * returns what the getter would return, by calling it: the `bl` at the point
 * where both arms have joined is a tail call the compiler could not turn into
 * a `b` because it still has `r4` to pop.
 *
 * The checksum covers 0x1D8 bytes starting at +4, not the whole block, and the
 * pair at +0x1DC and +0x1DE is one 32 bit value split across two `u16` fields:
 * sub_02008C64 reassembles it with an `adds`, not an `orrs`, so the source
 * adds rather than ors.
 *
 * NEAR MISS, 0x02008C28, 48 bytes, 3 concrete bytes wrong, skipped.  The
 * constructor clears the block and then seeds +0x1DE from the word at
 * 0x02FFFC3C in the region the two processors share.  That word is read twice
 * in a row and the two loads are not commoned up, which is a `volatile` read
 * and nothing else: written as a plain `extern u32` the function is two
 * instructions short.  With the `volatile` the size, the schedule and every
 * instruction are the original's, and the three wrong bytes are the register
 * numbering of the three loads alone: the original puts the pool address in
 * `r1` and the first value in `r0`, the compiler does the reverse.  Eleven
 * source shapes were tried (both operand orders, a temporary for either side,
 * a cast on either side, an array-typed declaration, a `const volatile`
 * declaration, and the multiply that folds the two terms into one) and none of
 * them moves it off three.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008C58.c  *       --addr 0x02008C58 --thumb
 */
struct Sub02008C20Obj *sub_02008C58(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}





void sub_02008C64(struct Sub02008C20Obj *obj, int commit)
{
    if (commit) {
        obj->unk1DC = sub_0203F2FC((const u8 *)(&obj->unk000[1]), 0x1D8);
        sub_0203F328((u16 *)(&obj->unk000[1]), 0x1D8,
                     obj->unk1DC + (obj->unk1DE << 16));
    }
}



void sub_02008C94(struct Sub02008C20Obj *obj, int commit)
{
    if (commit) {
        sub_0203F37C(&obj->unk000[1], 0x1D8,
                     obj->unk1DC + (obj->unk1DE << 16));
    }
}



u32 sub_02008CB4(const struct Sub02008C20Obj *obj, int i)
{
    if (i < 0x47) {
        return obj->unk000[i];
    }
    if (i < 0xA7) {
        return obj->unk11C[i - 0x47];
    }
    return 0;
}



u32 sub_02008CD4(struct Sub02008C20Obj *obj, int i, u32 value)
{
    if (i < 0x47) {
        obj->unk000[i] = value;
    } else if (i < 0xA7) {
        obj->unk11C[i - 0x47] = value;
    }
    return sub_02008CB4(obj, i);
}



int func_02008CF8(int idx)
{
    int v = g_020A70C4[idx];
    if (v >= 0xa7) return 0;
    if (v >= 6) return 0;
    return g_0209DDB4[v];
}




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the first half of the clamped read-modify-write layer over the save
 * block with id 0x26 (src/matched/unit_02008C58.c).  Each of these takes the
 * block and a counter index, looks the counter's ceiling up with
 * sub_02008CF8, unlocks the block with sub_02008C94, writes through
 * sub_02008CD4 and re-checksums with sub_02008C64.
 *
 * The cut at 0x02008DAC is the one the header of unit_02008C58.c recorded as
 * viable: sub_02008CF8, sub_02008C64, sub_02008C94, sub_02008CB4 and
 * sub_02008CD4 are each called from both halves, so each half is the other's
 * outside witness and no site is left without one.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008D1C.c \
 *       --addr 0x02008D1C --thumb
 */
u32 sub_02008D1C(struct Sub02008C20Obj *obj, int i, u32 value)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    sub_02008C94(obj, i);
    if (value < max) {
        result = sub_02008CD4(obj, i, value);
    } else {
        result = sub_02008CD4(obj, i, max);
    }
    sub_02008C64(obj, i);
    return result;
}



u32 sub_02008D58(struct Sub02008C20Obj *obj, int i, u32 limit)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    sub_02008C94(obj, i);
    result = sub_02008CB4(obj, i);
    if (limit > max) {
        limit = max;
    }
    if (result < limit) {
        result = sub_02008CD4(obj, i, limit);
    } else if (result > max) {
        result = sub_02008CD4(obj, i, max);
    }
    sub_02008C64(obj, i);
    return result;
}




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the second half of the clamped read-modify-write layer over the save
 * block with id 0x26; see src/matched/unit_02008D1C.c for the cut.
 *
 * sub_02008DF0 is twelve bytes with no prologue and carries no label in the
 * listing: `ldr r3, [pc, #4]; movs r2, #1; bx r3` plus the pool word
 * 0x02008DAD.  That is `return sub_02008DAC(obj, i, 1);`, the increment-by-one
 * spelling of the function above it, and it is `local` to this range because
 * sub_02008DAC is in it.
 *
 * The one byte that had to be found: `adds r2, r0, r7` in sub_02008DAC is the
 * counter plus the delta with the *call result* in the left slot, and that
 * only happens when a named local holds it.  Written inline in either operand
 * order, `sub_02008CB4(obj, i) + delta` and `delta + sub_02008CB4(obj, i)`
 * both give `adds r2, r7, r0`.  See
 * docs/idioms/commutative-operand-order-names-the-temporary.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008DAC.c \
 *       --addr 0x02008DAC --thumb
 */
u32 sub_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta)
{
    u32 max = sub_02008CF8(i);
    u32 result;
    u32 cur;

    sub_02008C94(obj, i);
    cur = sub_02008CB4(obj, i);
    result = cur + delta;
    if (result < max) {
        result = sub_02008CD4(obj, i, result);
    } else {
        result = sub_02008CD4(obj, i, max);
    }
    sub_02008C64(obj, i);
    return result;
}



u32 sub_02008DF0(struct Sub02008C20Obj *obj, int i)
{
    return sub_02008DAC(obj, i, 1);
}



u32 sub_02008DFC(struct Sub02008C20Obj *obj, int i)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    sub_02008C94(obj, i);
    result = sub_02008CB4(obj, i);
    sub_02008C64(obj, i);
    if (result <= max) {
        max = result;
    }
    return max;
}




/*
 *           this function's own.  The `literal` class discards that witness
 *           under the honesty rule and no cut helps (the pool word is inside
 *           the section whatever the range).  Every concrete byte is right:
 *           56 bytes, 3 calls resolved, 1 ABS32 wildcarded.
 */
void func_02008E30(void *a0)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        u16 b = g_0209DDA0[i].b;

        func_02008D58(a0, g_0209DDA0[i].a, func_02008DFC(a0, b));
        func_02008D1C(a0, b, 0);
    }
}





/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the named entry points on top of the clamped counter layer of
 * src/matched/unit_02008D1C.c and src/matched/unit_02008DAC.c.  Counter 0x7B
 * has a ceiling of 6 and counter 0x7C a ceiling of 9999, and each writer range
 * checks its argument against that ceiling before writing.
 *
 * The ceiling table sub_02008CF8 indexes is at 0x0209DDB4 and is six words:
 * 999999999, 999999, 65535, 9999, 999, 6.  That is what makes the bare 9999
 * here and the 7 in sub_02008E68 readable.
 *
 * sub_02008EA0 is twelve bytes with no prologue and no label:
 * `ldr r3, [pc, #4]; movs r1, #0x7c; bx r3` over the pool word 0x02008DFD,
 * that is `return sub_02008DFC(obj, 0x7C);`.
 *
 * NEAR MISS, 0x02008E30, 56 bytes, MATCH with every concrete byte right,
 * skipped.  It walks a five entry table of counter index pairs at 0x0209DDA0,
 *
 *   1A 1B  51 52  53 54  55 56  57 58
 *
 * copying the value of each pair's second counter into its first through
 * sub_02008D58 and then zeroing the second with sub_02008D1C.  Written as
 *
 *   for (i = 0; i < 5; i++) {
 *       int src = tbl[i].unk02;
 *       sub_02008D58(obj, tbl[i].unk00, sub_02008DFC(obj, src));
 *       sub_02008D1C(obj, src, 0);
 *   }
 *
 * over `struct { u16 unk00; u16 unk02; }` it reproduces all 56 bytes, both
 * loads of the one pool word included, and caps at MATCH on the pool word
 * itself: 0x0209DDA0 is named by exactly one word in the 3.9 MB image, its own
 * at 0x02008E64, so the `literal` class discards its only witness and no cut
 * helps.  `--suggest-split` reports the same and leaves this one function out.
 * It is a table of halfwords, not a string, so the `string` class cannot reach
 * it either.  It closes the day anything else in the image loads 0x0209DDA0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008E68.c \
 *       --addr 0x02008E68 --thumb
 */
void sub_02008E68(struct Sub02008C20Obj *obj, u32 value)
{
    if (value < 7) {
        sub_02008D58(obj, 0x7B, value);
    }
}



u8 sub_02008E78(struct Sub02008C20Obj *obj)
{
    return sub_02008DFC(obj, 0x7B);
}



void sub_02008E88(struct Sub02008C20Obj *obj, u32 value)
{
    if (value < 9999) {
        sub_02008D58(obj, 0x7C, value);
    }
}



u32 sub_02008EA0(struct Sub02008C20Obj *obj)
{
    return sub_02008DFC(obj, 0x7C);
}




static inline void MI_CpuFill16(void *dest, u16 data, u32 size)
{
    MIi_CpuClear16(data, dest, size);
}





/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the constructor of a 0x38-byte record.  It is the last function of
 * the file that begins at 0x02008C20 with the 0x26 save block, or the first of
 * the next one; nothing in the bytes separates them, so it is kept as its own
 * range.
 *
 * The two byte globals it seeds the record from are 0x0209DF0C and 0x0209DF08,
 * and each is also loaded from a pool word in 005_02013528.s, at 0x020178C8
 * and 0x020178D4, which is what attests them.
 *
 * `MI_CpuFill16` is the SDK header's inline wrapper: it compiles to a direct
 * `blx MIi_CpuClear16` with the data and destination swapped, which is exactly
 * what the original does.  Calling MIi_CpuClear16 by hand would produce the
 * same bytes, but the wrapper is what the source said.
 *
 * The 0xFFFF at +0x1E is a pool word rather than a `movs`, because the Thumb
 * immediate stops at 255; the 0xFF at +7 is a `movs`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008EAC.c \
 *       --addr 0x02008EAC --thumb
 */
void sub_02008EAC(struct Sub02008EACObj *obj)
{
    int i;

    obj->unk00 = 0;
    obj->unk04 = 0;
    obj->unk05 = unk_0209DF0C;
    obj->unk06 = unk_0209DF08;
    obj->unk07 = 0xFF;
    MI_CpuFill16(obj->unk08, func_02045A98(), sizeof(obj->unk08));
    obj->unk1E = 0xFFFF;
    for (i = 0; i < 3; i++) {
        func_0202428C(&obj->unk20[i]);
    }
}




/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * Original (14 bytes, leaf, no relocations):
 *   ldrb r0, [r0, #7]
 *   cmp  r0, #0xb
 *   bhi  0x2008f02
 *   movs r0, #1
 *   bx   lr
 *   movs r0, #0
 *   bx   lr
 *
 * The range predicate on the byte at +7 of the 0x38-byte object described in
 * src/matched/unit_02008F80.c: the setter there refuses anything at or past
 * 0xC, and this answers whether the field is inside that range.  `bhi` rather
 * than `bgt` is the only evidence that the comparison is unsigned; the field is
 * loaded with `ldrb` either way.
 *
 * The taken arm is the zero, so the source tests the in-range case and returns
 * 1 by falling through.
 *
 * Recorded as a one-function byte range rather than as a function entry
 * because the function ends at 0x02008F06 and the next label is at 0x02008F08:
 * two bytes of inter-section fill sit between them, so the extent disasm.py
 * infers runs two bytes long and a function entry would read EXACT*.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008EF8.c  *       --addr 0x02008EF8 --thumb
 */
int sub_02008EF8(const struct Sub02008F80Obj *obj)
{
    if (obj->unk07 <= 0xB) {
        return 1;
    }
    return 0;
}



void *func_02008F08(int a0)
{
    void *p = func_02030734((unsigned short)((a0 & 0x7fff) | 0x8000), 0x38, 0, g_020A716C, 0x87);
    func_02008EAC(p);
    return p;
}




/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * Original (6 bytes plus a literal pool, leaf):
 *   ldr  r3, [pc, #4]
 *   movs r2, #0x38
 *   bx   r3
 *
 * A whole-object copy of the 0x38-byte object described in
 * src/matched/unit_02008F80.c.  Both pointer arguments are already in the
 * registers MI_CpuCopy8 wants, so the only work is the size and the tail call;
 * the `bx r3` rather than a `blx` is what a tail call to an ARM function
 * through a pool word looks like, and the pool word carries the Thumb bit
 * clear because the callee is ARM.
 */
void sub_02008F3C(const struct Sub02008F80Obj *src, struct Sub02008F80Obj *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Sub02008F80Obj));
}




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: mail.c.  The record this fills in is the 0x38-byte object
 * src/matched/unit_02008EAC.c constructs and src/matched/unit_02008F80.c
 * accesses, and the file name is in the image: the allocator at 0x02008F08
 * passes 0x020A716C to the debug allocator and those bytes spell "mail.c".
 *
 * sub_020084F4 is four bytes, `bx lr`, and src/matched/unit_020084BC.c records
 * it as `void sub_020084F4(void)`.  This call site says what it is: its result
 * feeds MI_CpuCopy8's source operand with no move in between, so it is an
 * identity accessor on its argument, declared here with the type that call
 * needs.  The declaration is a claim about the source, not about the bytes,
 * which are `bx lr` either way.
 *
 * The third parameter is dead: nothing in the function reads r2.
 *
 * NEAR MISS, 0x02008F08, 52 bytes, MATCH with every concrete byte right,
 * skipped.  It is mail.c's allocator,
 *
 *   struct Mail *sub_02008F08(u32 heap)
 *   {
 *       struct Mail *p = sub_02030734((u16)((heap & 0x7FFF) | 0x8000), 0x38,
 *                                     0, sub_02008F08_File, 135);
 *       sub_02008EAC(p);
 *       return p;
 *   }
 *
 * which reproduces all 52 bytes, the single 0x7FFF pool word the compiler
 * turns into 0x8000 with `adds r0, r1, #1` included, and caps at MATCH on the
 * __FILE__ pool word.  0x020A716C is named by exactly one word in the image,
 * its own at 0x02008F38, so `literal` has no witness and no cut helps.  The
 * `string` class cannot reach it either, and the reason is worth recording:
 * the run before "mail.c" is not a string.  Its single NUL terminator at
 * 0x020A716B is preceded by 0x2B bytes of 0x02 and 0x03, a static table, so
 * condition 5 of the rule ("the bytes before those NULs are themselves at
 * least four printable ASCII characters") refuses it.  A string at the head of
 * a string section, or one whose neighbour is data, has no outside witness at
 * all.  See docs/idioms/a-string-after-a-data-table-has-no-witness.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008F48.c \
 *       --addr 0x02008F48 --thumb
 */
void sub_02008F48(struct Sub02008EACObjLayout *obj, u8 kind, u32 unused,
                  void *p)
{
    struct Sub0200852CObj *src;

    sub_02008EAC((struct Sub02008EACObj *)obj);
    obj->unk07 = kind;
    src = (struct Sub0200852CObj *)func_02012944(p);
    MI_CpuCopy8(sub_020084F4(src), obj->unk08, sizeof(obj->unk08));
    obj->unk04 = sub_02008550(src);
    obj->unk00 = sub_02008530(src);
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02008FA0, sub_02008FA4, sub_02008FA8, sub_02008FB0,
 *           sub_02008FB4, sub_02008FB8, sub_02008FBC, sub_02008FC0,
 *           sub_02008FC4, sub_02008FC8, sub_02008FD8, sub_02008FEC
 *
 * The accessor tail of the 0x38-byte object the allocator at 0x02008F08 hands
 * out, plus the two functions after it.  The range is closed on the right by
 * 0x02008FFC, which is a four-byte function returning 0x460: the size-returning
 * opener of the next file, the same seam that separates the three save block
 * files before this one.  On the left it is closed by the end of sub_02008F48
 * at 0x02008F7E.
 *
 * Fourteen of the sixteen carry no label in the generated listing, because
 * disasm.py's prologue sweep only fires on a function that saves `lr` and a
 * two-instruction accessor saves nothing; the listing emits them as data words
 * and they were read out of the bytes.
 *
 * Object layout, from the accessors:
 *
 *   +0x00  u32   get by sub_02008F80, written by sub_02008F48
 *   +0x04  u8    get/set
 *   +0x05  u8    get/set
 *   +0x06  u8    get/set
 *   +0x07  u8    get by sub_02008F9C's neighbour; the setter refuses >= 0xC
 *   +0x08  0x10  a block copied in whole by sub_02008F88, address handed out
 *                by sub_02008F84
 *   +0x1E  u16   get/set
 *   +0x20  3 x 8 a small table, indexed with a range check that folds out of
 *                range to entry 0 rather than failing
 *
 * Two things worth naming:
 *
 *  - sub_02008F88 copies *into* the object, not out of it.  The argument
 *    shuffle says so: `adds r2, r0, #0` / `adds r2, #8` builds the field
 *    address in `r2`, then `adds r0, r1, #0` puts the caller's pointer in the
 *    source register and `adds r1, r2, #0` the field in the destination
 *    register.  Reading the `#8` as the first argument inverts the function.
 *  - sub_02008FC8 falls through to the in-range arm and puts the out of range
 *    arm at the end, so the source tests `i < 3` first and returns entry 0
 *    after it.  Written the other way round the compiler emits the same six
 *    instructions with the branch inverted and the two arms swapped, which is
 *    ten wrong bytes in a sixteen-byte function.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008F80.c \
 *       --addr 0x02008F80 --thumb
 */
u32 sub_02008F80(const struct Sub02008F80Obj *obj)
{
    return obj->unk00;
}



u8 *sub_02008F84(struct Sub02008F80Obj *obj)
{
    return obj->unk08;
}



void sub_02008F88(struct Sub02008F80Obj *obj, const void *src)
{
    MI_CpuCopy8(src, obj->unk08, sizeof(obj->unk08));
}



u8 sub_02008F9C(const struct Sub02008F80Obj *obj)
{
    return obj->unk04;
}



void sub_02008FA0(struct Sub02008F80Obj *obj, u8 value)
{
    obj->unk04 = value;
}



u8 sub_02008FA4(const struct Sub02008F80Obj *obj)
{
    return obj->unk07;
}



void sub_02008FA8(struct Sub02008F80Obj *obj, u32 value)
{
    if (value < 0xC) {
        obj->unk07 = value;
    }
}



u8 sub_02008FB0(const struct Sub02008F80Obj *obj)
{
    return obj->unk05;
}



void sub_02008FB4(struct Sub02008F80Obj *obj, u8 value)
{
    obj->unk05 = value;
}



u8 sub_02008FB8(const struct Sub02008F80Obj *obj)
{
    return obj->unk06;
}



void sub_02008FBC(struct Sub02008F80Obj *obj, u8 value)
{
    obj->unk06 = value;
}



u16 sub_02008FC0(const struct Sub02008F80Obj *obj)
{
    return obj->unk1E;
}



void sub_02008FC4(struct Sub02008F80Obj *obj, u16 value)
{
    obj->unk1E = value;
}



struct Sub02008F80Entry *sub_02008FC8(struct Sub02008F80Obj *obj, u32 i)
{
    if (i < 3) {
        return &obj->unk20[i];
    }
    return &obj->unk20[0];
}



void sub_02008FD8(struct Sub02008F80Obj *obj, void *arg, u32 i)
{
    if (i < 3) {
        sub_02024570((struct Rec8 *)(&obj->unk20[i]), arg);
    }
}



struct Sub02008F80Obj *sub_02008FEC(void *sys)
{
    return sub_020071CC(sub_02012EBC(sys), 0x28);
}




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the table of twenty of the 0x38-byte objects described in
 * src/matched/unit_02008F80.c, and the operations over it.  The original file
 * runs 0x02008FFC..0x020090B0 in one piece, closed on both sides by the
 * size-returning openers this part of the image uses throughout: 0x02008FFC
 * returns 0x460, which is twenty times 0x38, and 0x020090B0 returns 0x2C for
 * the next file.  It is committed as three pieces plus one function left out,
 * and the split is forced by the attestation rule rather than by anything in
 * the code:
 *
 *   src/matched/unit_02008FFC.c   0x02008FFC..0x02009020
 *   0x02009020                    a near miss, see below
 *   src/matched/unit_0200902C.c   0x0200902C..0x02009050
 *   src/matched/unit_02009050.c   0x02009050..0x020090B0
 *
 * sub_0200903C and sub_02009050 are the only two callers of sub_02008F3C
 * anywhere in the ROM, so matched in one range they attest each other's call
 * site out of existence and the whole file caps at MATCH with every concrete
 * byte right.  Split so that the two sit in different ranges, each is the
 * other's outside witness.  The same trick closed the pair at 0x02008B20; see
 * "The honesty rule" in docs/MATCHING.md.
 *
 * NEAR MISS, 0x02009020, 12 bytes, every concrete byte right, skipped.  It is
 * a three-instruction tail call to sub_02009074 through a pool word, and that
 * pool word is the only reference to 0x02009074 in the image: nothing branches
 * to it, so the `label` class has nothing to offer and the `literal` class's
 * only witness is the word under test.  Inside a range that also defines
 * sub_02009074 the reference is `local` and needs no evidence, but such a
 * range spans both sub_0200903C and sub_02009050 and so gives the sub_02008F3C
 * problem back.  The two constraints cannot both be met, so this is the one
 * function of the file left out.
 *
 * 0x38 is not a power of two, so every index in this file costs a `muls` and
 * the element size sits in a register hoisted out of the loop.  That multiply
 * is the tell that the array is of a struct and not of words: an array of
 * anything 1, 2, 4 or 8 bytes wide would have been a shift.
 *
 * sub_020090A0 is the bounds-checked element lookup the three functions before
 * it go through, and it ignores its second argument entirely: the parameter is
 * in `r1`, `r1` is dead from the first instruction, and the callers pass their
 * own second argument straight through.  That is not an artefact of the
 * matching; no instruction in the function reads `r1`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008FFC.c \
 *       --addr 0x02008FFC --thumb
 */
u32 sub_02008FFC(void)
{
    return sizeof(struct Sub02008F80Obj[ENTRY_COUNT]);
}




void sub_02009004(struct Sub02008F80Obj *arr)
{
    int i;

    for (i = 0; i < ENTRY_COUNT; i++) {
        sub_02008EAC((struct Sub02008EACObj *)(&arr[i]));
    }
}




/*
 * Tail call to func_02009074 with the count 0x14: the twenty-element table
 * of 0x38-byte objects described in src/matched/unit_02008FFC.c.  That file
 * left it out as a near miss because the pool word was the only reference to
 * 0x02009074; func_02009074 is now matched (src/matched/unit_02009050.c), so
 * the relocation attests through the `matched` class.  Seeded from ov119
 * 0x021E062E (tree_ov170_3).
 *
 * Addresses are Black-image addresses.
 */
void func_02009020(void *table)
{
    func_02009074(table, 0x14);
}




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the table of twenty of the 0x38-byte objects described in
 * src/matched/unit_02008F80.c, and the operations over it.  The original file
 * runs 0x02008FFC..0x020090B0 in one piece, closed on both sides by the
 * size-returning openers this part of the image uses throughout: 0x02008FFC
 * returns 0x460, which is twenty times 0x38, and 0x020090B0 returns 0x2C for
 * the next file.  It is committed as three pieces plus one function left out,
 * and the split is forced by the attestation rule rather than by anything in
 * the code:
 *
 *   src/matched/unit_02008FFC.c   0x02008FFC..0x02009020
 *   0x02009020                    a near miss, see below
 *   src/matched/unit_0200902C.c   0x0200902C..0x02009050
 *   src/matched/unit_02009050.c   0x02009050..0x020090B0
 *
 * sub_0200903C and sub_02009050 are the only two callers of sub_02008F3C
 * anywhere in the ROM, so matched in one range they attest each other's call
 * site out of existence and the whole file caps at MATCH with every concrete
 * byte right.  Split so that the two sit in different ranges, each is the
 * other's outside witness.  The same trick closed the pair at 0x02008B20; see
 * "The honesty rule" in docs/MATCHING.md.
 *
 * NEAR MISS, 0x02009020, 12 bytes, every concrete byte right, skipped.  It is
 * a three-instruction tail call to sub_02009074 through a pool word, and that
 * pool word is the only reference to 0x02009074 in the image: nothing branches
 * to it, so the `label` class has nothing to offer and the `literal` class's
 * only witness is the word under test.  Inside a range that also defines
 * sub_02009074 the reference is `local` and needs no evidence, but such a
 * range spans both sub_0200903C and sub_02009050 and so gives the sub_02008F3C
 * problem back.  The two constraints cannot both be met, so this is the one
 * function of the file left out.
 *
 * 0x38 is not a power of two, so every index in this file costs a `muls` and
 * the element size sits in a register hoisted out of the loop.  That multiply
 * is the tell that the array is of a struct and not of words: an array of
 * anything 1, 2, 4 or 8 bytes wide would have been a shift.
 *
 * sub_020090A0 is the bounds-checked element lookup the three functions before
 * it go through, and it ignores its second argument entirely: the parameter is
 * in `r1`, `r1` is dead from the first instruction, and the callers pass their
 * own second argument straight through.  That is not an artefact of the
 * matching; no instruction in the function reads `r1`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200902C.c \
 *       --addr 0x0200902C --thumb
 */
void sub_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i)
{
    struct Sub02008F80Obj *obj = sub_020090A0(arr, unused, i);

    if (obj != 0) {
        sub_02008EAC((struct Sub02008EACObj *)obj);
    }
}



void sub_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i,
                  const struct Sub02008F80Obj *src)
{
    struct Sub02008F80Obj *obj = sub_020090A0(arr, unused, i);

    if (obj != 0) {
        sub_02008F3C(src, obj);
    }
}




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the table of twenty of the 0x38-byte objects described in
 * src/matched/unit_02008F80.c, and the operations over it.  The original file
 * runs 0x02008FFC..0x020090B0 in one piece, closed on both sides by the
 * size-returning openers this part of the image uses throughout: 0x02008FFC
 * returns 0x460, which is twenty times 0x38, and 0x020090B0 returns 0x2C for
 * the next file.  It is committed as three pieces plus one function left out,
 * and the split is forced by the attestation rule rather than by anything in
 * the code:
 *
 *   src/matched/unit_02008FFC.c   0x02008FFC..0x02009020
 *   0x02009020                    a near miss, see below
 *   src/matched/unit_0200902C.c   0x0200902C..0x02009050
 *   src/matched/unit_02009050.c   0x02009050..0x020090B0
 *
 * sub_0200903C and sub_02009050 are the only two callers of sub_02008F3C
 * anywhere in the ROM, so matched in one range they attest each other's call
 * site out of existence and the whole file caps at MATCH with every concrete
 * byte right.  Split so that the two sit in different ranges, each is the
 * other's outside witness.  The same trick closed the pair at 0x02008B20; see
 * "The honesty rule" in docs/MATCHING.md.
 *
 * NEAR MISS, 0x02009020, 12 bytes, every concrete byte right, skipped.  It is
 * a three-instruction tail call to sub_02009074 through a pool word, and that
 * pool word is the only reference to 0x02009074 in the image: nothing branches
 * to it, so the `label` class has nothing to offer and the `literal` class's
 * only witness is the word under test.  Inside a range that also defines
 * sub_02009074 the reference is `local` and needs no evidence, but such a
 * range spans both sub_0200903C and sub_02009050 and so gives the sub_02008F3C
 * problem back.  The two constraints cannot both be met, so this is the one
 * function of the file left out.
 *
 * 0x38 is not a power of two, so every index in this file costs a `muls` and
 * the element size sits in a register hoisted out of the loop.  That multiply
 * is the tell that the array is of a struct and not of words: an array of
 * anything 1, 2, 4 or 8 bytes wide would have been a shift.
 *
 * sub_020090A0 is the bounds-checked element lookup the three functions before
 * it go through, and it ignores its second argument entirely: the parameter is
 * in `r1`, `r1` is dead from the first instruction, and the callers pass their
 * own second argument straight through.  That is not an artefact of the
 * matching; no instruction in the function reads `r1`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009050.c \
 *       --addr 0x02009050 --thumb
 */
struct Sub02008F80Obj *sub_02009050(struct Sub02008F80Obj *arr, u32 unused,
                                    int i, u32 heap)
{
    struct Sub02008F80Obj *obj = sub_020090A0(arr, unused, i);
    struct Sub02008F80Obj *copy = sub_02008F08(heap);

    if (obj != 0) {
        sub_02008F3C(obj, copy);
    }
    return copy;
}



/* The index of the first element the predicate says is out of range, or -1. */
int sub_02009074(struct Sub02008F80Obj *arr, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (sub_02008EF8(&arr[i]) == 0) {
            return i;
        }
    }
    return -1;
}



struct Sub02008F80Obj *sub_020090A0(struct Sub02008F80Obj *arr, u32 unused,
                                    int i)
{
    if (i < ENTRY_COUNT) {
        return &arr[i];
    }
    return 0;
}




/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * Original (4 bytes, leaf, no relocations):
 *   movs r0, #0x2c
 *   bx   lr
 *
 * The size-returning opener of the next file in the chain, and the value the
 * constructor at 0x020090B4 clears.  The accessors over the object are in
 * src/matched/unit_020090D8.c, which also says why the constructor between the
 * two is not matched here.
 */
u32 sub_020090B0(void)
{
    return sizeof(struct Sub020090B0Obj);
}



int func_020090B4(int a0, int a1, int a2, int a3){ int t0, t1, t2; t0 = func_020090B0(); t1 = func_02082BCC((int)((a0 + 0) + 0), (int)0, (int)(t0 + 0)); t2 = func_02082D44((int)0x20A7174, (int)((a0 + 0) + 0), (int)0x24); return t2; }




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020090F8, sub_02009100, sub_02009108, sub_0200910C
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/sub_020090B0.c.  Seven of the eight carry no label in the
 * generated listing: they have no register-saving prologue, so disasm.py's
 * sweep never fires and the listing emits them as data words.
 *
 * Layout, from the accessors and from the constructor's 0x24-byte copy:
 *
 *   +0x00  u8[9][4]  the table the three-argument readers after this range
 *                    index, with the row bound 9 and the column bound 4
 *   +0x24  u16       get/set
 *   +0x26  u8        get/set
 *   +0x27  u8        get/set
 *   +0x28  u8        get/set
 *
 * NEAR MISS, 0x020090B4, 36 bytes, skipped.  The constructor clears the object
 * and then copies 0x24 bytes of initial state over it from 0x020A7174.  That
 * address appears in exactly one literal pool in the image, the constructor's
 * own, so the `literal` class discards its only witness and there is nothing
 * else to attest a data address with.  It is the same shape as the hole the
 * `string` class was invented for, but the bytes at 0x020A7174 are a table
 * rather than a string, so that class does not reach it either.  It closes the
 * day anything else in the image loads that address.
 *
 * Six of the eight cost an extra `adds r0, #imm` before the load or store,
 * because `ldrb` and `strb` reach only +31 and the fields are at +0x26, +0x27
 * and +0x28.  The two `u16` accessors at +0x24 need no such thing: `ldrh`
 * reaches +62.  See docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020090D8.c \
 *       --addr 0x020090D8 --thumb
 */
void sub_020090D8(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk27 = value;
}



u8 sub_020090E0(const struct Sub020090B0Obj *obj)
{
    return obj->unk27;
}



void sub_020090E8(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk28 = value;
}



u8 sub_020090F0(const struct Sub020090B0Obj *obj)
{
    return obj->unk28;
}



void sub_020090F8(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk26 = value;
}



u8 sub_02009100(const struct Sub020090B0Obj *obj)
{
    return obj->unk26;
}



void sub_02009108(struct Sub020090B0Obj *obj, u16 value)
{
    obj->unk24 = value;
}



u16 sub_0200910C(const struct Sub020090B0Obj *obj)
{
    return obj->unk24;
}



u32 sub_02009110(const struct Sub020090B0Obj *obj, int row, int col)
{
    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    return obj->unk00[row][col] & 0xF;
}



int sub_02009134(const struct Sub020090B0Obj *obj, int row, int col)
{
    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    if ((obj->unk00[row][col] & 0x80) != 0) {
        return 1;
    }
    return 0;
}
