/*
 * function: func_02166B2C
 * address:  0x02166B2C
 * packet:   pkt_ov009_02166B2C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_WmifConnectAsync (libwcm.TWL.HYB.a wmif.o)
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02090DEC  0x02090DEC  arm
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02166F24  0x02166F24  arm  ov009
 *
 * Starts a WM connection by setting the life times, then maps the WM result to a WCM result and phase.
 */

typedef struct WCMWork {
    unsigned char pad0[0x12DA];
    unsigned short notify;
    unsigned char pad1[1];
    unsigned char resetting;
    unsigned char phase;
    unsigned char pad2[0x2F];
    unsigned short field130E;
    unsigned short field1310;
} WCMWork;

extern WCMWork *func_021657C8(void);
extern long func_02090DEC(void (*callback)(void *), unsigned short tableNumber, unsigned short camLifeTime, unsigned short frameLifeTime, unsigned short mpLifeTime);
extern void func_02165A4C(unsigned char phase);
extern void func_02166F24(void *arg);

long func_02166B2C(void)
{
    WCMWork *wcmw;
    long wmResult;

    wcmw = func_021657C8();
    if (wcmw->phase == 3) {
        wcmw->field1310 = wcmw->field130E | 3;
    }
    wmResult = func_02090DEC(func_02166F24, 0xFFFF, 0x50, 0xFFFF, 0xFFFF);
    switch (wmResult) {
    case 2:
        func_02165A4C(8);
        wcmw->notify = 5;
        break;
    case 8:
        return 4;
    case 3:
    default:
        func_02165A4C(11);
        return 7;
    }
    return 3;
}
