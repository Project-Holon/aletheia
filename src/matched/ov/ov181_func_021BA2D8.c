/*
 * function: func_021BA2D8
 * address: 0x021BA2D8
 * packet: pkt_ov181_021BA2D8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: The progress field at +0x1c is re-read at 0x021BA2F8 after its store at 0x021BA2F6.
 * symbols:
 *   func_0207D658 0x0207D658 arm
 */
extern void func_0207D658(unsigned, int, int);
void func_021BA2D8(char *p)
{
    int v = *(int *)(p + 0x1c);
    if (v <= 0x10000) {
        *(int *)(p + 0x1c) = v + (*(unsigned char *)(p + 0x2d2) == 1 ? 0x400 : 0x100);
        func_0207D658(0x04000050, 1, *(volatile int *)(p + 0x1c) / 0x1000 - 0x10);
    }
}
