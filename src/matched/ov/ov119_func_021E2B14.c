/*
 * function: func_021E2B14
 * address: 0x021E2B14
 * packet: pkt_ov119_021E2B14
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   func_02046858 0x02046858 arm
 *   d_021E799C 0x021E799C data a4
 *   d_021F4560 0x021F4560 data a4
 *   d_021E7B1C 0x021E7B1C data a4
 *   d_020A1DF8 0x020A1DF8 data a2
 */
typedef struct {int a,b,c,d,e,f,g,h;} Config;
extern const Config d_021E7B1C;
extern char d_021E799C[];
extern void *d_021F4560;
extern short d_020A1DF8[];
extern void *func_02048BC4(void *,int);
extern void func_02048C58(void *);
extern void func_02046858(Config *);
void func_021E2B14(int a) {
    Config c;
    d_021F4560=func_02048BC4(d_021E799C,a);
    func_02048C58(d_021F4560);
    c=d_021E7B1C;
    c.b=d_020A1DF8[12]; c.c=d_020A1DF8[13];
    func_02046858(&c);
}
