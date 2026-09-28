/*
 * function: func_021ED108
 * address:  0x021ED108
 * packet:   pkt_ov170_021ED108
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B570 0x0204B570 arm
 *   func_0204B588 0x0204B588 arm
 */

extern void func_0204B588(int, unsigned short *);
extern void func_0204B570(int, int);

#define HND(p) (*(int *)((p) + 0x9E9C))

void func_021ED108(char *p, int on)
{
    unsigned short s[2];
    if (on == 1) {
        func_0204B570(HND(p), 1);
        s[0] = 0xC;
        s[1] = 0xC;
        func_0204B588(HND(p), s);
    } else {
        s[0] = 0;
        s[1] = 0;
        func_0204B588(HND(p), s);
        func_0204B570(HND(p), 0);
    }
}
