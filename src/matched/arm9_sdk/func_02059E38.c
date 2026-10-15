/*
 * function: DWC_GetLastErrorEx
 * address:  0x02059E38
 * packet:   pkt_02059E38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetLastErrorEx (libdwccommon.TWL.HYB.a dwc_error.o)
 *
 * symbols:
 *   stDwcLastError 0x02146AA4 data a4
 */

typedef struct {
    int error;
    int errorCode;
} DWCErrorInfo;

extern DWCErrorInfo stDwcLastError;

int DWC_GetLastErrorEx(int *errorCode, int *errorType)
{
    if (errorCode != 0)
        *errorCode = stDwcLastError.errorCode;
    if (errorType != 0) {
        switch (stDwcLastError.error) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 8:
            *errorType = 6;
            break;
        case 6:
            *errorType = 3;
            break;
        case 22:
            *errorType = 2;
            break;
        case 7:
            *errorType = 4;
            break;
        case 10:
        case 11:
        case 12:
        case 21:
            *errorType = 1;
            break;
        case 1:
        case 9:
            *errorType = 7;
            break;
        case 13:
            *errorType = 5;
            break;
        case 14:
        case 16:
        case 18:
            *errorType = 6;
            break;
        case 15:
        case 17:
        case 19:
        case 20:
            *errorType = 2;
            break;
        case 0:
        default:
            *errorType = 0;
            break;
        }
    }
    return stDwcLastError.error;
}
