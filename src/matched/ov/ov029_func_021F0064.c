/*
 * function: func_021F0064
 * address: 0x021F0064
 * packet: pkt_ov029_021F0064
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 */
extern int func_0204B98C(int a);
int func_021F0064(unsigned char *p, int a, int b)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (*(int *)(p + i * 12 + 0x3c) != 0 && *(int *)(p + i * 12 + 0x40) == a && *(int *)(p + i * 12 + 0x44) == b) {
            if (func_0204B98C(*(int *)(p + i * 12 + 0x3c)) != 0) return 0;
        }
    }
    return 1;
}
