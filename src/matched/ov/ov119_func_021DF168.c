/*
 * function: func_021DF168
 * address: 0x021DF168
 * packet: pkt_ov119_021DF168
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: field p+0x11fa re-read at 0x021DF18E after store at 0x021DF18C.
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021E4888 0x021E4888 thumb ov119
 *   func_020435F4 0x020435F4 arm
 *   func_02022230 0x02022230 thumb
 *   func_021D89CC 0x021D89CC thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_021DF0B8 0x021DF0B8 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
typedef unsigned int   u32;
extern u32 func_020221A4(void);
extern void func_021E4888(char *p);
extern void func_020435F4(u32 planes);
extern void func_02022230(u32 which);
extern void func_021D89CC(char *p);
extern void func_021D9434(void *);
extern void func_021DF0B8(char *p);
extern void func_021D8E84(void *,int);
extern unsigned func_020399A8(void);
extern void func_02039C68(unsigned,unsigned,unsigned);
void func_021DF168(void *p) {
 if(func_020221A4()) {
  func_021E4888(p);func_020435F4(4);func_02022230(4);
  ++*(volatile unsigned char *)((char *)p+0x11fa);
  if(*(volatile unsigned char *)((char *)p+0x11fa)>=3) {func_021D89CC(p);func_021D8E84(p,(int)func_021D9434);return;}
  func_02039C68(func_020399A8(),31,8);func_021D8E84(p,(int)func_021DF0B8);
 }
}
