/*
 * function: func_021B6BA8
 * address: 0x021B6BA8
 * packet: pkt_ov101_021B6BA8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6C20 0x021B6C20 thumb ov101
 *   func_021B6A3C 0x021B6A3C thumb ov101
 *   func_021B6A7C 0x021B6A7C thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B6C20(int *,int,int,int);
extern void func_021B6A3C(u8 *,u32);
extern void func_021B6A7C(u8 *,u16 *);
void func_021B6BA8(u8 *p,u16 *state) { switch(*state) { case 0: *state=1; break; case 1: if(func_021B6C20((int *)(p+4),4,58,(int)p)) *state=2; break; case 2: func_021B6A3C(p,(u32)func_021B6A7C); break; } }
