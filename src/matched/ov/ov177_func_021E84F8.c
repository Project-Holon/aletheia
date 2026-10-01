/*
 * function: func_021E84F8
 * address: 0x021E84F8
 * packet: pkt_ov177_021E84F8
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
extern unsigned func_02045770(void *);
extern int func_0201C6C4(void *, unsigned);
extern void func_02045334(void *);
int func_021E84F8(char *p, void *q)
{
 int result=1;
 unsigned i;
 for(i=0;(int)i<6;i++) {
 if(*(void **)(p+i*4+0x68)!=0) {
 unsigned char *e=(unsigned char *)p+i*8;
 if(e[0x84]!=0) {
 if(func_0201C6C4(q,func_02045770(*(void **)(e+0x80)))==0) {
 func_02045334(*(void **)((unsigned)p+(int)i*8+0x80));*(unsigned char *)((unsigned)p+(int)i*8+0x84)=0;
 }
 }
 result &= e[0x84]==0;
 }
 }
 return result;
}
