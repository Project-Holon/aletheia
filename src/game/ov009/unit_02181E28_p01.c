/*
 * file:     unit_02181E28_p01.c
 * unit:     yes
 * function: func_0218263C, func_0218290C, func_021829AC, func_02182A2C, func_02182AC0
 * address:  0x0218263C
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
 *   func_020949F4                    0x020949f4 arm
 *   func_02094A28                    0x02094a28 arm
 *   func_0208CF34                    0x0208cf34 arm
 *   func_020964E0                    0x020964e0 arm
 *   func_02092364                    0x02092364 arm
 *   func_020923B0                    0x020923b0 arm
 *   g_021A3F1C                       0x021a3f1c data
 *   g_021A3F24                       0x021a3f24 data
 *   g_021A3F2C                       0x021a3f2c data
 *   g_021A3F34                       0x021a3f34 data
 *   g_021A3F3C                       0x021a3f3c data
 *   g_021A3F44                       0x021a3f44 data
 *   g_021A3F48                       0x021a3f48 data
 *   g_021A3F50                       0x021a3f50 data
 *   gsiXmlUtilSkipWhiteSpace  0x02181E28 arm ov009
 *   gsiXmlUtilDecodeString    0x0218263C arm ov009
 *   gsiXmlUtilWriteChar    0x02183210 arm ov009
 *   gsiXmlUtilWriteString  0x0218325C arm ov009
 *   strlen                        0x0209477C arm
 *   gsXmlWriteOpenTag             0x021829AC arm ov009
 *   gsiXmlUtilWriteXmlSafeString  0x0218335C arm ov009
 *   gsXmlWriteCloseTag            0x02182A2C arm ov009
 */
typedef unsigned char  u8;

typedef unsigned int   u32;

struct GSIXmlString
{
    char * string;  /* 0x00 */
    int length;     /* 0x04 */
};

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern int func_020949F4(const u8 *s1, const u8 *s2, unsigned int n);
extern char *func_02094A28(const char *s, int c);
extern int func_0208CF34(const char *src, const char *fmt, ...);
extern int func_020964E0(u32 a0);
extern void *func_02092364(void *dst, const void *src, unsigned int n);
extern void *func_020923B0(void *dst, int c, unsigned int n);
extern int gsiXmlUtilSkipWhiteSpace(void *stream, char *buffer, int len, int *pos);
extern int gsiXmlUtilDecodeString(char *buffer, int *len);
extern int gsiXmlUtilWriteChar(struct GSIXmlStreamWriter *stream, char ch);
extern int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str);
extern unsigned int strlen(const char *s);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsiXmlUtilWriteXmlSafeString(struct GSIXmlStreamWriter *stream, char *str);
int func_0218263C(char *buffer, int *len);
int func_0218290C(void *stream, char *buffer, int len, int *pos, struct GSIXmlString *strOut);
int func_021829AC(void *stream, char *namespaceName, char *tag);
int func_02182A2C(void *stream, char *namespaceName, char *tag);
int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern char g_021A3F1C[];       /* "&amp;" */
extern char g_021A3F24[];       /* "&quot;" */
extern char g_021A3F2C[];       /* "&apos;" */
extern char g_021A3F34[];       /* "&lt;" */
extern char g_021A3F3C[];       /* "&gt;" */
extern char g_021A3F44[];       /* "&#x" */
extern char g_021A3F48[];       /* "%08x" */
extern char g_021A3F50[];       /* "&#" */


/*
 * sdk:      gsiXmlUtilDecodeString (gsxml.o, static)
 *
 * notes:    closed by compiling the vendor's own body from the GameSpy
 *           upstream (scratch/U2/gs/src/GameSpy/common/gsXML.c). The
 *           three-way register rotation that parked this row (image
 *           readPos r4, len r5, buffer r6) is fixed by the vendor's
 *           `int charsToRemove = 0;` declared *inside* the loop with an
 *           initialiser, plus the initialised locals (`char ch = ' ';`,
 *           `int i = 0;`, `unsigned int mask = 0xFF000000;`) and the
 *           `buffer[readPos++] = ...` post-increment form. The earlier
 *           draft hoisted charsToRemove out of the loop uninitialised,
 *           which lengthened its live range and rotated r4/r5/r6.
 *           The `%08x` vs `%x` string spelling is irrelevant (ABS32).
 */
int func_0218263C(char *buffer, int *len)
{
	int readPos = 0;

	while(readPos < *len)
	{
		int charsToRemove = 0;

		if (buffer[readPos] != '&')
		{
			readPos++;
			continue;
		}

		if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F1C, 5)==0)
		{
			buffer[readPos++] = '&';
			charsToRemove = 5-1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F24, 6)==0)
		{
			buffer[readPos++] = '"';
			charsToRemove = 6-1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F2C, 6)==0)
		{
			buffer[readPos++] = '\'';
			charsToRemove = 6-1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F34, 4)==0)
		{
			buffer[readPos++] = '<';
			charsToRemove = 4-1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F3C, 4)==0)
		{
			buffer[readPos++] = '>';
			charsToRemove = 4-1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F44, 3)==0)
		{
			unsigned int digitValue = 0;
			char ch = ' ';
			int haveWritten = 0;
			int i = 0;
			unsigned int mask = 0xFF000000;

			char * digitEnd = func_02094A28(&buffer[readPos+3], ';');
			if (digitEnd == 0)
				return 0;
			if (digitEnd - &buffer[readPos+3] > 8)
				return 0;

			func_0208CF34(&buffer[readPos+3], g_021A3F48, &digitValue);

			for (i=0; i < 4; i++)
			{
				ch = (char)((digitValue & mask) >> ((3-i)*8));
				if (haveWritten || ch != 0x00)
				{
					buffer[readPos++] = ch;
					haveWritten = 1;
				}
				mask = mask >> 8;
			}

			charsToRemove = digitEnd - &buffer[readPos] + 1;
		}
		else if (func_020949F4((const u8 *)(&buffer[readPos]), (const u8 *)g_021A3F50, 2)==0)
		{
			unsigned int digitValue = 0;
			char ch = ' ';
			int haveWritten = 0;
			int i = 0;
			unsigned int mask = 0xFF000000;

			char * digitEnd = func_02094A28(&buffer[readPos+2], ';');
			if (digitEnd == 0)
				return 0;

			digitValue = (unsigned int)func_020964E0((u32)(&buffer[readPos+2]));

			for (i=0; i < 4; i++)
			{
				ch = (char)((digitValue & mask) >> ((3-i)*8));
				if (haveWritten || ch != 0x00)
				{
					buffer[readPos++] = ch;
					haveWritten = 1;
				}
				mask = mask >> 8;
			}

			charsToRemove = digitEnd - &buffer[readPos] + 1;
		}
		else
			return 0;

		func_02092364(&buffer[readPos], &buffer[readPos+charsToRemove], (unsigned int)(*len-(readPos+charsToRemove)));
		func_020923B0(&buffer[*len-charsToRemove], ' ', (unsigned int)charsToRemove);
		(*len) -= charsToRemove;
	}

	return 1;
}


/*
 * sdk:      gsiXmlUtilParseValue (gsxml)
 */
int func_0218290C(void *stream, char *buffer, int len, int *pos, struct GSIXmlString *strOut)
{
    char *strStart = 0;

    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if (buffer[*pos] != '<')
    {
        strStart = &buffer[*pos];
        strOut->string = strStart;
    }
    while (*pos < len)
    {
        if (buffer[*pos] == '<')
            return gsiXmlUtilDecodeString(strStart, &strOut->length) != 0;
        (*pos)++;
        strOut->length++;
    }
    return 0;
}


/*
 * sdk:      gsXmlWriteOpenTag (gsxml)
 */
int func_021829AC(void *stream, char *namespaceName, char *tag)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    if (!(gsiXmlUtilWriteChar(writer, '<')
        && gsiXmlUtilWriteString(writer, namespaceName)
        && gsiXmlUtilWriteChar(writer, ':')
        && gsiXmlUtilWriteString(writer, tag)
        && gsiXmlUtilWriteChar(writer, '>')))
        return 0;
    return 1;
}


/*
 * sdk:      gsXmlWriteCloseTag (gsxml)
 */
int func_02182A2C(void *stream, char *namespaceName, char *tag)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    if (!(gsiXmlUtilWriteChar(writer, '<')
        && gsiXmlUtilWriteChar(writer, '/')
        && gsiXmlUtilWriteString(writer, namespaceName)
        && gsiXmlUtilWriteChar(writer, ':')
        && gsiXmlUtilWriteString(writer, tag)
        && gsiXmlUtilWriteChar(writer, '>')))
        return 0;
    return 1;
}


/*
 * sdk:      gsXmlWriteAsciiStringElement (gsxml)
 */
int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value)
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
