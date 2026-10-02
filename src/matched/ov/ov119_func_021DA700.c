/*
 * function: func_021DA700
 * address: 0x021DA700
 * packet: pkt_ov119_021DA700
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D4B88 0x021D4B88 thumb ov117
 *   func_021D6F2C 0x021D6F2C thumb ov118
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned char u8;
extern int func_021D8A24(void *),func_021D8AA8(void *);
extern void func_021D8E84(void *,int),func_021D4B88(void *),func_021D6F2C(void *);
extern unsigned func_020399A8(void);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, void *d);
void func_021DA700(char *p) {
 u8 b=*(int *)(p+0x10a0);
 if(func_021D8A24(p)) {if(func_0203D3A8(func_020399A8(),0xc03,1,&b)==0) return;}
 *(unsigned *)0x04001000 &= 0xffff1fff;
 if(func_021D8AA8(p)==0) func_021D8E84(p,(int)func_021D4B88);
 else func_021D8E84(p,(int)func_021D6F2C);
}
