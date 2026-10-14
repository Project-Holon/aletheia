/*
 * function: MB_PARENT_SYS_Init
 * address: 0x021F0754
 * packet: pkt_ov107_021F0754
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02087D28 0x02087D28 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   func_021F5904 0x021F5904 arm ov107
 *   func_02034714 0x02034714 arm
 *   MB_SetParentCommParam 0x021F5B4C arm ov107
 *   func_021F1B3C 0x021F1B3C arm ov107
 *   MB_PARENT_SYS_SetState 0x021F0D1C thumb ov107
 *   MB_PARENT_SYS_EventCallback 0x021F0B2C thumb ov107
 *   gMbChildStageMasks 0x021F6EB4 data a4
 *   d_021F6E1C 0x021F6E1C data a4
 *   gMbParentSys 0x021F6EAC data a4
 *   d_021F6E24 0x021F6E24 data a4
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u8 f00,f01,f02,f03;u16 f04[10];u16 f18,f1A;u16 f1C[26];u16 f50,f52;u8 f54;} User;
typedef struct {u8 f00:4;u8 f00hi:4;u8 f01;u16 f02[10];} MBUser;
typedef struct {u32 words[5];} Zero;
struct OSOwnerInfoEx;
extern void func_02087D28(struct OSOwnerInfoEx *info);extern void MI_CpuCopy8(const void *,void *,u32);extern void *GFL_NET_AllocAligned(u32,u32,const char *,u16);extern int func_021F5904(void *,MBUser *,int,int,u16);extern void func_02034714(void *,int,void *);extern int MB_SetParentCommParam(u16,u16);extern void func_021F1B3C(void (*)(u16,u32,void *));extern void MB_PARENT_SYS_SetState(u16);extern void MB_PARENT_SYS_EventCallback(u16,u32,void *);
extern Zero gMbChildStageMasks;extern struct Masks gMbParentSys;extern u8 d_021F6E1C[],d_021F6E24[];
void MB_PARENT_SYS_Init(int a,int b){User user;MBUser mb;u8 buffer[20];Zero *zero;
func_02087D28((struct OSOwnerInfoEx *)(&user));mb.f00=user.f01;mb.f01=user.f1A;MI_CpuCopy8(user.f04,mb.f02,user.f1A*2);mb.f00hi=0;
zero=(Zero *)buffer;zero->words[0]=0;zero->words[1]=0;zero->words[2]=0;zero->words[3]=0;zero->words[4]=0;gMbChildStageMasks=*zero;
gMbParentSys.f04=GFL_NET_AllocAligned(93,45312,(const char *)d_021F6E1C,158);
if(func_021F5904(gMbParentSys.f04,&mb,a,b,1))func_02034714(d_021F6E24,0,d_021F6E24);
MB_SetParentCommParam(256,1);func_021F1B3C(MB_PARENT_SYS_EventCallback);MB_PARENT_SYS_SetState(1);}
