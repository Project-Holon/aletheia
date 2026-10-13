/*
 * function: FIELD_PLACE_NAME_DeleteLetters
 * address:  0x021BC7F8
 * packet:   pkt_ov021_021BC7F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLACE_NAME_LETTER_Delete  0x021BD184  thumb  ov021
 */

typedef struct {
    char pad[0x50];
    void *f50[0x1E];
} Obj;

extern void PLACE_NAME_LETTER_Delete(void *a);

void FIELD_PLACE_NAME_DeleteLetters(Obj *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        PLACE_NAME_LETTER_Delete(p->f50[i]);
    }
}
