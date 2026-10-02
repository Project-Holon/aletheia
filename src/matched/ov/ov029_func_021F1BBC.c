/*
 * function: func_021F1BBC
 * address: 0x021F1BBC
 * packet: pkt_ov029_021F1BBC
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
extern void func_0204B3B4(int);
void func_021F1BBC(char *p)
{
    int i;
    if (*(int *)(p + 0x170) != 0) {
        for (i = 0; i < 18; i++) {
            func_0204B3B4(*(int *)(p + i * 4 + 0x170));
            *(int *)(p + i * 4 + 0x170) = 0;
        }
    }
}
