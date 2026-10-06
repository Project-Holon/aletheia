/*
 * file:     unit_02087D28_p01.c
 * unit:     yes
 * function: func_02087D28, OS_IsAvailableWireless
 * address:  0x02087D28
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
 *   MIi_CpuCopy16  0x02082A60  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_027312D0 0x027312D0 arm twl
 */
typedef unsigned long u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef int BOOL;

typedef struct OSBirthday {
    u8 month;
    u8 day;
} OSBirthday;

typedef struct OSOwnerInfo {
    u8 language;
    u8 favoriteColor;
    OSBirthday birthday;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OSOwnerInfo;

/* The user settings copy in system work at 0x02FFFC80, as far as the
   reads here reach. */
typedef struct OSiNvramOwner {
    u8 version;
    u8 rsv1;
    u8 favoriteColor : 4;
    u8 rsv2 : 4;
    u8 month;
    u8 day;
    u8 rsv3;
    u16 nickName[10];
    u8 nickNameLength;
    u8 rsv4;
    u16 comment[26];
    u8 commentLength;
    u8 rsv5;
    u8 rsv6[0x12];
    u16 language : 3;
    u16 rsv7 : 13;
} OSiNvramOwner;

typedef struct OSOwnerInfoEx {
    u8 language;
    u8 favoriteColor;
    OSBirthday birthday;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
    u8 country;
    u8 padding;
} OSOwnerInfoEx;

typedef struct OSiNvramSystemWork {
    OSiNvramOwner owner;
    u8 rsv[0x17C - sizeof(OSiNvramOwner)];
    u8 *twlSettings;
} OSiNvramSystemWork;

extern BOOL OS_IsRunOnTwl(void);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern void func_027312D0(void);
void func_02087D28(OSOwnerInfoEx *info);
asm void OS_IsAvailableWireless(void);


#define OSi_NVRAM_OWNER ((OSiNvramOwner *)0x02FFFC80)


/*
 * sdk:      OS_GetOwnerInfoEx (os_ownerinfoex.o)
 */
void func_02087D28(OSOwnerInfoEx *info)
{
    OSiNvramSystemWork *src = (OSiNvramSystemWork *)0x02FFFC80;

    info->favoriteColor = src->owner.favoriteColor;
    info->birthday.month = src->owner.month;
    info->birthday.day = src->owner.day;
    info->nickNameLength = src->owner.nickNameLength;
    info->commentLength = src->owner.commentLength;
    MIi_CpuCopy16(src->owner.nickName, info->nickName, 10 * sizeof(u16));
    MIi_CpuCopy16(src->owner.comment, info->comment, 26 * sizeof(u16));
    info->nickName[10] = 0;
    info->comment[26] = 0;

    if (OS_IsRunOnTwl()) {
        u8 *twlSettings = src->twlSettings;

        info->country = twlSettings[5];
        info->language = twlSettings[6];
    } else {
        info->country = 0;
        info->language = (u8)src->owner.language;
    }
}


asm void OS_IsAvailableWireless(void)
{
    stmfd sp!, {r3, lr}
    bl OS_IsRunOnTwl
    cmp r0, #0
    moveq r0, #1
    ldmeqfd sp!, {r3, pc}
    bl func_027312D0
    ldmfd sp!, {r3, pc}
}
