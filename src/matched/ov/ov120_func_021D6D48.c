/*
 * function: GTSNEGO_MSG_TeardownActorList
 * address: 0x021D6D48
 * packet: pkt_ov120_021D6D48
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GTSNEGO_DISP_DeleteTouchbar 0x021D698C thumb ov120
 *   GTSNEGO_DISP_CreateTouchbar 0x021D692C thumb ov120
 *   GTSNEGO_MSG_DeleteCursorActor 0x021D6ED8 thumb ov120
 */
#include "../include/Obj00199.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern void GTSNEGO_DISP_DeleteTouchbar(u8 *);
extern void GTSNEGO_DISP_CreateTouchbar(u8 *, int);
extern void GTSNEGO_MSG_DeleteCursorActor(u8 *);
void GTSNEGO_MSG_TeardownActorList(u8 *p)
{
    void *t = func_020490F4(144, ((struct Obj00199 *)p)->fF4);
    int i;
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0x14c)) {
            CLACT_DeleteActor(*(void **)(p + i * 4 + 0x14c));
            *(void **)(p + i * 4 + 0x14c) = 0;
        }
    }
    GTSNEGO_DISP_DeleteTouchbar(p);
    GTSNEGO_DISP_CreateTouchbar(p, 0);
    GTSNEGO_MSG_DeleteCursorActor(p);
    ARC_TOOL_DeleteHandle(t);
}
