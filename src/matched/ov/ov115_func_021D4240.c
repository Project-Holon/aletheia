/*
 * function: func_021D4240
 * address: 0x021D4240
 * packet: pkt_ov115_021D4240
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two zero bytes of alignment padding follow the return.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_020362DC(void),func_02035C60(void);
int func_021D4240(u8 *p) { if(func_020362DC()&3) return 1; if(*(int *)(*(u32 *)(p+0x40)+4) && func_02035C60()) return 1; return 0; }
