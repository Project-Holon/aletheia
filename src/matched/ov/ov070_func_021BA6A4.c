/*
 * function: ITEMMENU_MoveCursorToRow
 * address:  0x021BA6A4
 * packet:   pkt_ov070_021BA6A4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_GetItemCount  0x021B61C8  thumb  ov070
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   SCROLLBAR_GetPosFromValue  0x0202EE0C  thumb
 */
#include "../include/Obj00002.h"

typedef struct {
    unsigned short a, b;
} Pt;

typedef unsigned char  u8;
extern int ITEMMENU_GetItemCount(u8 *p);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, unsigned int which);
typedef unsigned int   u32;
extern u32 SCROLLBAR_GetPosFromValue(u32 a, u32 b, u32 c, u32 d, u32 e);

void ITEMMENU_MoveCursorToRow(char *p)
{
    Pt pt;
    int n = ITEMMENU_GetItemCount((u8 *)p);
    if (n >= 7) {
        CLACT_GetActorSurfacePos((struct Actor *)*(int *)&((struct Obj00002 *)p)->f6A8, (struct PtS *)&pt, 0xFFFF);
        pt.b = SCROLLBAR_GetPosFromValue(n - 6, ((struct Obj00002 *)p)->f814 + 1, 0x1A, 0x8E, 0);
        CLACT_AddActorSurfacePos((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f6A8), (const struct Vec2 *)(&pt), 0xFFFF);
    }
}
