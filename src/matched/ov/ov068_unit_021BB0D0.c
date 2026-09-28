/*
 * unit:     yes
 * function: func_021BB0D0, func_021BB0D8
 * address:  0x021BB0D0
 * packet:   pkt_ov068_021BB0D0
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * ARM9 tail call then a byte read-modify-write.
 *
 * symbols:
 *   func_02012FFC  0x02012FFC  thumb
 */

void func_021BB0D0(void)
{
    void func_02012FFC(void);
    func_02012FFC();
}

int func_021BB0D8(void *p)
{
    unsigned char old = *(unsigned char *)((char *)p + 5);
    *(unsigned char *)((char *)p + 5) = 0xb;
    return old;
}
