/*
 * function: func_0216BD04
 * address:  0x0216BD04
 * packet:   pkt_ov009_0216BD04
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HandleGPError (dwc_main.o)
 *
 * Extra open callee of DWCi_GPErrorCallback (0x0216C08C).
 *
 * symbols:
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   func_0216EB68  0x0216EB68  arm  ov009
 *   func_02168E50  0x02168E50  arm  ov009
 *   g_021AA878     0x021AA878  data
 */

extern char g_021AA878[];
extern void func_0216A3B8(int error, int errorCode);
extern void func_0216EB68(int error, int errorCode);
extern void func_02168E50(int error, int errorCode);

int func_0216BD04(int result)
{
    int errorCode;
    int dwcError;

    if (result == 0) return 0;
    switch (result) {
    case 1: dwcError = 9; errorCode = -1; break;
    case 2: dwcError = 9; errorCode = -2; break;
    case 3: dwcError = 6; errorCode = -10; break;
    case 4: dwcError = 6; errorCode = -20; break;
    }
    switch (*(int *)(*(char **)(g_021AA878 + 4) + 0x24)) {
    case 1:
        errorCode += (int)0xffff11b8;
        func_0216A3B8(dwcError, errorCode);
        break;
    case 2:
        errorCode += (int)0xffff11b8;
        if (*(int *)(*(char **)(g_021AA878 + 4) + 0x94) < 1)
            func_0216A3B8(dwcError, errorCode);
        break;
    case 4:
        errorCode += (int)0xfffec398;
        func_0216EB68(dwcError, errorCode);
        break;
    default:
        errorCode += (int)0xfffe9c88;
        break;
    }
    func_02168E50(dwcError, errorCode);
    return result;
}
