/*
 * function: func_021C8F2C
 * address: 0x021C8F2C
 * packet: pkt_ov212_021C8F2C
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02031330 0x02031330 arm
 *   d_021C9944 0x021C9944 data a4
 */
extern unsigned func_02031330(void *);extern unsigned char d_021C9944[];
int func_021C8F2C(int a,int b,int c,unsigned char *p){if(*(unsigned *)(p+28)==9)return 1;*(unsigned *)(p+8)=func_02031330(*(void **)(p+4));*(unsigned *)(p+28)=(*(unsigned (**)(unsigned char *))(d_021C9944+*(unsigned *)(p+28)*4))(p);return 0;}
