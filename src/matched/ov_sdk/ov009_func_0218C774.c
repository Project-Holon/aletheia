/*
 * function: gpiSetInfoi
 * address:  0x0218C774
 * packet:   pkt_ov009_0218C774
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSetInfoi (libdwcgsgp.TWL.HYB.a(gpiinfo.o))
 *
 * symbols:
 *   gpiSetErrorString  0x02193734  arm
 *   OS_SPrintf         0x02084F40  arm
 *   gpiSendLocalInfo   0x0218C6E4  arm  ov009
 *   gpiSendUserInfo    0x0218C72C  arm  ov009
 *   str15081           0x021A4B24  data
 *   str15083           0x021A4B3C  data
 *   str15091           0x021A4B7C  data
 *   str15094           0x021A4B94  data
 *   str15095           0x021A4B9C  data
 *   str15096           0x021A4BA4  data
 *   str15097           0x021A4BAC  data
 *   str15098           0x021A4BB4  data
 *   str15099           0x021A4BBC  data
 *   str15100           0x021A4BC4  data
 *   str15206           0x021A4C34  data
 *   str15207           0x021A4C48  data
 *   str15208           0x021A4C4C  data
 *   str15209           0x021A4C50  data
 *   str15210           0x021A4C54  data
 *   str15211           0x021A4C58  data
 *   str15212           0x021A4C68  data
 *   str15213           0x021A4C78  data
 *   str15214           0x021A4C84  data
 *   str15215           0x021A4C90  data
 *   str15216           0x021A4CA0  data
 *   str15217           0x021A4CB0  data
 *   str15218           0x021A4CC0  data
 *   str15219           0x021A4CD4  data
 *   str15220           0x021A4CE4  data
 */

typedef int _GPResult;

extern void gpiSetErrorString(void **connection, char *errorString);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern _GPResult gpiSendLocalInfo(void **connection, char *info, char *value);
extern _GPResult gpiSendUserInfo(void **connection, char *info, char *value);

extern char str15081[];
extern char str15083[];
extern char str15091[];
extern char str15094[];
extern char str15095[];
extern char str15096[];
extern char str15097[];
extern char str15098[];
extern char str15099[];
extern char str15100[];
extern char str15206[];
extern char str15207[];
extern char str15208[];
extern char str15209[];
extern char str15210[];
extern char str15211[];
extern char str15212[];
extern char str15213[];
extern char str15214[];
extern char str15215[];
extern char str15216[];
extern char str15217[];
extern char str15218[];
extern char str15219[];
extern char str15220[];

_GPResult gpiSetInfoi(void **connection, int info, int value)
{
    char intValue[16];
    _GPResult __result__;

    switch (info) {
    case 0x708:
        if (value < 0) {
            gpiSetErrorString(connection, str15206);
            return 2;
        }
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15083, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x70B:
        switch (value) {
        case 0x500:
            __result__ = gpiSendLocalInfo(connection, str15091, str15208);
            if (__result__)
                return __result__;
            break;
        case 0x501:
            __result__ = gpiSendLocalInfo(connection, str15091, str15209);
            if (__result__)
                return __result__;
            break;
        case 0x502:
            __result__ = gpiSendLocalInfo(connection, str15091, str15210);
            if (__result__)
                return __result__;
            break;
        default:
            gpiSetErrorString(connection, str15211);
            return 2;
        }
        break;
    case 0x706:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15081, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x70C:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendUserInfo(connection, str15212, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x70D:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendUserInfo(connection, str15213, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x70E:
        OS_SPrintf(intValue, str15207, value / 16);
        __result__ = gpiSendUserInfo(connection, str15214, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x710:
        OS_SPrintf(intValue, str15207, value / 4);
        __result__ = gpiSendUserInfo(connection, str15215, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x712:
        OS_SPrintf(intValue, str15207, value / 4);
        __result__ = gpiSendUserInfo(connection, str15216, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x713:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendUserInfo(connection, str15217, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x714:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendUserInfo(connection, str15218, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x715:
        value = value;
        if (value)
            value = 1;
        OS_SPrintf(intValue, str15207, value);
        __result__ = gpiSendUserInfo(connection, str15219, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x718:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15094, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x719:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15095, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x71A:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15096, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x71B:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15097, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x71C:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15098, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x71D:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15099, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x71E:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15100, intValue);
        if (__result__)
            return __result__;
        break;
    default:
        gpiSetErrorString(connection, str15220);
        return 2;
    }
    return 0;
}
