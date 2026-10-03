/*
 * function: func_021B64DC
 * address: 0x021B64DC
 * packet: pkt_ov180_021B64DC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017D30 0x02017D30 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017D70 0x02017D70 thumb
 */
extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *,unsigned);
typedef unsigned int   u32;
struct Sav;
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017D70(struct Sav *p, u32 f);
void func_021B64DC(unsigned char *p) {
 unsigned i; void *mon; unsigned saved;
 p[0x915E]=0;
 for(i=0;i<func_0201AA18(**(void ***)p);i++) {
  mon=func_0201AB28(**(void ***)p,i); saved=func_02017D30(mon);
  if(func_02017E1C(mon,76,0)==0) { *(void **)(p+(unsigned char)p[0x915E]*4+0x9140)=mon; p[0x915E]++; }
  func_02017D70(mon,saved);
 }
}
