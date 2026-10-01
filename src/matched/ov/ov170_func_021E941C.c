/*
 * function: func_021E941C
 * address: 0x021E941C
 * packet: pkt_ov170_021E941C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 */
#define WORK(p) (*(char **)((p)+0x2C))
extern void func_021EBA5C(char *,int);
extern void func_021DD14C(unsigned char *);
extern void func_020260E4(void *,unsigned char);
extern void func_021ECB20(unsigned char *,int,int);
extern void func_021ED6E4(unsigned char *,int);
extern int func_020355C4(void);
extern void func_020260F4(void *,int);
int func_021E941C(unsigned char *p) {
 func_021EBA5C(WORK(p),0x1B); func_021DD14C(p);
 func_020260E4(*(void **)(WORK(p)+0x70),p[0x16]);
 func_021ECB20(p,0x81,1); func_021ED6E4(p,0);
 if(func_020355C4()==1) func_020260F4(*(void **)(WORK(p)+0x70),0);
 else func_020260F4(*(void **)(WORK(p)+0x70),1);
 return 0x4B;
}
