/*
 * function: func_021754FC
 * address:  0x021754FC
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_IsBackupMine: whether node 0 is this host's own profile.
 *
 * symbols:
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern int func_02175F3C(void);
extern int *func_0217637C(int index);

int func_021754FC(void)
{
    int r = 0;
    int *node = func_0217637C(r);

    if (node != 0 && *node == *(int *)(func_02175F3C() + 0x678)) {
        r = 1;
    }
    return r;
}
