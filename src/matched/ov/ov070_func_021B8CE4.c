/*
 * function: ITEMMENU_StartPocketTabPress
 * address:  0x021B8CE4
 * packet:   pkt_ov070_021B8CE4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_SwitchPocketCursor  0x021B6288  thumb  ov070
 *   ITEMMENU_RefreshInputGuard  0x021B80BC  thumb  ov070
 *   ITEMMENU_UpdatePocketSortIcon  0x021B81F4  thumb  ov070
 *   ITEMMENU_RedrawList  0x021B6138  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskWaitPocketTabPress  0x021B8D88  thumb  ov070
 */
#include "../include/Obj00002.h"

struct Obj;
extern void ITEMMENU_SwitchPocketCursor(struct Obj *o, int a, int b);
extern void ITEMMENU_RefreshInputGuard(void *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Obj;
extern void ITEMMENU_UpdatePocketSortIcon(u8 *p);
extern void ITEMMENU_RedrawList(char *p);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskWaitPocketTabPress(char *p);

void ITEMMENU_StartPocketTabPress(int p, int u, int a, int b)
{
    int x;
    ITEMMENU_SwitchPocketCursor((struct Obj *)p, u, ((struct Obj00002 *)p)->f80C);
    ITEMMENU_RefreshInputGuard((void *)p);
    ITEMMENU_UpdatePocketSortIcon((u8 *)p);
    ((struct Obj00002 *)p)->f818 = 0xFFFF;
    ITEMMENU_RedrawList((char *)p);
    if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    ((struct Obj00002 *)p)->f864 = a;
    ((struct Obj00002 *)p)->f866 = 6;
    CLACT_SetActorAnimFrame((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), 0);
    CLACT_SetActorAnimSeq((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), (unsigned short)x);
    func_0204B92C((struct Obj *)*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710), 1);
    *(int *)&((struct Obj00002 *)p)->f868 = b;
    ITEMMENU_SetTask((char *)p, (int)ITEMMENU_TaskWaitPocketTabPress);
}
