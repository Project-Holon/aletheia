/*
 * function: func_021F1BE4
 * address: 0x021F1BE4
 * packet: pkt_ov029_021F1BE4
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 */
extern int func_0204B98C(int);
int func_021F1BE4(char *p)
{
    int i;
    for (i = 0; i < 18; i++) {
        if (func_0204B98C(*(int *)(p + i * 4 + 0x170)) == 1)
            return 0;
    }
    return 1;
}
