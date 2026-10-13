/*
 * function: WEATHER_Delete
 * address:  0x021A1AAC
 * packet:   pkt_ov021_021A1AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   WEATHER_TASK_Delete  0x021A1DF8  thumb  ov021
 *   WEATHER_UnloadOverlay  0x021A1C04  thumb  ov021
 *   CLACT_DeleteRenderer  0x0204B084  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   FIELD_3DBG_DeleteBillboard  0x021A15D4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07491.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bank;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void WEATHER_TASK_Delete(u8 *p);
extern void WEATHER_UnloadOverlay(u8 *p);
extern void CLACT_DeleteRenderer(u32 v);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern int FIELD_3DBG_DeleteBillboard(u32 a);
extern u32 func_020307B0(void *p);

void WEATHER_Delete(u8 *p)
{
    int i;

    func_02030EAC((struct Node *)(((struct Obj07491 *)p)->f2C));
    for (i = 0; i < 2; i++) {
        WEATHER_TASK_Delete((u8 *)(*(u32 *)(p + 0x20 + i * 4)));
    }
    WEATHER_UnloadOverlay(p);
    CLACT_DeleteRenderer(((struct Obj07491 *)p)->f1C);
    CLACT_DeleteUnit((struct Bank *)(((struct Obj07491 *)p)->f18));
    for (i = 0; i < 2; i++) {
        FIELD_3DBG_DeleteBillboard(((u32 *)p)[i]);
    }
    func_020307B0(p);
}
