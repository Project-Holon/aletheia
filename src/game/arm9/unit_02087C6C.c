/*
 * file:     unit_02087C6C.c
 * unit:     yes
 * function: func_02087C6C, func_02087C88, func_02087D08
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
 *   func_02082D44 0x02082D44 arm
 *   MIi_CpuCopy16  0x02082A60  arm
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

extern void func_02082D44(void);
extern BOOL OS_IsRunOnTwl(void);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
asm void OS_GetMacAddress(void);
void func_02087C88(OSOwnerInfo *info);
asm void OS_GetOwnerRtcOffset(void);


asm void OS_GetMacAddress(void)
{
    mov	r1, r0
    ldr r0, =0x02FFFCF4
    ldr ip, =func_02082D44
    mov	r2, #6
    bx	ip
}


#define OSi_NVRAM_OWNER ((OSiNvramOwner *)0x02FFFC80)


/*
 * sdk:      OS_GetOwnerInfo (os_ownerinfo.o)
 */
void func_02087C88(OSOwnerInfo *info)
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

asm void OS_GetOwnerRtcOffset(void)
{
    ldr r1, =0x02FFFC80
    ldr	r0, [r1, #0x68]
    ldr	r1, [r1, #0x6c]
    bx	lr
}
