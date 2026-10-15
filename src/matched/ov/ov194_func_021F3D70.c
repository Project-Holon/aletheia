/*
 * function: NAMEIN_GRAPHIC_PrintMsg
 * address: 0x021F3D70
 * packet: pkt_ov194_021F3D70
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 */
#include "../include/Obj02239.h"
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
void NAMEIN_GRAPHIC_PrintMsg(char *p,int value) {
    int window;
    while (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((struct Obj02239 *)p)->f10),(void *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02239 *)p)->f14))))
        PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj02239 *)p)->f10));
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02239 *)p)->f14)),((struct Obj02239 *)p)->f20);
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj02239 *)p)->f0),value,(void *)(((struct Obj02239 *)p)->f1C));
    window=((struct Obj02239 *)p)->f10;
    PRINTSYS_PrintQue((struct PrintSys *)window,(int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02239 *)p)->f8),0,0,(void *)(*(int *)&((struct Obj02239 *)p)->f1C),((struct Obj02239 *)p)->f4);
    ((struct Obj02239 *)p)->fC=1;
}
