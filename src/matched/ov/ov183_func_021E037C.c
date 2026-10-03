/*
 * function: func_021E037C
 * address: 0x021E037C
 * packet: pkt_ov183_021E037C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding.
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void func_021FBDA4(int,unsigned);
extern void func_020409B4(u32 index);
void func_021E037C(char *p,char *q){int i;for(i=0;i<6;i++){if(*(void **)(p+i*4+0x20)){func_021FC734(*(void **)(p+i*4+0x20));*(void **)(p+i*4+0x20)=0;}}func_021FBDA4(*(int *)(q+8),25);func_020409B4(1);}
