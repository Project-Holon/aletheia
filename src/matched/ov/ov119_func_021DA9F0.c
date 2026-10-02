/*
 * function: func_021DA9F0
 * address: 0x021DA9F0
 * packet: pkt_ov119_021DA9F0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_020221A4 0x020221A4 thumb
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA8F8 0x021DA8F8 thumb ov119
 */
extern int func_021E12AC(void *);
extern int func_020221A4(void);
extern void func_021E1098(void *);
extern void func_021D8E84(void *,int);
extern void func_021DA8F8(void *);
void func_021DA9F0(void *p) {
 if(func_021E12AC(p) && func_020221A4()) {
  func_021E1098(p);
  func_021D8E84(p,(int)func_021DA8F8);
 }
}
