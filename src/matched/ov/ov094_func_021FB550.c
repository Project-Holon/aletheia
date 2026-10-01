/*
 * function: func_021FB550
 * address:  0x021FB550
 * packet:   pkt_ov094_021FB550
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: func_0204047C(3, arg) and sets flag bit 4.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0204047C 0x0204047C arm
 */
extern int func_0201134C(void *);
extern void func_0204047C(int, unsigned char);

int func_021FB550(void *a, char *s)
{
    func_0204047C(3, func_0201134C(a));
    *(unsigned *)s |= 0x10;
    return *(int *)(s + 0x23c);
}
