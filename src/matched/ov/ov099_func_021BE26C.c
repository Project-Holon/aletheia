/*
 * function: func_021BE26C
 * address: 0x021BE26C
 * packet: pkt_ov099_021BE26C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9670 0x021B9670 thumb ov099
 *   func_021C203C 0x021C203C thumb ov099
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void func_021B9670(char *);
extern void func_021C203C(char *,int);
extern void MI_CpuFill8(void *,int,int);
void func_021BE26C(char *p) {
 int i;
 func_021B9670(p+0x274);
 for (i=0;i<33;i++) {
  *(int *)((unsigned int)p+(unsigned int)i*4+0x814)=0;
  func_021C203C(p,i+1);
 }
 MI_CpuFill8(p+0x50,0,32);
}
