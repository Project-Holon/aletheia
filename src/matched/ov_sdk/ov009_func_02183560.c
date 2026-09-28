/*
 * function: gsXmlMoveToParent
 * address:  0x02183560
 * packet:   pkt_ov009_02183560
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlMoveToParent (gsxml.o)
 *
 * symbols:
 *   ArrayLength                      0x02184200 arm
 *   ArrayNth                         0x02184208 arm
 */

struct GSIXmlStreamReader
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
};

struct GSIXmlElement
{
    int pad[5];
    int parent;        /* 0x14 */
};

extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);

int gsXmlMoveToParent(void *stream)
{
    struct GSIXmlStreamReader * reader = (struct GSIXmlStreamReader *)stream;
    struct GSIXmlElement * elem;
    int result;
    int idx;

    idx = reader->index;
    if (idx >= ArrayLength(reader->elements) || idx == -1)
        return 0;
    elem = (struct GSIXmlElement *)ArrayNth(reader->elements, idx);
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
