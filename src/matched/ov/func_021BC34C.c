/*
 * function: func_021BC34C
 * address:  0x021BC34C
 * packet:   pkt_021BC34C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Calls the ARM9 function at 0x020307B0 on the word at +0x10, then clears the field.
 */

extern void func_020307B0(int);

void func_021BC34C(char *p)
{
    func_020307B0(*(int *)(p + 0x10));
    *(int *)(p + 0x10) = 0;
}
