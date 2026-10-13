/*
 * function: FIELD_RAIL_POINT_DebugPrint
 * address:  0x021B976C
 * packet:   pkt_ov021_021B976C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_DebugPrintPos  0x021B9768  thumb  ov021
 */

typedef struct {
    char pad[0x30];
    char f30[1];
} Obj;

extern void FIELD_RAIL_DebugPrintPos(void *a, void *b);

void FIELD_RAIL_POINT_DebugPrint(void *a, Obj *b)
{
    if (b != 0) {
        FIELD_RAIL_DebugPrintPos(a, b->f30);
    }
}
