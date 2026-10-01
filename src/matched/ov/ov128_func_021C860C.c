/*
 * unit: yes
 * function: func_021C860C, func_021C8660, func_021C8664, func_021C8668
 * address: 0x021C860C
 * packet: pkt_ov128_021C860C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CA40C 0x021CA40C thumb ov128
 *   func_021C88C0 0x021C88C0 thumb ov128
 *   func_021C8904 0x021C8904 thumb ov128
 *   func_021CA2DC 0x021CA2DC thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_021CA40C(u8 *, int);
extern void func_021C88C0(s16 *, void *, u8 *);
extern void func_021C8904(u8 *, u8 *, u8 *, void *, u8 *, u8 *, int, u16);
extern void func_021CA2DC(u8 *);
void func_021C860C(u8 *p, u8 *a, u8 *b, int x, int y, u16 c)
{
    *(s16 *)(p + 4) = y;
    *(s16 *)p = x;
    func_021CA40C(p, x);
    func_021C88C0((s16 *)(p + 12), b, b + 0x16c);
    func_021C8904(p + 12, a, b, *(void **)(p + 0x104), b + 0x16c, a + 16, x, c);
    func_021CA2DC(p);
}
void func_021C8660(void) {}
void func_021C8664(void) {}
void func_021C8668(u8 *p, u8 *a, int n)
{
    a[8] = 3;
    *(u16 *)(p + 0x102) = n;
    *(u16 *)(p + 0x100) = 0;
}
