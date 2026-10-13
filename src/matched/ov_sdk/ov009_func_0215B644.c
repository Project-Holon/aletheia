/*
 * function: set_fixed_ip
 * address:  0x0215B644
 * packet:   pkt_0215B644
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021A826C     0x021A826C  data
 *   garprequest  0x0215B5C4  arm
 *   func_02157290  0x02157290  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
extern u8 d_021A826C[];
extern int garprequest(void);
extern void func_02157290(int);

void set_fixed_ip(void)
{
    ((void (*)(void))(*(unsigned int *)(d_021A826C + 0x28)))();
    if (*(unsigned int *)(d_021A826C + 0x50) == 0)
        return;
    if (garprequest() != 0)
        return;
    func_02157290(4);
}
