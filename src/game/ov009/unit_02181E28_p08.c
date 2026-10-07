/*
 * file:     unit_02181E28_p08.c
 * unit:     yes
 * function: func_02183E50, func_02183EE0
 * address:  0x02183E50
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
 *   ArrayLength           0x02184200 arm ov009
 *   ArrayNth              0x02184208 arm ov009
 *   gsiXmlUtilTagMatches  0x02183D98 arm ov009
 */
typedef unsigned int u32;

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
    char * name;       /* 0x00 */
    int nameLen;       /* 0x04 */
    char * value;      /* 0x08 */
    int valueLen;      /* 0x0C */
    int pad10;         /* 0x10 */
    int parent;        /* 0x14 */
};

extern void *func_020923B0(void *p, int c, u32 n);
extern int func_021837A4(void *stream, char *matchtag, unsigned char *valueOut, int maxLen, int *lenOut);
extern int func_0217E934(char *p);
extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);
extern int gsiXmlUtilTagMatches(char *matchtag, void *xmlstr);
int func_02183E50(void *a, int b, int *c);
int func_02183EE0(void *stream, char *matchtag);


/*
 * Clear 0x104 bytes at `c`, then fill `c+4` with up to 0x200 bytes through
 * func_021837A4; the byte count it reports is rounded up to a word count and
 * stored at c[0].  Returns 1 when the object validates, 0 when the fill loop
 * reports nothing produced.
 */
int func_02183E50(void *a, int b, int *c)
{
    u32 n = 0;
    u32 k;

    func_020923B0(c, 0, 0x104);
    if (func_021837A4(a, (char *)b, (unsigned char *)(c + 1), 0x200, (int *)(&n)) == 0)
        return 0;

    k = n >> 2;
    c[0] = k;
    if (n & 3)
        c[0] = k + 1;

    if (func_0217E934((char *)c) == 0)
        return 0;
    return 1;
}


int func_02183EE0(void *stream, char *matchtag)
{
    struct GSIXmlStreamReader *reader = (struct GSIXmlStreamReader *)stream;
    struct GSIXmlElement *searchElem;
    int i;
    int count = 0;

    for (i = reader->index + 1; i < ArrayLength(reader->elements); i++)
    {
        searchElem = (struct GSIXmlElement *)ArrayNth(reader->elements, i);
        if (searchElem->parent == reader->index)
        {
            if (matchtag == 0 || gsiXmlUtilTagMatches(matchtag, searchElem))
                count++;
        }
        else if (searchElem->parent < reader->index)
            break;
    }
    return count;
}
