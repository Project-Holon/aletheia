/*
 * function: Wf2dmapFriend_Delete, Wf2dmapFriend_Proc
 * unit: yes
 * address: 0x021C6304
 * packet: pkt_ov128_021C6304
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   Wf2dmapFriend_DeleteGfx 0x021C6664 thumb ov128
 *   Wf2dmapFriend_DeleteText 0x021C6420 thumb ov128
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   Wf2dmapFriend_VBlank 0x021C665C thumb ov128
 *   gWf2dmapTouchbarOverlayIdRef 0x00000043 data
 *   gWf2dmapOverlayId 0x0000007F data
 */
#include "../include/Obj10480.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int     s32;
struct Node;
struct Proc;
extern void func_02030EAC(struct Node *n);
extern void Wf2dmapFriend_DeleteGfx(u8 *p);
extern void Wf2dmapFriend_DeleteText(u8 *p, void *a1);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern void func_02034A5C(s32 handle);
extern void Wf2dmapFriend_VBlank(void *);
extern char gWf2dmapTouchbarOverlayIdRef[],gWf2dmapOverlayId[];
int Wf2dmapFriend_Delete(void *p,int a,int b,char *q)
{
    func_02030EAC(((struct Obj10480 *)q)->f5A8); ((struct Obj10480 *)q)->f5A8=0;
    Wf2dmapFriend_DeleteGfx((u8 *)(q+4));
    Wf2dmapFriend_DeleteText((u8 *)(q+0x190),((struct Obj10480 *)q)->f1F8);
    func_020315D4(p); GFL_HEAP_DeleteChecked(52);
    func_02034A5C((u32)gWf2dmapTouchbarOverlayIdRef); func_02034A5C((u32)gWf2dmapOverlayId);
    return 1;
}
void Wf2dmapFriend_Proc(void *p,char *q) { Wf2dmapFriend_VBlank(q+4); }
