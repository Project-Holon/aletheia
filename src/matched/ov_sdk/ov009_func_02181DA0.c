/*
 * function: gsXmlFreeReader
 * address:  0x02181DA0
 * packet:   pkt_ov009_02181DA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlFreeReader (gsxml.o)
 *
 * symbols:
 *   ArrayFree                        0x021841b0 arm
 *   gsifree                          0x0217eae0 arm
 */

struct GSIXmlStreamReader
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
};

extern void ArrayFree(void *array);
extern void gsifree(void *ptr);

void gsXmlFreeReader(void *stream)
{
    struct GSIXmlStreamReader * reader = (struct GSIXmlStreamReader *)stream;

    ArrayFree(reader->attributes);
    ArrayFree(reader->elements);
    gsifree(reader);
}
