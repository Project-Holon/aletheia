/*
 * file:     unit_0218198C_p02.c
 * unit:     yes
 * function: func_02181D84, func_02181DA0, func_02181DC4, func_02181DE8
 * address:  0x02181D84
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
 *   ArrayFree                        0x021841b0 arm
 *   gsifree                          0x0217eae0 arm
 *   ArrayClear                       0x0218452c arm
 *   gsXmlMoveToStart                 0x021834d0 arm
 *   gsiXmlUtilWriteString            0x0218325c arm
 *   g_021A3EEC                       0x021a3eec data
 */
struct GSIXmlStreamReader
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
};

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
    int bookkeeping;/* 0x0C */
};

extern void func_0217EAE0(void *p);
extern void ArrayFree(void *array);
extern void gsifree(void *ptr);
extern void ArrayClear(void *array);
extern int gsXmlMoveToStart(void *stream);
extern int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str);
void func_02181D84(void **p);
void gsXmlFreeReader(void *stream);
void gsXmlResetReader(void *stream);
int gsXmlCloseWriter(void *stream);
extern char g_021A3EEC[];


/*
 * Calls the module helper on the pointed-to block and then on the pointer.
 */
void func_02181D84(void **p)
{
    func_0217EAE0(*p);
    func_0217EAE0(p);
}


void gsXmlFreeReader(void *stream)
{
    struct GSIXmlStreamReader * reader = (struct GSIXmlStreamReader *)stream;

    ArrayFree(reader->attributes);
    ArrayFree(reader->elements);
    gsifree(reader);
}


void gsXmlResetReader(void *stream)
{
    struct GSIXmlStreamReader * reader = (struct GSIXmlStreamReader *)stream;

    ArrayClear(reader->attributes);
    ArrayClear(reader->elements);
    gsXmlMoveToStart(reader);
}


int gsXmlCloseWriter(void *stream)
{
    struct GSIXmlStreamWriter * writer = (struct GSIXmlStreamWriter *)stream;
    int result;

    if (gsiXmlUtilWriteString(writer, g_021A3EEC) == 0)
        result = 0;
    else
    {
        result = 1;
        writer->bookkeeping = 1;
    }
    return result;
}
