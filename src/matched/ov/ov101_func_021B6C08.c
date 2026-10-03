/*
 * function: func_021B6C08
 * address: 0x021B6C08
 * packet: pkt_ov101_021B6C08
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203133C(void *);
extern void func_02082BCC(void *,int,u32);
void func_021B6C08(u8 *p) { func_0203133C(*(void **)p); func_02082BCC(p,0,12); }
