/*
 * function: func_021DED74
 * address: 0x021DED74
 * packet: pkt_ov119_021DED74
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DED58 0x021DED58 thumb ov119
 */
typedef unsigned short u16;
extern void func_0202208C(int,int,int,int,int,int,int);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
extern void func_021DED58(void *);
void func_021DED74(void *p) {
 if(!func_021D8A24(p) || *(int *)((char *)p+0x1060)) {
  func_0202208C(0,0,0,0,6,1,*(u16 *)((char *)p+0x5f4));
  func_021D8E84(p,(int)func_021DED58);
 }
}
