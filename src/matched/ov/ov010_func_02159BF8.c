/*
 * function: MAP_MATRIX_GetHeight
 * address:  0x02159BF8
 * packet:   pkt_ov010_02159BF8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor (prints as .word): returns the field at +0xA.
 * Sole blocker of ov021 FIELDMAP_SetupMapperParam's MATCH.
 */

typedef struct Obj {
    char pad[0xA];
    unsigned short f;
} Obj;

unsigned short MAP_MATRIX_GetHeight(Obj *p)
{
    return p->f;
}
