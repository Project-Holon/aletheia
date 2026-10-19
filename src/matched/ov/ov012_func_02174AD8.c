/*
 * function: UNION_SCENE_StepStartBattleSelect
 * address:  0x02174AD8
 * packet:   pkt_ov012_02174AD8
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRC_BATTLE_TASK_Create  0x02157450  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Rec;
void *IRC_BATTLE_TASK_Create(void *a0, void *a1, u32 kind, struct Rec *rec);

u32 UNION_SCENE_StepStartBattleSelect(void *a0, u8 *a1, void *a2, void *a3, u32 a4, void **out, u8 *state)
{
    u8 *q = a1 + 0x2830;
    if (*state == 0) {
        *out = IRC_BATTLE_TASK_Create(a0, a2, q[0], a3);
    } else {
        return 1;
    }
    (*state)++;
    return 0;
}
