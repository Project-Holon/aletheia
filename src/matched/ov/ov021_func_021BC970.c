/*
 * function: FIELD_PLACE_NAME_UpdateLetters
 * address:  0x021BC970
 * packet:   pkt_ov021_021BC970
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetMessageLength  0x021BD138  thumb  ov021
 *   PLACE_NAME_LETTER_Update  0x021BD1CC  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    char pad[0xC8];
    void *fC8[0x20];
} Obj;

extern u8 FIELD_PLACE_NAME_GetMessageLength(u8 *p);
extern void PLACE_NAME_LETTER_Update(void *a);

void FIELD_PLACE_NAME_UpdateLetters(Obj *p)
{
    int n = FIELD_PLACE_NAME_GetMessageLength((u8 *)p);
    int i;

    for (i = 0; i < n; i++) {
        if (p->fC8[i] != 0) {
            PLACE_NAME_LETTER_Update(p->fC8[i]);
        }
    }
}
