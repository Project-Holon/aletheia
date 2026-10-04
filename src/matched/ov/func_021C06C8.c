/*
 * function: func_021C06C8
 * address:  0x021C06C8
 * packet:   pkt_021C06C8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Fills four 4-byte entries with the current halfword and clears a word.
 */


typedef unsigned int   u32;
extern u32 func_0201C440(void *p);

void func_021C06C8(unsigned short *a, char *b)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = b + i * 4;
        *(int *)(e + 0x34) = func_0201C440((void *)(*a));
        *(int *)(e + 0x24) = 0;
    }
}

