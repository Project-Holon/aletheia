/*
 * function: func_02181E20
 * address:  0x02181E20
 * packet:   pkt_ov009_02181E20
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlWriterGetDataLength (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * notes:    `ldr r0, [r0, #4]; bx lr`; called by bl from ov114 ghttp code (see
 *           layout/function_starts.txt).  Seeded in layout/function_starts.txt.
 */

typedef struct GSIXmlStreamWriter {
    char *buffer;               /* +0x00 */
    int len;                    /* +0x04 */
    int capacity;               /* +0x08 */
    int openElements;           /* +0x0c */
} GSIXmlStreamWriter;

int func_02181E20(void *stream)
{
    return ((GSIXmlStreamWriter *)stream)->len;
}
