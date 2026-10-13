/*
 * function: PLACE_NAME_LETTER_MeasureGlyph
 * address:  0x021BD30C
 * packet:   pkt_ov021_021BD30C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PLACE_NAME_LETTER_GetFont  0x021BD2C0  thumb  ov021
 *   PLACE_NAME_LETTER_GetChar  0x021BD2C8  thumb  ov021
 *   PLACE_NAME_LETTER_GetHeapId  0x021BD2B8  thumb  ov021
 *   PLACE_NAME_LETTER_MeasureChar  0x021BD604  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 PLACE_NAME_LETTER_GetFont(u8 *p);
extern u16 PLACE_NAME_LETTER_GetChar(u8 *p);
extern u16 PLACE_NAME_LETTER_GetHeapId(u8 *p);
extern void PLACE_NAME_LETTER_MeasureChar(void *a, void *b, void *c, void *d, void *e);

void PLACE_NAME_LETTER_MeasureGlyph(char *p)
{
    void *a;
    void *b;

    a = (void *)PLACE_NAME_LETTER_GetFont((u8 *)p);
    b = (void *)PLACE_NAME_LETTER_GetChar((u8 *)p);
    PLACE_NAME_LETTER_MeasureChar(a, b, (void *)PLACE_NAME_LETTER_GetHeapId((u8 *)p), p + 0x40, p + 0x41);
}
