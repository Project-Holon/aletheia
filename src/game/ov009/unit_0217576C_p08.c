/*
 * file:     unit_0217576C_p08.c
 * unit:     yes
 * function: func_0217637C, func_021763AC
 * address:  0x0217637C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */
extern char *func_02175F3C(void);
char *func_0217637C(int index);
char *func_021763AC(int pid);


/*
 * DWCi_NodeInfoList_GetNodeInfoForIndex: the 0x28-byte node record at an index, or null past the count.
 */
char *func_0217637C(int index)
{
    if (index >= *(int *)(func_02175F3C() + 0x50)) {
        return 0;
    }
    return func_02175F3C() + 0x54 + index * 0x28;
}


/*
 * DWCi_NodeInfoList_GetNodeInfoForProfileID: the node record whose profile id matches, or null.
 */
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
