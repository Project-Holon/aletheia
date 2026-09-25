/*
 * function: func_021F6508
 * address:  0x021F6508
 * packet:   pkt_021F6508
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F65B8 0x021F65B8 thumb
 *   func_021F6624 0x021F6624 thumb
 */

extern void func_021F65B8(void *);
extern void func_021F6624(void *);

void func_021F6508(int a, char *b)
{
    func_021F65B8(b);
    func_021F6624(b + 4);
}