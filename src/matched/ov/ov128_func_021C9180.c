/*
 * function: func_021C9180
 * address: 0x021C9180
 * packet: pkt_ov128_021C9180
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C6ADC 0x021C6ADC thumb ov128
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_02012944(void *);
extern void func_0201F02C(void *,int,void *);
extern void func_021C6ADC(void *,void *,int);
extern void func_02041090(u32,void *,u32,u32,u8,u8);
extern void func_02041B6C(int);
void func_021C9180(char *p,char *q,char *r) {
 char *s;
 func_0201F02C(*(void **)r,0,func_02012944(*(void **)(q+4)));
 func_021C6ADC(r,r+12,50);
 s=*(char **)(p+20);
 func_02041090(2,s+12,0,0,(*(u16 *)s>>3)&255,(*(u16 *)(s+2)>>3)&255);
 func_02041B6C(2);
}
