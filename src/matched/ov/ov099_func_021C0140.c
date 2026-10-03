/*
 * function: func_021C0140
 * address: 0x021C0140
 * packet: pkt_ov099_021C0140
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
extern unsigned int func_020362DC(void);
extern void func_021BAAB8(char *,int,int);
int func_021C0140(char *p,int ret) {
 if (*(int *)(p+0x1e0)>0) { --*(int *)(p+0x1e0); return ret; }
 if (func_020362DC()&3) {
  func_021BAAB8(p,26,1);
  *(int *)(p+0x1cc)=51;
  *(int *)(p+0x1e0)=1;
 }
 return ret;
}
