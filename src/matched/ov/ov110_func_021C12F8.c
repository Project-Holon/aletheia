/*
 * function: func_021C12F8
 * address: 0x021C12F8
 * packet: pkt_ov110_021C12F8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_02035D20(u32 *,u32 *);
int func_021C12F8(void) { u32 x,y; u32 result; if(func_02035D20(&x,&y) && x<232 && y>=8) { result=(y/8-1)/6; if(result<3) return result; } return -1; }
