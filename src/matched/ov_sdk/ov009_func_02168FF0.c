/*
 * function: func_02168FF0
 * address:  0x02168FF0
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_GetProfileIDFromList: the profile id of a friend list entry, zero when unset or invalid.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 *   func_0216A39C  0x0216A39C  arm  ov009
 *   DWC_GetGsProfileId  0x020598EC  arm
 */

extern char g_021AA860[];
extern int func_0216A39C(void);
extern int DWC_GetGsProfileId(void *user, void *data);

int func_02168FF0(int index)
{
    char *list = *(char **)(*(char **)(g_021AA860 + 0xc) + 0x18);
    int pid;

    if (list == 0) {
        return 0;
    }
    pid = DWC_GetGsProfileId((void *)func_0216A39C(), list + index * 0xc);
    if (pid != 0 && pid != -1) {
        return pid;
    }
    return 0;
}
