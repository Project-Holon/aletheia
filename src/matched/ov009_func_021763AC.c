/*
 * function: func_021763AC
 * address:  0x021763AC
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_NodeInfoList_GetNodeInfoForProfileID: the node record whose profile id matches, or null.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern char *func_02175F3C(void);

char *func_021763AC(int pid)
{
    int i;

    for (i = 0; i < *(int *)(func_02175F3C() + 0x50); i++) {
        if (pid == *(int *)(func_02175F3C() + i * 0x28 + 0x54)) {
            return func_02175F3C() + 0x54 + i * 0x28;
        }
    }
    return 0;
}
