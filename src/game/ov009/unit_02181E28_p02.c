/*
 * file:     unit_02181E28_p02.c
 * unit:     yes
 * function: func_02182B68, func_02182C10, func_02182CF0, func_02182D78, func_02182DFC
 * address:  0x02182B68
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   strlen                        0x0209477C arm
 *   gsXmlWriteOpenTag             0x021829AC arm ov009
 *   gsiXmlUtilWriteXmlSafeString  0x0218335C arm ov009
 *   gsXmlWriteCloseTag            0x02182A2C arm ov009
 *   gsUnicodeStringLen            0x0218198C arm ov009
 *   gsiXmlUtilWriteUnicodeString  0x021832DC arm ov009
 *   sprintf                0x02094530 arm
 *   gsiXmlUtilWriteString  0x0218325C arm ov009
 *   g_021A3F54             0x021A3F54 data
 *   gsiInt64ToString       0x0217F130 arm ov009
 *   _f2d                   0x0209BD38 arm
 *   g_021A3F58             0x021A3F58 data
 */
struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern unsigned int strlen(const char *s);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsiXmlUtilWriteXmlSafeString(struct GSIXmlStreamWriter *stream, char *str);
extern int gsUnicodeStringLen(unsigned short *str);
extern int gsiXmlUtilWriteUnicodeString(struct GSIXmlStreamWriter *stream, unsigned short *str);
extern int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str);
extern int sprintf(char *buf, const char *fmt, ...);
extern void gsiInt64ToString(char *theNumberStr, long long theNumber);
int func_02182B68(void *stream, char *namespaceName, char *tag, char *value);
int func_02182C10(void *stream, char *namespaceName, char *tag, unsigned short *value);
int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
int func_02182D78(void *stream, char *namespaceName, char *tag, long long value);
int func_02182DFC(void *stream, char *namespaceName, char *tag, float value);
extern char g_021A3F54[];
extern char g_021A3F58[];


/*
 * sdk:      gsXmlWriteStringElement (gsxml)
 */
int func_02182B68(void *stream, char *namespaceName, char *tag, char *value)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    int len = strlen(value);
    int i;

    for (i = 0; i < len; i++)
    {
        if (((unsigned char *)value)[i] < 0x20 && ((unsigned char *)value)[i] != 9 && ((unsigned char *)value)[i] != 10 && ((unsigned char *)value)[i] != 13)
            return 0;
    }
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteXmlSafeString(writer, value)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}


/*
 * sdk:      gsXmlWriteUnicodeStringElement (gsxml)
 */
int func_02182C10(void *stream, char *namespaceName, char *tag, unsigned short *value)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    int len = gsUnicodeStringLen(value);
    int i;

    for (i = 0; i < len; i++)
    {
        if (value[i] < 0x20)
        {
            if (value[i] != 9 && value[i] != 10 && value[i] != 13)
                return 0;
        }
        else if (value[i] > 0xD7FF && value[i] < 0xE000)
            return 0;
        else if (value[i] > 0xFFFD)
            return 0;
    }
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteUnicodeString(writer, value)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}


/*
 * sdk:      gsXmlWriteIntElement (gsxml)
 */
int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value)
{
    char buf[32];
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;

    sprintf(buf, g_021A3F54, value);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, buf)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}


/*
 * sdk:      gsXmlWriteInt64Element (gsxml)
 */
int func_02182D78(void *stream, char *namespaceName, char *tag, long long value)
{
    char buf[33];
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;

    gsiInt64ToString(buf, value);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, buf)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}


/*
 * sdk:      gsXmlWriteFloatElement (gsxml)
 */
int func_02182DFC(void *stream, char *namespaceName, char *tag, float value)
{
    char buf[32];
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;

    sprintf(buf, g_021A3F58, (double)value);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, buf)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}
