/*
 * function: func_021C5470
 * address:  0x021C5470
 * packet:   pkt_ov136_021C5470
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5470 0x021C5470 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 */
typedef unsigned char u8;
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
void func_021C5470(u8 *p)
{
    func_0204B1CC(*(void **)(p + 0xa0));
    func_0204A5AC();
}
