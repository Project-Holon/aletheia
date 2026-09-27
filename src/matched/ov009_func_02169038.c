/*
 * function: func_02169038
 * address:  0x02169038
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_GetFriendListIndex: the friend list index holding a profile id, or -1.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 *   func_02168FF0  0x02168FF0  arm  ov009
 */

extern char g_021AA860[];
extern int func_02168FF0(int index);

int func_02169038(int pid)
{
    int i;

    if (*(char **)(g_021AA860 + 0xc) == 0 || pid == 0) {
        return -1;
    }
    for (i = 0; i < *(int *)(*(char **)(g_021AA860 + 0xc) + 0x14); i++) {
        if (pid == func_02168FF0(i)) {
            return i;
        }
    }
    return -1;
}
