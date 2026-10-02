/*
 * function: func_021F0A38
 * address: 0x021F0A38
 * packet: pkt_ov029_021F0A38
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F0B88 0x021F0B88 thumb ov029
 */
extern void func_021F0B88(void *p, void *q);
void func_021F0A38(unsigned char *p)
{
    int i, j;
    unsigned char *base;
    i = 0;
    base = p + 0x2d0;
    for (; i < 9; i++) {
        for (j = 0; j < 4; j++) func_021F0B88(base + i * 32 + j * 8, p);
    }
}
