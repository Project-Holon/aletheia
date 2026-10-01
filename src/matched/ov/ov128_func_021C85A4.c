/*
 * function: func_021C85A4
 * address: 0x021C85A4
 * packet: pkt_ov128_021C85A4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CA40C 0x021CA40C thumb ov128
 *   func_021C88C0 0x021C88C0 thumb ov128
 *   func_021C899C 0x021C899C thumb ov128
 *   func_021CA2DC 0x021CA2DC thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_021CA40C(u8 *, int);
extern void func_021C88C0(s16 *, void *, u8 *);
extern void func_021C899C(u8 *, u8 *, u8 *, void *, u8 *, u8 *, int, u16);
extern void func_021CA2DC(u8 *);
void func_021C85A4(u8 *p, u8 *a, u8 *b, int x, int y, int n, u16 c)
{
    int offset;
    u8 *base;
    if (n == 0) {
        *(s16 *)p = x;
        *(s16 *)(p + 4) = y;
        func_021CA40C(p, x);
    }
    offset = n * 0x4c;
    base = p + 12;
    func_021C88C0((s16 *)(base + offset), b, b + 0x16c);
    func_021C899C(base + offset, a, b, *(void **)(p + 0x104), b + 0x16c, a + 16, x, c);
    func_021CA2DC(p);
}
