/*
 * function: func_021E912C
 * address: 0x021E912C
 * packet: pkt_ov170_021E912C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021EBA70 0x021EBA70 thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021E8F50 0x021E8F50 thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 */
#define WORK(p) (*(char **)((p)+0x2C))
extern void func_021ED6E4(unsigned char *,int);
extern void func_021EBA70(char *,int);
extern void func_021DD14C(unsigned char *);
extern void func_021ED888(char *,int);
extern void func_021ECB20(unsigned char *,int,int);
extern int func_020355C4(void);
extern void func_020260F4(void *,int);
extern void func_021ED55C(unsigned char *,int);
extern int func_021E8F50(unsigned char *,int);
extern int func_021E8FC0(unsigned char *,int (*)(unsigned char *),int);
extern int func_021E0190(unsigned char *);
int func_021E912C(unsigned char *p) {
 func_021ED6E4(p,1); func_021EBA70(WORK(p),0x18); func_021DD14C(p);
 if(p[0x16]<0x1E) { func_021ED888(WORK(p),1); func_021ECB20(p,1,0); }
 else func_021ECB20(p,2,0);
 if(func_020355C4()==1) func_020260F4(*(void **)(WORK(p)+0x70),0);
 else { func_020260F4(*(void **)(WORK(p)+0x70),1); func_021ED55C(p,0); }
 return func_021E8FC0(p,func_021E0190,func_021E8F50(p,0xE));
}
