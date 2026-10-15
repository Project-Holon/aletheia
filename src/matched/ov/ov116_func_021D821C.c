/*
 * function: WIFI_BSUBWAY_GRAPHIC_Create
 * address: 0x021D821C
 * packet: pkt_ov116_021D821C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   WIFI_BSUBWAY_GRAPHIC_SetupBg 0x021D8304 thumb ov116
 *   func_020056A0 0x020056A0 thumb
 *   d_021D858C 0x021D858C data a1
 *   d_021D83C0 0x021D83C0 data a4
 *   WIFI_BSUBWAY_GRAPHIC_OnRedraw 0x021D82F8 thumb ov116
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 are read/written at 021D8244..021D8258 or 021D82C4..021D82DA.
 */
#include "../include/Obj22632.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,int);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void WIFI_BSUBWAY_GRAPHIC_SetupBg(void *,unsigned);
extern void *func_020056A0(void *,void *,int);
extern void WIFI_BSUBWAY_GRAPHIC_OnRedraw(void *,void *);
extern char d_021D858C[], d_021D83C0[];
void *WIFI_BSUBWAY_GRAPHIC_Create(int a,unsigned heap) {
 void *p;
 p=func_02030734(heap,16,0,d_021D858C,0x1bc);
 MI_CpuFill8(p,0,16);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 BG_SYS_ClearGraphicsMemory(0); BG_SYS_SetVramBanks((const struct DispVram *)d_021D83C0); func_0204363C(a);
 BG_SYS_ResetSubDisplay(); BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes(); func_0201DD60();
 WIFI_BSUBWAY_GRAPHIC_SetupBg(p,heap);
 ((struct Obj22632 *)p)->fC=func_020056A0((void *)WIFI_BSUBWAY_GRAPHIC_OnRedraw,p,0);
 return p;
}
