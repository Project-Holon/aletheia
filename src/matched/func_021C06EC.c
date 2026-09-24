/*
 * function: func_021C06EC
 * address:  0x021C06EC
 * packet:   pkt_021C06EC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Clears a word and releases two handles of each of four entries.
 */


extern void func_0201C6EC(int);
extern void func_0201C4C0(int);

void func_021C06EC(int unused, char *p)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = p + i * 4;
        *(int *)(e + 0x24) = 0;
        func_0201C6EC(*(int *)(e + 0x34));
        func_0201C4C0(*(int *)(e + 0x34));
    }
}

