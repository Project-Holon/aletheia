/*
 * function: func_021F9008
 * address:  0x021F9008
 * packet:   pkt_021F9008
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD860   0x021FD860  thumb
 *   func_020061E4   0x020061E4  thumb
 *
 * Range-gate the pair then hand them to 0x21FD860 as a two-word record.
 */


extern void func_021FD860(int, int, int *);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);

int func_021F9008(int a, int b, int c)
{
    int ok = ((unsigned)(b - 0x18) <= 0x28) & ((unsigned)(c - 0x40) <= 0x28);
    if (ok) {
        int buf[2];
        buf[0] = b;
        buf[1] = c;
        func_021FD860(*(int *)(a + 0x3C), 1, buf);
        func_020061E4(0x703);
    }
    return ok;
}
