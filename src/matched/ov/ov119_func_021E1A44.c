/*
 * function: POKETRADE_SAVE_PrintNatureName
 * address: 0x021E1A44
 * packet: pkt_ov119_021E1A44
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   POKE_TOOL_GetNature  0x02018598  thumb  arm9
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 */
#include "../include/Obj00001.h"
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u8 POKE_TOOL_GetNature(void *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern u32 MSGDATA_Delete(struct Rec *rec);
void POKETRADE_SAVE_PrintNatureName(int a,int b,int x,int y,char *p)
{
    int s;
    s=(int)func_02045B38(0,2,24,((struct Obj00001 *)p)->f5F4);
    MSGDATA_ReadString((struct MsgBank *)s,POKE_TOOL_GetNature((void *)a),(void *)(*(int *)&((struct Obj00001 *)p)->f730));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
    MSGDATA_Delete((struct Rec *)s);
}
