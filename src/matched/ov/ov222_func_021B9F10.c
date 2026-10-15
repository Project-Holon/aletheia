/*
 * function: ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create
 * address: 0x021B9F10
 * packet: pkt_ov222_021B9F10
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B9F38..021B9F4C BLDCNT/DISPCNT stores and reads
 * prototype evidence: 434CC full 16B body and both 4349C/434B4 full bodies ignore all input; no caller setup.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg 0x021BA048 thumb ov222
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact 0x021BA0EC thumb ov222
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera 0x021BA15C thumb ov222
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task 0x021BA034 thumb ov222
 *   d_021BA390 0x021BA390 data a1
 *   d_021BA2CC 0x021BA2CC data a4
 */
#include "../include/Obj26083.h"

typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021BA390[];
extern u32 d_021BA2CC[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void*,int,u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BMP_SetDisplaySwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void* func_020056A0(u32,u32,u32);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg(void*,u32);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact(unsigned char*,int,int);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera(u32**,u32);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task(void*,char*);
void* ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create(u32 swap,u32 heap)
{
 char*p;
 u32*g;
 p=func_02030734(heap,16,0,d_021BA390,0x1cc);
 MI_CpuFill8(p,0,16);
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 BG_SYS_ClearGraphicsMemory(0);
 g=d_021BA2CC;
 BG_SYS_SetVramBanks((const struct DispVram *)g);
 BMP_SetDisplaySwap(swap);
 BG_SYS_ResetSubDisplay();
 BG_SYS_ClearMainPlanes();
 BG_SYS_ClearSubPlanes();
 GF_FONT_InitTextColor();
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg(p,heap);
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact((unsigned char*)p+4,(int)g,heap);
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera((u32**)(p+8),heap);
 *(void* *)&((struct Obj26083 *)p)->fC=func_020056A0((u32)ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task,(u32)p,0);
 return p;
}
