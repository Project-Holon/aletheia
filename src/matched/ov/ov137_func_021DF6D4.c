/*
 * function: func_021DF6D4
 * address: 0x021DF6D4
 * packet: pkt_ov137_021DF6D4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021E0130 0x021E0130 thumb ov137
 */
typedef unsigned char u8;
extern void *func_020399A8(void);extern void func_02039C68(void *,int,int);extern void func_021E0130(u8 *,int);
int func_021DF6D4(u8 *p){void *ctx=func_020399A8();if(!*(int *)(p+0x18))func_02039C68(ctx,206,40);func_021E0130(p,10);*(int *)p=48;return 0;}
