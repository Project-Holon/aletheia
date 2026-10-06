/*
 * function: func_02087E1C
 * address:  0x02087E1C
 * packet:   pkt_02087E1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_GetAgreedEULAVersion (os_ownerinfoex.o)
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
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

#define OSi_NVRAM_OWNER ((OSiNvramOwner *)0x02FFFC80)

extern BOOL OS_IsRunOnTwl(void);

/* HW_PARAM_TWL_SETTINGS_DATA: a pointer at 0x02FFFDFC to the TWL settings. */
#define OSi_TWL_SETTINGS (*(u8 **)0x02FFFDFC)

u8 func_02087E1C(void)
{
    if (OS_IsRunOnTwl()) {
        return OSi_TWL_SETTINGS[0x10];
    }
    return 0;
}
