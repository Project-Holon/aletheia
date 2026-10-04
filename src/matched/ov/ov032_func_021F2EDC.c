/*
 * function: func_021F2EDC
 * address:  0x021F2EDC
 * packet:   pkt_ov032_021F2EDC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F2EDC 0x021F2EDC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021F31A8 0x021F31A8 thumb ov032
 */

extern void func_020307B0(void *p);
extern void func_021F31A8(char *, char *);

void func_021F2EDC(char *p)
{
    int i;

    for (i = 0; i < 12; i++) {
        func_020307B0((void *)(*(int *)(p + 0x2dc + i * 8)));
    }
    for (i = 0; i < 16; i++) {
        func_020307B0((void *)(*(int *)(p + 0x33c + i * 8)));
    }
    func_020307B0((void *)(*(int *)(p + 0x3cc)));
    func_020307B0((void *)(*(int *)(p + 0x3c0)));
    func_021F31A8(p, p + 0x14c);
    func_021F31A8(p, p + 0x164);
    func_021F31A8(p, p + 0x134);
}
