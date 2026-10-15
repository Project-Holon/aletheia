/*
 * function: GSYNC_STATE_ProcExit
 * address: 0x021D920C
 * packet: pkt_ov123_021D920C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: unlabelled ov009 02156DE0 leaf filed and verified before caller rerun.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   GSYNC_MESSAGE_ExitSystem 0x021D5644 thumb ov123
 *   GSYNC_DISP_Exit 0x021D5E8C thumb ov123
 *   GSYNC_DOWNLOAD_FreeWork 0x021D5B70 thumb ov123
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov114_id 0x00000072 data
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 */
#include "../include/Obj00990.h"
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
typedef unsigned char  u8;
struct Proc;
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern u32 func_020307B0(void *p);
extern void GSYNC_MESSAGE_ExitSystem(char *p);
extern void GSYNC_DISP_Exit(u8 *p);
extern void GSYNC_DOWNLOAD_FreeWork(char *p);
extern int GFL_NET_GetRunState(void);
extern void DWC_RAP_SetErrorHookCallback(int,int);
extern void NHTTP_RAP_Destroy(u8 *p);
extern void DWC_RAP_SetErrorCallback(int,int);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void func_02034A5C(int handle);
extern char ov114_id[];
int GSYNC_STATE_ProcExit(void *a, int b, int c, char *p)
{
    if (!WIPE_SYS_EndCheck()) return 0;
    if (((struct Obj00990 *)p)->f1C) APP_TASKMENU_CloseMenu(((struct Obj00990 *)p)->f1C);
    if (((struct Obj00990 *)p)->f38) {
        func_020307B0(((struct Obj00990 *)p)->f38);
        ((struct Obj00990 *)p)->f38=0;
    }
    GSYNC_MESSAGE_ExitSystem(((struct Obj00990 *)p)->f18);
    GSYNC_DISP_Exit(((struct Obj00990 *)p)->f14);
    GSYNC_DOWNLOAD_FreeWork(((struct Obj00990 *)p)->f8);
    if (((struct Obj00990 *)p)->f30) func_020307B0(((struct Obj00990 *)p)->f30);
    if (((struct Obj00990 *)p)->f3C) func_020307B0(((struct Obj00990 *)p)->f3C);
    if (((struct Obj00990 *)p)->f40) func_020307B0(((struct Obj00990 *)p)->f40);
    if (((struct Obj00990 *)p)->fC) func_020307B0(((struct Obj00990 *)p)->fC);
    if (((struct Obj00990 *)p)->f44) func_020307B0(((struct Obj00990 *)p)->f44);
    if (GFL_NET_GetRunState()) DWC_RAP_SetErrorHookCallback(0,0);
    if (((struct Obj00990 *)p)->f10) {
        NHTTP_RAP_Destroy(((struct Obj00990 *)p)->f10);
        DWC_RAP_SetErrorCallback(0,0);
    }
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(98);
    func_02034A5C((int)ov114_id);
    return 1;
}
