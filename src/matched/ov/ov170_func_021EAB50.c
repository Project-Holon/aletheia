/*
 * function: func_021EAB50
 * address: 0x021EAB50
 * packet: pkt_ov170_021EAB50
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 */
#define WORK(p) (*(char **)((p)+0x2C))
extern int func_0201C4E4(void *);
extern int func_0201C6C4(void *,void *);
extern void *func_02045770(void *);
extern void func_02045334(void *);
void func_021EAB50(unsigned char *w) {
 unsigned i; void *print;
 func_0201C4E4(*(void **)(w+0x8C));
 for(i=0;i<28;i++) {
  print=*(void **)(w+0x8C);
  if(w[0x98+i*8]) {
   if(func_0201C6C4(print,func_02045770(*(void **)(w+i*8+0x94)))==0) {
    func_02045334(*(void **)(w+i*8+0x94));
    w[0x98+i*8]=0;
   }
  }
 }
}
