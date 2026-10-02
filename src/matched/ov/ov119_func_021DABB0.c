/*
 * function: func_021DABB0
 * address: 0x021DABB0
 * packet: pkt_ov119_021DABB0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E5098 0x021E5098 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAB34 0x021DAB34 thumb ov119
 */
extern void func_021E5098(char *,int),func_021E4E64(int,void *,int),func_021D8E84(char *,int),func_021DAB34(char *);
void func_021DABB0(char *p) {
 func_021E5098(p,*(int *)(p+0xf2c)-1);
 if(*(int *)(p+0xf2c)>25) {
  func_021E4E64(*(int *)(p+0x828),p,0);
  func_021D8E84(p,(int)func_021DAB34);
 }
}
