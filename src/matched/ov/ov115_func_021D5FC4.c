/*
 * function: WIFILOGIN_MSG_GetFrameIdB
 * address: 0x021D5FC4
 * packet: pkt_ov115_021D5FC4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D663C 0x021D663C data a4
 *   func_02034714 0x02034714 arm
 */
typedef unsigned char u8;typedef unsigned int u32;
extern char d_021D663C[];extern void func_02034714(const char *,u32,const char *);
u32 WIFILOGIN_MSG_GetFrameIdB(u32 a) { switch(a){case 1:return 2;case 0:return 5;default:func_02034714(d_021D663C,0,d_021D663C);return 0;} }
