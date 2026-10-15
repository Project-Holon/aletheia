/*
 * function: BEACON_DETAIL_Exit
 * address: 0x02184470
 * packet: pkt_ov219_02184470
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 28604 legacy trailing three inputs neither read nor forwarded:
 * full body, 437AC and307B0 targets use only incoming r0; caller sets only r0.
 * ED04 legacy void leaves307B0 result live in r0 for following845A4 input;
 * preserve that return.306F0 caller explicitly truncates heap input to u16.
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   func_021845A4 0x021845A4 thumb ov219
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj05564.h"
typedef unsigned short u16;
struct PrintSys;struct S02031140;struct Proc;struct WordSet;
extern void PRINTSYS_QUE_Clear(struct PrintSys *),PRINTSYS_QUE_Delete(struct PrintSys *);
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetLcdSwap(unsigned);
extern int APP_KEYCURSOR_Delete(int);
extern void TCBL_Destroy(struct S02031140 *);
extern unsigned WORDSET_DeleteStrbufED04(struct WordSet *);
extern void func_021845A4(int),func_020315D4(struct Proc *),GFL_HEAP_DeleteChecked(unsigned int);
int BEACON_DETAIL_Exit(struct Proc *controller,void *unused1,void *unused2,char *p)
{
    unsigned heap=((struct Obj05564 *)p)->f0;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj05564 *)p)->fC080);
    PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj05564 *)p)->fC080);
    func_02040588(6,0);func_02040588(2,0);func_02040588(7,0);func_02040588(3,0);
    BG_SYS_SetLcdSwap(1);
    APP_KEYCURSOR_Delete(((struct Obj05564 *)p)->fC088);
    TCBL_Destroy(*(struct S02031140 * *)&((struct Obj05564 *)p)->fC0A4);
    func_021845A4(WORDSET_DeleteStrbufED04(*(struct WordSet * *)&((struct Obj05564 *)p)->fC0A8));
    func_020315D4(controller);GFL_HEAP_DeleteChecked((u16)heap);
    return 1;
}
