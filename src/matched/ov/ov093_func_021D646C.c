/*
 * function: BTL_POKEPARAM_ResetAllEffects
 * address:  0x021D646C
 * packet:   pkt_ov093_021D646C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   BTL_POKEPARAM_RestoreIfNeeded  0x021D533C  thumb  ov093
 *   BTL_POKEPARAM_ResetBattleMoves  0x021D5150  thumb  ov093
 *   BTL_POKEPARAM_ResetMoveHistory  0x021D5364  thumb  ov093
 *   BTL_POKEPARAM_ClearMoveFlags  0x021D539C  thumb  ov093
 *   BTL_EVENT_ClearClientReservedChoice  0x021D6E88  thumb  ov093
 *   BTL_POKEPARAM_ClearIllusion  0x021D6C2C  thumb  ov093
 *   BTL_POKEPARAM_ClearSubstitute  0x021D6D70  thumb  ov093
 *   BTL_POKEPARAM_ClearSickConts  0x021D63B8  thumb  ov093
 *   BTL_POKEPARAM_InitStatStages  0x021D53C0  thumb  ov093
 */
#include "../include/Obj00041.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct {
    void *w;
    u8 pad4[0x12];
    u16 f16;
    u8 pad18[3];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj;
extern void MI_CpuFill8(void *dst, u8 v, u32 n);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_RecalcParam(void *p);
struct S;
struct Unk021D6C2C;
struct UtilWork;
struct Work;
extern void BTL_POKEPARAM_RestoreIfNeeded(struct S *p);
extern void BTL_POKEPARAM_ResetBattleMoves(struct Work *p);
extern void BTL_POKEPARAM_ResetMoveHistory(struct UtilWork *p);
extern void BTL_POKEPARAM_ClearMoveFlags(struct UtilWork *p);
extern void BTL_EVENT_ClearClientReservedChoice(u8 *p);
extern void BTL_POKEPARAM_ClearIllusion(struct Unk021D6C2C *p);
extern void BTL_POKEPARAM_ClearSubstitute(unsigned char *p);
extern void BTL_POKEPARAM_ClearSickConts(u8 *p, int all);
extern void BTL_POKEPARAM_InitStatStages(unsigned char *p);

void BTL_POKEPARAM_ResetAllEffects(Obj *p)
{
    MI_CpuFill8((u8 *)p + 0x153, 0, 2);
    MI_CpuFill8((u8 *)p + 0x155, 0, 2);
    BTL_POKEPARAM_RestoreIfNeeded((struct S *)p);
    BTL_POKEPARAM_ResetBattleMoves((struct Work *)p);
    BTL_POKEPARAM_ResetMoveHistory((struct UtilWork *)p);
    BTL_POKEPARAM_ClearMoveFlags((struct UtilWork *)p);
    BTL_EVENT_ClearClientReservedChoice((u8 *)p);
    BTL_POKEPARAM_ClearIllusion((struct Unk021D6C2C *)p);
    BTL_POKEPARAM_ClearSubstitute((unsigned char *)p);
    BTL_POKEPARAM_ClearSickConts((u8 *)p, 1);
    BTL_POKEPARAM_InitStatStages((unsigned char *)((char *)p + 0xfc));
    ((u8 *)p)[0x141] = p->f1b_lo;
    ((struct Obj00041 *)p)->f13C = p->f16;
    POKE_TOOL_SetPartyValue(p->w, 0x6f, ((u8 *)p)[0x141]);
    POKE_TOOL_RecalcParam(p->w);
}
