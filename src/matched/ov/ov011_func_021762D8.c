/*
 * function: INTRUDE_COMM_SetWordSetRequest
 * address:  0x021762D8
 * packet:   pkt_ov011_021762D8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   INTRUDE_COMM_SetWordSetMemberName  0x021762C0  thumb  ov011
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_Callback_EF40  0x0201EF40  thumb
 *   WORDSET_SetSlotFromMsgA0  0x0201F184  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u32 f0_0 : 15;
    u32 f0_15 : 7;
    u32 f0_22 : 10;
    u32 kind : 4;
    u32 f4_4 : 28;
    u32 pad8[3];
    Pos pos;
} Obj;

extern void INTRUDE_COMM_SetWordSetMemberName(void *a, int b, void *c, void *d);
typedef signed int     s32;
struct WordSet;
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsgA0(struct WordSet *p, u32 i, s32 v);

void INTRUDE_COMM_SetWordSetRequest(const Obj *obj, void *a1, void *a2, void *a3)
{
    int v;

    switch (obj->kind) {
    case 0:
        INTRUDE_COMM_SetWordSetMemberName(a2, 0, a1, a3);
        WORDSET_SetSlotNumber(a2, 1, obj->pos.x, 3, 0, 1);
        break;
    case 1:
        INTRUDE_COMM_SetWordSetMemberName(a2, 0, a1, a3);
        WORDSET_SetSlotFromMsgA0(a2, 1, obj->pos.x);
        break;
    case 2:
        INTRUDE_COMM_SetWordSetMemberName(a2, 0, a1, a3);
        WORDSET_SetSlotFromMsgA0(a2, 1, obj->pos.x);
        break;
    case 3: {
        const Pos *pos = &obj->pos;
        INTRUDE_COMM_SetWordSetMemberName(a2, 0, a1, a3);
        WORDSET_Callback_EF40(a2, 1, pos->x);
        WORDSET_SetSlotNumber(a2, 2, pos->y, 5, 0, 1);
        break;
    }
    case 4:
        WORDSET_Callback_EF40(a2, 0, obj->pos.y);
        INTRUDE_COMM_SetWordSetMemberName(a2, 1, a1, a3);
        break;
    case 5:
        INTRUDE_COMM_SetWordSetMemberName(a2, 0, a1, a3);
        break;
    }
    WORDSET_SetSlotNumber(a2, 2, obj->f0_22, 4, 0, 1);
    v = obj->f0_15;
    if (v > 20) {
        v = 1;
    }
    WORDSET_SetSlotNumber(a2, 3, v, 4, 0, 1);
}
