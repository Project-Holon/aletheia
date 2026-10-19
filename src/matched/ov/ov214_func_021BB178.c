/*
 * function: BTL_REC_SEL_GRAPHIC_Create
 * address: 0x021BB178
 * packet: pkt_ov214_021BB178
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * volatile: MMIO accesses 021BB19E..021BB1B2
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   BTL_REC_SEL_GRAPHIC_InitBg 0x021BB2C8 thumb ov214
 *   BTL_REC_SEL_GRAPHIC_InitClact 0x021BB36C thumb ov214
 *   BTL_REC_SEL_GRAPHIC_InitG3d 0x021BB3DC thumb ov214
 *   BTL_REC_SEL_GRAPHIC_VBlank 0x021BB2B4 thumb ov214
 *   func_020056A0 0x020056A0 thumb
 *   site 0x021BB668 data ov214
 *   config 0x021BB588 data ov214
 */
#include "../include/Obj25730.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern const char site[];
extern const u32 config[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,u32,u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void BTL_REC_SEL_GRAPHIC_InitBg(void *,u32);
extern void BTL_REC_SEL_GRAPHIC_InitClact(unsigned char *,int,int);
extern void BTL_REC_SEL_GRAPHIC_InitG3d(u32 **,u32);
typedef unsigned char  u8;
extern void BTL_REC_SEL_GRAPHIC_VBlank(void *unused, u8 *p);
extern u32 func_020056A0(void (*)(void *),void *,u32);
char *BTL_REC_SEL_GRAPHIC_Create(u32 a,u32 heap)
{
    char *p=func_02030734(heap,16,0,site,458);
    MI_CpuFill8(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)config);
    BG_SYS_SetLcdSwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    BTL_REC_SEL_GRAPHIC_InitBg(p,heap);
    BTL_REC_SEL_GRAPHIC_InitClact((unsigned char *)p+4,(int)config,heap);
    BTL_REC_SEL_GRAPHIC_InitG3d((u32 **)(p+8),heap);
    ((struct Obj25730 *)p)->fC=func_020056A0((void (*)(void *))BTL_REC_SEL_GRAPHIC_VBlank,p,0);
    return p;
}
