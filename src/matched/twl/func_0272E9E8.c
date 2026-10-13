/*
 * function: CARDi_ReadCardWithHash
 * address:  0x0272E9E8
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   data_02732DC4 0x02732DC4 data twl
 *   CARD_ReadRomHashImage 0x0272F740 arm twl
 */

void CARD_ReadRomHashImage(void *ptr);

int CARDi_ReadCardWithHash(int a0, int a1, int a2, int a3) {
    CARD_ReadRomHashImage((void *)0x02732DC4);
    return a3;
}
