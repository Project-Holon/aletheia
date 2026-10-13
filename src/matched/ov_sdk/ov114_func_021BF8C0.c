/*
 * function: DWCi_HandleGHTTPError
 * address:  0x021BF8C0
 * packet:   pkt_ov114_021BF8C0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HandleGHTTPError (libdwcghttp.TWL.HYB.a(dwc_ghttp.o))
 *
 * symbols:
 *   func_02059F54  0x02059F54  arm
 */

extern void func_02059F54(int error, int errorCode);

int DWCi_HandleGHTTPError(int result)
{
    int errorCode;
    int dwcError;

    dwcError = 7;
    errorCode = -98000;
    if (result == 0)
        return 0;
    switch (result) {
    case -7:
        errorCode += -800;
        break;
    case -6:
        errorCode += -810;
        break;
    case -5:
        errorCode += -840;
        break;
    case -4:
    case -3:
    case -2:
        errorCode += -820;
        break;
    case -1:
        errorCode += -830;
        break;
    case 1:
    case 20:
        dwcError = 9;
        errorCode += -1;
        break;
    case 2:
        errorCode += -840;
        break;
    case 3:
        errorCode += -850;
        break;
    case 4:
        errorCode += -30;
        break;
    case 5:
        errorCode += -50;
        break;
    case 6:
    case 11:
    case 12:
        errorCode += -20;
        break;
    case 7:
        errorCode += -860;
        break;
    case 8:
    case 9:
    case 10:
        errorCode += -870;
        break;
    case 13:
    case 14:
        errorCode += -880;
        break;
    case 15:
        errorCode += -890;
        break;
    case 16:
        errorCode += -900;
        break;
    case 17:
        errorCode += -910;
        break;
    }
    func_02059F54(dwcError, errorCode);
    return result;
}
