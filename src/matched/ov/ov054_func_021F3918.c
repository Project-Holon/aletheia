/*
 * function: func_021F3918
 * address: 0x021F3918
 * packet: pkt_ov054_021F3918
 * region: ov054
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: Inline random call keeps the returned value on the right of the add.
 *       The final two bytes of the handed extent are alignment padding.
 * symbols:
 *   func_02005728 0x02005728 thumb
 */
extern unsigned func_02005728(unsigned);
void func_021F3918(char *p, int i)
{
    ((int *)(p + 0x10))[i] = ((int *)(p + 0x18))[i] +
        func_02005728(((int *)(p + 0x20))[i] - ((int *)(p + 0x18))[i] + 1);
}
