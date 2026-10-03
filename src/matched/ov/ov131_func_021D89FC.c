/*
 * function: func_021D89FC
 * address: 0x021D89FC
 * packet: pkt_ov131_021D89FC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021DBC3C 0x021DBC3C thumb ov131
 *   func_020437AC 0x020437AC arm
 */
typedef unsigned char  u8;
struct Obj;
struct Obj020437AC;
extern void func_0204B3B4(struct Obj *p);
extern void func_021DBC3C(u8 *p);
extern void func_020437AC(struct Obj020437AC *p);
struct E { unsigned char p[0x7c]; void *f7c; void *f80; unsigned char q[0x14 - 0x8]; };
void func_021D89FC(void *unused, unsigned char *s) {
 unsigned char i;
 func_0204B3B4(*(void **)(s + 0x54));
 for (i = 0; i < 10; i++) {
  struct E *e = (struct E *)(s + i * 20);
  func_021DBC3C(e->f80);
  func_020437AC(e->f7c);
 }
}
