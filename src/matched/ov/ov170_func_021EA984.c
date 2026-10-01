/*
 * function: func_021EA984
 * address: 0x021EA984
 * packet: pkt_ov170_021EA984
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EF480 0x021EF480 thumb ov170
 */
#define WORK(p) (*(char **)((p)+0x2C))
extern void func_021ECB20(unsigned char *,int,int);
extern void func_021ED888(char *,int);
extern int func_021EF480(int);
void func_021EA984(unsigned char *p) {
 switch(*(unsigned *)(*(char **)p+0x24)) {
 case 0: func_021ECB20(p,2,1); return;
 case 1: case 3: func_021ED888(WORK(p),0); func_021ECB20(p,1,1); return;
 case 2: case 4: case 5:
  func_021ED888(WORK(p),0);
  if(func_021EF480(*(int *)(WORK(p)+0x74))==1) {
   func_021ECB20(p,2,1); return;
  } else { func_021ECB20(p,1,1); return; }
 }
}
