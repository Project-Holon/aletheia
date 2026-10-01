/*
 * function: func_021F3364
 * address: 0x021F3364
 * packet: pkt_ov194_021F3364
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 */
extern void func_0207D63C(void *,int,int,int,int);
int func_021F3364(char *p,int mode) {
 int flag;
 if(*(int *)(p+0x114)!=mode) {
 *(int *)(p+0x114)=mode;*(unsigned short *)(p+0x10A)=0;*(unsigned short *)(p+0x10C)=0;*(int *)(p+0x110)=1;
 flag=0;
 if(mode==3 || *(int *)(p+0x100)==3)flag=1;
 *(int *)(p+0x118)=flag;
 if(flag)func_0207D63C((void *)0x04000050,14,47,16,16);
 else func_0207D63C((void *)0x04000050,10,47,16,16);
 return 1;
 }return 0;
}
