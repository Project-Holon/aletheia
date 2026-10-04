/*
 * function: func_021678AC
 * address:  0x021678AC
 * packet:   pkt_ov009_021678AC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmWmcbEndDCF (libwcm.TWL.HYB.a wmif.o)
 *
 * symbols:
 *   func_021657C8    0x021657C8  arm  ov009
 *   func_02165A4C    0x02165A4C  arm  ov009
 *   func_02166E5C    0x02166E5C  arm  ov009
 *   func_0208F938    0x0208F938  arm
 *   func_021659B4    0x021659B4  arm  ov009
 *   func_021676E4    0x021676E4  arm  ov009
 */

typedef struct WMEndDCFCallback {
    unsigned short apiid;
    unsigned short errcode;
} WMEndDCFCallback;

typedef struct WCMWork {
    unsigned char pad0[0x12DE];
    unsigned char phase;
    unsigned char pad1[0x12E0 - 0x12DF];
    unsigned char notifyParam[1];
} WCMWork;

extern int func_021657C8(void);
extern void func_02165A4C(unsigned char phase);
extern void func_02166E5C(void);
extern long func_0208F938(void (*callback)(void *), unsigned long arg);
extern void func_021659B4(short result, void *para0, void *para1, long para2);
extern void func_021676E4(void *arg);

void func_021678AC(void *arg)
{
    WCMWork *wcmw;
    long wmResult;
    WMEndDCFCallback *cb;

    cb = arg;
    wcmw = (WCMWork *)func_021657C8();
    switch (cb->errcode) {
    case 0:
        if (wcmw->phase == 0xc) {
            func_02165A4C(0xa);
            func_02166E5C();
            return;
        }
        wmResult = func_0208F938(func_021676E4, 0);
        switch (wmResult) {
        case 2:
            return;
        case 8:
            func_02165A4C(0xc);
            func_021659B4(1, wcmw->notifyParam, 0, 0x4fa);
            return;
        case 3:
            func_02165A4C(0xa);
            func_02166E5C();
            return;
        default:
            func_02165A4C(0xb);
            func_021659B4(7, wcmw->notifyParam, 0, 0x506);
            return;
        }
    case 1:
    case 3:
        func_02165A4C(0xa);
        func_02166E5C();
        return;
    case 2:
    case 4:
    default:
        func_02165A4C(0xb);
        func_021659B4(7, wcmw->notifyParam, 0, 0x519);
        return;
    }
}
