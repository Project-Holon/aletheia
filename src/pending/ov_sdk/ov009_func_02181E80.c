/*
 * function: gsiXmlUtilParseElement
 * address:  0x02181E80
 * packet:   pkt_ov009_02181E80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gsiXmlUtilParseElement (libdwcgscommon.TWL.HYB.a gsxml.o)
 *
 * residue:  size-exact (1428) and all 25 relocations resolve; ~95 concrete
 *   words differ and every one is -O4,p scheduling or operand/register
 *   choice, not shape.  mwcc hoists the four call-argument movs above the
 *   `(*pos)` store in the source's `(*pos)++; SkipWhiteSpace(...)` pairs
 *   (ours stores `*pos` first), picks the commutative `cmp` order the other
 *   way at `buffer[*pos] == c`, and predicated the while-top `*pos >= len`
 *   exit where the original branches to the shared `mov r0,#0` epilogue.
 *   The stack slots (newElem@0x20, newAttr@8, startPos@4) and the callee
 *   registers already match.
 *
 * symbols:
 *   gsiXmlUtilSkipWhiteSpace         0x02181E28 arm ov009
 *   gsiXmlUtilParseName              0x02182414 arm ov009
 *   ArrayLength                      0x02184200 arm ov009
 *   ArrayAppend                      0x02184234 arm ov009
 *   gsiXmlUtilParseString            0x02182554 arm ov009
 *   gsiXmlUtilParseValue             0x0218290C arm ov009
 *   ArrayReplaceAt                   0x0218439C arm ov009
 *   strncmp                          0x020949F4 arm
 *   __ctype_mapC                     0x020A61DC data
 */

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

extern int gsiXmlUtilSkipWhiteSpace(void *stream, char *buffer, int len, int *pos);
extern int gsiXmlUtilParseName(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int gsiXmlUtilParseString(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int gsiXmlUtilParseValue(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut);
extern int ArrayLength(void *array);
extern void ArrayAppend(void *array, void *newElem);
extern void ArrayReplaceAt(void *array, void *newElem, int n);
extern int strncmp(const char *a, const char *b, unsigned long n);
extern const unsigned short __ctype_mapC[];

#define isalnum(c) (((unsigned)(c) >= 0x80u) ? 0 : (__ctype_mapC[c] & 0x9))

static int gsiXmlUtilParseElement(GSIXmlStreamReader *stream, char *buffer, int len,
                                  int *pos, int parentIndex)
{
    GSIXmlElement newElem;
    GSIXmlAttribute newAttr;
    int startPos;
    int storeElement = 1;
    char c;

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

    while (*pos < len && isalnum(c = buffer[*pos])) {
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
    c = buffer[startPos + 1];
    if ((!isalnum(c) && buffer[*pos] == c) || buffer[*pos] == '/') {
        (*pos)++;
        if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
            return 0;
        if (buffer[*pos] == '>') {
            (*pos)++;
            return 1;
        }
        return 0;
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
        int savePos = *pos;
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
            if (strncmp(&buffer[*pos], newElem.name.string, newElem.name.length) != 0)
                return 0;
            *pos += newElem.name.length;
            if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
                return 0;
            if (buffer[*pos] == '>') {
                (*pos)++;
                return 1;
            }
            return 0;
        }
        if (newElem.value.string != 0)
            return 0;
        *pos = savePos;
        if (!gsiXmlUtilParseElement(stream, buffer, len, pos, newElem.index))
            return 0;
        gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos);
    }
}
