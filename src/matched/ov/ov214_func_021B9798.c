/*
 * function: BTL_REC_SEL_Delete
 * address: 0x021B9798
 * packet: pkt_ov214_021B9798
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_REC_SEL_DeletePalanm 0x021BAF30 thumb ov214
 *   BTL_REC_SEL_DeleteWindowList 0x021BA43C thumb ov214
 *   BTL_REC_SEL_Noop 0x021BA39C thumb ov214
 *   BTL_REC_SEL_DeleteWindows 0x021BA018 thumb ov214
 *   BTL_REC_SEL_DeleteSubBg 0x021BAE10 thumb ov214
 *   BTL_REC_SEL_DeleteBgRun 0x021BAC3C thumb ov214
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BTL_REC_SEL_GRAPHIC_Delete 0x021BB220 thumb ov214
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
#include "../include/Obj00636.h"
struct Rec;
extern const char ov067_id[];
typedef unsigned char  u8;
extern void BTL_REC_SEL_DeletePalanm(int unused, u8 *p);
extern void BTL_REC_SEL_DeleteWindowList(int unused,char *p);
extern void BTL_REC_SEL_Noop(int unused,char *p);
extern void BTL_REC_SEL_DeleteWindows(int unused,char *p);
extern void BTL_REC_SEL_DeleteSubBg(int unused,char *p);
extern void BTL_REC_SEL_DeleteBgRun(int unused, u8 *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
struct Node;
struct PrintSys;
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void BTL_REC_SEL_GRAPHIC_Delete(char *p);
struct Proc;
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void func_02034A5C(int handle);
int BTL_REC_SEL_Delete(void *owner,int unused,int state,char *p)
{
    BTL_REC_SEL_DeletePalanm(state,(u8 *)p);
    BTL_REC_SEL_DeleteWindowList(state,p);
    BTL_REC_SEL_Noop(state,p);
    BTL_REC_SEL_DeleteWindows(state,p);
    BTL_REC_SEL_DeleteSubBg(state,p);
    BTL_REC_SEL_DeleteBgRun(state,(u8 *)p);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj00636 *)p)->f58);
    func_02030EAC((struct Node *)(((struct Obj00636 *)p)->f4C));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00636 *)p)->f18));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj00636 *)p)->f18));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00636 *)p)->f14));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj00636 *)p)->f14));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00636 *)p)->f10));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj00636 *)p)->f10));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00636 *)p)->fC));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj00636 *)p)->fC));
    GF_FONT_Delete(((struct Obj00636 *)p)->f8);
    BTL_REC_SEL_GRAPHIC_Delete(*(char * *)&((struct Obj00636 *)p)->f4);
    func_020315D4(owner);
    GFL_HEAP_DeleteChecked(117);
    func_02034A5C((int)ov067_id);
    return 1;
}
