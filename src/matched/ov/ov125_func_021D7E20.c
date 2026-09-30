/*
 * function: func_021D7E20
 * address: 0x021D7E20
 * packet: pkt_ov125_021D7E20
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_021D7D88 0x021D7D88 arm ov125
 *   func_0215F650 0x0215F650 arm ov009
 *   func_0215FA9C 0x0215FA9C arm ov009
 */
extern int func_021D7D88(const char *);
extern void *func_0215F650(const char *);
extern char *func_0215FA9C(unsigned);
extern void func_02094798(char *, const char *);
int func_021D7E20(const char *s, char *out) {
 void *p;
 if (!func_021D7D88(s)) {
  p=func_0215F650(s);
  if (p) {
   func_02094798(out, func_0215FA9C(*** (unsigned ***)((char *)p+12)));
  } else return 0;
 } else {
  func_02094798(out,s);
 }
 return 1;
}
