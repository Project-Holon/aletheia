/*
 * function: gpiSetInfos
 * address:  0x0218CC48
 * packet:   pkt_ov009_0218CC48
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSetInfos (libdwcgsgp.TWL.HYB.a(gpiinfo.o))
 *
 * symbols:
 *   gpiSetErrorString  0x02193734  arm
 *   strzcpy            0x0219327C  arm
 *   gpiSendLocalInfo   0x0218C6E4  arm  ov009
 *   _strlwr            0x0217F21C  arm  ov009
 *   gpiSendUserInfo    0x0218C72C  arm  ov009
 *   gpiEncodeString    0x02193748  arm
 *   strlen             0x0209477C  arm
 *   gsiSafeStrcpyA     0x021803BC  arm
 *   atoi               0x020964E0  arm
 *   gpiSetInfoi        0x0218C774  arm  ov009
 *   str15341           0x021A4CF4  data
 *   str15076           0x021A4AEC  data
 *   str15077           0x021A4AF4  data
 *   str15078           0x021A4B04  data
 *   str15342           0x021A4D04  data
 *   str15079           0x021A4B0C  data
 *   str15080           0x021A4B18  data
 *   str15082           0x021A4B30  data
 *   str15083           0x021A4B3C  data
 *   str15343           0x021A4D14  data
 *   str15084           0x021A4B48  data
 *   __upper_mapC       0x020A615C  data
 *   str15091           0x021A4B7C  data
 *   str15081           0x021A4B24  data
 *   str15344           0x021A4D2C  data
 *   str15345           0x021A4D40  data
 *   str15346           0x021A4D54  data
 *   str15093           0x021A4B8C  data
 *   str15094           0x021A4B94  data
 *   str15095           0x021A4B9C  data
 *   str15096           0x021A4BA4  data
 *   str15097           0x021A4BAC  data
 *   str15098           0x021A4BB4  data
 *   str15099           0x021A4BBC  data
 *   str15100           0x021A4BC4  data
 *   str15220           0x021A4CE4  data
 */

typedef int _GPResult;

extern void gpiSetErrorString(void **connection, char *errorString);
extern void strzcpy(char *dest, char *src, unsigned long len);
extern _GPResult gpiSendLocalInfo(void **connection, char *info, char *value);
extern char *_strlwr(char *string);
extern _GPResult gpiSendUserInfo(void **connection, char *info, char *value);
extern void gpiEncodeString(char *unencodedString, char *encodedString);
extern int strlen(char *s);
extern unsigned long gsiSafeStrcpyA(char *dst, char *src, unsigned long size);
extern int atoi(char *s);
extern _GPResult gpiSetInfoi(void **connection, int info, int value);

extern char str15341[];
extern char str15076[];
extern char str15077[];
extern char str15078[];
extern char str15342[];
extern char str15079[];
extern char str15080[];
extern char str15082[];
extern char str15083[];
extern char str15343[];
extern char str15084[];
extern unsigned char __upper_mapC[];
extern char str15091[];
extern char str15081[];
extern char str15344[];
extern char str15345[];
extern char str15346[];
extern char str15093[];
extern char str15094[];
extern char str15095[];
extern char str15096[];
extern char str15097[];
extern char str15098[];
extern char str15099[];
extern char str15100[];
extern char str15220[];

_GPResult gpiSetInfos(void **connection, int info, char *value)
{
    char *iconnection;
    char passwordenc[45];
    char buffer[256];
    char sex;
    _GPResult __result__;

    iconnection = (char *)*connection;
    if (value == 0) {
        gpiSetErrorString(connection, str15341);
        return 2;
    }

    switch (info) {
    case 0x700:
        if (value[0] == 0) {
            gpiSetErrorString(connection, str15341);
            return 2;
        }
        strzcpy(buffer, value, 0x1f);
        strzcpy(iconnection + 0x110, buffer, 0x1f);
        __result__ = gpiSendLocalInfo(connection, str15076, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x701:
        if (value[0] == 0) {
            gpiSetErrorString(connection, str15341);
            return 2;
        }
        strzcpy(buffer, value, 0x15);
        strzcpy(iconnection + 0x12f, buffer, 0x15);
        __result__ = gpiSendLocalInfo(connection, str15077, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x702:
        if (value[0] == 0) {
            gpiSetErrorString(connection, str15341);
            return 2;
        }
        strzcpy(buffer, value, 0x33);
        _strlwr(buffer);
        strzcpy(iconnection + 0x144, buffer, 0x33);
        __result__ = gpiSendUserInfo(connection, str15078, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x703:
        if (value[0] == 0) {
            gpiSetErrorString(connection, str15341);
            return 2;
        }
        strzcpy(buffer, value, 0x1f);
        strzcpy(iconnection + 0x177, buffer, 0x1f);
        gpiEncodeString(iconnection + 0x177, passwordenc);
        __result__ = gpiSendUserInfo(connection, str15342, passwordenc);
        if (__result__)
            return __result__;
        break;
    case 0x704:
        strzcpy(buffer, value, 0x1f);
        __result__ = gpiSendLocalInfo(connection, str15079, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x705:
        strzcpy(buffer, value, 0x1f);
        __result__ = gpiSendLocalInfo(connection, str15080, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x707:
        strzcpy(buffer, value, 0x4c);
        __result__ = gpiSendLocalInfo(connection, str15082, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x708:
        strzcpy(buffer, value, 0xb);
        __result__ = gpiSendLocalInfo(connection, str15083, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x709:
        if (strlen(value) != 2) {
            gpiSetErrorString(connection, str15343);
            return 2;
        }
        strzcpy(buffer, value, 3);
        __result__ = gpiSendLocalInfo(connection, str15084, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x70B:
        {
            int c;
            c = value[0];
            if (c >= 0 && c < 0x80)
                c = __upper_mapC[c];
            sex = c;
        }
        if (sex == 'M')
            buffer[0] = '0';
        else if (sex == 'F')
            buffer[0] = '1';
        else
            buffer[0] = '2';
        buffer[1] = 0;
        __result__ = gpiSendLocalInfo(connection, str15091, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x706:
        gsiSafeStrcpyA(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15081, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x70D:
        __result__ = gpiSetInfoi(connection, 0x70D, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x70E:
        __result__ = gpiSetInfoi(connection, 0x70E, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x70F:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15344, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x710:
        __result__ = gpiSetInfoi(connection, 0x710, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x711:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15345, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x712:
        __result__ = gpiSetInfoi(connection, 0x712, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x714:
        __result__ = gpiSetInfoi(connection, 0x714, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x715:
        __result__ = gpiSetInfoi(connection, 0x715, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x716:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15346, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x717:
        strzcpy(buffer, value, 0x33);
        __result__ = gpiSendLocalInfo(connection, str15093, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x718:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15094, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x719:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15095, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x71A:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15096, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x71B:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15097, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x71C:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15098, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x71D:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15099, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x71E:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15100, buffer);
        if (__result__)
            return __result__;
        break;
    default:
        gpiSetErrorString(connection, str15220);
        return 2;
    }
    return 0;
}


