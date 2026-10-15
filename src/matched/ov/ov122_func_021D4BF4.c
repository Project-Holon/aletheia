/*
 * function: INTRUDE_COMM_VIEW_AnimateSelectedRow
 * address: 0x021D4BF4
 * packet: pkt_ov122_021D4BF4
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: unit pkt_ov122_021D4B74 attests callbacks 0x021D4BDC and 0x021D4BF0.
 * symbols:
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   INTRUDE_COMM_VIEW_StartExit 0x021D4BDC thumb ov122
 *   INTRUDE_COMM_VIEW_Noop 0x021D4BF0 thumb ov122
 *   INTRUDE_COMM_VIEW_SetCallback 0x021D4244 thumb ov122
 */
#include "../include/Obj22930.h"
typedef unsigned short u16;
typedef struct { u16 f00; char *f04; void (*f08)(void); } Params;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void INTRUDE_COMM_VIEW_StartExit(char *p);
extern void INTRUDE_COMM_VIEW_Noop(void);
extern void INTRUDE_COMM_VIEW_SetCallback(void *p, u32 a, int a2);
void INTRUDE_COMM_VIEW_AnimateSelectedRow(char *p)
{
    int i;
    Params args;
    void **base;
    i = ((struct Obj22930 *)p)->f35C;
    args.f00 = 0;
    args.f04 = p;
    args.f08 = (void (*)(void))INTRUDE_COMM_VIEW_StartExit;
    if (i == 3) i = 0;
    else if (i == 4) i = 1;
    base = (void **)(p + 0x390);
    CLACT_SetActorAutoAnim(base[i], 1);
    CLACT_ApplyActorAnimCommand(base[i], (const struct Cmd *)(&args));
    CLACT_RestartActorAnim(base[i]);
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_Noop, 0x390);
}
