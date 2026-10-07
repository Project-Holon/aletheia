/*
 * file:     unit_02181E28_p05.c
 * unit:     yes
 * function: func_0218325C, func_021832DC, func_0218335C, func_02183490, func_021834D0, func_021834E8, func_02183560, func_021835D0, func_02183670
 * address:  0x0218325C
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
 *   strlen                           0x0209477c arm
 *   strcpy                           0x02094798 arm
 *   gsUnicodeStringLen            0x0218198C arm ov009
 *   _UCS2CharToUTF8String         0x021801C0 arm ov009
 *   gsiXmlUtilWriteXmlSafeString  0x0218335C arm ov009
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
 *   gsirealloc                       0x0217eac8 arm
 *   ArrayLength                      0x02184200 arm
 *   ArrayNth                         0x02184208 arm
 *   gsiXmlUtilTagMatches             0x02183d98 arm
 */
struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

struct GSIXmlStreamReader_021834E8
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
};

struct GSIXmlStreamReader_02183560
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
};

struct GSIXmlElement_02183560
{
    int pad[5];
    int parent;        /* 0x14 */
};

struct GSIXmlStreamReader_021835D0
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
};

struct GSIXmlElement_021835D0
{
    char * name;       /* 0x00 */
    int nameLen;       /* 0x04 */
    char * value;      /* 0x08 */
    int valueLen;      /* 0x0C */
    int pad10;         /* 0x10 */
    int parent;        /* 0x14 */
};

struct GSIXmlString
{
    char * string;  /* 0x00 */
    int length;     /* 0x04 */
};

struct GSIXmlStreamReader_02183670
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int readIndex;     /* 0x0C */
    int field10;       /* 0x10 */
};

struct GSIXmlElement_02183670
{
    char * name;       /* 0x00 */
    int nameLen;       /* 0x04 */
    char * value;      /* 0x08 */
    int valueLen;      /* 0x0C */
    int pad10;         /* 0x10 */
    int parent;        /* 0x14 */
};

extern unsigned int strlen(const char *s);
extern char *strcpy(char *dest, const char *src);
extern int gsUnicodeStringLen(unsigned short *str);
extern int _UCS2CharToUTF8String(unsigned short theUCS2Char, char *theUTF8String);
extern int gsiXmlUtilWriteXmlSafeString(struct GSIXmlStreamWriter *stream, char *str);
extern int sprintf(char *, const char *, ...);
extern int func_0218325C(void *, char *);
extern int func_02183210(void *, char);
extern void *gsirealloc(void *ptr, unsigned long size);
extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);
extern int gsiXmlUtilTagMatches(char *matchtag, void *xmlstr);
int func_021832DC(struct GSIXmlStreamWriter *stream, unsigned short *str);
int func_0218335C(void *stream, char *str);
int func_021834D0(int *p);
int gsXmlMoveToNext(void *stream, char *matchtag);
int gsXmlMoveToParent(void *stream);
int func_021835D0(void *stream, char *matchtag);
int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *lenOut);
extern char g_021A3F1C[];
extern char g_021A3F24[];
extern char g_021A3F2C[];
extern char g_021A3F34[];
extern char g_021A3F3C[];
extern char g_021A3F84[];
extern char g_021A3F8C[];


static int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str)
{
    int strLen;

    strLen = strlen(str);
    if (strLen == 0)
        return 1;
    while (stream->capacity - stream->position <= strLen)
    {
        if (gsiXmlUtilGrowBuffer(stream) == 0)
            return 0;
    }
    strcpy(stream->buffer + stream->position, str);
    stream->position += strLen;
    return 1;
}


/*
 * sdk:      gsiXmlUtilWriteUnicodeString (gsxml)
 */
int func_021832DC(struct GSIXmlStreamWriter *stream, unsigned short *str)
{
    int strLen;
    int pos;
    int utf8Len;
    char utf8String[4] = {0, 0, 0, 0};

    strLen = gsUnicodeStringLen(str);
    utf8String[3] = 0;
    for (pos = 0; pos < strLen; pos++)
    {
        utf8Len = _UCS2CharToUTF8String(str[pos], utf8String);
        utf8String[utf8Len] = 0;
        if (!gsiXmlUtilWriteXmlSafeString(stream, utf8String))
            return 0;
    }
    return 1;
}


/*
 * sdk:      gsiXmlUtilWriteXmlSafeString (libdwcgscommon.TWL.HYB.a gsxml.o)
 */
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


static int gsiXmlUtilGrowBuffer(struct GSIXmlStreamWriter *stream)
{
    int newCapacity;
    void *newBuf;

    newCapacity = stream->capacity + 0x400;
    newBuf = gsirealloc(stream->buffer, newCapacity);
    if (newBuf == 0)
        return 0;
    stream->capacity = newCapacity;
    if (newBuf != stream->buffer)
        stream->buffer = newBuf;
    return 1;
}

/*
 * Fills the three words at +8, +0xc and +0x10 with -1 and reports success.
 */
int func_021834D0(int *p)
{
    p[2] = -1;
    p[3] = -1;
    p[4] = -1;
    return 1;
}


int gsXmlMoveToNext(void *stream, char *matchtag)
{
    struct GSIXmlStreamReader_021834E8 * reader = (struct GSIXmlStreamReader_021834E8 *)stream;
    int i = reader->index + 1;

    while (i < ArrayLength(reader->elements))
    {
        if (gsiXmlUtilTagMatches(matchtag, ArrayNth(reader->elements, i)))
        {
            reader->index = i;
            reader->attrIndex = -1;
            reader->childIndex = -1;
            return 1;
        }
        i++;
    }
    return 0;
}


int gsXmlMoveToParent(void *stream)
{
    struct GSIXmlStreamReader_02183560 * reader = (struct GSIXmlStreamReader_02183560 *)stream;
    struct GSIXmlElement_02183560 * elem;
    int result;
    int idx;

    idx = reader->index;
    if (idx >= ArrayLength(reader->elements) || idx == -1)
        return 0;
    elem = (struct GSIXmlElement_02183560 *)ArrayNth(reader->elements, idx);
    idx = elem->parent;
    if (idx == -1)
        return 0;
    if (idx >= ArrayLength(reader->elements))
        result = 0;
    else
    {
        reader->index = idx;
        reader->attrIndex = -1;
        reader->childIndex = -1;
        result = 1;
    }
    return result;
}


/*
 * sdk:      gsXmlMoveToChild (gsxml)
 */
int func_021835D0(void *stream, char *matchtag)
{
    struct GSIXmlStreamReader_021835D0 *reader = (struct GSIXmlStreamReader_021835D0 *)stream;
    struct GSIXmlElement_021835D0 *searchElem;
    int i;

    for (i = reader->index + 1; i < ArrayLength(reader->elements); i++)
    {
        searchElem = (struct GSIXmlElement_021835D0 *)ArrayNth(reader->elements, i);
        if (searchElem->parent == reader->index && gsiXmlUtilTagMatches(matchtag, searchElem))
        {
            reader->index = i;
            reader->attrIndex = -1;
            reader->childIndex = -1;
            return 1;
        }
        if (searchElem->parent < reader->index)
            return 0;
    }
    return 0;
}


int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *lenOut)
{
    struct GSIXmlStreamReader_02183670 * reader = (struct GSIXmlStreamReader_02183670 *)stream;
    struct GSIXmlElement_02183670 * searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (struct GSIXmlElement_02183670 *)ArrayNth(reader->elements, i);
        if ((searchValueElem->parent == reader->index) &&
            gsiXmlUtilTagMatches(matchtag, (struct GSIXmlString *)searchValueElem))
        {
            reader->readIndex = i;
            *valueOut = searchValueElem->value;
            *lenOut = searchValueElem->valueLen;
            return 1;
        }
        if (searchValueElem->parent < reader->index)
            return 0;
        i++;
    }
    return 0;
}
