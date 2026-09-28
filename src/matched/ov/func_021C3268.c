/*
 * function: func_021C3268
 * address:  0x021C3268
 * packet:   pkt_021C3268
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Clears +0x10 and releases the two handles at +8 and +0xC.
 */


extern void func_0201C6EC(int);
extern void func_020452E8(int);

void func_021C3268(int unused, char *p)
{
    *(int *)(p + 0x10) = 0;
    func_0201C6EC(*(int *)(p + 8));
    func_020452E8(*(int *)(p + 0xc));
}

