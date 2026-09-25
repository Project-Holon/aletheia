/*
 * function: func_021F21BC
 * address:  0x021F21BC
 * packet:   pkt_021F21BC
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045A98 0x02045A98 arm
 *   func_021F23FC 0x021F23FC thumb
 */

extern unsigned short func_02045A98(void);
extern void func_021F23FC(unsigned char *, int);

int func_021F21BC(unsigned char *p, unsigned short a, unsigned short b)
{
    if (*(unsigned short *)(p + 0x1e) < *(unsigned short *)(p + 0x22) &&
        *(unsigned short *)(p + 0x20) < 3) {
        *(unsigned short *)(p + 0x16 + *(unsigned short *)(p + 0x20) * 2) = a;
        *(unsigned short *)(p + 0x20) += 1;
        *(unsigned short *)(p + 0x16 + *(unsigned short *)(p + 0x20) * 2) =
            func_02045A98();
        func_021F23FC(p, b);
        *(int *)(p + 0x28) = 1;
        return 1;
    }
    return 0;
}
