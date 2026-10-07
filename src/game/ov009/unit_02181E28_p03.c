/*
 * file:     unit_02181E28_p03.c
 * unit:     yes
 * function: func_02182E90, func_02182F40
 * address:  0x02182E90
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
 *   gsXmlWriteOpenTag    0x021829AC arm ov009
 *   sprintf              0x02094530 arm
 *   gsiXmlUtilWriteChar  0x02183210 arm ov009
 *   gsXmlWriteCloseTag   0x02182A2C arm ov009
 *   g_021A3F5C           0x021A3F5C data
 *   B64InitEncodeStream    0x0217FC68 arm ov009
 *   B64EncodeStream        0x0217FC70 arm ov009
 *   gsiXmlUtilWriteString  0x0218325C arm ov009
 */
struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

typedef struct {
    int f0;
    int f4;
    int f8;
} B64StreamData;

extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int sprintf(char *buf, const char *fmt, ...);
extern int gsiXmlUtilWriteChar(struct GSIXmlStreamWriter *stream, char ch);
extern int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str);
extern void B64InitEncodeStream(B64StreamData *data, unsigned char *input, int len, int type);
extern int B64EncodeStream(B64StreamData *data, char *output);
int func_02182E90(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
int func_02182F40(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern char g_021A3F5C[];


/*
 * sdk:      gsXmlWriteHexBinaryElement (gsxml)
 */
int func_02182E90(void *stream, char *namespaceName, char *tag, unsigned char *data, int len)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    int pos = 0;
    char hex[3];

    hex[2] = 0;
    if (!gsXmlWriteOpenTag(writer, namespaceName, tag))
        return 0;
    for (pos = 0; pos < len; )
    {
        sprintf(hex, g_021A3F5C, data[pos]);
        pos++;
        if (!gsiXmlUtilWriteChar(writer, hex[0]))
            return 0;
        if (!gsiXmlUtilWriteChar(writer, hex[1]))
            return 0;
    }
    if (!gsXmlWriteCloseTag(writer, namespaceName, tag))
        return 0;
    return 1;
}


/*
 * sdk:      gsXmlWriteBase64BinaryElement (gsxml)
 */
int func_02182F40(void *stream, char *namespaceName, char *tag, unsigned char *data, int len)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    B64StreamData streamData;
    char b64[5];

    if (!gsXmlWriteOpenTag(writer, namespaceName, tag))
        return 0;
    B64InitEncodeStream(&streamData, data, len, 0);
    while (B64EncodeStream(&streamData, b64))
    {
        b64[4] = 0;
        if (!gsiXmlUtilWriteString(writer, b64))
            return 0;
    }
    if (!gsXmlWriteCloseTag(writer, namespaceName, tag))
        return 0;
    return 1;
}
