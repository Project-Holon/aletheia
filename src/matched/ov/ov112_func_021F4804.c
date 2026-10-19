/*
 * function: MUSICAL_SHOT_INFO_PrintMessageQueued
 * address: 0x021F4804
 * packet: pkt_ov112_021F4804
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 */
#include "../include/Obj02167.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
struct MsgBank;
struct PrintSys;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);
void MUSICAL_SHOT_INFO_PrintMessageQueued(u8 *p,u32 index)
{
    u32 win;
    if (((struct Obj02167 *)p)->f2C) {
        STRBUF_Delete(((struct Obj02167 *)p)->f2C);
        *(u32 *)&((struct Obj02167 *)p)->f2C=0;
    }
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj02167 *)p)->f1C)),15);
    ((struct Obj02167 *)p)->f2C=func_02045EC0((struct MsgBank *)(((struct Obj02167 *)p)->f28),index);
    win=(u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj02167 *)p)->f1C);
    PRINTSYS_PrintQue((struct PrintSys *)(((struct Obj02167 *)p)->f38),win,0,0,((struct Obj02167 *)p)->f2C,((struct Obj02167 *)p)->f20);
    ((struct Obj02167 *)p)->f30=1;
    BMP_MENUWORK_DrawWindow(((struct Obj02167 *)p)->f1C,1,1,11);
}
