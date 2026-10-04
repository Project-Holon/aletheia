/*
 * function: func_021D5A2C
 * address:  0x021D5A2C
 * packet:   pkt_021D5A2C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D5A2C 0x021D5A2C arm
 *
 * Release the word at +0x28 then hand the record to the queue at +0x670.
 * Addresses are Black-image addresses.
 */

extern void func_021D71C0(void *ovram);
extern void func_021D546C(void *queue, void *data);

void func_021D5A2C(char *a)
{
    func_021D71C0((void *)(*(int *)(a + 0x28)));
    func_021D546C((void *)(*(int *)(*(char **)0x021DE680 + 0x670)), a);
}
