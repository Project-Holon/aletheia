/*
 * function: DWCi_GPSetServerStatus
 * address:  0x0216F20C
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Builds the match key-value status string and hands it to DWCi_SetGPStatus.
 *
 * symbols:
 *   d_021A207C  0x021A207C  data
 *   d_021A2080  0x021A2080  data
 *   d_021A2084  0x021A2084  data
 *   d_021A2088  0x021A2088  data
 *   d_021A208C  0x021A208C  data
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   OS_SNPrintf  0x02084F80  arm
 *   func_02168454  0x02168454  arm  ov009
 *   func_0216848C  0x0216848C  arm  ov009
 *   DWCi_NodeInfoList_GetCount  0x0217603C  arm  ov009
 *   DWCi_IsServerLocked  0x021767F4  arm  ov009
 *   DWCi_SetGPStatus  0x021690D0  arm  ov009
 */

extern char d_021A207C[];
extern char d_021A2080[];
extern char d_021A2084[];
extern char d_021A2088[];
extern char d_021A208C[];
extern int func_02175F3C(void);
extern int OS_SNPrintf(char *dst, int len, const char *fmt, ...);
extern int func_02168454(const char *key, const char *value, char *string, char sep);
extern int func_0216848C(const char *key, const char *value, char *string, char sep);
extern int DWCi_NodeInfoList_GetCount(void);
extern int DWCi_IsServerLocked(void);
extern int DWCi_SetGPStatus(int status, const char *statusString, const char *locString);

int DWCi_GPSetServerStatus(int status)
{
    char value[12];
    char str[0x27];
    int n;

    OS_SNPrintf(value, 12, d_021A207C, *(unsigned char *)(func_02175F3C() + 0x17) + 1);
    func_02168454(d_021A2080, value, str, '/');
    n = DWCi_NodeInfoList_GetCount();
    if (*(unsigned char *)(func_02175F3C() + 0x15) == 2 && n == 0) {
        n = 1;
    }
    OS_SNPrintf(value, 12, d_021A207C, n);
    func_0216848C(d_021A2084, value, str, '/');
    OS_SNPrintf(value, 12, d_021A207C, 0x5a);
    func_0216848C(d_021A2088, value, str, '/');
    OS_SNPrintf(value, 12, d_021A207C, DWCi_IsServerLocked() ? 1 : 0);
    func_0216848C(d_021A208C, value, str, '/');
    return DWCi_SetGPStatus(status, str, 0);
}
