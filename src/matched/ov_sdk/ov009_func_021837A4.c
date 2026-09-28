/*
 * function: func_021837A4
 * address:  0x021837A4
 * packet:   pkt_ov009_021837A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlReadChildAsHexBinary (libdwcgscommon.TWL.HYB.a gsxml.o)
 *
 * symbols:
 *   ArrayLength           0x02184200  arm   ov009
 *   ArrayNth              0x02184208  arm   ov009
 *   gsiXmlUtilTagMatches  0x02183d98  arm   ov009
 *   STD_TSScanf           0x0208cf34  arm
 *   g_021A3F5C            0x021a3f5c  data
 *   g_021A3F98            0x021a3f98  data
 */

struct GSIXmlStreamReader {
    void *elements;
    void *attributes;
    int index;
    int readIndex;
    int field10;
};

struct GSIXmlElement {
    char *name;
    int nameLen;
    char *value;
    int valueLen;
    int pad10;
    int parent;
};

extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);
extern int gsiXmlUtilTagMatches(char *matchtag, void *xmlstr);
extern int STD_TSScanf(char *src, char *fmt, ...);
extern char g_021A3F5C[];
extern char g_021A3F98[];

int func_021837A4(void *stream, char *matchtag, unsigned char *valueOut, int maxLen, int *lenOut)
{
    struct GSIXmlStreamReader *reader = (struct GSIXmlStreamReader *)stream;
    struct GSIXmlElement *searchValueElem;
    int i;
    unsigned int temp;
    int writepos;
    int readpos;
    int bytesleft;

    if (reader->readIndex == -1)
        reader->readIndex = reader->index;
    i = reader->readIndex + 1;
    while (i < ArrayLength(reader->elements)) {
        searchValueElem = (struct GSIXmlElement *)ArrayNth(reader->elements, i);
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
