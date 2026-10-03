/*
 * function: func_021B874C
 * address: 0x021B874C
 * packet: pkt_ov104_021B874C
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B6508 0x021B6508 thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,int);
extern void func_021B6508(u32 p, u32 a);
void func_021B874C(u8 *p) { func_021B6508(*(int *)p,0xf00); func_02082BCC(p,0,0x198); }
