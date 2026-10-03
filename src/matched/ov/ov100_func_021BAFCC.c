/*
 * function: func_021BAFCC
 * address: 0x021BAFCC
 * packet: pkt_ov100_021BAFCC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA290 0x021BA290 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAD78 0x021BAD78 thumb ov100
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Word { int x; };
extern void func_021BA5F4(int),func_021BA3A4(struct Word *,int),func_021BA290(int,int),func_021B95B8(u8 *,u32),func_021BAD78(int);
void func_021BAFCC(int p) {
    struct Word x;
    func_021BA5F4(p);
    x.x=12;
    func_021BA3A4(&x,p);
    func_021BA290(p,0);
    func_021B95B8((u8 *)p,(u32)func_021BAD78);
}
