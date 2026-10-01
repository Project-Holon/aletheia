/*
 * function: func_021B6994
 * address: 0x021B6994
 * packet: pkt_ov174_021B6994
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021B6A02..0x021B6A04 is two zero alignment bytes.
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045730 0x02045730 arm
 *   func_021B7350 0x021B7350 thumb ov174
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0201F7A8(void *,int),func_020456F8(void *),func_02041B6C(unsigned),func_020452E8(void *),func_0201CE48(void *),func_02045808(void *);
extern unsigned func_02045730(void *);
extern void func_021B7350(int,int *);
void func_021B6994(u8 *p)
{
 void *tmp; u8 i;
 if(*(void **)(p+92)){
 func_0201F7A8(*(void **)(p+92),1);tmp=*(void **)(p+92);
 func_020456F8(tmp);func_02041B6C(func_02045730(tmp));
 func_020452E8(*(void **)(p+92));*(void **)(p+92)=0;
 }
 if(*(void **)(p+100)){func_0201CE48(*(void **)(p+100));*(void **)(p+100)=0;}
 if(*(void **)(p+112)){func_02045808(*(void **)(p+112));*(void **)(p+112)=0;}
 for(i=0;i<*(int *)(p+8);i++) if(*(int **)(p+28+i*4)) func_021B7350((int)p,*(int **)(p+28+i*4));
}
