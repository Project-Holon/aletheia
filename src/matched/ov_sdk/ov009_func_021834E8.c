/*
 * function: gsXmlMoveToNext
 * address:  0x021834E8
 * packet:   pkt_ov009_021834E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlMoveToNext (gsxml.o)
 *
 * symbols:
 *   ArrayLength                      0x02184200 arm
 *   ArrayNth                         0x02184208 arm
 *   gsiXmlUtilTagMatches             0x02183d98 arm
 */

struct GSIXmlStreamReader
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
};

extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);
extern int gsiXmlUtilTagMatches(char *matchtag, void *xmlstr);

int gsXmlMoveToNext(void *stream, char *matchtag)
{
    struct GSIXmlStreamReader * reader = (struct GSIXmlStreamReader *)stream;
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
