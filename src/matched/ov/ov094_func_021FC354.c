/*
 * function: func_021FC354
 * address:  0x021FC354
 * packet:   pkt_ov094_021FC354
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: sets flag bit 7, waits on func_021FC9E4, and suspends.
 *
 * symbols:
 *   func_020113D0 0x020113D0 thumb
 *   func_021FC9E4 0x021FC9E4 thumb ov094
 */
extern void func_020113D0(void *, int);
extern int func_021FC9E4(void *, void *);

int func_021FC354(void *a, char *s)
{
    *(unsigned *)s |= 0x80;
    func_020113D0(a, (int)func_021FC9E4);
    *(int *)(s + 0x23c) = 1;
    return 1;
}
