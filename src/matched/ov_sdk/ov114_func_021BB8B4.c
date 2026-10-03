/*
 * function: func_021BB8B4
 * address:  0x021BB8B4
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
 *   func_021BB934  0x021BB934  arm  ov114
 *   func_021BEBE0  0x021BEBE0  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *
 *
 * Unlinks the record from the module's list, releases its handle and then tears the record down.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void *func_021BEF58(int p);
u8 *func_021BEBE0(int, int);
void func_021BA850(int a);
int func_021BB934(int, u8 *);

void func_021BB8B4(int a, u8 *b)
{
    void *p = func_021BEF58(a);
    u8 *r = func_021BEBE0((int)p, (int)b);

    if (r != 0)
        *(u32 *)(r + 0x14) = 0;
    func_021BA850(*(u32 *)(b + 0x2c));
    func_021BB934((int)p, b);
}
