/*
 * file:     gsxml_2.c
 * unit:     yes
 * function: func_02181E10, func_02181E14, func_02181E18, func_02181E20
 * address:  0x02181E10
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef struct GSIXmlStreamWriter {
    char *buffer;               /* +0x00 */
    int len;                    /* +0x04 */
    int capacity;               /* +0x08 */
    int openElements;           /* +0x0c */
} GSIXmlStreamWriter;

void func_02181E10(void);
void func_02181E14(void);
char *func_02181E18(void *stream);
int func_02181E20(void *stream);

/*
 * sdk:      gsiXmlUtilElementFree (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * notes:    a 4-byte `bx lr` (ArrayNew element free callback); gsXmlCreateStreamReader's
 *           relocation at +0xD8 (ABS32 gsiXmlUtilElementFree) is the pool word at
 *           0x02181D04 that names it.  Seeded in layout/function_starts.txt.
 */
void func_02181E10(void)
{
}

/*
 * sdk:      gsiXmlUtilAttributeFree (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * notes:    a 4-byte `bx lr`; gsXmlCreateStreamReader's relocation at +0xE0
 *           (ABS32 gsiXmlUtilAttributeFree) is the pool word at 0x02181D0C.
 *           Byte-identical to 0x02181E10: the name comes from that relocation.
 *           Seeded in layout/function_starts.txt.
 */
void func_02181E14(void)
{
}


/*
 * sdk:      gsXmlWriterGetData (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * notes:    `ldr r0, [r0]; bx lr`; called by bl from ov114 ghttp code (see
 *           layout/function_starts.txt).  Seeded in layout/function_starts.txt.
 */
char *func_02181E18(void *stream)
{
    return ((GSIXmlStreamWriter *)stream)->buffer;
}


/*
 * sdk:      gsXmlWriterGetDataLength (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * notes:    `ldr r0, [r0, #4]; bx lr`; called by bl from ov114 ghttp code (see
 *           layout/function_starts.txt).  Seeded in layout/function_starts.txt.
 */
int func_02181E20(void *stream)
{
    return ((GSIXmlStreamWriter *)stream)->len;
}
