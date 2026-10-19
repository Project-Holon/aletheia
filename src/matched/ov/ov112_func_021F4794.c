/*
 * function: MUSICAL_SHOT_INFO_PrintMessageStream
 * address: 0x021F4794
 * packet: pkt_ov112_021F4794
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
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 */
#include "../include/Obj01395.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec3;
struct U16Vec;
struct Descriptor;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct CharBuf;
struct MsgBank;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern signed char MSG_SPEED_GetWait(void);
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);
void MUSICAL_SHOT_INFO_PrintMessageStream(u8 *p,u32 index)
{
    u32 t;
    if (((struct Obj01395 *)p)->f24) {
        PRINTSYS_PrintStreamDelete(((struct Obj01395 *)p)->f24);
        *(u32 *)&((struct Obj01395 *)p)->f24=0;
    }
    if (((struct Obj01395 *)p)->f2C) {
        STRBUF_Delete(((struct Obj01395 *)p)->f2C);
        *(u32 *)&((struct Obj01395 *)p)->f2C=0;
    }
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj01395 *)p)->f1C)),15);
    ((struct Obj01395 *)p)->f2C=func_02045EC0((struct MsgBank *)(((struct Obj01395 *)p)->f28),index);
    t=MSG_SPEED_GetWait();
    *(u32 *)&((struct Obj01395 *)p)->f24=PRINTSYS_PrintStream(*(u32 *)&((struct Obj01395 *)p)->f1C,0,0,*(u32 *)&((struct Obj01395 *)p)->f2C,((struct Obj01395 *)p)->f20,t,((struct Obj01395 *)p)->f18,2,((struct Obj01395 *)p)->f0,0);
    BMP_MENUWORK_DrawWindow(((struct Obj01395 *)p)->f1C,1,1,11);
}
