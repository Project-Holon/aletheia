/*
 * function: func_021BB2D4
 * address: 0x021BB2D4
 * packet: pkt_ov206_021BB2D4
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
extern void func_0204B3DC(void *, int);
void func_021BB2D4(char *p)
{
    unsigned char i;
    for (i = 0; i < 2; i++) {
        if (i != *(int *)(p + 0xb4) && *(void **)(p + i * 4 + 0xac) != 0) {
            func_0204B3DC(*(void **)(p + i * 4 + 0xac), 0);
        }
    }
}
