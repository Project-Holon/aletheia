/*
 * function: func_021DCF24
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
 *   func_021DC720 0x021DC720 thumb ov119
 *   BEACON_STATUS_DoNothing 0x020275E0 thumb
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   POKETRADE_3D_Delete3DScene 0x021E31BC thumb ov119
 *   func_02030EAC 0x02030EAC arm
 *   func_021DC5D0 0x021DC5D0 thumb ov119
 *   func_021DC428 0x021DC428 thumb ov119
 *   func_021DC484 0x021DC484 thumb ov119
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   d_00000072 0x00000072 data a1
 *   d_00000043 0x00000043 data a1
 *   d_00000075 0x00000075 data a1
 *   d_00000076 0x00000076 data a1
 */
#include "../include/Obj00001.h"
extern unsigned WIPE_SYS_EndCheck(void);
extern char d_00000072[],d_00000043[],d_00000075[],d_00000076[];
extern unsigned int func_020307B0(void *p);
extern void POKETRADE_2D_DeleteMarkingIcon(void *);
extern void POKETRADE_2D_ClearSubScreen(char *);
extern void func_021DC720(char *);
extern void BEACON_STATUS_DoNothing(void);
extern int POKETRADE_PROC_IsNetSession(void *);
struct S020315D4;
typedef unsigned int   u32;
struct Node;
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern void POKETRADE_3D_Delete3DScene(char *);
extern void func_02030EAC(struct Node *n);
extern void func_021DC5D0(char *p, int a1);
extern void func_021DC428(char *p);
extern void func_021DC484(void *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void func_02034A5C(int);
int func_021DCF24(void *owner,int unused,int keep,char *p)
{
    int state=((struct Obj00001 *)p)->f118C;
    if(WIPE_SYS_EndCheck()==0)return 0;
    func_020307B0(((struct Obj00001 *)p)->f10A4);
    func_020307B0(((struct Obj00001 *)p)->f10A8);
    POKETRADE_2D_DeleteMarkingIcon(p+0x950);POKETRADE_2D_DeleteMarkingIcon(p+0x964);POKETRADE_2D_DeleteMarkingIcon(p+0x978);
    POKETRADE_2D_ClearSubScreen(p);func_021DC720(p);BEACON_STATUS_DoNothing();
    if(POKETRADE_PROC_IsNetSession(p))GFL_NET_COMMAND_DeleteCommandTable(0xc00);
    POKETRADE_3D_Delete3DScene(p);
    func_020307B0(((struct Obj00001 *)p)->f5DC);func_020307B0(((struct Obj00001 *)p)->f5E0);
    func_02030EAC(((struct Obj00001 *)p)->f9C8);
    func_021DC5D0(p,keep!=0);
    func_021DC428(p);func_021DC484(p);func_020315D4(owner);
    func_020306F0(31);func_020306F0(145);
    if(state<5) {func_02034A5C((int)d_00000072);func_02034A5C((int)d_00000043);}
    func_02034A5C(state==0 || state==4 ?(int)d_00000075:(int)d_00000076);
    return 1;
}
