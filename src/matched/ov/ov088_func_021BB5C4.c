/*
 * function: func_021BB5C4
 * address:  0x021BB5C4
 * packet:   pkt_ov088_021BB5C4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frees the eight row buffers at +0xF8 allocated by func_021BB544.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

extern void func_020307B0(void *);

void func_021BB5C4(char *p)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        func_020307B0(*(void **)(p + 0xf8 + i * 4));
}
