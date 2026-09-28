/*
 * function: func_02059474
 * address:  0x02059474
 * packet:   pkt_02059474
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Acc_LoginIdToUserName (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   DWCi_Acc_GetUserId               0x02059084 arm
 *   DWCi_Acc_U64ToString32           0x02059408 arm
 *   DWCi_Acc_GetPlayerId             0x020590a4 arm
 *   OS_SNPrintf                      0x02084f80 arm
 *   g_020A8018                       0x020A8018 data
 */

struct DWCstAccLoginId;

extern const char g_020A8018[];
extern unsigned long long DWCi_Acc_GetUserId(struct DWCstAccLoginId *userdata);
extern void DWCi_Acc_U64ToString32(unsigned long long num, int bitnum, char *result);
extern unsigned long DWCi_Acc_GetPlayerId(struct DWCstAccLoginId *userdata);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);

void func_02059474(struct DWCstAccLoginId *loginid, unsigned long gamecode, char *username)
{
    char userid[21];
    char playerid[21];

    DWCi_Acc_U64ToString32(DWCi_Acc_GetUserId(loginid), 43, userid);
    DWCi_Acc_U64ToString32(DWCi_Acc_GetPlayerId(loginid), 32, playerid);
    OS_SNPrintf(username, 21, g_020A8018, userid,
                (unsigned char)(gamecode >> 24), (unsigned char)(gamecode >> 16),
                (unsigned char)(gamecode >> 8), (unsigned char)gamecode, playerid);
}
