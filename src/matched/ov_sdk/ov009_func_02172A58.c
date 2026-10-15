/*
 * function: DWCi_FinishCancelMatch
 * address:  0x02172A58
 * packet:   pkt_ov009_02172A58
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FinishCancelMatch (dwc_match.o)
 *
 * symbols:
 *   DWCi_GPSetServerStatus  0x0216F20C  arm  ov009
 *   func_02173D28  0x02173D28  arm  ov009
 *   DWCi_CloseMatch  0x0216F6C0  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_GetFriendListIndex  0x02169038  arm  ov009
 */

extern int DWCi_GPSetServerStatus(int status);
extern int func_02173D28(int gpResult);
extern void DWCi_CloseMatch(void);
extern int func_02175F3C(void);
extern int DWCi_GetFriendListIndex(int profileID);

void DWCi_FinishCancelMatch(void)
{
    int gpResult;
    int a = 1;
    int b;

    gpResult = DWCi_GPSetServerStatus(a);
    if (func_02173D28(gpResult))
        return;
    DWCi_CloseMatch();
    if (*(int *)(func_02175F3C() + 0x680) == 0) {
        if (*(unsigned char *)(func_02175F3C() + 0x14) != 2)
            a = 0;
    }
    b = *(int *)(func_02175F3C() + 0x680) == 0;
    {
        char *m = (char *)func_02175F3C();

        (*(int (**)(int, int, int, int, int, int))(m + 0x770))(0, 1, b, a, DWCi_GetFriendListIndex(*(int *)(func_02175F3C() + 0x680)), *(int *)(func_02175F3C() + 0x774));
    }
    *(unsigned char *)(func_02175F3C() + 0x62a) = 0;
}
