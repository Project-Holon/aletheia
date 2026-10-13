/*
 * function: func_021DA5D0
 * address:  0x021DA5D0
 * packet:   pkt_021DA5D0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unblocked by matching DWC_RAP_SetErrorCallback (ov009, EXACT): the +004A call site now
 * attests as `matched`.  Every other relocation resolves (the 0x72 argument is
 * an overlay id, attested as overlay_id).
 * symbols:
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   func_021D941C  0x021D941C  thumb  ov123
 *   func_021D9A1C  0x021D9A1C  thumb  ov123
 *   func_020307B0  0x020307B0  arm
 *   NHTTP_RAP_Destroy  0x021B9838  thumb  ov114
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   DWC_RAP_SetErrorCallback  0x02156DC4  thumb  ov009
 *   func_020315D4  0x020315D4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   ov114_id       0x00000072  data
 */
#include "../include/Obj02479.h"

typedef unsigned char  u8;
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_021D941C(u8 *p);
extern void func_021D9A1C(u8 *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void NHTTP_RAP_Destroy(u8 *p);
extern int GFL_NET_GetRunState(void);
extern void DWC_RAP_SetErrorCallback(int a, int b);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_02034A5C(int handle);
extern unsigned char ov114_id[];

int func_021DA5D0(int a, int b, int c, char *obj)
{
    if (((struct Obj02479 *)obj)->f14)
        APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj02479 *)obj)->f14));
    func_021D941C((u8 *)(((struct Obj02479 *)obj)->f10));
    func_021D9A1C((u8 *)(((struct Obj02479 *)obj)->fC));
    if (((struct Obj02479 *)obj)->f4)
        func_020307B0((void *)(((struct Obj02479 *)obj)->f4));
    if (((struct Obj02479 *)obj)->f24)
        func_020307B0((void *)(((struct Obj02479 *)obj)->f24));
    if (((struct Obj02479 *)obj)->f8) {
        NHTTP_RAP_Destroy((u8 *)(((struct Obj02479 *)obj)->f8));
        ((struct Obj02479 *)obj)->f8 = 0;
    }
    if (GFL_NET_GetRunState())
        DWC_RAP_SetErrorCallback(0, 0);
    func_020315D4((struct S020315D4 *)a);
    func_02034A5C((int)ov114_id);
    return 1;
}
