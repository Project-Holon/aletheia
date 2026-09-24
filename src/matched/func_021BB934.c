/*
 * function: func_021BB934
 * address:  0x021BB934
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BA850  0x021BA850  arm  ov114
 *   func_021BB8F0  0x021BB8F0  arm  ov114
 *   func_021BEBE0  0x021BEBE0  arm  ov114
 *
 *
 * Releases the record's four handles plus the record itself, then clears the +0x10 slot of the module view.
 */

typedef unsigned char u8;
typedef unsigned int u32;
u8 *func_021BEBE0(int, int);
void func_021BB8F0(u32);
void func_021BA850(u32);

int func_021BB934(int a, u8 *b)
{
    u8 *p = func_021BEBE0(a, (int)b);

    if (p != 0)
        *(u32 *)(p + 0x10) = 0;
    func_021BB8F0(*(u32 *)(b + 0x30));
    func_021BB8F0(*(u32 *)(b + 0x34));
    func_021BA850(*(u32 *)(b + 0x24));
    func_021BA850(*(u32 *)(b + 0x28));
    func_021BA850((u32)b);
    return 1;
}
