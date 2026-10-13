/*
 * function: sakeiCheckSakeResult
 * address:  0x021DD64C
 * packet:   pkt_ov175_021DD64C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020948E0  0x020948E0  arm
 *   sResultSuccess     0x021E3730  data
 *   sResultSecretKeyInvalid     0x021E3738  data
 *   sResultServiceDisabled     0x021E374C  data
 *   sResultDatabaseUnavailable     0x021E375C  data
 *   sResultLoginTicketInvalid     0x021E3770  data
 *   sResultLoginTicketExpired     0x021E3784  data
 *   sResultTableNotFound     0x021E3798  data
 *   sResultRecordNotFound     0x021E37A8  data
 *   sResultFieldNotFound     0x021E37B8  data
 *   sResultFieldTypeInvalid     0x021E37C8  data
 *   sResultNoPermission     0x021E37DC  data
 *   sResultRecordLimitReached     0x021E37EC  data
 *   sResultAlreadyRated     0x021E3800  data
 *   sResultNotRateable     0x021E3810  data
 *   sResultNotOwned     0x021E381C  data
 *   sResultFilterInvalid     0x021E3828  data
 *   sResultSortInvalid     0x021E3838  data
 *   sResultTargetFilterInvalid     0x021E3844  data
 *
 * Nintendo WFC / Wi-Fi connection error-name to index table: a plain
 * strcmp-style probe (func_020948E0) against each known status string,
 * returning the string's index.  Seven indices (6 in the 9..0x14 range)
 * are skipped because they are not reachable from this pool; the caller
 * reads the dedicated return value from those.
 */

typedef int s32;

extern s32 func_020948E0(const char *a, const char *b);

extern char sResultSuccess[];
extern char sResultSecretKeyInvalid[];
extern char sResultServiceDisabled[];
extern char sResultDatabaseUnavailable[];
extern char sResultLoginTicketInvalid[];
extern char sResultLoginTicketExpired[];
extern char sResultTableNotFound[];
extern char sResultRecordNotFound[];
extern char sResultFieldNotFound[];
extern char sResultFieldTypeInvalid[];
extern char sResultNoPermission[];
extern char sResultRecordLimitReached[];
extern char sResultAlreadyRated[];
extern char sResultNotRateable[];
extern char sResultNotOwned[];
extern char sResultFilterInvalid[];
extern char sResultSortInvalid[];
extern char sResultTargetFilterInvalid[];

s32 sakeiCheckSakeResult(const char *p)
{
    if (func_020948E0(p, sResultSuccess) == 0)
        return 0;
    if (func_020948E0(p, sResultSecretKeyInvalid) == 0)
        return 1;
    if (func_020948E0(p, sResultServiceDisabled) == 0)
        return 2;
    if (func_020948E0(p, sResultDatabaseUnavailable) == 0)
        return 7;
    if (func_020948E0(p, sResultLoginTicketInvalid) == 0)
        return 8;
    if (func_020948E0(p, sResultLoginTicketExpired) == 0)
        return 9;
    if (func_020948E0(p, sResultTableNotFound) == 0)
        return 0xa;
    if (func_020948E0(p, sResultRecordNotFound) == 0)
        return 0xb;
    if (func_020948E0(p, sResultFieldNotFound) == 0)
        return 0xc;
    if (func_020948E0(p, sResultFieldTypeInvalid) == 0)
        return 0xd;
    if (func_020948E0(p, sResultNoPermission) == 0)
        return 0xe;
    if (func_020948E0(p, sResultRecordLimitReached) == 0)
        return 0xf;
    if (func_020948E0(p, sResultAlreadyRated) == 0)
        return 0x10;
    if (func_020948E0(p, sResultNotRateable) == 0)
        return 0x11;
    if (func_020948E0(p, sResultNotOwned) == 0)
        return 0x12;
    if (func_020948E0(p, sResultFilterInvalid) == 0)
        return 0x13;
    if (func_020948E0(p, sResultSortInvalid) == 0)
        return 0x14;
    return func_020948E0(p, sResultTargetFilterInvalid) == 0 ? 0x15 : 0x16;
}
