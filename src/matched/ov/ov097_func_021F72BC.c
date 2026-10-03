/*
 * function: func_021F72BC
 * address: 0x021F72BC
 * packet: pkt_ov097_021F72BC
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
struct Obj;
struct Bank;
extern void func_0204B3B4(struct Obj *);
extern void func_0204B1CC(struct Bank *);
void func_021F72BC(char *p)
{
    unsigned i;
    for (i = 0; i < 24; i++)
        func_0204B3B4(*(struct Obj **)(p + i * 4 + 0x54));
    func_0204B1CC(*(struct Bank **)(p + 0x50));
}
