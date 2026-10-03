/*
 * function: func_022021C0
 * address: 0x022021C0
 * packet: pkt_ov135_022021C0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02202840 0x02202840 thumb ov135
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02202840(void *),func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
int func_022021C0(u8 *p) { if((func_02202840(p+0xfa0)==0 && (func_020362DC()&1)) || func_02035C60()) { func_020061E4(0x547); *(u32 *)(p+40)=*(u32 *)(p+44); } return 2; }
