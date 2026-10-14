/*
 * function: GURU2_RECEIPT_ProcMain
 * address: 0x021DCF80
 * packet: pkt_ov137_021DCF80
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Table callbacks receive the switch value as their second argument.
 * symbols:
 * GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 * GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 * UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 * UNION_APP_Open 0x02184134 thumb ov022
 * UNION_APP_SetCallbacks 0x021840FC thumb ov022
 * UNION_APP_RequestReset 0x02184174 thumb ov022
 * UNION_APP_IsResetDone 0x0218417C thumb ov022
 * GURU2_RECEIPT_SendMemberCount 0x021DCF58 thumb ov137
 * GURU2_RECEIPT_UnionAppNoop 0x021DCF7C thumb ov137
 * GURU2_RECEIPT_PrintMemberList 0x021DE248 thumb ov137
 * GURU2_RECEIPT_UpdatePlayerActors 0x021DE5D0 thumb ov137
 * GURU2_RECEIPT_CheckMemberChange 0x021DE738 thumb ov137
 * GURU2_RECEIPT_UpdateQueues 0x021DD1B4 thumb ov137
 * GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 * CLACT_DrawSystem 0x0204A600 arm
 * WIPE_SYS_EndCheck 0x020221A4 thumb
 * func_0200FB24 0x0200FB24 thumb
 * gGuru2LobbyStateTable 0x021E1C20 data a4
 */
#include "../include/Obj00170.h"
#include "../include/Obj23706.h"
#include "../include/Obj23707.h"
#include "../include/Obj23708.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef void (*Cb)(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 func_0200FB24(void);
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern unsigned char UNION_APP_GetJoinedBits(unsigned char *p);
extern void UNION_APP_Open(u8 *p);
extern void UNION_APP_RequestReset(u8 *p);
extern u32 UNION_APP_IsResetDone(u8 *);
extern void UNION_APP_SetCallbacks(u8 *,Cb,Cb,void *);
extern void GURU2_RECEIPT_SendMemberCount(int a, int b, u8 *p);
extern void GURU2_RECEIPT_UnionAppNoop(void);
extern int (*const gGuru2LobbyStateTable[])(u8 *,u32);
extern int GURU2_RECEIPT_PrintMemberList(void *,int,u16,void *);
extern void GURU2_RECEIPT_UpdatePlayerActors(u8 *p);
extern int GURU2_RECEIPT_CheckMemberChange(void *,int);
extern void GURU2_RECEIPT_UpdateQueues(u8 *);
extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned),CLACT_DrawSystem(void);
int GURU2_RECEIPT_ProcMain(int a,int b,int c,u8 *p)
{
    int v;
    if(GFL_NET_SYSTEM_GetCurrentAid()==0 && ((struct Obj23706 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f30!=0)
        ((struct Obj23707 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f30&=UNION_APP_GetJoinedBits(GURU2_RECEIPT_GetUnionApp(p));
    switch(((struct Obj00170 *)p)->f0) {
    case 0:
        if(WIPE_SYS_EndCheck()) {
            ((struct Obj00170 *)p)->f0=1;
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp(p));
            UNION_APP_SetCallbacks(GURU2_RECEIPT_GetUnionApp(p),(Cb)GURU2_RECEIPT_SendMemberCount,GURU2_RECEIPT_UnionAppNoop,p);
        }
        break;
    case 1:
        if(gGuru2LobbyStateTable[((struct Obj00170 *)p)->f118]) ((struct Obj00170 *)p)->f0=gGuru2LobbyStateTable[*(u32 *)(p+280)](p,((struct Obj00170 *)p)->f0);
        if(((struct Obj23708 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f24==0) GURU2_RECEIPT_PrintMemberList(((struct Obj00170 *)p)->fD0,0,1152,p);
        GURU2_RECEIPT_UpdatePlayerActors(p);
        if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
            v=GURU2_RECEIPT_CheckMemberChange(p,1);
            if(((struct Obj00170 *)p)->f0==1) ((struct Obj00170 *)p)->f0=v;
        }
        break;
    case 2:
        if(gGuru2LobbyStateTable[((struct Obj00170 *)p)->f118]) ((struct Obj00170 *)p)->f0=gGuru2LobbyStateTable[*(u32 *)(p+280)](p,((struct Obj00170 *)p)->f0);
        break;
    case 3:
        if(WIPE_SYS_EndCheck()) {
            if(((struct Obj00170 *)p)->f8) return 1;
            GFL_NET_COMMAND_DeleteCommandTable(10240);
            UNION_APP_RequestReset(GURU2_RECEIPT_GetUnionApp(p));
            ((struct Obj00170 *)p)->f0=4;
        }
        break;
    case 4:
        if(UNION_APP_IsResetDone(GURU2_RECEIPT_GetUnionApp(p))) return 1;
        break;
    }
    if(WIPE_SYS_EndCheck() && func_0200FB24()) return 1;
    CLACT_DrawSystem(); GURU2_RECEIPT_UpdateQueues(p);
    return 0;
}
