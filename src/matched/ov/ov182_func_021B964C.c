/*
 * function: THE_END_GRAPHIC_Exit
 * address: 0x021B964C
 * packet: pkt_ov182_021B964C
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 04001050 and 04001000 read/write at 021B966C-021B967A.
 * symbols:
 *   d_021B9BAC 0x021B9BAC data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   THE_END_GRAPHIC_Dummy 0x021B9810 thumb ov182
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   THE_END_GRAPHIC_Delete 0x021B998C thumb ov182
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj06593.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 id; u32 v[10];} Record;
extern const Record d_021B9BAC[1];
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void THE_END_GRAPHIC_Dummy(void *);
struct Node;
struct PrintSys;
struct Proc;
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void THE_END_GRAPHIC_Delete(char *p);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
int THE_END_GRAPHIC_Exit(void *task, int b, int c, char *p)
{
    int i;
    for (i = 0; i < sizeof(d_021B9BAC) / sizeof(d_021B9BAC[0]); i++)
        BG_SYS_FreeLayerBuf((u8)d_021B9BAC[i].id);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    THE_END_GRAPHIC_Dummy(p);
    func_02030EAC(((struct Obj06593 *)p)->f14);
    PRINTSYS_QUE_Clear(((struct Obj06593 *)p)->fC);
    PRINTSYS_QUE_Delete(((struct Obj06593 *)p)->fC);
    GF_FONT_Delete(((struct Obj06593 *)p)->f8);
    THE_END_GRAPHIC_Delete(((struct Obj06593 *)p)->f4);
    func_020315D4(task);
    GFL_HEAP_DeleteChecked(0x88);
    return 1;
}
