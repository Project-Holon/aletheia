/*
 * function: func_021BC6F8
 * address:  0x021BC6F8
 * packet:   pkt_021BC6D8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC6C8 0x021BC6C8  thumb  ov208
 *   func_021BC7B4 0x021BC7B4  thumb  ov208

 * Runs the idle transition with 0x10 in the fourth argument and marks state 3.
 */


extern int func_021BC6C8(char *);
extern void func_021BC7B4(char *p, short b, unsigned char c, unsigned char d);

void func_021BC6F8(char *p)
{
    if (func_021BC6C8(p))
        return;
    func_021BC7B4(p, -1, 0, 0x10);
    *(int *)(p + 0x10) = 3;
}

