/*
 * function: gsiXmlUtilDecodeString
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
 *   strncmp                    0x020949f4 arm
 *   strchr                    0x02094a28 arm
 *   func_0208CF34                    0x0208cf34 arm
 *   atoi                    0x020964e0 arm
 *   memmove                    0x02092364 arm
 *   MSL_C_LIB_MemsetPtr                    0x020923b0 arm
 *   gGsXmlEntityAmp                       0x021a3f1c data
 *   gGsXmlEntityQuot                       0x021a3f24 data
 *   gGsXmlEntityApos                       0x021a3f2c data
 *   gGsXmlEntityLt                       0x021a3f34 data
 *   gGsXmlEntityGt                       0x021a3f3c data
 *   gGsXmlEntityHexPrefix                       0x021a3f44 data
 *   gGsXmlHex8Format                       0x021a3f48 data
 *   gGsXmlEntityDecPrefix                       0x021a3f50 data
 */

typedef unsigned char  u8;
extern int strncmp(const u8 *s1, const u8 *s2, unsigned int n);
extern char *strchr(const char *s, int c);
extern int func_0208CF34(const char *src, const char *fmt, ...);
typedef unsigned int   u32;
extern int atoi(u32 a0);
extern void *memmove(void *dst, const void *src, unsigned int n);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int c, unsigned int n);
extern char gGsXmlEntityAmp[];       /* "&amp;" */
extern char gGsXmlEntityQuot[];       /* "&quot;" */
extern char gGsXmlEntityApos[];       /* "&apos;" */
extern char gGsXmlEntityLt[];       /* "&lt;" */
extern char gGsXmlEntityGt[];       /* "&gt;" */
extern char gGsXmlEntityHexPrefix[];       /* "&#x" */
extern char gGsXmlHex8Format[];       /* "%08x" */
extern char gGsXmlEntityDecPrefix[];       /* "&#" */

int gsiXmlUtilDecodeString(char *buffer, int *len)
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

		if (strncmp((const u8 *)(&buffer[readPos]), (const u8 *)gGsXmlEntityAmp, 5)==0)
		{
			buffer[readPos++] = '&';
			charsToRemove = 5-1;
		}
		else if (strncmp((const u8 *)(&buffer[readPos]), (const u8 *)gGsXmlEntityQuot, 6)==0)
		{
			buffer[readPos++] = '"';
			charsToRemove = 6-1;
		}
		else if (strncmp((const u8 *)(&buffer[readPos]), (const u8 *)gGsXmlEntityApos, 6)==0)
		{
			buffer[readPos++] = '\'';
			charsToRemove = 6-1;
		}
		else if (strncmp((const u8 *)(&buffer[readPos]), (const u8 *)gGsXmlEntityLt, 4)==0)
		{
			buffer[readPos++] = '<';
			charsToRemove = 4-1;
		}
		else if (strncmp((const u8 *)(&buffer[readPos]), (const u8 *)gGsXmlEntityGt, 4)==0)
		{
			buffer[readPos++] = '>';
			charsToRemove = 4-1;
		}
		else if (strncmp((const u8 *)(&buffer[readPos]), (const u8 *)gGsXmlEntityHexPrefix, 3)==0)
		{
			unsigned int digitValue = 0;
			char ch = ' ';
			int haveWritten = 0;
			int i = 0;
			unsigned int mask = 0xFF000000;

			char * digitEnd = strchr(&buffer[readPos+3], ';');
			if (digitEnd == 0)
				return 0;
			if (digitEnd - &buffer[readPos+3] > 8)
				return 0;

			func_0208CF34(&buffer[readPos+3], gGsXmlHex8Format, &digitValue);

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
		else if (strncmp((const u8 *)(&buffer[readPos]), (const u8 *)gGsXmlEntityDecPrefix, 2)==0)
		{
			unsigned int digitValue = 0;
			char ch = ' ';
			int haveWritten = 0;
			int i = 0;
			unsigned int mask = 0xFF000000;

			char * digitEnd = strchr(&buffer[readPos+2], ';');
			if (digitEnd == 0)
				return 0;

			digitValue = (unsigned int)atoi((u32)(&buffer[readPos+2]));

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

		memmove(&buffer[readPos], &buffer[readPos+charsToRemove], (unsigned int)(*len-(readPos+charsToRemove)));
		MSL_C_LIB_MemsetPtr(&buffer[*len-charsToRemove], ' ', (unsigned int)charsToRemove);
		(*len) -= charsToRemove;
	}

	return 1;
}
