/*
 * function: GSYNC_MENU_StatePlayButtonAnim
 * address: 0x021D4B44
 * packet: pkt_ov123_021D4B44
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: callback 0x021D45F0 resolved by its verified ov123 shard.
 * symbols:
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   GSYNC_MENU_OnButtonAnimEnd 0x021D451C thumb ov123
 *   GSYNC_MENU_NoOp 0x021D45F0 thumb ov123
 */
#include "../include/Obj10435.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 value; char *object; void (*callback)(char *); } Callback;
struct Actor;
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void GSYNC_MENU_ChangeState(char *, void *, int);
extern void GSYNC_MENU_OnButtonAnimEnd(char *);
extern void GSYNC_MENU_NoOp(void);
void GSYNC_MENU_StatePlayButtonAnim(char *p)
{
    Callback cb;
    cb.value = 0;
    cb.object = p;
    cb.callback = GSYNC_MENU_OnButtonAnimEnd;
    CLACT_SetActorAutoAnim(*(void **)(p + ((struct Obj10435 *)p)->f270 * 4 + 0x2a0), 1);
    CLACT_ApplyActorAnimCommand(*(void **)(p + ((struct Obj10435 *)p)->f270 * 4 + 0x2a0), (const struct Cmd *)(&cb));
    CLACT_RestartActorAnim(*(void **)(p + ((struct Obj10435 *)p)->f270 * 4 + 0x2a0));
    GSYNC_MENU_ChangeState(p, GSYNC_MENU_NoOp, 0x376);
}
