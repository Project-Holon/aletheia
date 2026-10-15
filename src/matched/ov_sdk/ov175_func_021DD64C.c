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
 *   strcmp  0x020948E0  arm
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
 * strcmp-style probe (strcmp) against each known status string,
 * returning the string's index.  Seven indices (6 in the 9..0x14 range)
 * are skipped because they are not reachable from this pool; the caller
 * reads the dedicated return value from those.
 */

typedef int s32;

extern s32 strcmp(const char *a, const char *b);

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
    if (strcmp(p, sResultSuccess) == 0)
        return 0;
    if (strcmp(p, sResultSecretKeyInvalid) == 0)
        return 1;
    if (strcmp(p, sResultServiceDisabled) == 0)
        return 2;
    if (strcmp(p, sResultDatabaseUnavailable) == 0)
        return 7;
    if (strcmp(p, sResultLoginTicketInvalid) == 0)
        return 8;
    if (strcmp(p, sResultLoginTicketExpired) == 0)
        return 9;
    if (strcmp(p, sResultTableNotFound) == 0)
        return 0xa;
    if (strcmp(p, sResultRecordNotFound) == 0)
        return 0xb;
    if (strcmp(p, sResultFieldNotFound) == 0)
        return 0xc;
    if (strcmp(p, sResultFieldTypeInvalid) == 0)
        return 0xd;
    if (strcmp(p, sResultNoPermission) == 0)
        return 0xe;
    if (strcmp(p, sResultRecordLimitReached) == 0)
        return 0xf;
    if (strcmp(p, sResultAlreadyRated) == 0)
        return 0x10;
    if (strcmp(p, sResultNotRateable) == 0)
        return 0x11;
    if (strcmp(p, sResultNotOwned) == 0)
        return 0x12;
    if (strcmp(p, sResultFilterInvalid) == 0)
        return 0x13;
    if (strcmp(p, sResultSortInvalid) == 0)
        return 0x14;
    return strcmp(p, sResultTargetFilterInvalid) == 0 ? 0x15 : 0x16;
}
