/*
 * file:     unit_021BF520_p02.c
 * unit:     yes
 * function: func_021BF880, func_021BF8C0
 * address:  0x021BF880
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C22A4  0x021C22A4  arm  ov114
 *   func_021BFAF0  0x021BFAF0  arm  ov114
 *   DWC_Free       0x0205A1B0  arm
 *   func_021BFA70  0x021BFA70  arm  ov114
 *   func_02059F54  0x02059F54  arm
 */
struct Node;
typedef struct {
    char pad[0x14];
    void *data;
} Entry;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_021C22A4(int request);
extern u8 *func_021BFAF0(u32 key);
extern void DWC_Free(int name, void *ptr, int size);
extern void func_021BFA70(struct Node *x);
extern void func_02059F54(int error, int errorCode);
void func_021BF880(int req);
int func_021BF8C0(int result);


/*
 * sdk:      DWC_CancelGHTTPRequest (dwc_ghttp.o)
 */
void func_021BF880(int req)
{
    Entry *entry;

    func_021C22A4(req);
    entry = (Entry *)func_021BFAF0(req);
    if (entry == 0) {
        return;
    }
    if (entry->data != 0) {
        DWC_Free(6, entry->data, 0);
    }
    func_021BFA70((struct Node *)entry);
}


/*
 * sdk:      DWCi_HandleGHTTPError (libdwcghttp.TWL.HYB.a(dwc_ghttp.o))
 */
int func_021BF8C0(int result)
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
