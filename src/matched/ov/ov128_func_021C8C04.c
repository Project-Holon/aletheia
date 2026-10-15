/*
 * function: Wf2dmapFriend_NameEntryMain
 * address: 0x021C8C04
 * packet: pkt_ov128_021C8C04
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034A5C 0x02034A5C arm
 *   func_02034AC4 0x02034AC4 arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   func_0203133C 0x0203133C arm
 *   PROCSYS_Push 0x02031348 arm
 *   func_020355C4 0x020355C4 arm
 *   WF2DMAP_TOUCH_CreateNameEntry 0x021C8DA0 thumb ov128
 *   Wf2dmapFriend_Teardown 0x021C6390 thumb ov128
 *   Wf2dmapFriend_Setup 0x021C6360 thumb ov128
 *   Wf2dmapFriend_SetState 0x021C6438 thumb ov128
 *   Wf2dmapFriend_CopyText 0x021C6440 thumb ov128
 *   NAMEIN_SETUP_FreeArgs 0x0216C0C0 thumb ov010
 *   gWf2dmapTouchbarOverlayId 0x00000043 data
 *   gWf2dmapNameEntryOverlayId 0x000000C2 data
 *   gWf2dmapNameInOverlayId 0x00000081 data
 *   gNameInProcData 0x021F5580 data ov194 a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   CODEIN_PARAM_Create  0x0202E4EC  thumb  arm9
 * interface: 02031324 forwards heap to 02031354 and returns its node;
 * 02031348 forwards all four inputs to 020314F4 despite legacy void(void).
 * data: Process setup loads ov194/ov129 and receives their callback tables.
 */
#include "../include/Obj23097.h"
#include "../include/Obj23098.h"
#include "../include/Obj23099.h"
#include "../include/Obj23100.h"
#include "../include/Obj23101.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int     s32;
struct Obj0202E54C;
struct Param;
struct S020314B8;
extern void func_02034A5C(s32 handle);
extern int func_02034AC4(s32 handle);
extern void *PROCSYS_Create(int);
extern u32 PROCSYS_Main(void *);
extern void func_0203133C(struct S020314B8 *p);
extern void PROCSYS_Push(void *, u32, void *, void *);
extern u8 func_020355C4(void);
extern char *WF2DMAP_TOUCH_CreateNameEntry(void *unused, char *q, int mode, int heap);
extern struct Param *CODEIN_PARAM_Create(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern void func_0202E54C(struct Obj0202E54C *p);
extern void Wf2dmapFriend_Teardown(u8 *);
extern void Wf2dmapFriend_Setup(char *p, int heap);
extern void Wf2dmapFriend_SetState(u8 *p, u8 a, u8 b);
extern void Wf2dmapFriend_CopyText(u8 *p, void *a, void *b);
extern int NAMEIN_SETUP_FreeArgs(int a0);
extern char gWf2dmapTouchbarOverlayId[], gWf2dmapNameEntryOverlayId[], gWf2dmapNameInOverlayId[];
extern char gNameInProcData[], d_021DA62C[];
int Wf2dmapFriend_NameEntryMain(void **p, u8 *a, u8 *b, void *unused, int heap)
{
    u32 sizes[3];
    switch (b[8]) {
    case 0:
        func_02034A5C((u32)gWf2dmapTouchbarOverlayId);
        p[1] = WF2DMAP_TOUCH_CreateNameEntry(p, (char *)b, 1, heap);
        sizes[0] = 4; sizes[1] = 4; sizes[2] = 4;
        p[2] = CODEIN_PARAM_Create(heap, 0, 0, 12, sizes);
        Wf2dmapFriend_Teardown(a);
        p[0] = PROCSYS_Create(heap);
        PROCSYS_Push(p[0], (u32)gWf2dmapNameEntryOverlayId, gNameInProcData, p[1]);
        b[8] = 1;
        break;
    case 1:
        if (PROCSYS_Main(p[0]) == 0) {
            if (((struct Obj23097 *)((u8 *)p[1]))->f1C == 0) {
                PROCSYS_Push(p[0], (u32)gWf2dmapNameInOverlayId, d_021DA62C, p[2]);
                b[8] = 2;
            } else {
                func_0203133C(p[0]);
                Wf2dmapFriend_SetState(b, 0, 0);
                b[8] = 3;
            }
        }
        break;
    case 2:
        if (PROCSYS_Main(p[0]) == 0) {
            func_0203133C(p[0]);
            Wf2dmapFriend_CopyText(b, ((struct Obj23098 *)((u8 *)p[1]))->f20, ((struct Obj23099 *)((u8 *)p[2]))->f20);
            Wf2dmapFriend_SetState(b, 0, 7);
            b[8] = 3;
        }
        break;
    case 3:
        NAMEIN_SETUP_FreeArgs((int)p[1]);
        func_0202E54C(p[2]);
        func_02034AC4((u32)gWf2dmapTouchbarOverlayId);
        Wf2dmapFriend_Setup((char *)a, heap);
        return 1;
    case 4:
        func_02034A5C((u32)gWf2dmapTouchbarOverlayId);
        p[1] = WF2DMAP_TOUCH_CreateNameEntry(p, (char *)b, 0, heap);
        Wf2dmapFriend_Teardown(a);
        p[0] = PROCSYS_Create(heap);
        PROCSYS_Push(p[0], (u32)gWf2dmapNameEntryOverlayId, gNameInProcData, p[1]);
        b[8] = 5;
        break;
    case 5:
        if (PROCSYS_Main(p[0]) == 0) {
            func_0203133C(p[0]);
            *(int *)b = func_020355C4();
            if (((struct Obj23100 *)((u8 *)p[1]))->f1C == 0) {
                Wf2dmapFriend_SetState(b, 1, 14);
                Wf2dmapFriend_CopyText(b, ((struct Obj23101 *)((u8 *)p[1]))->f20, 0);
                b[8] = 6;
            } else {
                Wf2dmapFriend_SetState(b, 1, 15);
                b[8] = 6;
            }
        }
        break;
    case 6:
        NAMEIN_SETUP_FreeArgs((int)p[1]);
        func_02034AC4((u32)gWf2dmapTouchbarOverlayId);
        Wf2dmapFriend_Setup((char *)a, heap);
        return 1;
    }
    return 0;
}
