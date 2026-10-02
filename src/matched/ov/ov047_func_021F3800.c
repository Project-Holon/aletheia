/*
 * function: func_021F3800
 * address: 0x021F3800
 * packet: pkt_ov047_021F3800
 * region: ov047
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020120F4(u32);
extern u32 func_02012EC4(u32);
extern void *func_0200B3A4(u32,u32);
extern void func_02082BCC(void *,int,int);
void func_021F3800(u32 a) { func_02082BCC(func_0200B3A4(func_02012EC4(func_020120F4(a)),31),0,4); }
