/*
 * file:     card_common_2.c
 * function: CARDi_GetAccessLevel
 * address:  0x02075FCC
 * packet:   pkt_02075DA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_GetBootType  0x02087B04  arm
 *   OS_IsRunOnTwl   0x02085D3C  arm
 *   func_02075E04   0x02075E04  arm
 *
 * A permission mask built from the TWL ROM header.  func_02075E04 returns the
 * header buffer (its pool word is 0x02FFE000), and the four one-bit extracts
 * of the word at +0x1B4 are its access-control flags, read as u32 bitfields
 * (bits 5, 8, 15, 16).  A ROM boot (OS_GetBootType() == 1) or a non-TWL run
 * grants everything (7).  Otherwise bit 8 grants 4 and enables the other two
 * checks, bit 5 only enables them, and bits 15/16 grant 1/2.  Byte-exact under
 * both 1.1p1 and ../2.0/sp2 on the first compile; EXACT* because the follower
 * 0x02076050 (already filed) carries no label.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/CARDi_GetAccessLevel.c \
 *       --func CARDi_GetAccessLevel --addr 0x02075FCC --arm --cc 1.1p1
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int BOOL;
typedef struct {
    u32 keyAndSlotAccess    : 5;
    u32 gameCardPowerOn     : 1;
    u32 sharedFileAccess    : 2;
    u32 gameCardNitroMode   : 1;
    u32 sdAndPhotoAccess    : 6;
    u32 backupAccess        : 1;
    u32 romAccess           : 1;
    u32 reserved            : 15;
} TwlAccessControl;
typedef struct { u8 pad00[0x1b4]; TwlAccessControl access; } TwlRomHeader;
extern int OS_GetBootType(void);
extern BOOL OS_IsRunOnTwl(void);
extern TwlRomHeader *func_02075E04(void);
u32 CARDi_GetAccessLevel(void)
{
    u32 accessLevel = 0;
    TwlRomHeader *romHeader;
    BOOL accessGranted;
    if (OS_GetBootType() == 1) {
        accessLevel = 7;
    } else if (!OS_IsRunOnTwl()) {
        accessLevel = 7;
    } else {
        romHeader = func_02075E04();
        accessGranted = 0;
        if (romHeader->access.gameCardNitroMode) {
            accessLevel |= 4;
            accessGranted = 1;
        } else if (romHeader->access.gameCardPowerOn) {
            accessGranted = 1;
        }
        if (accessGranted) {
            if (romHeader->access.backupAccess) accessLevel |= 1;
            if (romHeader->access.romAccess) accessLevel |= 2;
        }
    }
    return accessLevel;
}
