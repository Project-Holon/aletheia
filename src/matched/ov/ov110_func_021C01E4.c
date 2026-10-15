/*
 * function: PMS_SELECT_GRAPHIC_ProcExit
 * address: 0x021C01E4
 * packet: pkt_ov110_021C01E4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_SELECT_GRAPHIC_Teardown 0x021C05B0 thumb ov110
 *   func_0203133C 0x0203133C arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x43 data
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 */
#include "../include/Obj06394.h"
extern void PMS_SELECT_GRAPHIC_Teardown(char *p);
struct PrintSys;
struct Rec;
struct S020314B8;
struct Proc;
extern void func_0203133C(struct S020314B8 *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void func_02034A5C(int handle);
extern char ov067_id[];
int PMS_SELECT_GRAPHIC_ProcExit(void *p, int a, int b, char *q) {
    PMS_SELECT_GRAPHIC_Teardown(q);
    func_0203133C(((struct Obj06394 *)q)->fAC);
    PRINTSYS_QUE_Clear(((struct Obj06394 *)q)->f5C);
    PRINTSYS_QUE_Delete(((struct Obj06394 *)q)->f5C);
    MSGDATA_Delete(((struct Obj06394 *)q)->f60);
    GF_FONT_Delete(((struct Obj06394 *)q)->f58);
    func_020315D4(p);
    GFL_HEAP_DeleteChecked(0x51);
    func_02034A5C((int)ov067_id);
    return 1;
}
