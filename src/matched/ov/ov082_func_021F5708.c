/*
 * function: func_021F5708
 * address:  0x021F5708
 * packet:   pkt_ov082_021F5708
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);

int func_021F5708(char *p)
{
    int q;

    *(u16 *)(p + 0x24) = *(u16 *)(p + 0x24) + 1;
    q = (*(u16 *)(p + 0x24) << 4) / 30;
    func_0207D63C(0x04000050, 8, 4, q, 16 - q);
    if (*(u16 *)(p + 0x24) >= 30)
        return 1;
    return 0;
}
