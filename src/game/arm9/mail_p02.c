/*
 * file:     mail_p02.c
 * unit:     yes
 * function: func_02008AF0, func_02008B08, func_02008B14, func_02008B20, func_02008B4C, func_02008B78, func_02008B94, func_02008B98, func_02008B9C, func_02008BD0, func_02008BE0, func_02008C00
 * address:  0x02008AF0
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
 *   func_02082AC0  0x02082AC0  arm
 *   func_02008B9C  0x02008B9C  thumb
 *   OS_GetMacAddress      0x02087C6C  arm
 *   OS_GetOwnerInfo       0x02087C88  arm
 *   OS_GetOwnerRtcOffset  0x02087D08  arm
 *   sub_020071CC          0x020071CC  thumb
 *   RTC_ConvertDateToDay         0x02088F58  arm
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   sub_0203F49C                 0x0203F49C  arm
 *   src/matched/sub_02008AEC.c       0x02008AEC  the size
 */
struct Sub02008AECSession;
struct Sub020071CCCtrl;
struct RtcDate;
struct RtcTime;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef signed   short s16;

typedef signed long long   s64;

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

struct Sub02008AECObj {
    s64 rtcOffset;
    u8  mac[6];
    u8  birthdayMonth;
    u8  birthdayDay;
    struct Sub02008AECSession unk10;
    u8  unk48[0x14];
};

extern void func_02082AC0(u32 val, void *dst, u32 size);
extern void func_02008B9C(struct Sub02008AECSession *s);
extern void OS_GetMacAddress(u8 *mac);
extern void OS_GetOwnerInfo(struct OSOwnerInfo *info);
extern s64  OS_GetOwnerRtcOffset(void);
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32  RTC_ConvertDateToDay(const struct RTCDate *date);
extern u64  RTC_ConvertDateTimeToSecond(const struct RTCDate *date,
                                        const struct RTCTime *time);
extern void sub_0203F49C(struct RtcDate *date, struct RtcTime *time);
void func_02008AF0(void *obj);
struct Sub02008AECObj *sub_02008B08(void *sys);
struct Sub02008AECSession *sub_02008B14(void *sys);


void func_02008AF0(void *obj)
{
    func_02082AC0(0, obj, 0x5C);
    func_02008B9C((struct Sub02008AECSession *)((u8 *)obj + 0x10));
}


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
struct Sub02008AECObj *sub_02008B08(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}


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
struct Sub02008AECSession *sub_02008B14(void *sys)
{
    struct Sub02008AECObj *obj = sub_020071CC(sys, BLOCK_ID);

    return &obj->unk10;
}


/* Stamp the block with this console's identity. */
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
void sub_02008B20(struct Sub02008AECObj *obj)
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
 *   src/matched/sub_02008AEC.c       0x02008AEC  the size
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
int sub_02008B4C(const struct Sub02008AECObj *obj)
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
 *   src/matched/sub_02008AEC.c       0x02008AEC  the size
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
int sub_02008B78(const struct Sub02008AECObj *obj)
{
    if (OS_GetOwnerRtcOffset() != obj->rtcOffset) {
        return 0;
    }
    return 1;
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
 *   src/matched/sub_02008AEC.c       0x02008AEC  the size
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
u8 sub_02008B94(const struct Sub02008AECObj *obj)
{
    return obj->birthdayMonth;
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
 *   src/matched/sub_02008AEC.c       0x02008AEC  the size
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
u8 sub_02008B98(const struct Sub02008AECObj *obj)
{
    return obj->birthdayDay;
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
 *   src/matched/sub_02008AEC.c       0x02008AEC  the size
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
 *   src/matched/sub_02008AEC.c       0x02008AEC  the size
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
int sub_02008BD0(const struct Sub02008AECSession *s)
{
    if (s->unk34 == 0) {
        return 0;
    }
    return 1;
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
 *   src/matched/sub_02008AEC.c       0x02008AEC  the size
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
 *   src/matched/sub_02008AEC.c       0x02008AEC  the size
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
void sub_02008C00(struct Sub02008AECSession *s)
{
    s->unk34 = 0x5A0;
    sub_0203F49C((struct RtcDate *)(&s->date), (struct RtcTime *)(&s->time));
    s->unk20 = RTC_ConvertDateToDay(&s->date);
}
