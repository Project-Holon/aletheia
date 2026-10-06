/*
 * function: func_021BA028, func_021BA1C8
 * unit: yes
 * address: 0x021BA028
 * packet: pkt_ov100_021BA028
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: includes the eight-byte Thumb forwarding follower 0x021BA1C8.
 * symbols:
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0204A648 0x0204A648 arm
 *   d_021BB6F0 0x021BB6F0 data a4
 *   d_021BB6B0 0x021BB6B0 data a4
 *   d_021BB720 0x021BB720 data a4
 *   d_021BB740 0x021BB740 data a4
 *   d_021BB760 0x021BB760 data a4
 *   d_021BB780 0x021BB780 data a4
 *   d_021BB7A0 0x021BB7A0 data a4
 *   d_021BB7C0 0x021BB7C0 data a4
 */
typedef unsigned char u8;
struct BgTemplate { unsigned int words[8]; };
extern const unsigned int d_021BB6F0[],d_021BB6B0[];
extern const struct BgTemplate d_021BB720,d_021BB740,d_021BB760,d_021BB780,d_021BB7A0,d_021BB7C0;
typedef unsigned int   u32;
struct DispConfig;
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(int,int,int,int,u8,u8,u8);
extern void func_020409B4(u32 index);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
void func_021BA028(char *a0) {
 func_020433E0((const struct DispVram *)d_021BB6F0);func_0203FC28((struct DispConfig *)d_021BB6B0);
 func_02043534(0);func_020435F4(0);
 {struct BgTemplate t=d_021BB720;func_0203FCA0(0,&t,0);func_02041300(0,0,0,0,32,32,17);func_020409B4(0);}
 {struct BgTemplate t=d_021BB740;func_0203FCA0(1,&t,0);func_02041300(1,0,0,0,32,32,17);func_020409B4(1);}
 {struct BgTemplate t=d_021BB760;func_0203FCA0(4,&t,0);func_02041300(4,0,0,0,32,32,17);}
 {struct BgTemplate t=d_021BB780;func_0203FCA0(5,&t,0);func_02041300(5,0,0,0,32,32,17);func_020409B4(5);}
 {struct BgTemplate t=d_021BB7A0;func_0203FCA0(6,&t,0);func_02040C14(6,0,1,0);func_02041300(6,0,0,0,32,32,17);func_020409B4(6);}
 {struct BgTemplate t=d_021BB7C0;func_0203FCA0(7,&t,0);func_02041300(7,0,0,0,32,32,17);func_020409B4(7);}
}
extern void func_0204A648(void);
void func_021BA1C8(void) { func_0204A648(); }
