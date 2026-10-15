/*
 * function: FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges
 * address:  0x021F3880
 * packet:   pkt_ov060_021F3880
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetIntrudeId  0x02012B80  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GAME_DATA_GetEnterMode  0x02012B40  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GAME_DATA_GetBattleRecSlot  0x020127AC  thumb
 *   INTRUDE_GetMissionScore  0x0200BDF8  thumb
 *   INTRUDE_GetMissionBonusScore  0x0200BDFC  thumb
 *   FIELD_GIMMICK_GAUGE_EFFECT_ToGaugeStep  0x021F3870  thumb  ov060
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

struct BigObj;
extern u8 GAME_DATA_GetIntrudeId(const struct BigObj *p);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern u8 GAME_DATA_GetEnterMode(const struct BigObj *p);
extern void *GAME_DATA_GetLastBattleRecSlot(void *p);
typedef unsigned int   u32;
struct Rec1B0;
struct SaveBlock;
extern void *GAME_DATA_GetBattleRecSlot(struct SaveBlock *p, u32 idx);
extern u16 INTRUDE_GetMissionScore(struct Rec1B0 *p);
extern u16 INTRUDE_GetMissionBonusScore(struct Rec1B0 *p);
extern int FIELD_GIMMICK_GAUGE_EFFECT_ToGaugeStep(int x);
extern V *FLD_EXP_OBJ_GetModelStatus(void *p, int i, u16 j);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);

u8 FIELD_GIMMICK_GAUGE_EFFECT_ShowGauges(void *a, void *b, void *unused)
{
    int r6;
    int r4;
    int r5;
    int r7;
    int e;
    V *p;

    r6 = GAME_DATA_GetIntrudeId(a);
    r4 = r6 - GAME_DATA_GetExitMode(a);
    if (r4 < 0) {
        r4 += GAME_DATA_GetEnterMode(a);
    }
    if (r6 == GAME_DATA_GetExitMode(a)) {
        e = (int)GAME_DATA_GetLastBattleRecSlot(a);
    } else {
        e = (int)GAME_DATA_GetBattleRecSlot(a, r6);
    }
    r7 = e;
    r5 = FIELD_GIMMICK_GAUGE_EFFECT_ToGaugeStep(INTRUDE_GetMissionScore((struct Rec1B0 *)r7));
    r7 = FIELD_GIMMICK_GAUGE_EFFECT_ToGaugeStep(INTRUDE_GetMissionBonusScore((struct Rec1B0 *)r7));
    p = FLD_EXP_OBJ_GetModelStatus(b, 0, r5 + 10);
    r4 = (r4 << 22) + 0x1F8000;
    p->a = r4;
    p->b = 0x20000;
    p->c = 0x1B8000;
    p = FLD_EXP_OBJ_GetModelStatus(b, 0, r7);
    p->a = r4;
    p->b = 0x20000;
    p->c = 0x1B8000;
    FLD_EXP_OBJ_SetModelHidden(b, 0, (u16)(r5 + 10), 0);
    FLD_EXP_OBJ_SetModelHidden(b, 0, (u16)r7, 0);
    return r6;
}
