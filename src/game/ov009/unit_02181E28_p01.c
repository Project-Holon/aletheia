/*
 * file:     unit_02181E28_p01.c
 * unit:     yes
 * function: gsiXmlUtilSkipWhiteSpace, func_02181E80
 * address:  0x02181E28
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
 *   strchr                           0x02094a28 arm
 *   g_021A3F14                       0x021a3f14 data
 *   gsiXmlUtilParseName              0x02182414 arm ov009
 *   ArrayLength                      0x02184200 arm ov009
 *   ArrayAppend                      0x02184234 arm ov009
 *   gsiXmlUtilParseString            0x02182554 arm ov009
 *   gsiXmlUtilParseValue             0x0218290C arm ov009
 *   ArrayReplaceAt                   0x0218439C arm ov009
 *   strncmp                          0x020949F4 arm
 *   __ctype_mapC                     0x020A61DC data
 */
#include "../../matched/arm9_sdk/libc/strncmp/string.h"

typedef struct GSIXmlString {
    char *string;
    int length;
} GSIXmlString;

typedef struct GSIXmlElement {
    GSIXmlString name;
    GSIXmlString value;
    int index;
    int parentIndex;
} GSIXmlElement;

typedef struct GSIXmlAttribute {
    GSIXmlString name;
    GSIXmlString value;
    int elementIndex;
    int unk14;
} GSIXmlAttribute;

typedef struct GSIXmlStreamReader {
    void *elements;
    void *attributes;
} GSIXmlStreamReader;

extern char *strchr(const char *s, int c);
extern int gsiXmlUtilParseName(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int gsiXmlUtilParseString(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int gsiXmlUtilParseValue(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int ArrayLength(void *array);
extern void ArrayAppend(void *array, void *newElem);
extern void ArrayReplaceAt(void *array, void *newElem, int n);
extern char g_021A3F14[];
extern const unsigned short __ctype_mapC[];


static int gsiXmlUtilSkipWhiteSpace(void *unused, char *buffer, int len, int *pos)
{
    while (*pos < len)
    {
        if (strchr(g_021A3F14, buffer[*pos]) == 0)
            return 1;
        (*pos)++;
    }
    return 0;
}


#define isalnum(c) (((unsigned)(c) >= 0x80u) ? 0 : (__ctype_mapC[c] & 0x9))


/*
 * notes:    strncmp is declared by the strncmp variant of the house string.h, so the
 *           compiler keeps newElem.name.length in a register across the call (a
 *           prototype in the .c file reloads it).  The vendor keeps no local for the
 *           opening quote character or for the position saved in the closing-tag loop:
 *           the quote test reads buffer[startPos + 1] twice and the loop reuses startPos.
 *           The function ends with `return 0` after the last loop, and the two `>`
 *           checks test != first, which orders the conditional returns as the image has
 *           them.
 *
 * sdk:      gsiXmlUtilParseElement (libdwcgscommon.TWL.HYB.a gsxml.o)
 */
static int func_02181E80(GSIXmlStreamReader *stream, char *buffer, int len,
                                  int *pos, int parentIndex)
{
    GSIXmlElement newElem;
    GSIXmlAttribute newAttr;
    int startPos;
    int storeElement = 1;

    gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos);
    if (*pos >= len)
        return storeElement;

    __builtin__clear(&newElem, sizeof(newElem));
    if (buffer[*pos] != '<')
        return 0;
    if (++(*pos) >= len)
        return 0;
    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if (buffer[*pos] != '!' && buffer[*pos] != '?' &&
        buffer[*pos] != '%' && buffer[*pos] != '/') {
        startPos = *pos - 1;
    } else {
        storeElement = 0;
        (*pos)++;
        startPos = *pos - 2;
    }
    if (!gsiXmlUtilParseName(stream, buffer, len, pos, &newElem.name))
        return 0;
    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if (storeElement) {
        newElem.index = ArrayLength(stream->elements);
        newElem.parentIndex = parentIndex;
        ArrayAppend(stream->elements, &newElem);
    }

    while (*pos < len && isalnum(buffer[*pos])) {
        __builtin__clear(&newAttr, sizeof(newAttr));
        if (!gsiXmlUtilParseName(stream, buffer, len, pos, &newAttr.name))
            return 0;
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
        if (buffer[*pos] != '=')
            return 0;
        (*pos)++;
        if (!gsiXmlUtilParseString(stream, buffer, len, pos, &newAttr.value))
            return 0;
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
        if (storeElement) {
            newAttr.elementIndex = ArrayLength(stream->attributes);
            newAttr.unk14 = newElem.index;
            ArrayAppend(stream->attributes, &newAttr);
        }
    }

    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if ((!isalnum(buffer[startPos + 1]) && buffer[*pos] == buffer[startPos + 1]) || buffer[*pos] == '/') {
        (*pos)++;
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
        if (buffer[*pos] != '>')
            return 0;
        (*pos)++;
        return 1;
    }
    if (buffer[*pos] != '>')
        return 0;
    (*pos)++;
    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if (buffer[*pos] != '<') {
        if (!gsiXmlUtilParseValue(stream, buffer, len, pos, &newElem.value))
            return 0;
        if (storeElement)
            ArrayReplaceAt(stream->elements, &newElem, newElem.index);
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
    }

    while (*pos < len) {
        startPos = *pos;
        if (buffer[*pos] != '<')
            return 0;
        (*pos)++;
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
        if (buffer[*pos] == '/') {
            (*pos)++;
            if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
                return 0;
            if (*pos + newElem.name.length >= len)
                return 0;
            if (strncmp(newElem.name.string, &buffer[*pos], newElem.name.length) != 0)
                return 0;
            *pos += newElem.name.length;
            if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
                return 0;
            if (buffer[*pos] != '>')
                return 0;
            (*pos)++;
            return 1;
        }
        if (newElem.value.string != 0)
            return 0;
        *pos = startPos;
        if (!func_02181E80(stream, buffer, len, pos, newElem.index))
            return 0;
        gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos);
    }
    return 0;
}
