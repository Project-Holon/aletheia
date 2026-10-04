/*
 * function: func_021BF6B0
 * address:  0x021BF6B0
 * packet:   pkt_021BF6B0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BF6B0 0x021BF6B0 arm
 *
 * Feed the two words at +0x58 and +0x5c of the object behind 0x021DE560 to the library.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void func_021D4F60(u8 *p);
extern void func_021D771C(char *p, unsigned int v);

void func_021BF6B0(void)
{
    func_021D4F60((u8 *)(*(int *)(*(char **)0x021DE560 + 0x58)));
    func_021D771C((char *)(*(int *)(*(char **)0x021DE560 + 0x5c)), (unsigned int)((void *)0x021C0528));
}
