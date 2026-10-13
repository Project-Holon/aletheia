/*
 * function: func_021CA084
 * address: 0x021CA084
 * packet: pkt_ov128_021CA084
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern int TOUCHPANEL_GetTrg(void);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
int func_021CA084(int *p) { if(TOUCHPANEL_GetTrg()==1) {func_020355D8(1);*p=1;return 1;} if(func_020362DC()&3) {func_020355D8(0);*p=0;return 1;} return 0; }
