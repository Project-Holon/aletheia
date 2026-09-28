/*
 * function: func_021FD820
 * address:  0x021FD820
 * packet:   pkt_021FD820
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4   0x0204B3B4  arm
 *   func_021FC0C8   0x021FC0C8  thumb
 *   func_021FD714   0x021FD714  thumb
 *   func_020307B0   0x020307B0  arm
 *
 * Release the twelve handles at r5+0x1F8, then tear the object down.
 */


extern void func_0204B3B4(int);
extern void func_021FC0C8(int, int);
extern void func_021FD714(int);
extern void func_020307B0(int *);

void func_021FD820(char *r5)
{
    int i;
    for (i = 0; i < 0xC; i++)
        func_0204B3B4(*(int *)(r5 + 0x1F8 + i * 4));
    func_021FC0C8(*(int *)(r5 + 0x14), *(int *)(r5 + 0xC) + 9);
    func_021FD714(*(int *)(r5 + 0x10));
    func_020307B0((int *)r5);
}
