/*
 * function: gsXmlResetReader
 * address:  0x02181DC4
 * packet:   pkt_ov009_02181DC4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlResetReader (gsxml.o)
 *
 * symbols:
 *   ArrayClear                       0x0218452c arm
 *   gsXmlMoveToStart                 0x021834d0 arm
 */

struct GSIXmlStreamReader
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
};

extern void ArrayClear(void *array);
extern int gsXmlMoveToStart(void *stream);

void gsXmlResetReader(void *stream)
{
    struct GSIXmlStreamReader * reader = (struct GSIXmlStreamReader *)stream;

    ArrayClear(reader->attributes);
    ArrayClear(reader->elements);
    gsXmlMoveToStart(reader);
}
