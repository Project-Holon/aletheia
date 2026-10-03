/*
 * function: func_021D9254
 * address: 0x021D9254
 * packet: pkt_ov121_021D9254
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D928C 0x021D928C thumb ov121
 *   func_021D933C 0x021D933C thumb ov121
 */
extern void func_021D928C(void),func_021D933C(void);
void func_021D9254(char *p,int n) {
 *(unsigned *)p=1;
 *(unsigned short *)(p+8)=0;
 *(unsigned *)(p+20)=*(unsigned *)(p+16);
 switch(n) {case 0: *(unsigned *)(p+0x11c)=(unsigned)func_021D928C;break;case 1:*(unsigned *)(p+0x11c)=(unsigned)func_021D933C;break;}
}
