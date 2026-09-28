/*
 * function: func_02183918
 * address:  0x02183918
 * packet:   pkt_ov009_02183918
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlReadChildAsBase64Binary (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * symbols:
 *   ArrayLength           0x02184200 arm ov009
 *   ArrayNth              0x02184208 arm ov009
 *   gsiXmlUtilTagMatches  0x02183D98 arm ov009
 *   func_0217F8B4         0x0217F8B4 arm ov009
 *   func_0217FBC8         0x0217FBC8 arm ov009
 */

struct GSIXmlStreamReader
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int readIndex;     /* 0x0C */
    int field10;       /* 0x10 */
};

struct GSIXmlElement
{
    char * name;       /* 0x00 */
    int nameLen;       /* 0x04 */
    char * value;      /* 0x08 */
    int valueLen;      /* 0x0C */
    int pad10;         /* 0x10 */
    int parent;        /* 0x14 */
};

extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);
extern int gsiXmlUtilTagMatches(char *matchtag, void *xmlstr);
extern void func_0217F8B4(char *input, char *output, int inlen, int *outlen, int encodingType);
extern int func_0217FBC8(char *input, int encodingType);

int func_02183918(void *stream, char *matchtag, unsigned char *valueOut, int *lenOut)
{
    struct GSIXmlStreamReader *reader = (struct GSIXmlStreamReader *)stream;
    struct GSIXmlElement *searchValueElem;
    int i;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements))
    {
        searchValueElem = (struct GSIXmlElement *)ArrayNth(reader->elements, i);
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
