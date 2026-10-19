/*
 * file:     sealed_checks_console.c
 * unit:     yes
 * function: OV230_CheckConsoleIdentity0, OV230_CheckConsoleIdentity1
 * address:  0x02188CDC
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Second-layer bodies of overlay 230 (region ov230d, opened by tools/ovcrypt.py): two checks of the console's own
 * identity. Each reads the MAC address and the owner information, compares the MAC with a fixed address kept
 * complemented in the overlay's tail data, and returns a tag times a constant. The tag is 0xFB when the MAC is the fixed
 * one and the owner has the default birthday 1 January and an empty nickname, or when the MAC is all zero; any other
 * console gives 0xF1. The second check has the two tags swapped.
 *
 * symbols:
 *   OV230_CheckConsoleIdentity0  0x02188CDC  arm  ov230d
 *   OV230_CheckConsoleIdentity1  0x02188D8C  arm  ov230d
 *   OS_GetMacAddress  0x02087C6C  arm
 *   OS_GetOwnerInfo  0x02087C88  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* SDK owner information as the overlay lays it out: the nickname has room for 10 characters and a terminator. */
typedef struct OvOwnerInfo {
    u8 language;
    u8 favoriteColor;
    u8 birthdayMonth;
    u8 birthdayDay;
    u16 nickname[11];
    u16 nicknameLength;
    u16 comment[27];
    u16 commentLength;
} OvOwnerInfo;

extern void OS_GetMacAddress(u8 *mac);
extern void OS_GetOwnerInfo(OvOwnerInfo *info);
/* the complemented MAC address sits in the overlay's tail data, which the data registry names g_0218996C */
#define OV230_MAC_MASK ((const u8 *)0x0218996C)

u32 OV230_CheckConsoleIdentity0(void)
{
    u8 mac[6];
    OvOwnerInfo info;
    const u8 *a;
    const u8 *b;
    int i;
    u32 tag;

    OS_GetMacAddress(mac);
    a = mac;
    b = OV230_MAC_MASK;
    i = 0;
    do {
        if (*b != (*a ^ 0xFF)) {
            break;
        }
        i++;
        a++;
        b++;
    } while (i < 6);
    OS_GetOwnerInfo(&info);
    if (i == 6 && info.birthdayMonth == 1 && info.birthdayDay == 1 && info.nicknameLength == 0) {
        tag = 0xFB;
    } else {
        a = mac;
        for (i = 0; i < 6; i++) {
            if (*a != 0) {
                tag = 0xF1;
                goto done;
            }
            a++;
        }
        tag = 0xFB;
    }
done:
    return tag * 0xAD;
}

u32 OV230_CheckConsoleIdentity1(void)
{
    u8 mac[6];
    OvOwnerInfo info;
    const u8 *a;
    const u8 *b;
    int i;
    u32 tag;

    OS_GetMacAddress(mac);
    a = mac;
    b = OV230_MAC_MASK;
    i = 0;
    do {
        if (*b != (*a ^ 0xFF)) {
            break;
        }
        i++;
        a++;
        b++;
    } while (i < 6);
    OS_GetOwnerInfo(&info);
    if (i == 6 && info.birthdayMonth == 1 && info.birthdayDay == 1 && info.nicknameLength == 0) {
        tag = 0xF1;
    } else {
        a = mac;
        for (i = 0; i < 6; i++) {
            if (*a != 0) {
                tag = 0xFB;
                goto done;
            }
            a++;
        }
        tag = 0xF1;
    }
done:
    return tag * 0xB3;
}
