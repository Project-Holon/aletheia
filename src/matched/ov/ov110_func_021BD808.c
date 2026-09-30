/*
 * function: func_021BD808
 * address: 0x021BD808
 * packet: pkt_ov110_021BD808
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C38 0x02035C38 arm
 *   func_0203630C 0x0203630C arm
 */
typedef unsigned char u8;
extern int func_02035C38(void);
extern int func_0203630C(void);
int func_021BD808(u8 *p,void *q) {
 void (*cb)(u8 *,void *);
 if(*(int *)(p+0x70)==1) {
  if(func_02035C38()) return 0;
  if(func_0203630C()) { cb=*(void (**)(u8 *,void *))(p+0x74); *(int *)(p+0x70)=0; if(cb) cb(p,q); return 1; }
 } else {
  if(func_0203630C()) return 0;
  if(func_02035C38()) { cb=*(void (**)(u8 *,void *))(p+0x74); *(int *)(p+0x70)=1; if(cb) cb(p,q); return 1; }
 }
 return 0;
}
