/*
 * function: BTL_REC_SEL_DeleteCellActors
 * address:  0x021BAAB0
 * packet:   pkt_021BAAB0
 * region:   ov214
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_REC_SEL_DeleteActor 0x021BABA4 thumb
 */

extern void BTL_REC_SEL_DeleteActor(void *p, void *actor);

void BTL_REC_SEL_DeleteCellActors(int unused, int base)
{
    unsigned char j, i;

    for (j = 0; j < 2; j++) {
        char *p = (char *)base + j * 0xf0;
        char *q = (char *)base + 0xd4 + j * 0xf0;
        for (i = 0; i < 6; i++) {
            if (*(int *)(p + 0xc4 + i * 0x28) != 0) {
                BTL_REC_SEL_DeleteActor(q + i * 0x28, (void *)(*(int *)(p + 0xe4 + i * 0x28)));
            }
        }
    }
}
