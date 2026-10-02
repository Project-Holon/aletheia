/*
 * function: func_0215A990
 * address: 0x0215A990
 * packet: pkt_ov010_0215A990
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: result declared before pointer gives original r4/result, r5/base.
 * symbols:
 *   func_0215A954 0x0215A954 thumb ov010
 *   func_020362DC 0x020362DC arm
 *   func_0215A920 0x0215A920 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_0215A954(u8 *);
extern unsigned func_020362DC(void);
extern void func_0215A920(void *);
int func_0215A990(u8 *a) {
 int v;
 u8 *p;
 p = *(u8 **)(a + 32) + 52;
 v = func_0215A954(a);
 if (v == 0 && (func_020362DC() & 1024)) {
 func_0215A920(p);
 **(u16 **)(p + 8) = 65533;
 v = 1;
 }
 return v;
}
