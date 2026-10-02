/*
 * function: func_02178C98
 * address: 0x02178C98
 * packet: pkt_ov014_02178C98
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02178138 0x02178138 thumb ov014
 *   func_0217814C 0x0217814C thumb ov014
 *   func_0208F938 0x0208F938 arm
 *   func_02178CC4 0x02178CC4 thumb ov014
 *   func_0217945C 0x0217945C thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02178138(int);
extern void func_0217814C(int);
extern void func_02178CC4(u8 *);
extern void func_0217945C(void);
extern int func_0208F938(void (*)(u8 *), u16);
int func_02178C98(void) {
 int r;
 int result = 0;
 func_02178138(3);
 r = func_0208F938(func_02178CC4, 0);
 if (r != 2) { func_0217814C(r); func_0217945C(); return result; }
 return 1;
}
