/*
 * function: func_021D1F6C
 * address:  0x021D1F6C
 * packet:   pkt_021D1F6C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_021D1F6C   0x021D1F6C  arm
 *   func_021F1C30   0x021F1C30  arm
 *   func_021F5FB0   0x021F5FB0  arm
 *   func_02087988   0x02087988  arm
 *   func_0208799C   0x0208799C  arm
 *
 * PARKED: 49 bytes differ, ALL of them register naming only -- the image holds
 * the address of the 0x021DE65C global in r1 and its pointee in r3, the
 * compiler holds them in r0/r2.  Every instruction, the six-halfword
 * read-modify-write reload of the pointee and all four relocations reproduce.
 * Re-spelling the base as a local `unsigned int *g` or reading through the
 * macro changes nothing; this is the O39 note 2 register-naming class.
 *
 * If func_021F1C30(a, 1) reports busy, return; otherwise lock, clear bit a of
 * the six halfwords at (+2..+0xc) of the record published through 0x021DE65C,
 * unlock and hand a to func_021F5FB0. Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern int func_021F1C30(int, int);
extern void func_021F5FB0(int);
extern void func_02087988(void);
extern void func_0208799C(void);



void func_021D1F6C(int a)
{
    int one = 1;
    unsigned int *g;
    u16 m;

    if (func_021F1C30(a, one) != 0)
        return;

    m = (u16)~(one << a);

    func_02087988();

    g = (unsigned int *)0x021DE65C;

    ((u16 *)*g)[1] &= m;
    ((u16 *)*g)[2] &= m;
    ((u16 *)*g)[3] &= m;
    ((u16 *)*g)[4] &= m;
    ((u16 *)*g)[5] &= m;
    ((u16 *)*g)[6] &= m;

    func_0208799C();
    func_021F5FB0(a);
}
