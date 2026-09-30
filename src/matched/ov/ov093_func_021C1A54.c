/*
 * function: func_021C1A54
 * address: 0x021C1A54
 * packet: pkt_ov093_021C1A54
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1CE4 0x021C1CE4 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C1B5C 0x021C1B5C thumb ov093
 *   func_021C1B2C 0x021C1B2C thumb ov093
 *   func_021C1B3C 0x021C1B3C thumb ov093
 *   func_021C1B4C 0x021C1B4C thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 *   func_021C1C88 0x021C1C88 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C1CE4(u8 *, u8 *, u8 *, u8 *);
extern u32 func_021CC8D8(void *, int);
extern void func_021C1B5C(u8 *, u8 *, u8 *, u8 *, u32, int, int);
extern void func_021C1B2C(u8 *);
extern u8 *func_021C1B3C(u8 *);
extern u8 *func_021C1B4C(u8 *);
extern void func_021C195C(u8 *, u8 *, u32);
extern void func_021C1C88(u8 *, u8 *, u8 *, u8 *, u32);
extern void func_021CC95C(void *, u32, int);
void func_021C1A54(u8 *p, u8 *a, u8 *b, u8 *c, u32 unused, u32 d)
{
    u32 lock;
    u8 *x;
    func_021C1CE4(p, a, b, c);
    lock = func_021CC8D8(p + 0x1d74, 0x1b07);
    func_021C1B5C(p, b, c, a, d, 0, 0x84);
    func_021C1B5C(p, b, c, a, d, 1, 0x83);
    func_021C1B5C(p, b, c, a, d, 0, 0x85);
    func_021C1B2C(c);
    x = func_021C1B3C(c);
    while (x) {
        func_021C195C(p, x, 1);
        x = func_021C1B4C(c);
    }
    func_021C1B5C(p, b, c, a, d, 0, 0x86);
    func_021C1B5C(p, b, c, a, d, 1, 0x87);
    func_021C1C88(p, b, c, a, d);
    func_021CC95C(p + 0x1d74, lock, 0x1b1b);
}
