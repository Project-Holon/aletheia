/*
 * function: func_0216A42C
 * address:  0x0216A42C
 * packet:   pkt_ov009_0216A42C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CloseLogin (dwc_login.o)
 *
 * Extra open callee of DWCi_StopLogin (0x0216A3B8).
 *
 * symbols:
 *   func_02178EF4  0x02178EF4  arm  ov009
 *   stpLoginCnt    0x021AA874  data
 */

extern char *stpLoginCnt;
extern void func_02178EF4(void);

void func_0216A42C(void)
{
    if (stpLoginCnt == 0) return;
    func_02178EF4();
    *(int *)(stpLoginCnt + 4) = 0;
    *(int *)(stpLoginCnt + 0x30) = 0;
}
