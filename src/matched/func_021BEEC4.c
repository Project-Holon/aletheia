/*
 * function: func_021BEEC4
 * address:  0x021BEEC4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BA7DC  0x021BA7DC  arm  ov114
 *   func_021BACEC  0x021BACEC  arm  ov114
 *   func_021BB3C0  0x021BB3C0  arm  ov114
 *   func_021BBE94  0x021BBE94  arm  ov114
 *   func_021BEF3C  0x021BEF3C  arm  ov114
 *   func_021BEF40  0x021BEF40  arm  ov114
 *   func_021BEF48  0x021BEF48  arm  ov114
 *   func_021BEF50  0x021BEF50  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   func_021BEF98  0x021BEF98  arm  ov114
 *
 *
 * Constructs the module object: zeroes each of its four sub-blocks.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void func_021BEF3C(void);
void func_021BA7DC(void);
u8 *func_021BEF40(int);
void func_021BACEC(u8 *);
u8 *func_021BEF48(int);
void func_021BB3C0(u8 *);
u8 *func_021BEF58(int);
void func_021BEF98(u8 *);
u8 *func_021BEF50(int);
void func_021BBE94(u8 *);

void func_021BEEC4(u8 *p)
{
    func_021BEF3C();
    func_021BA7DC();
    func_021BACEC(func_021BEF40((int)p));
    func_021BB3C0(func_021BEF48((int)p));
    func_021BEF98(func_021BEF58((int)p));
    func_021BBE94(func_021BEF50((int)p));
}
