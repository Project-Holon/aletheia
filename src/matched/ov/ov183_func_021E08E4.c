/*
 * function: func_021E08E4
 * address: 0x021E08E4
 * packet: pkt_ov183_021E08E4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E0952 alignment padding.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021E10BC 0x021E10BC thumb ov183
 */
extern void func_0204B3B4(void *);
extern void func_021E10BC(char *);
void func_021E08E4(char *p)
{
    int i;
    for (i = 0; i < *(int *)(p + 0x23c); i++) func_0204B3B4(*(void **)(p + i * 28 + 12));
    for (i = 0; i < 2; i++) {
        func_0204B3B4(*(void **)(p + i * 28 + 0x15c));
        func_0204B3B4(*(void **)(p + i * 28 + 0x1e8));
    }
    for (i = 0; i < 3; i++) func_0204B3B4(*(void **)(p + i * 28 + 0x194));
    func_021E10BC(p);
}
