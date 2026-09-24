/*
 * function: func_021ED544
 * address:  0x021ED544
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBFA8  0x021EBFA8  thumb  ov170
 *
 * Offset by four when the low nibble of 0x1c is set.
 */



struct Slot { unsigned char a[0x1c]; unsigned char f : 4; };
extern void func_021EBFA8(char *, int, int);
void func_021ED544(char *p, int b)
{
    if (((struct Slot *)p)->f)
        b += 4;
    func_021EBFA8(*(char **)(p + 0x2c), 4, b);
}
