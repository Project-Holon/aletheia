/*
 * function: WIFICLUB_ProcExit
 * address: 0x021C2724
 * packet: pkt_ov099_021C2724
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_UpdateBgmFade 0x021C2438 thumb ov099
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   WIFICLUBACTOR_RemoveNetCommands 0x021BA7F8 thumb ov099
 *   REGULATION_Copy 0x0200AE08 thumb
 *   func_020307B0 0x020307B0 arm
 *   WIFICLUB_DeleteMenuAndIcons 0x021BC0C4 thumb ov099
 *   WIFICLUB_ExitScreen 0x021BDF7C thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_FreeRegulation 0x021BCBB0 thumb ov099
 *   WIFICLUB_DeleteTextBuffers 0x021BB224 thumb ov099
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj03736.h"
#include "../include/Obj06360.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WIFICLUB_UpdateBgmFade(char *);
typedef unsigned int   u32;
struct Reg;
struct Proc;
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_NET_GetRunState(void);
extern void WIFICLUBACTOR_RemoveNetCommands(char *);
extern void REGULATION_Copy(const struct Reg *src, struct Reg *dest);
extern u32 func_020307B0(void *p);
extern void WIFICLUB_DeleteMenuAndIcons(char *);
extern void WIFICLUB_ExitScreen(char *);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void WIFICLUB_FreeRegulation(void *);
extern void WIFICLUB_DeleteTextBuffers(char *);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
int WIFICLUB_ProcExit(void *task, int unused, char *output, char *p)
{
    if (!WIFICLUB_UpdateBgmFade(p)) return 0;
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) WIFICLUBACTOR_RemoveNetCommands(p);
    ((struct Obj06360 *)output)->f49 = ((struct Obj03736 *)p)->f135C;
    if (((struct Obj03736 *)p)->f1348) {
        REGULATION_Copy(((struct Obj03736 *)p)->f1348, ((struct Obj06360 *)output)->f1C);
        func_020307B0(((struct Obj03736 *)p)->f1348);
        ((struct Obj03736 *)p)->f1348 = 0;
    }
    WIFICLUB_DeleteMenuAndIcons(p);
    WIFICLUB_ExitScreen(p);
    ((struct Obj06360 *)output)->f47 = ((struct Obj03736 *)p)->f242;
    ((struct Obj06360 *)output)->fC = ((struct Obj03736 *)p)->f1D0;
    if (GFL_NET_GetRunState()) ((struct Obj06360 *)output)->f10 = DWC_RAP_GetTargetFriendIndex();
    WIFICLUB_FreeRegulation(((struct Obj03736 *)p)->fCC);
    WIFICLUB_DeleteTextBuffers(p);
    func_020315D4(task);
    GFL_HEAP_DeleteChecked(33);
    return 1;
}
