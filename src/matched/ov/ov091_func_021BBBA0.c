/*
 * function: func_021BBBA0
 * address: 0x021BBBA0
 * packet: pkt_ov091_021BBBA0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02027858 0x02027858 thumb
 *   func_02045808 0x02045808 arm
 *   func_020355C4 0x020355C4 arm
 */
extern void func_02027858(int);
extern void func_02045808(unsigned int);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
void func_021BBBA0(unsigned char *a,unsigned char *b) {unsigned char i;func_02027858(*(int *)(b+116));for(i=0;i<b[0];i++)func_02045808(*(unsigned int *)((unsigned int)b+(unsigned int)i*12+20));*(int *)(a+8)=func_020355C4();}
