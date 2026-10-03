/*
 * function: func_021BA1D8
 * address: 0x021BA1D8
 * packet: pkt_ov110_021BA1D8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_021BAE24 0x021BAE24 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BAE24(void *, void *, void *);
extern void func_021B9CBC(u8 *);
void func_021BA1D8(void *unused, u8 *p)
{
    func_021BAE24(*(void **)p, *(void **)(p + 4), *(void **)(p + 8));
    func_021B9CBC(p);
}
