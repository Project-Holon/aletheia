/*
 * function: func_0218335C
 * address:  0x0218335C
 * packet:   pkt_ov009_0218335C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiXmlUtilWriteXmlSafeString (libdwcgscommon.TWL.HYB.a gsxml.o)
 *
 * symbols:
 *   strlen         0x0209477c  arm
 *   func_0218325C  0x0218325c  arm   ov009
 *   sprintf        0x02094530  arm
 *   func_02183210  0x02183210  arm   ov009
 *   g_021A3F2C     0x021a3f2c  data
 *   g_021A3F1C     0x021a3f1c  data
 *   g_021A3F24     0x021a3f24  data
 *   g_021A3F34     0x021a3f34  data
 *   g_021A3F3C     0x021a3f3c  data
 *   g_021A3F84     0x021a3f84  data
 *   g_021A3F8C     0x021a3f8c  data
 */

extern unsigned int strlen(const char *);
extern int sprintf(char *, const char *, ...);
extern int func_0218325C(void *, char *);
extern int func_02183210(void *, char);
extern char g_021A3F1C[];
extern char g_021A3F24[];
extern char g_021A3F2C[];
extern char g_021A3F34[];
extern char g_021A3F3C[];
extern char g_021A3F84[];
extern char g_021A3F8C[];

int func_0218335C(void *stream, char *str)
{
    int strLen;
    int pos;
    int result;
    char numeric[7];

    strLen = strlen(str);
    for (pos = 0; pos < strLen; pos++) {
        char c = str[pos];
        if (c == '&') {
            result = func_0218325C(stream, g_021A3F1C);
        } else if (c == '\'') {
            result = func_0218325C(stream, g_021A3F2C);
        } else if (c == '"') {
            result = func_0218325C(stream, g_021A3F24);
        } else if (c == '<') {
            result = func_0218325C(stream, g_021A3F34);
        } else if (c == '>') {
            result = func_0218325C(stream, g_021A3F3C);
        } else if (c == ' ') {
            result = func_0218325C(stream, g_021A3F84);
        } else if (c < ' ' || (unsigned char)c > 0x7f) {
            sprintf(numeric, g_021A3F8C, (unsigned char)c);
            numeric[6] = 0;
            result = func_0218325C(stream, numeric);
        } else {
            result = func_02183210(stream, c);
        }
        if (!result)
            return 0;
    }
    return 1;
}
