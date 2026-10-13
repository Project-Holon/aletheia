/*
 * function: IRC_APPBAR_SetLabel
 * address: 0x021B72A8
 * packet: pkt_ov101_021B72A8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * APP_TASKMENU_WIN_Delete 0x02028148 thumb
 * func_02045B38 0x02045B38 arm
 * MI_CpuFill8 0x02082BCC arm
 * func_02045EC0 0x02045EC0 arm
 * APP_TASKMENU_WIN_Create 0x02027FEC thumb
 * STRBUF_Delete 0x02045808 arm
 * MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj03228.h"
typedef unsigned short u16;
typedef struct { unsigned data; u16 tag,pad; unsigned flag; } Desc;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
struct Rec;
struct U16Vec;
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MI_CpuFill8(void *,int,unsigned);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
void IRC_APPBAR_SetLabel(unsigned *p,unsigned b) {
 unsigned q;
 Desc t;
 if(b==p[21]) return;
 APP_TASKMENU_WIN_Delete((u8 *)p[0]);
 q=(unsigned int)func_02045B38(0,2,0x31,((struct Obj03228 *)p)->f58);
 MI_CpuFill8(&t,0,12);
 t.tag=0x39e3;
 t.data=(unsigned int)func_02045EC0((struct MsgBank *)q,b+8);
 t.flag=1;
 p[0]=APP_TASKMENU_WIN_Create(p[1],(u32)(&t),0x13,0x15,0xd,((struct Obj03228 *)p)->f58);
 STRBUF_Delete((struct U16Vec *)t.data);
 MSGDATA_Delete((struct Rec *)q);
 p[21]=b; p[20]=0; p[17]=-1;
}
