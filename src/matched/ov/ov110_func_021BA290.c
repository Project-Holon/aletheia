/*
 * function: func_021BA290
 * address: 0x021BA290
 * packet: pkt_ov110_021BA290
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF71C 0x021BF71C thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021BC728 0x021BC728 thumb ov110
 *   func_021BC704 0x021BC704 thumb ov110
 *   func_021BF714 0x021BF714 thumb ov110
 *   func_021BC72C 0x021BC72C thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 func_021BF71C(u8 *);
extern void func_021BCF7C(u8 *, u8, int);
extern void func_021BC728(u8 *);
typedef unsigned int   u32;
extern void func_021BC704(u8 *p, u32 flag);
extern u16 func_021BF714(u8 *);
extern void func_021BC72C(u8 *, int);
extern void func_021B9CBC(u8 *);
void func_021BA290(int unused, u8 *p) {
    u8 *q = *(u8 **)p;
    q[0x74] = 0;
    func_021BCF7C(*(u8 **)(q+0x64), func_021BF71C(*(u8 **)(q+0x18)), 0);
    func_021BC728(*(u8 **)(q+0x54));
    func_021BC704(*(u8 **)(q+0x54), 1);
    func_021BC72C(*(u8 **)(q+0x54), func_021BF714(*(u8 **)(p+4)));
    func_021B9CBC(p);
}
