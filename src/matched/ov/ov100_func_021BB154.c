/*
 * function: func_021BB154
 * address: 0x021BB154
 * packet: pkt_ov100_021BB154
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAEB4 0x021BAEB4 thumb ov100
 *   d_021BB660 0x021BB660 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Word { int x; };
extern const struct Word d_021BB660;
extern void func_021BA5F4(unsigned a);
extern void func_021BA3A4(struct Word *,int);
extern void func_021B95B8(u8 *,u32);
extern void func_021BAEB4(int);
void func_021BB154(int p) {
    struct Word x=d_021BB660;
    func_021BA5F4(p);
    func_021BA3A4(&x,p);
    func_021B95B8((u8 *)p,(u32)func_021BAEB4);
}
