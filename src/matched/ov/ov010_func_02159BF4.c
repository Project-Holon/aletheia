/*
 * function: MAP_MATRIX_GetWidth
 * address:  0x02159BF4
 * packet:   pkt_ov010_02159BF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor (prints as .word): returns the field at +8.
 * Sole blocker of ov021 FIELDMAP_SetupMapperParam's MATCH.
 */

typedef struct Obj {
    char pad[8];
    unsigned short f;
} Obj;

unsigned short MAP_MATRIX_GetWidth(Obj *p)
{
    return p->f;
}
