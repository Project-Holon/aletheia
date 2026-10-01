/*
 * function: func_021D5B58
 * address: 0x021D5B58
 * packet: pkt_ov131_021D5B58
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D5BAC 0x021D5BAC thumb ov131
 *   func_021D5C4C 0x021D5C4C thumb ov131
 */
extern int func_021D5BAC(void *,int,unsigned short *);
extern void func_02017528(void *);
extern void func_020307B0(void *);
extern void *func_021D6064(void *);
extern void *func_0201747C(void *,unsigned int);
extern void func_021D5C4C(void *);
int func_021D5B58(unsigned char *p,int a) {
 unsigned short n;
 int r=func_021D5BAC(p,a,&n);
 if(r==1) {
 *(unsigned short *)(p+24)=n;
 if((*(unsigned char **)(p+8))[12]==2) {
 if(*(void **)(p+600)) {func_02017528(*(void **)(p+600));func_020307B0(*(void **)(p+600));}
 *(void **)(p+600)=func_0201747C(func_021D6064(p),*(unsigned short *)p);
 }
 func_021D5C4C(p);
 }
 return r;
}
