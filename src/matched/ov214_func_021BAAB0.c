/*
 * function: func_021BAAB0
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
 *   func_021BABA4 0x021BABA4 thumb
 */

extern void func_021BABA4(void *, int);

void func_021BAAB0(int unused, int base)
{
    unsigned char j, i;

    for (j = 0; j < 2; j++) {
        char *p = (char *)base + j * 0xf0;
        char *q = (char *)base + 0xd4 + j * 0xf0;
        for (i = 0; i < 6; i++) {
            if (*(int *)(p + 0xc4 + i * 0x28) != 0) {
                func_021BABA4(q + i * 0x28, *(int *)(p + 0xe4 + i * 0x28));
            }
        }
    }
}
