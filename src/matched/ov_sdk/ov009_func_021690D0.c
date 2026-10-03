/*
 * function: func_021690D0
 * address:  0x021690D0
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_SetGPStatus: sets the GP status, defaulting each unset argument to the current one.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   func_0218627C  0x0218627C  arm  ov009
 */

extern char g_021AA860[];
extern int func_0216AA70(void);
extern int func_0218627C(void **connection, int status, const char *statusString, const char *locationString);

int func_021690D0(int status, const char *statusString, const char *locString)
{
    if (*(char **)(g_021AA860 + 0xc) == 0 || func_0216AA70() == 0) {
        return 0;
    }
    if (status == -1) {
        status = *(int *)(**(char ***)(*(char **)(g_021AA860 + 0xc) + 4) + 0x23c);
    }
    if (statusString == 0) {
        statusString = **(char ***)(*(char **)(g_021AA860 + 0xc) + 4) + 0x3b8;
    }
    if (locString == 0) {
        locString = **(char ***)(*(char **)(g_021AA860 + 0xc) + 4) + 0x4b8;
    }
    return func_0218627C(*(void **)(*(char **)(g_021AA860 + 0xc) + 4), status, statusString, locString);
}
