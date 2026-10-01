/*
 * function: func_021B68F8
 * address: 0x021B68F8
 * packet: pkt_ov174_021B68F8
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021B6992..0x021B6994 is two zero alignment bytes.
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02028470 0x02028470 thumb
 *   func_02045730 0x02045730 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0201F7A8(void *,int),func_020456F8(void *),func_02041B6C(unsigned),func_020452E8(void *),func_0201F73C(void *,int,int,int),func_02043B5C(void *,int),func_02045334(void *),func_02045374(void *),func_02028470(void *,int);
extern unsigned func_02045730(void *);
extern void *func_020450F0(unsigned,unsigned,unsigned,unsigned,u8,u8,u8),*func_02045770(void *);
void func_021B68F8(u8 *p,int mode)
{
 void *tmp;
 if(*(void **)(p+92)){
 func_0201F7A8(*(void **)(p+92),1);
 tmp=*(void **)(p+92);func_020456F8(tmp);func_02041B6C(func_02045730(tmp));
 func_020452E8(*(void **)(p+92));*(void **)(p+92)=0;
 }
 if(mode==0) *(void **)(p+92)=func_020450F0(0,1,1,30,4,12,1);
 else if(mode==1) *(void **)(p+92)=func_020450F0(0,1,19,30,4,12,1);
 func_0201F73C(*(void **)(p+92),1,1,13);
 func_02043B5C(func_02045770(*(void **)(p+92)),15);
 func_02045334(*(void **)(p+92));func_02045374(*(void **)(p+92));
 func_02041B6C(0);func_02028470(p+128,6);
}
