/*
 * function: func_021C3638
 * address:  0x021C3638
 * packet:   pkt_021C3638
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Releases the three handles at +0x2C, +0x20 and +0x14.
 */


extern void func_020437AC(int);
extern void func_020452E8(int);
extern void func_020307B0(int);

void func_021C3638(int unused, char *p)
{
    func_020437AC(*(int *)(p + 0x2c));
    func_020452E8(*(int *)(p + 0x20));
    func_020307B0(*(int *)(p + 0x14));
}

