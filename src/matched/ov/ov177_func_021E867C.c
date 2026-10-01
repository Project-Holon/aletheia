/*
 * function: func_021E867C
 * address: 0x021E867C
 * packet: pkt_ov177_021E867C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   func_020310C4 0x020310C4 arm
 */
extern void func_0201C4E4(void *);
extern unsigned func_02045770(void *);
extern int func_0201C6C4(void *, unsigned);
extern void func_02045334(void *);
extern void func_020286C4(void *,void *,void *);
extern int func_02028484(void *,void *);
extern void func_020310C4(void *);
void func_021E867C(char *p)
{
 void *q;
 func_0201C4E4(*(void **)(p+0x28));
 switch(*(unsigned *)(p+0x2C)) {
 case 2:
 q=*(void **)(p+0x28);
 if(*(unsigned char *)(p+0x24)!=0 && func_0201C6C4(q,func_02045770(*(void **)(p+0x20)))==0) {
 func_02045334(*(void **)(p+0x20));*(unsigned char *)(p+0x24)=0;
 }
 break;
 case 0:
 q=*(void **)(p+0x28);
 if(*(unsigned char *)(p+0x24)!=0 && func_0201C6C4(q,func_02045770(*(void **)(p+0x20)))==0) {
 func_02045334(*(void **)(p+0x20));*(unsigned char *)(p+0x24)=0;
 }
 *(int *)(p+0x30)=*(unsigned char *)(p+0x24)==0;
 break;
 case 1:
 if(*(void **)(p+8)!=0) {
 if(*(void **)(p+0x34)!=0)func_020286C4(*(void **)(p+0x34),*(void **)(p+8),*(void **)(p+0x14));
 if(func_02028484(p+0x38,*(void **)(p+8))!=0)*(int *)(p+0x30)=1;
 }
 break;
 case 3:break;
 }
 func_020310C4(*(void **)(p+0xC));
}
