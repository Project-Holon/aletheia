/*
 * function: func_02178CDC
 * address: 0x02178CDC
 * packet: pkt_ov014_02178CDC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02178138 0x02178138 thumb ov014
 *   func_0217814C 0x0217814C thumb ov014
 *   func_0208F400 0x0208F400 arm
 *   func_02178D00 0x02178D00 thumb ov014
 */
typedef unsigned char u8;
extern void func_02178138(int);
extern void func_0217814C(int);
extern void func_02178D00(u8 *);
extern int func_0208F400(void (*)(u8 *));
int func_02178CDC(void) {
 int r;
 func_02178138(3);
 r = func_0208F400(func_02178D00);
 if (r != 2) { func_0217814C(r); return 0; }
 return 1;
}
