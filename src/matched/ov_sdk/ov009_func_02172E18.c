/*
 * function: func_02172E18
 * address:  0x02172E18
 * packet:   pkt_ov009_02172E18
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CloseCancelHostAsync (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0216BBDC  0x0216BBDC  arm  ov009
 *   func_02195DC4  0x02195DC4  arm  ov009
 *   func_02176254  0x02176254  arm  ov009
 */

extern int func_02175F3C(void);
extern int **func_0216BBDC(int profileID, int flag);
extern void func_02195DC4(int *connection);
extern int func_02176254(int profileID);

int func_02172E18(int profileID)
{
    int **connection;
    int ret;

    *(int *)(func_02175F3C() + 0x680) = profileID;
    connection = func_0216BBDC(profileID, 0);
    if (connection) {
        *(char *)(func_02175F3C() + 0x629) = 1;
        func_02195DC4(*connection);
        *(char *)(func_02175F3C() + 0x629) = 0;
        func_02176254(profileID);
        ret = 1;
    } else {
        func_02176254(profileID);
        ret = 0;
    }
    return ret;
}
