/*
 * function: func_021F2150
 * address:  0x021F2150
 * packet:   pkt_021F2150
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045A98 0x02045A98 arm
 */

extern unsigned short func_02045A98(void);

int func_021F2150(unsigned char *p)
{
    if (*(unsigned short *)(p + 0x20) != 0) {
        *(unsigned short *)(p + 0x20) -= 1;
        *(unsigned short *)(p + 0x16 + *(unsigned short *)(p + 0x20) * 2) =
            func_02045A98();
        *(int *)(p + 0x28) = 1;
        return 1;
    }
    if (*(unsigned short *)(p + 0x1e) != 0) {
        *(unsigned short *)(p + 0x1e) -= 1;
        *(unsigned short *)(p + *(unsigned short *)(p + 0x1e) * 2) =
            func_02045A98();
        *(int *)(p + 0x28) = 1;
        return 1;
    }
    return 0;
}
