/*
 * function: func_021D7ECC
 * address: 0x021D7ECC
 * packet: pkt_ov120_021D7ECC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_WIN_CreateEx  0x0202800C  thumb  arm9
 */
#include "../include/Obj02832.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 *APP_TASKMENU_WIN_CreateEx(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
extern void STRBUF_Delete(struct U16Vec *vec);
void *func_021D7ECC(char *p,u16 n)
{
    int width;
    void *result;
    void *text;
    text=STRBUF_Create(100,((struct Obj02832 *)p)->fC8);
    ((struct Obj02832 *)p)->fA8=text;
    MSGDATA_ReadString(((struct Obj02832 *)p)->fC,n,text);
    ((struct Obj02832 *)p)->fAC=0x39e3;
    ((struct Obj02832 *)p)->fB0=0;
    width=((int)func_0201D304(((struct Obj02832 *)p)->fA8,(int)(((struct Obj02832 *)p)->f14),(int)0)+32)/16;
    result=APP_TASKMENU_WIN_CreateEx((u32)(((struct Obj02832 *)p)->fC0),(u32)(p+0xa8),(u8)(16-width),(u8)21,width*2,3,(int)0,(int)1,((struct Obj02832 *)p)->fC8);
    STRBUF_Delete(((struct Obj02832 *)p)->fA8);
    return result;
}
