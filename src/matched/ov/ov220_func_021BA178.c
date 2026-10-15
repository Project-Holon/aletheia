/*
 * function: TH_AWARD_GRAPHIC_Delete
 * address: 0x021BA178
 * packet: pkt_ov220_021BA178
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BA19E/021BA1A8 hardware DISPCNT masked updates.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   TH_AWARD_GRAPHIC_DeleteClact 0x021BA2E4 thumb ov220
 *   TH_AWARD_GRAPHIC_CleanupBg 0x021BA260 thumb ov220
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj26062.h"
struct Node;
extern void func_02030EAC(struct Node *);
extern void TH_AWARD_GRAPHIC_DeleteClact(char *);
extern void TH_AWARD_GRAPHIC_CleanupBg(void *p);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *,unsigned,unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void TH_AWARD_GRAPHIC_Delete(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj26062 *)p)->fC);
    TH_AWARD_GRAPHIC_DeleteClact((char *)p+4);
    TH_AWARD_GRAPHIC_CleanupBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}
