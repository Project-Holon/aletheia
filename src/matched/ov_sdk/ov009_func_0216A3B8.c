/*
 * function: func_0216A3B8
 * address:  0x0216A3B8
 * packet:   pkt_ov009_0216A3B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_StopLogin (dwc_login.o)
 *
 * Extra open callee of DWCi_HandleGPError (0x0216BD04).
 *
 * symbols:
 *   func_02059F54  0x02059F54  arm
 *   func_0216A42C  0x0216A42C  arm  ov009
 *   stpLoginCnt    0x021AA874  data
 */

extern char *stpLoginCnt;
extern void func_02059F54(int error, int errorCode);
extern void func_0216A42C(void);

void func_0216A3B8(int error, int errorCode)
{
    if (stpLoginCnt == 0 || error == 0) return;
    func_02059F54(error, errorCode);
    if (*(int *)(stpLoginCnt + 0x14) != 0) {
        (*(void (*)(int, int, int))(*(int *)(stpLoginCnt + 0x14)))(error, 0,
            *(int *)(stpLoginCnt + 0x18));
    }
    func_0216A42C();
}
