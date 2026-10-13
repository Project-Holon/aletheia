/*
 * function: FIELD_PLACE_NAME_CreateLetters
 * address:  0x021BC7D4
 * packet:   pkt_ov021_021BC7D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PLACE_NAME_LETTER_Create  0x021BD148  thumb  ov021
 */

typedef unsigned short u16;

typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x1E];
    void *f2C;
    void *f30;
    char pad3[0x1C];
    void *f50[0x1E];
} Obj;

extern void *PLACE_NAME_LETTER_Create(int a0, int a1, int a2, int a3);

void FIELD_PLACE_NAME_CreateLetters(Obj *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        p->f50[i] = PLACE_NAME_LETTER_Create(p->hC, (int)p->f30, 0, (int)p->f2C);
    }
}
