/*
 * function: func_021B80C4
 * address: 0x021B80C4
 * packet: pkt_ov173_021B80C4
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0202822C 0x0202822C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202822C(char *,int);
int func_021B80C4(u8 *p,u16 n) {u8 *q;q=p+464;*(u16 *)(q+10)=1;*(u16 *)(q+6)=0;*(u16 *)(q+8)=n;func_0202822C(*(char **)(p+*(u16 *)(q+6)*4+544),1);return 13;}
