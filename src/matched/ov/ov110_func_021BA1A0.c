/*
 * function: func_021BA1A0
 * address: 0x021BA1A0
 * packet: pkt_ov110_021BA1A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_021BC23C 0x021BC23C thumb ov110
 *   func_021BF714 0x021BF714 thumb ov110
 *   func_021BC72C 0x021BC72C thumb ov110
 *   func_021BCCA8 0x021BCCA8 thumb ov110
 *   func_021BCD44 0x021BCD44 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BC23C(void *);
extern u16 func_021BF714(u8 *);
extern void func_021BC72C(u8 *, int);
extern void func_021BCCA8(void *);
extern void func_021BCD44(u8 *p);
extern void func_021B9CBC(u8 *);
void func_021BA1A0(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 **)p;
    q[0x74] = 0;
    func_021BC23C(*(void **)(q + 0x54));
    func_021BC72C(*(u8 **)(q + 0x54), func_021BF714(*(u8 **)(p + 4)));
    func_021BCCA8(*(void **)(q + 0x64));
    func_021BCD44(*(void **)(q + 0x64));
    func_021B9CBC(p);
}
