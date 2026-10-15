/*
 * function: B_PLIST_MAIN_Task
 * address: 0x0220F478
 * packet: pkt_ov198_0220F478
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_ClearSelection 0x02211944 thumb ov198
 *   B_PLIST_MAIN_Delete 0x02210420 thumb ov198
 *   TCBL_Main 0x020310C4 arm
 *   B_PLIST_MAIN_UpdateActorAnims 0x0220F1A4 thumb ov198
 *   B_PLIST_ANM_StepPaletteAnim 0x0220B7AC thumb ov198
 *   B_PLIST_DRAW_UpdateToolWindows 0x0220E22C thumb ov198
 *   d_0221221C 0x0221221C data a4
 */
#include "../include/Obj01006.h"
#include "../include/Obj25225.h"
typedef unsigned char u8;
extern int (*const d_0221221C[])(u8 *);
extern void B_PLIST_MAIN_ClearSelection(u8 **);
struct Node;
extern int B_PLIST_MAIN_Delete(struct Node *task, char *p);
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void B_PLIST_MAIN_UpdateActorAnims(u8 *);
extern void B_PLIST_ANM_StepPaletteAnim(u8 *);
extern void B_PLIST_DRAW_UpdateToolWindows(u8 *);
void B_PLIST_MAIN_Task(void *task,u8 *p)
{
    if (((struct Obj25225 *)(*(u8 * *)&((struct Obj01006 *)p)->f0))->f34==1) {
        B_PLIST_MAIN_ClearSelection((u8 **)p);
        ((struct Obj01006 *)p)->f2178=33;
    }
    if (((struct Obj01006 *)p)->f2178!=33)
        ((struct Obj01006 *)p)->f2178=d_0221221C[*(int *)(p+0x2178)](p);
    if (((struct Obj01006 *)p)->f2178==33 && B_PLIST_MAIN_Delete(task,(char *)p)==1) return;
    TCBL_Main(((struct Obj01006 *)p)->f1D4);
    B_PLIST_MAIN_UpdateActorAnims(p);
    B_PLIST_ANM_StepPaletteAnim(p);
    B_PLIST_DRAW_UpdateToolWindows(p);
}
