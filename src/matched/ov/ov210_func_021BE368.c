/*
 * function: func_021BE368
 * address: 0x021BE368
 * packet: pkt_ov210_021BE368
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_021BE4B4 0x021BE4B4 thumb ov210
 *   d_021C0900 0x021C0900 data a1
 */
typedef unsigned char u8;
struct Record { u8 a, b, c, d, e, f; };
extern const struct Record d_021C0900[];
extern void func_02045088(unsigned short);
extern unsigned func_020450F0(unsigned, unsigned, unsigned, unsigned, u8, u8, u8);
extern void func_021BE4B4(u8 *);
void func_021BE368(u8 *p)
{
    unsigned i;
    func_02045088(123);
    for (i = 0; i < 16; i++) {
        const struct Record *r = &d_021C0900[i];
        *(unsigned *)(p + i * 8 + 0x14c) = func_020450F0(r->a, r->b, r->c, r->d, r->e, r->f, 1);
    }
    func_021BE4B4(p);
}
