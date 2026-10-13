/*
 * function: HAND_WAZA_TriAttackOnDecideAddSick
 * address:  0x021E10D8
 * packet:   pkt_ov093_021E10D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gTriAttackSickIds     0x021F286C  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Word { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
extern u32 BTL_CALC_Random(u32 range);
extern Word BTL_CALC_MakeDefaultSickCont(int x);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u32 gTriAttackSickIds[];

void HAND_WAZA_TriAttackOnDecideAddSick(int unused, void *q, int id)
{
    u32 v;
    Word w;
    int k;

    k = 3;
    if (id == BTL_EVENT_GetVar(3)) {
        v = gTriAttackSickIds[(u8)BTL_CALC_Random(k)];
        w = BTL_CALC_MakeDefaultSickCont(v);
        BTL_EVENT_OverwriteVar(0x1d, v);
        BTL_EVENT_OverwriteVar(0x1e, w.v);
        BTL_EVENT_OverwriteVar(0x26, 0x14);
    }
}
