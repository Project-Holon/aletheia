/*
 * function: func_0218263C
 * address:  0x0218263C
 * packet:   pkt_ov009_0218263C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 */

typedef unsigned char  u8;
extern int func_020949F4(const u8 *s1, const u8 *s2, unsigned int n);
extern char *func_02094A28(const char *s, int c);
extern int func_0208CF34(const char *src, const char *fmt, ...);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern void *func_02092364(void *dst, const void *src, unsigned int n);
extern void *func_020923B0(void *dst, int c, unsigned int n);
extern char g_021A3F1C[];       /* "&amp;" */
extern char g_021A3F24[];       /* "&quot;" */
extern char g_021A3F2C[];       /* "&apos;" */
extern char g_021A3F34[];       /* "&lt;" */
extern char g_021A3F3C[];       /* "&gt;" */
extern char g_021A3F44[];       /* "&#x" */
extern char g_021A3F48[];       /* "%08x" */
extern char g_021A3F50[];       /* "&#" */

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
