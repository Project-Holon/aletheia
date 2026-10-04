/*
 * function: func_02176C00
 * address:  0x02176C00
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call passing the address of func_02195CC0 as the first argument.
 *
 * symbols:
 *   func_02195CC0  0x02195CC0  arm  ov009
 *   func_02176C14  0x02176C14  arm  ov009
 */

extern void func_02195CC0(void);
extern int func_02176C14(int (*func)(void *, unsigned char *, int, int));

void func_02176C00(void)
{
    func_02176C14((int (*)(void *, unsigned char *, int,  int))func_02195CC0);
}

