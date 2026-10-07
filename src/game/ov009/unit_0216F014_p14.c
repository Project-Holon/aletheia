/*
 * file:     unit_0216F014_p14.c
 * unit:     yes
 * function: func_02172E18, func_02172E7C
 * address:  0x02172E18
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
 *   func_0216BBDC  0x0216BBDC  arm  ov009
 *   func_02195DC4  0x02195DC4  arm  ov009
 *   func_02176254  0x02176254  arm  ov009
 *   gt2CloseAllConnections  0x02195DE4  arm  ov009
 */
extern int func_02175F3C(void);
extern int *func_0216BBDC(int pid, int flag);
extern void func_02195DC4(int a);
extern int func_02176254(int profileID);
extern void gt2CloseAllConnections(int conn);
int func_02172E18(int profileID);
void func_02172E7C(void);


/*
 * sdk:      DWCi_CloseCancelHostAsync (dwc_match.o)
 */
int func_02172E18(int profileID)
{
    int **connection;
    int ret;

    *(int *)(func_02175F3C() + 0x680) = profileID;
    connection = (int **)func_0216BBDC(profileID, 0);
    if (connection) {
        *(char *)(func_02175F3C() + 0x629) = 1;
        func_02195DC4((int)(*connection));
        *(char *)(func_02175F3C() + 0x629) = 0;
        func_02176254(profileID);
        ret = 1;
    } else {
        func_02176254(profileID);
        ret = 0;
    }
    return ret;
}


/*
 * DWCi_CloseAllConnectionsByTimeout: closes every gt2 connection with the closing flag raised.
 */
void func_02172E7C(void)
{
    ((char *)func_02175F3C())[0x629] = 1;
    gt2CloseAllConnections(**(int **)(func_02175F3C() + 4));
    ((char *)func_02175F3C())[0x629] = 0;
}
