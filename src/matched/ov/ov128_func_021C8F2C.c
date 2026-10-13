/*
 * function: func_021C8F2C
 * address: 0x021C8F2C
 * packet: pkt_ov128_021C8F2C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   d_021CA529 0x021CA529 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int TOUCHPANEL_HitTrg(const void *);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern const u8 d_021CA529[];
int func_021C8F2C(void *unused,int *q) {
 int v=TOUCHPANEL_HitTrg(d_021CA529);
 if(v!=-1) {func_020355D8(1);*q=1;return v;}
 if(func_020362DC()&2) {func_020355D8(0);*q=0;return 0;}
 if(func_020362DC()&1024) {func_020355D8(0);*q=0;return 1;}
 return -1;
}
