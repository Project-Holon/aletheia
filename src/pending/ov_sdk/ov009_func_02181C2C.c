/*
 * function: func_02181C2C
 * address:  0x02181C2C
 * packet:   pkt_ov009_02181C2C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gsXmlCreateStreamReader (gsxml)
 *
 * symbols:
 *   gsimalloc                0x0217EAB0 arm ov009
 *   gsDebugFormat            0x0217D254 arm ov009
 *   ArrayNew                 0x02184144 arm ov009
 *   gsifree                  0x0217EAE0 arm ov009
 *   ArrayFree                0x021841B0 arm ov009
 *   gsXmlMoveToStart         0x021834D0 arm ov009
 *   g_021A3E74               0x021A3E74 data
 *   gsiXmlUtilElementFree    0x02181E10 arm ov009
 *   g_021A3EA8               0x021A3EA8 data
 *   gsiXmlUtilAttributeFree  0x02181E14 arm ov009
 *
 * note: near miss, 6 bytes differ (literal pool order only): original pool is g_021A3E74, gsiXmlUtilElementFree, g_021A3EA8, gsiXmlUtilAttributeFree; C yields ...ElementFree, AttributeFree, g_021A3EA8; also blocked for EXACT because gsiXmlUtilElementFree 0x02181E10 and gsiXmlUtilAttributeFree 0x02181E14 (4-byte bx lr statics) have no catalog row and no witness. 2026-09-29 (w3_tools): both callees now have catalog rows and matched bodies and resolve; only the pool order remains (DIFF)
 */

struct GSIXmlStreamReader
{
    void * elements;   /* 0x00 */
    void * attributes; /* 0x04 */
    int index;         /* 0x08 */
    int attrIndex;     /* 0x0C */
    int childIndex;    /* 0x10 */
};

extern void *gsimalloc(unsigned long size);
extern void gsifree(void *ptr);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern void *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void ArrayFree(void *array);
extern int gsXmlMoveToStart(void *stream);
extern void gsiXmlUtilElementFree(void *elem);
extern void gsiXmlUtilAttributeFree(void *elem);
extern char g_021A3E74[];
extern char g_021A3EA8[];

void *func_02181C2C(void)
{
    struct GSIXmlStreamReader *newStream;

    newStream = (struct GSIXmlStreamReader *)gsimalloc(sizeof(struct GSIXmlStreamReader));
    if (newStream == 0)
    {
        gsDebugFormat(12, 2, 1, g_021A3E74, sizeof(struct GSIXmlStreamReader));
        return 0;
    }
    newStream->elements = ArrayNew(24, 32, gsiXmlUtilElementFree);
    if (newStream->elements == 0)
    {
        gsDebugFormat(12, 2, 1, g_021A3E74);
        gsifree(newStream);
        return 0;
    }
    newStream->attributes = ArrayNew(24, 16, gsiXmlUtilAttributeFree);
    if (newStream->attributes == 0)
    {
        gsDebugFormat(12, 2, 1, g_021A3EA8);
        ArrayFree(newStream->elements);
        gsifree(newStream);
        return 0;
    }
    gsXmlMoveToStart(newStream);
    return newStream;
}
