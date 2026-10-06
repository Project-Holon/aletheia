/*
 * file:     unit_02059E18.c
 * unit:     yes
 * function: func_02059E18, func_02059E38, func_02059F18
 * address:  0x02059E18
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   stDwcError  0x02146AA4  data  a4
 *   stDwcLastError 0x02146AA4 data a4
 */
typedef struct {
    int lastError;
    int errorCode;
} DWCErrorState;

typedef struct {
    int error;
    int errorCode;
} DWCErrorInfo;

int DWC_GetLastError(int *errorCode);
int func_02059E38(int *errorCode, int *errorType);
void DWC_ClearError(void);
extern DWCErrorInfo stDwcLastError;


static DWCErrorState stDwcError;


int DWC_GetLastError(int *errorCode)
{
    if (errorCode != 0) {
        *errorCode = stDwcError.errorCode;
    }
    return stDwcError.lastError;
}


/*
 * sdk:      DWC_GetLastErrorEx (libdwccommon.TWL.HYB.a dwc_error.o)
 */
int func_02059E38(int *errorCode, int *errorType)
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


void DWC_ClearError(void)
{
    if (stDwcError.lastError != 9) {
        stDwcError.lastError = 0;
        stDwcError.errorCode = 0;
    }
}
