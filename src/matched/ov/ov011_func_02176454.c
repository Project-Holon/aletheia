/*
 * function: INTRUDE_COMM_PartyProcInit
 * address:  0x02176454
 * packet:   pkt_ov011_02176454
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   PROCSYS_Create  0x02031324  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_IsMemberBattleReady  0x0201AB34  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   POKE_TOOL_SetLevelAndRecalc  0x02019CA0  thumb
 *   func_02034714  0x02034714  arm
 *   d_02177010     0x02177010  data  ov011  a1
 */
#include "../include/Obj07335.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 w0;
    u8  pad4;
    u8  b5;
    u8  b6;
} Arg;

extern u8 d_02177010[];
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *PROCSYS_Create(int heap);
struct Ctx;
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
struct BigObj;
struct Party;
struct PartyMon;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void POKE_TOOL_HealParty(void *p);
extern u32 POKEPARTY_GetCount(void *p);
extern struct Party *POKEPARTY_Create(u32 heap);
extern u32 POKEPARTY_IsMemberBattleReady(void *p, u32 idx);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void POKE_TOOL_SetLevelAndRecalc(void *p, u32 v);
extern void func_02034714(const char *expr, u32 line, const char *file);

int INTRUDE_COMM_PartyProcInit(struct Proc *a0, int a1, Arg *arg)
{
    u8 *w;
    int n;
    void *list;
    int i;
    int cnt;

    cnt = 0;
    w = PROCSYS_AllocProcWork(a0, 0x100, 4);
    MI_CpuFill8(w, 0, 0x100);
    ((struct Obj07335 *)w)->fF4 = PROCSYS_Create(4);
    list = GAME_DATA_GetMyParty(ICA_ANIME_GetField1C((const struct Ctx *)arg->w0));
    POKE_TOOL_HealParty(list);
    n = POKEPARTY_GetCount(list);
    ((struct Obj07335 *)w)->fF8 = POKEPARTY_Create(4);
    for (i = 0; i < n; i++) {
        if (cnt >= arg->b6) {
            break;
        }
        if (POKEPARTY_IsMemberBattleReady(list, i) == 1) {
            POKEPARTY_Add(((struct Obj07335 *)w)->fF8, POKEPARTY_GetMember(list, i));
            POKE_TOOL_SetLevelAndRecalc(POKEPARTY_GetMember(((struct Obj07335 *)w)->fF8, cnt), arg->b5);
            cnt++;
        }
    }
    if (cnt <= 0) {
        func_02034714((const char *)d_02177010, 0, (const char *)d_02177010);
    }
    return 1;
}
