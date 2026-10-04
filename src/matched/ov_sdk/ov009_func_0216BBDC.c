/*
 * function: func_0216BBDC
 * address:  0x0216BBDC
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_GetGT2ConnectionByProfileID: the connection slot whose peer profile id matches, or null.
 *
 * symbols:
 *   g_021AA8A0  0x021AA8A0  data
 *   func_02195E78  0x02195E78  arm  ov009
 *   func_0216BBCC  0x0216BBCC  arm  ov009
 */

extern int g_021AA8A0[];
extern int func_02195E78(const int *p);
extern int *func_0216BBCC(int i);

int *func_0216BBDC(int pid)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (g_021AA8A0[i] != 0 && pid == *(int *)(func_02195E78((const int *)g_021AA8A0[i]) + 4)) {
            return func_0216BBCC(i);
        }
    }
    return 0;
}
