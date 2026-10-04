/*
 * function: func_021B6A04
 * address: 0x021B6A04
 * packet: pkt_ov174_021B6A04
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021B6A8E..0x021B6A90 is two zero alignment bytes.
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0201CE48(void *),func_02045808(void *),func_02043B5C(void *,int),func_0201F250(void *,void *,void *);
struct Descriptor;
extern void *func_02045770(struct Descriptor *),*func_02045EC0(void *,unsigned),*func_020457B0(unsigned,unsigned);
extern signed char func_02012FFC(void);
extern unsigned func_0201CCE4(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
void func_021B6A04(u8 *p,unsigned message)
{
 void *tmp; unsigned speed;
 if(*(void **)(p+100)){func_0201CE48(*(void **)(p+100));*(void **)(p+100)=0;}
 if(*(void **)(p+112)){func_02045808(*(void **)(p+112));*(void **)(p+112)=0;}
 func_02043B5C(func_02045770(*(void **)(p+92)),15);
 *(void **)(p+112)=func_02045EC0(*(void **)(p+108),message);
 if(*(void **)(p+116)){
 tmp=func_020457B0(1024,*(u16 *)p);
 func_0201F250(*(void **)(p+116),tmp,*(void **)(p+112));
 func_02045808(*(void **)(p+112));*(void **)(p+112)=tmp;
 }
 speed=func_02012FFC();
 *(unsigned *)(p+100)=func_0201CCE4(*(unsigned *)(p+92),0,0,*(unsigned *)(p+112),*(unsigned *)(p+96),speed,*(unsigned *)(p+88),2,*(u16 *)p,15);
}
