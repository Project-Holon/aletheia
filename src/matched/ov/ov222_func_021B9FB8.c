/*
 * function: ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete
 * address: 0x021B9FB8
 * region: ov222
 * isa: thumb
 * packet: pkt_ov222_021B9FB8
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * volatile: BLDCNT stores 021B9FDE/021B9FE4; DISPCNT accesses 021B9FE6..021B9FF4
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera 0x021BA1C8 thumb ov222
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact 0x021BA12C thumb ov222
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg 0x021BA0A8 thumb ov222
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 * 1DD68 ignores incoming arguments and tails with fixed 1,2,0.
 */
#include "../include/Obj26084.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(u32 *);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact(char *);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *,u32,u32);
extern u32 func_020307B0(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj26084 *)p)->fC));
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera((u32 *)(p+8));
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact(p+4);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}
