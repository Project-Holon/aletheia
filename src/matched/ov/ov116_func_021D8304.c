/*
 * function: WIFI_BSUBWAY_GRAPHIC_SetupBg
 * address: 0x021D8304
 * packet: pkt_ov116_021D8304
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021D83B0 0x021D83B0 data a4
 *   d_021D83F0 0x021D83F0 data a4
 */
#include "../include/Obj10347.h"
typedef unsigned char u8;
extern void MI_CpuFill8(void *,int,int);
extern void func_0203F8F4(unsigned);
extern void BMP_WIN_Init(unsigned);
typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern char d_021D83B0[],d_021D83F0[];
void WIFI_BSUBWAY_GRAPHIC_SetupBg(void *p,unsigned heap) {
 unsigned i; char *q; unsigned n;
 MI_CpuFill8(p,0,4);
 func_0203F8F4(heap); BMP_WIN_Init(heap); func_0203FC28((struct DispConfig *)d_021D83B0);
 for(i=0;i<8;i++) {
 q=d_021D83F0+i*44; n=((struct Obj10347 *)q)->f0;
 func_0203FCA0((u8)n,(const struct BgTemplate *)(q+4),(u8)(((struct Obj10347 *)q)->f24));
 func_020414AC(n); func_02040588(n,((struct Obj10347 *)q)->f28);
 }
}
