/*
 * function: GURU2_RECEIPT_ProcExit
 * address: 0x021DD0B8
 * packet: pkt_ov137_021DD0B8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021DD10A reads and 021DD110 writes hardware register 0x04000304
 * symbols:
 * TCBL_DeleteAllTasks 0x0203115C arm
 * TCBL_Destroy 0x02031140 arm
 * GURU2_RECEIPT_FreeActors 0x021DD570 thumb ov137
 * GURU2_RECEIPT_DeleteWindows 0x021DD760 thumb ov137
 * GURU2_RECEIPT_ExitBg 0x021DD3B0 thumb ov137
 * MSGDATA_Delete 0x02045C04 arm
 * func_02030EAC 0x02030EAC arm
 * GURU2_RECEIPT_GetMemberCount 0x021DE354 thumb ov137
 * GURU2_RECEIPT_GetJoinedBits 0x021DE37C thumb ov137
 * GURU2_RECEIPT_FreeStrings 0x021DD380 thumb ov137
 * func_020315D4 0x020315D4 arm
 * GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 */
#include "../include/Obj02207.h"
#include "../include/Obj23709.h"
#include "../include/Obj23710.h"
#include "../include/Obj23711.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct Node;
struct PrintSys;
struct Rec;
struct S02031140;
struct Tcbl;
struct WordSet;
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void GURU2_RECEIPT_FreeActors(u8 *p);
extern u32 GURU2_RECEIPT_DeleteWindows(void *);
extern void GURU2_RECEIPT_ExitBg(u32);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_02030EAC(struct Node *n);
struct S020315D4;
extern int GURU2_RECEIPT_GetMemberCount(void *p);
extern u32 GURU2_RECEIPT_GetJoinedBits(void *);
extern void GURU2_RECEIPT_FreeStrings(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int);
int GURU2_RECEIPT_ProcExit(void *a,int b,void *c,u8 *p)
{
    TCBL_DeleteAllTasks((struct Tcbl *)(((struct Obj02207 *)p)->fF4)); TCBL_Destroy((struct S02031140 *)(((struct Obj02207 *)p)->fF4));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj02207 *)p)->fEC)); PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj02207 *)p)->fEC));
    GURU2_RECEIPT_FreeActors(p); GURU2_RECEIPT_ExitBg(GURU2_RECEIPT_DeleteWindows(p));
    MSGDATA_Delete((struct Rec *)(((struct Obj02207 *)p)->f40)); WORDSET_DeleteStrbufED04((struct WordSet *)(((struct Obj02207 *)p)->f3C)); GF_FONT_Delete((void *)(((struct Obj02207 *)p)->f38));
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_02030EAC((struct Node *)(((struct Obj02207 *)p)->f30));
    ((struct Obj23709 *)(*(u8 * *)&((struct Obj02207 *)p)->fC))->f10=((struct Obj02207 *)p)->f8;
    ((struct Obj23710 *)(*(u8 * *)&((struct Obj02207 *)p)->fC))->f8=GURU2_RECEIPT_GetMemberCount(p);
    ((struct Obj23711 *)(*(u8 * *)&((struct Obj02207 *)p)->fC))->fC=GURU2_RECEIPT_GetJoinedBits(p);
    GURU2_RECEIPT_FreeStrings(p); func_020315D4(a); GFL_HEAP_DeleteChecked(114);
    return 1;
}
