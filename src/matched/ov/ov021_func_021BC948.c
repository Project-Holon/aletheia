/*
 * function: FIELD_PLACE_NAME_LaunchNextLetter
 * address:  0x021BC948
 * packet:   pkt_ov021_021BC948
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLACE_NAME_LETTER_Start  0x021BD1D4  thumb  ov021
 *   PLACE_NAME_LETTER_SetVisible  0x021BD1E4  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    char pad[0xC8];
    void *fC8[0x20];
    char pad2[0x149 - 0xC8 - 0x80];
    u8 b149;
} Obj;

extern void PLACE_NAME_LETTER_Start(void *a);
extern void PLACE_NAME_LETTER_SetVisible(void *a, unsigned int b);

void FIELD_PLACE_NAME_LaunchNextLetter(Obj *p)
{
    u8 i = p->b149++;

    if (p->fC8[i] != 0) {
        PLACE_NAME_LETTER_Start(p->fC8[i]);
        PLACE_NAME_LETTER_SetVisible(p->fC8[i], 1);
    }
}
