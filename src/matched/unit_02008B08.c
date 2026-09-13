/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008B08
 * packet:   pkt_02008A34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02008B08, sub_02008B14, sub_02008B20
 *
 * symbols:
 *   OS_GetMacAddress      0x02087C6C  arm
 *   OS_GetOwnerInfo       0x02087C88  arm
 *   OS_GetOwnerRtcOffset  0x02087D08  arm
 *   sub_020071CC          0x020071CC  thumb
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int   u32;
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

extern void OS_GetMacAddress(u8 *mac);
extern void OS_GetOwnerInfo(struct OSOwnerInfo *info);
extern s64  OS_GetOwnerRtcOffset(void);
extern void *sub_020071CC(void *sys, u32 id);

#define BLOCK_ID 0x25

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

struct Sub02008AECObj *sub_02008B08(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}

struct Sub02008AECSession *sub_02008B14(void *sys)
{
    struct Sub02008AECObj *obj = sub_020071CC(sys, BLOCK_ID);

    return &obj->unk10;
}

/* Stamp the block with this console's identity. */
void sub_02008B20(struct Sub02008AECObj *obj)
{
    struct OSOwnerInfo info;

    obj->rtcOffset = OS_GetOwnerRtcOffset();
    OS_GetMacAddress(obj->mac);
    OS_GetOwnerInfo(&info);
    obj->birthdayMonth = info.birthdayMonth;
    obj->birthdayDay = info.birthdayDay;
}
