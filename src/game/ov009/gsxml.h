#ifndef GAME_OV009_GSXML_H
#define GAME_OV009_GSXML_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsxml.c, prototypes copied from their definitions. */

struct GSIXmlString;
struct GSIXmlStreamWriter;
typedef struct GSIXmlString GSIXmlString;
typedef struct GSIXmlStreamWriter GSIXmlStreamWriter;

#include "../ov175/auth_types.h"

int gsUnicodeStringLen(const unsigned short *str);
void *gsXmlCreateStreamWriter(const char **namespaces, int count);
void *gsXmlCreateStreamReader(void);
int gsXmlParseBuffer(void *stream, char *data, int len);
void gsXmlFreeWriter(void **writerRef);
void gsXmlFreeReader(void *stream);
void gsXmlResetReader(void *stream);
int gsXmlCloseWriter(void *stream);
void gsiXmlUtilElementFree(void *elem);
void gsiXmlUtilAttributeFree(void *elem);
char *gsXmlWriterGetData(void *stream);
int gsXmlWriterGetDataLength(void *stream);
int gsiXmlUtilParseName(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
int gsiXmlUtilParseString(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
int gsiXmlUtilDecodeString(char *buffer, int *len);
int gsiXmlUtilParseValue(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
int gsXmlWriteAsciiStringElement(void *stream, char *namespaceName, char *tag, char *value);
int gsXmlWriteUnicodeStringElement(void *stream, char *namespaceName, char *tag, unsigned short *value);
int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
int gsXmlWriteInt64Element(void *stream, char *namespaceName, char *tag, long long value);
int gsXmlWriteFloatElement(void *stream, char *namespaceName, char *tag, float value);
int gsXmlWriteHexBinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
int gsXmlWriteBase64BinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
int gsXmlWriteDateTimeElement(void *stream, char *namespaceName, char *tag, long value);
int gsXmlWriteLargeIntElement(void *stream, char *namespaceName, char *tag, gsLargeInt_t *lint);
int gsiXmlUtilWriteChar(GSIXmlStreamWriter *stream, char ch);
int gsiXmlUtilWriteUnicodeString(GSIXmlStreamWriter *stream, unsigned short *str);
int gsiXmlUtilWriteXmlSafeString(void *stream, char *str);
int gsXmlMoveToStart(void *stream);
int gsXmlMoveToNext(void *stream, char *matchtag);
int gsXmlMoveToParent(void *stream);
int gsXmlMoveToChild(void *stream, char *matchtag);
int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *lenOut);
int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen);
int gsXmlReadChildAsHexBinary(void *stream, char *matchtag, unsigned char *valueOut, int maxLen, int *lenOut);
int gsXmlReadChildAsBase64Binary(void *stream, char *matchtag, unsigned char *valueOut, int *lenOut);
int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
int gsXmlReadChildAsInt64(void *stream, char *matchtag, long long *valueOut);
int gsXmlReadChildAsDateTimeElement(void *stream, char *matchtag, long *valueOut);
int gsXmlReadChildAsFloat(void *stream, char *matchtag, float *valueOut);
int gsXmlReadChildAsLargeInt(void *stream, char *matchtag, int *lintData);
int gsXmlCountChildren(void *stream, char *matchtag);
/* END mkheaders: generated region */

#endif
