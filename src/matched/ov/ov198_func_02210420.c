/*
 * function: B_PLIST_MAIN_Delete
 * address: 0x02210420
 * packet: pkt_ov198_02210420
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIPE_SYS_ExeEnd 0x020221B8 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BGWINFRM_Delete 0x0202CA0C thumb
 *   B_PLIST_MAIN_DeleteTextResources 0x02210774 thumb ov198
 *   B_PLIST_DRAW_DeleteActors 0x0220E74C thumb ov198
 *   B_PLIST_DRAW_DeleteAllWindows 0x0220BE04 thumb ov198
 *   B_PLIST_MAIN_ExitBg 0x022105E4 thumb ov198
 *   TCBL_Destroy 0x02031140 arm
 *   B_PLIST_MAIN_DeleteCursor 0x022119E8 thumb ov198
 *   B_APP_TOOL_Delete 0x0220AF64 thumb ov196
 *   TCB_DeleteTask 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01006.h"
#include "../include/Obj25239.h"
#include "../include/Obj25240.h"
#include "../include/Obj25241.h"
#include "../include/Obj25243.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;struct Rec3;struct Obj;struct S02031140;struct Node;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern u32 WIPE_SYS_EndCheck(void);
extern void WIPE_SYS_ExeEnd(void);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
struct WinMgr;
extern void BGWINFRM_Delete(struct WinMgr *obj);
extern void B_PLIST_MAIN_DeleteTextResources(u8 *p);
extern void B_PLIST_DRAW_DeleteActors(char *);
extern void B_PLIST_DRAW_DeleteAllWindows(u8 *p);
extern void B_PLIST_MAIN_ExitBg(void);
extern void TCBL_Destroy(struct S02031140 *);
extern u32 B_PLIST_MAIN_DeleteCursor(u8 *);
extern void B_APP_TOOL_Delete(void *);
extern void TCB_DeleteTask(struct Node *);
extern u32 func_020307B0(void *p);
int B_PLIST_MAIN_Delete(struct Node *task,char *p)
{
    if(((struct Obj01006 *)p)->f2540==1) {
        if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj01006 *)p)->f1EAC)==0) {
            if(((struct Obj25239 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f34==1) PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01006 *)p)->f1EAC);
            else return 0;
        }
        if(WIPE_SYS_EndCheck()==0) {
            if(((struct Obj25240 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f34==1) WIPE_SYS_ExeEnd();
            else return 0;
        }
        if(*(struct Rec3 * *)&((struct Obj01006 *)p)->f1EB0) PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj01006 *)p)->f1EB0);
        if(*(struct Obj * *)&((struct Obj01006 *)p)->f2194) BGWINFRM_Delete((struct WinMgr *)(*(struct Obj * *)&((struct Obj01006 *)p)->f2194));
        B_PLIST_MAIN_DeleteTextResources((u8 *)p);
        B_PLIST_DRAW_DeleteActors(p);
        B_PLIST_DRAW_DeleteAllWindows((u8 *)p);
        B_PLIST_MAIN_ExitBg();
        TCBL_Destroy(*(struct S02031140 * *)&((struct Obj01006 *)p)->f1D4);
        B_PLIST_MAIN_DeleteCursor((u8 *)p);
        B_APP_TOOL_Delete(((struct Obj01006 *)p)->f2188);
        if(((struct Obj01006 *)p)->f218C==1) **(u8 * *)&((struct Obj25241 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f44=1;
        else **(u8 * *)&((struct Obj25243 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f44=0;
    }
    (*(u8 **)p)[0x4c]=1;
    TCB_DeleteTask(task);
    func_020307B0(p);
    return 1;
}
