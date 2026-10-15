/*
 * file:     os_ownerinfoex.c
 * unit:     yes
 * function: OSi_GetOwnerInfoExBuffer, OS_GetOwnerInfoEx, OS_IsAvailableWireless, OS_IsAgreeEULA, OS_GetAgreedEULAVersion, OS_GetROMHeaderEULAVersion, OS_GetParentalControlInfoPtr, OS_IsForceDisableWireless
 * address:  0x02087D1C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Return the address of the object at 0x020A5CE8.  Unlabelled ARM leaf in
 * the ARM9 listing; matched so overlay callers get a `matched` witness.
 *
 * symbols:
 *   g_020A5CE8  0x020A5CE8  data  a4
 *   MIi_CpuCopy16  0x02082A60  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_IsAvailableWireless_ltdmain 0x027312D0 arm twl
 *   OS_IsForceDisableWireless_ltdmain 0x027312F8 arm twl
 */
#define OSi_NVRAM_OWNER ((OSiNvramOwner *)0x02FFFC80)
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

typedef volatile unsigned char vu8;

extern BOOL OS_IsRunOnTwl(void);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern BOOL OS_IsAvailableWireless_ltdmain(void);
extern BOOL OS_IsForceDisableWireless_ltdmain(void);
char *OSi_GetOwnerInfoExBuffer(void);
void OS_GetOwnerInfoEx(OSOwnerInfoEx *info);
BOOL OS_IsAvailableWireless(void);
BOOL OS_IsAgreeEULA(void);
u8 OS_GetAgreedEULAVersion(void);
u8 OS_GetROMHeaderEULAVersion(void);
const void *OS_GetParentalControlInfoPtr(void);
BOOL OS_IsForceDisableWireless(void);
extern char g_020A5CE8[];


char *OSi_GetOwnerInfoExBuffer(void)
{
    return g_020A5CE8;
}








/*
 * sdk:      OS_GetOwnerInfoEx (os_ownerinfoex.o)
 */
void OS_GetOwnerInfoEx(OSOwnerInfoEx *info)
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








BOOL OS_IsAvailableWireless(void)
{
    if (!OS_IsRunOnTwl()) {
        return 1;
    }
    return OS_IsAvailableWireless_ltdmain();
}







/* HW_PARAM_TWL_SETTINGS_DATA: a pointer at 0x02FFFDFC to the TWL settings. */
#define OSi_TWL_SETTINGS (*(u8 **)0x02FFFDFC)







/*
 * sdk:      OS_IsAgreeEULA (os_ownerinfoex.o)
 */
BOOL OS_IsAgreeEULA(void)
{
    if (OS_IsRunOnTwl()) {
        return ((*(u32 *)OSi_TWL_SETTINGS >> 24) & 1) ? 1 : 0;
    }
    return 0;
}






/* HW_PARAM_TWL_SETTINGS_DATA: a pointer at 0x02FFFDFC to the TWL settings. */
#define OSi_TWL_SETTINGS (*(u8 **)0x02FFFDFC)






/*
 * sdk:      OS_GetAgreedEULAVersion (os_ownerinfoex.o)
 */
u8 OS_GetAgreedEULAVersion(void)
{
    if (OS_IsRunOnTwl()) {
        return OSi_TWL_SETTINGS[0x10];
    }
    return 0;
}





u8 OS_GetROMHeaderEULAVersion(void)
{
    if (OS_IsRunOnTwl()) {
        return *(vu8 *)0x02FFE20E;
    }
    return 0;
}




/* HW_PARAM_TWL_SETTINGS_DATA: a pointer at 0x02FFFDFC to the TWL settings. */
#define OSi_TWL_SETTINGS (*(u8 **)0x02FFFDFC)




/*
 * sdk:      OS_GetParentalControlInfoPtr (os_ownerinfoex.o)
 */
const void *OS_GetParentalControlInfoPtr(void)
{
    if (OS_IsRunOnTwl()) {
        return OSi_TWL_SETTINGS + 0x94;
    }
    return 0;
}



BOOL OS_IsForceDisableWireless(void)
{
    if (!OS_IsRunOnTwl()) {
        return 0;
    }
    return OS_IsForceDisableWireless_ltdmain();
}
