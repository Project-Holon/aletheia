/*
 * function: DWCi_IsFriendByIdxList
 * address:  0x02173B74
 * packet:   pkt_ov009_02173B74
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_IsFriendByIdxList (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02168FF0  0x02168FF0  arm  ov009
 */

extern char *func_02175F3C(void);
extern int func_02168FF0(int idx);

int DWCi_IsFriendByIdxList(int profileID)
{
    int i;
    int id;

    if (*(int *)(func_02175F3C() + 0x68c) == 0)
        return 0;
    for (i = 0; i < *(int *)(func_02175F3C() + 0x6d4); i++) {
        id = func_02168FF0(*(unsigned char *)(func_02175F3C() + i + 0x694));
        if (id > 0 && id == profileID)
            return 1;
    }
    return 0;
}
