/*
 * function: func_021E8FE8
 * address:  0x021E8FE8
 * packet:   pkt_ov170_021E8FE8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DCF58 0x021DCF58 thumb
 *   func_02036270 0x02036270 arm
 *
 * Opens the yes/no menu with the cursor on sel and enters state 7.
 */

extern void func_021DCF58(unsigned char *p, int sel);
extern void func_02036270(unsigned a, unsigned b);

#define WORK(p) (*(char **)((p) + 0x2C))

int func_021E8FE8(unsigned char *p, int sel)
{
    *(unsigned short *)(WORK(p) + 0x1A4) = sel;
    if (sel == 1)
        func_021DCF58(p, 1);
    else
        func_021DCF58(p, 0);
    func_02036270(*(unsigned *)(WORK(p) + 0x4C), *(unsigned *)(WORK(p) + 0x50));
    return 7;
}
