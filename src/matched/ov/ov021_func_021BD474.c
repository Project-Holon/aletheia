/*
 * function: PLACE_NAME_LETTER_Activate
 * address:  0x021BD474
 * packet:   pkt_ov021_021BD474
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef struct {
    char pad[0x44];
    int f44;
} Obj;

void PLACE_NAME_LETTER_Activate(Obj *p)
{
    p->f44 = 1;
}
