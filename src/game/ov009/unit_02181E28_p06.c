/*
 * file:     unit_02181E28_p06.c
 * unit:     yes
 * function: func_0218372C, func_021837A4, func_02183918, func_02183A24, func_02183AE4
 * address:  0x0218372C
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
 *   gsXmlReadChildAsString           0x02183670 arm
 *   strncpy                          0x02094860 arm
 *   ArrayLength           0x02184200  arm   ov009
 *   ArrayNth              0x02184208  arm   ov009
 *   gsiXmlUtilTagMatches  0x02183d98  arm   ov009
 *   STD_TSScanf           0x0208cf34  arm
 *   g_021A3F5C            0x021a3f5c  data
 *   g_021A3F98            0x021a3f98  data
 *   func_0217F8B4         0x0217F8B4 arm ov009
 *   func_0217FBC8         0x0217FBC8 arm ov009
 *   atoi                  0x020964E0 arm
 *   gsiStringToInt64      0x0217F124 arm ov009
 */
struct GSIXmlStreamReader_021837A4 {
    void *elements;
    void *attributes;
    int index;
    int readIndex;
    int field10;
};

struct GSIXmlElement_021837A4 {
    char *name;
    int nameLen;
    char *value;
    int valueLen;
    int pad10;
    int parent;
};

struct GSIXmlStreamReader_02183918
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int readIndex;     /* 0x0C */
    int field10;       /* 0x10 */
};

struct GSIXmlElement_02183918
{
    char * name;       /* 0x00 */
    int nameLen;       /* 0x04 */
    char * value;      /* 0x08 */
    int valueLen;      /* 0x0C */
    int pad10;         /* 0x10 */
    int parent;        /* 0x14 */
};

struct GSIXmlStreamReader_02183A24
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int readIndex;     /* 0x0C */
    int field10;       /* 0x10 */
};

struct GSIXmlElement_02183A24
{
    char * name;       /* 0x00 */
    int nameLen;       /* 0x04 */
    char * value;      /* 0x08 */
    int valueLen;      /* 0x0C */
    int pad10;         /* 0x10 */
    int parent;        /* 0x14 */
};

struct GSIXmlStreamReader_02183AE4
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int readIndex;     /* 0x0C */
    int field10;       /* 0x10 */
};

struct GSIXmlElement_02183AE4
{
    char * name;       /* 0x00 */
    int nameLen;       /* 0x04 */
    char * value;      /* 0x08 */
    int valueLen;      /* 0x0C */
    int pad10;         /* 0x10 */
    int parent;        /* 0x14 */
};

extern int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *valueLen);
extern char *strncpy(char *dest, const char *src, unsigned int n);
extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);
extern int gsiXmlUtilTagMatches(char *matchtag, void *xmlstr);
extern int STD_TSScanf(char *src, char *fmt, ...);
extern void func_0217F8B4(const char *input, char *output, int inlen, int *outlen, int encodingType);
extern int func_0217FBC8(char *input, int encodingType);
extern int atoi(const char *s);
extern long long gsiStringToInt64(const char *s);
int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen);
int func_021837A4(void *stream, char *matchtag, unsigned char *valueOut, int maxLen, int *lenOut);
int func_02183918(void *stream, char *matchtag, unsigned char *valueOut, int *lenOut);
int func_02183A24(void *stream, char *matchtag, int *valueOut);
int func_02183AE4(void *stream, char *matchtag, long long *valueOut);
extern char g_021A3F5C[];
extern char g_021A3F98[];


int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen)
{
    char * strValue = 0;
    int strLen = 0;
    int count;

    if (gsXmlReadChildAsString(stream, matchtag, &strValue, &strLen) == 0)
    {
        valueOut[0] = 0;
        return 0;
    }
    count = (maxLen < strLen) ? maxLen : strLen;
    strncpy(valueOut, strValue, count);
    count = (maxLen - 1 < strLen) ? maxLen - 1 : strLen;
    valueOut[count] = 0;
    return 1;
}


/*
 * sdk:      gsXmlReadChildAsHexBinary (libdwcgscommon.TWL.HYB.a gsxml.o)
 */
int func_021837A4(void *stream, char *matchtag, unsigned char *valueOut, int maxLen, int *lenOut)
{
    struct GSIXmlStreamReader_021837A4 *reader = (struct GSIXmlStreamReader_021837A4 *)stream;
    struct GSIXmlElement_021837A4 *searchValueElem;
    int i;
    unsigned int temp;
    int writepos;
    int readpos;
    int bytesleft;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements)) {
        searchValueElem = (struct GSIXmlElement_021837A4 *)ArrayNth(reader->elements, i);
        if (searchValueElem->parent == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem)) {
            writepos = 0;
            temp = 0;
            readpos = 0;
            bytesleft = maxLen * 2;
            if (searchValueElem->valueLen <= bytesleft)
                bytesleft = searchValueElem->valueLen;
            if (searchValueElem->valueLen == 0 || searchValueElem->value == 0) {
                valueOut[0] = 0;
                *lenOut = 0;
                return 1;
            }
            if (valueOut == 0) {
                *lenOut = searchValueElem->valueLen / 2;
                return 1;
            }
            while (bytesleft > 1) {
                STD_TSScanf(searchValueElem->value + readpos, g_021A3F5C, &temp);
                valueOut[writepos] = temp;
                bytesleft -= 2;
                readpos += 2;
                writepos++;
            }
            if (bytesleft == 1) {
                STD_TSScanf(searchValueElem->value + readpos, g_021A3F98, &temp);
                valueOut[writepos] = temp;
                writepos++;
            }
            if (lenOut != 0)
                *lenOut = writepos;
            reader->readIndex = i;
            return 1;
        }
        if (searchValueElem->parent < reader->index)
            return 0;
        i++;
    }
    return 0;
}


/*
 * sdk:      gsXmlReadChildAsBase64Binary (libdwcgscommon.TWL.HYB.a(gsxml.o))
 */
int func_02183918(void *stream, char *matchtag, unsigned char *valueOut, int *lenOut)
{
    struct GSIXmlStreamReader_02183918 *reader = (struct GSIXmlStreamReader_02183918 *)stream;
    struct GSIXmlElement_02183918 *searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (struct GSIXmlElement_02183918 *)ArrayNth(reader->elements, i);
        if (searchValueElem->parent == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem))
        {
            if (valueOut != 0)
            {
                reader->readIndex = i;
                if (searchValueElem->value == 0)
                    *lenOut = 0;
                else
                    func_0217F8B4(searchValueElem->value, (char *)valueOut, searchValueElem->valueLen, lenOut, 0);
            }
            else
            {
                if (searchValueElem->value == 0)
                    *lenOut = 0;
                else
                    *lenOut = func_0217FBC8(searchValueElem->value, 0);
            }
            return 1;
        }
        if (searchValueElem->parent < reader->index)
            return 0;
        i++;
    }
    return 0;
}


/*
 * sdk:      gsXmlReadChildAsInt (gsxml)
 */
int func_02183A24(void *stream, char *matchtag, int *valueOut)
{
    struct GSIXmlStreamReader_02183A24 *reader = (struct GSIXmlStreamReader_02183A24 *)stream;
    struct GSIXmlElement_02183A24 *searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (struct GSIXmlElement_02183A24 *)ArrayNth(reader->elements, i);
        if (searchValueElem->parent == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem))
        {
            reader->readIndex = i;
            if (searchValueElem->value == 0)
                return 0;
            *valueOut = atoi(searchValueElem->value);
            return 1;
        }
        if (searchValueElem->parent < reader->index)
            return 0;
        i++;
    }
    return 0;
}


/*
 * sdk:      gsXmlReadChildAsInt64 (gsxml)
 */
int func_02183AE4(void *stream, char *matchtag, long long *valueOut)
{
    struct GSIXmlStreamReader_02183AE4 *reader = (struct GSIXmlStreamReader_02183AE4 *)stream;
    struct GSIXmlElement_02183AE4 *searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (struct GSIXmlElement_02183AE4 *)ArrayNth(reader->elements, i);
        if (searchValueElem->parent == reader->index && gsiXmlUtilTagMatches(matchtag, searchValueElem))
        {
            reader->readIndex = i;
            if (searchValueElem->value == 0)
                return 0;
            *valueOut = gsiStringToInt64(searchValueElem->value);
            return 1;
        }
        if (searchValueElem->parent < reader->index)
            return 0;
        i++;
    }
    return 0;
}
