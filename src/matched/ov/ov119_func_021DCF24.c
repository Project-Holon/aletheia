/*
 * function: POKETRADE_PROC_Exit
 * address: 0x021DCF24
 * packet: pkt_ov119_021DCF24
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Four pooled overlay IDs are absolute data symbols; literal integers
 * gave eight concrete differences and a 228-byte compile, symbols give EXACT (244 bytes).
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_020307B0 0x020307B0 arm
 *   POKETRADE_2D_DeleteMarkingIcon 0x021E5EF8 thumb ov119
 *   POKETRADE_2D_ClearSubScreen 0x021E5D84 thumb ov119
 *   POKETRADE_PROC_DeleteAllResources 0x021DC720 thumb ov119
 *   BEACON_STATUS_DoNothing 0x020275E0 thumb
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   POKETRADE_3D_Delete3DScene 0x021E31BC thumb ov119
 *   func_02030EAC 0x02030EAC arm
 *   POKETRADE_PROC_FreeMons 0x021DC5D0 thumb ov119
 *   POKETRADE_PROC_ExitMcssSystem 0x021DC428 thumb ov119
 *   POKETRADE_PROC_ExitDisplay 0x021DC484 thumb ov119
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov114_id 0x00000072 data a1
 *   ov067_id 0x00000043 data a1
 *   ov117_id 0x00000075 data a1
 *   ov118_id 0x00000076 data a1
 */
#include "../include/Obj00001.h"
extern unsigned WIPE_SYS_EndCheck(void);
extern char ov114_id[],ov067_id[],ov117_id[],ov118_id[];
extern unsigned int func_020307B0(void *p);
extern void POKETRADE_2D_DeleteMarkingIcon(void *);
extern void POKETRADE_2D_ClearSubScreen(char *);
extern void POKETRADE_PROC_DeleteAllResources(char *);
extern void BEACON_STATUS_DoNothing(void);
extern int POKETRADE_PROC_IsNetSession(void *);
struct S020315D4;
typedef unsigned int   u32;
struct Node;
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern void POKETRADE_3D_Delete3DScene(char *);
extern void func_02030EAC(struct Node *n);
extern void POKETRADE_PROC_FreeMons(char *p, int a1);
extern void POKETRADE_PROC_ExitMcssSystem(char *p);
extern void POKETRADE_PROC_ExitDisplay(void *);
extern void func_020315D4(struct S020315D4 *);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern void func_02034A5C(int);
int POKETRADE_PROC_Exit(void *owner,int unused,int keep,char *p)
{
    int state=((struct Obj00001 *)p)->f118C;
    if(WIPE_SYS_EndCheck()==0)return 0;
    func_020307B0(((struct Obj00001 *)p)->f10A4);
    func_020307B0(((struct Obj00001 *)p)->f10A8);
    POKETRADE_2D_DeleteMarkingIcon(p+0x950);POKETRADE_2D_DeleteMarkingIcon(p+0x964);POKETRADE_2D_DeleteMarkingIcon(p+0x978);
    POKETRADE_2D_ClearSubScreen(p);POKETRADE_PROC_DeleteAllResources(p);BEACON_STATUS_DoNothing();
    if(POKETRADE_PROC_IsNetSession(p))GFL_NET_COMMAND_DeleteCommandTable(0xc00);
    POKETRADE_3D_Delete3DScene(p);
    func_020307B0(((struct Obj00001 *)p)->f5DC);func_020307B0(((struct Obj00001 *)p)->f5E0);
    func_02030EAC(((struct Obj00001 *)p)->f9C8);
    POKETRADE_PROC_FreeMons(p,keep!=0);
    POKETRADE_PROC_ExitMcssSystem(p);POKETRADE_PROC_ExitDisplay(p);func_020315D4(owner);
    GFL_HEAP_DeleteChecked(31);GFL_HEAP_DeleteChecked(145);
    if(state<5) {func_02034A5C((int)ov114_id);func_02034A5C((int)ov067_id);}
    func_02034A5C(state==0 || state==4 ?(int)ov117_id:(int)ov118_id);
    return 1;
}
