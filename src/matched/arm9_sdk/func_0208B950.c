/*
 * function: PMi_CommonCallback
 * address:  0x0208B950
 * packet:   pkt_0208B950
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PMi_CommonCallback (libspi.TWL.HYB.a pm.o)
 *
 * symbols:
 *   PMi_CallCallbackAndUnlock      0x0208B84C  arm
 *   PMi_ProceedToExit              0x027314A4  arm
 *   s_02153000                     0x02153000  data
 *   PMi_BatteryLowCallbackInfo     0x02732FB0  data
 *
 * The DWARF lists (data, err); the body reads r1 and r2, so this is the
 * 3-argument PXI FIFO callback. The pool word at 0x02153000 is the pm.o bss
 * base; the object addresses its statics from it (+0x08, +0x3c). The two
 * switches keep their explicit no-op case labels (0x62; 1, 2, 3) so that
 * both lower to jump tables.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u32 vu32;
typedef int BOOL;

typedef struct PMiGenCallbackInfo {
    void (*callback)(void *);
    void *arg;
    int priority;
    struct PMiGenCallbackInfo *next;
} PMiGenCallbackInfo;

struct PMiWork {
    u8 pad_00[8];
    u32 f08;
    u8 pad_0c[0x30];
    u16 *f3c;
};

extern struct PMiWork s_02153000;
extern PMiGenCallbackInfo PMi_BatteryLowCallbackInfo;

void PMi_CallCallbackAndUnlock(u32 result);
void PMi_ProceedToExit(int factor);

void PMi_CommonCallback(int tag, u32 data, BOOL err)
{
    u16 command;
    u16 pxiResult;
    BOOL callCallback = 1;

    command = (u16)((data & 0x7f00) >> 8);
    pxiResult = (u16)(data & 0xff);

    if (err) {
        PMi_CallCallbackAndUnlock((command == 0x61 || command == 0x62) ? 1 : 2);
        return;
    }

    switch (command) {
    case 0x61:
        if (s_02153000.f3c) {
            *s_02153000.f3c = pxiResult;
        }
        pxiResult = 0;
        break;
    case 0x60:
        pxiResult = 0;
        break;
    case 0x62:
        break;
    case 0x63:
        s_02153000.f08 = 1;
        break;
    case 0x70:
        switch (pxiResult) {
        case 0:
            PMi_ProceedToExit(1);
            *(vu32 *)0x02FFF684 = 1;
            break;
        case 1:
        case 2:
        case 3:
            break;
        case 4:
            if (PMi_BatteryLowCallbackInfo.callback) {
                PMi_BatteryLowCallbackInfo.callback(PMi_BatteryLowCallbackInfo.arg);
            }
            break;
        case 5:
            PMi_ProceedToExit(2);
            *(vu32 *)0x02FFF684 = 1;
            break;
        }
        callCallback = 0;
        break;
    }

    if (callCallback) {
        PMi_CallCallbackAndUnlock(pxiResult);
    }
}
