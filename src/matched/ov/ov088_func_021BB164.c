/*
 * function: STARTMENU_DeleteRowWindows
 * address:  0x021BB164
 * packet:   pkt_ov088_021BB164
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases the fourteen 8-byte-stride handles at +0x80 created by
 * STARTMENU_CreateRowWindows, then the shared resource.
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 */

struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);

void STARTMENU_DeleteRowWindows(char *p)
{
    unsigned i;
    for (i = 0; i < 14; i++)
        BMP_WIN_Delete(*(void **)(p + 0x80 + i * 8));
    BMP_WIN_Exit();
}
