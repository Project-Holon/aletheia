/*
 * function: func_021C0290
 * address: 0x021C0290
 * packet: pkt_ov099_021C0290
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021C02C6.
 * symbols:
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned short u16;
struct Obj;
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *,u16 *,u16 *);
extern void func_0201F868(void *);
extern void func_021BA8EC(char *);
void func_021C0290(char *p) {
 if (((struct Obj00008 *)p)->f1A4) {
  ((struct Obj00008 *)p)->f1A4=(void *)func_021BA8BC(((struct Obj00008 *)p)->f1A4);
  func_0202020C(*(struct Obj * *)&((struct Obj00008 *)p)->fBC,0,(u16 *)(p+0x23c));
  func_0201F868(((struct Obj00008 *)p)->fB8);
  func_021BA8EC(p);
 }
}
