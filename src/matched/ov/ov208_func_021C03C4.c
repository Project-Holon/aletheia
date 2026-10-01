/*
 * function: func_021C03C4
 * address: 0x021C03C4
 * packet: pkt_ov208_021C03C4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: 021C044E..021C0450 is two zero alignment bytes, not a follower.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204B084 0x0204B084 arm
 */
typedef unsigned char u8;
struct Obj;
struct Bank;
extern void func_0204B3B4(struct Obj *);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204B1CC(struct Bank *);
extern void func_0204B084(void *);
void func_021C03C4(void *unused, char *p)
{
    u8 i;
    for (i = 0; i < 7; i++) func_0204B3B4(*(struct Obj **)(p + i * 4 + 0xbc));
    func_0204AFD8(*(unsigned *)(p + 0xb8));
    func_0204A8D4(*(unsigned *)(p + 0xb0));
    func_0204ADA4(*(unsigned *)(p + 0xb4));
    func_0204AFD8(*(unsigned *)(p + 0xac));
    func_0204A8D4(*(unsigned *)(p + 0xa4));
    func_0204ADA4(*(unsigned *)(p + 0xa8));
    func_0204AFD8(*(unsigned *)(p + 0xa0));
    func_0204A8D4(*(unsigned *)(p + 0x98));
    func_0204ADA4(*(unsigned *)(p + 0x9c));
    func_0204B1CC(*(struct Bank **)(p + 0x1d0));
    func_0204B084(*(void **)(p + 0x1d4));
}
