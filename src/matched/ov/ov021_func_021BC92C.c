/*
 * function: FIELD_PLACE_NAME_HideLetters
 * address:  0x021BC92C
 * packet:   pkt_ov021_021BC92C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLACE_NAME_LETTER_SetVisible  0x021BD1E4  thumb  ov021
 */

typedef struct {
    char pad[0x50];
    void *f50[0x1E];
} Obj;

extern void PLACE_NAME_LETTER_SetVisible(void *a, unsigned int b);

void FIELD_PLACE_NAME_HideLetters(Obj *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        PLACE_NAME_LETTER_SetVisible(p->f50[i], 0);
    }
}
