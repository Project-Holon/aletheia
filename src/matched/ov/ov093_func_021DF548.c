/*
 * function: HAND_ITEM_LightBallFlingParalyze
 * address:  0x021DF548
 * packet:   pkt_ov093_021DF548
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When id matches the value for key 2, allocate a 12-byte record (tag from
 * key 3), fill it (kind 1) and post it to the queue.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 */

typedef struct Word { unsigned int v; } Word;

typedef struct Rec {
    int f00;
    int f04;
    Word f08;
    unsigned char pad0c[3];
    unsigned char id;
} Rec;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern Word BTL_CALC_MakeDefaultSickCont(int x);

void HAND_ITEM_LightBallFlingParalyze(void *self, void *q, int id)
{
    Rec *r;
    unsigned char tag;

    if (id != BTL_EVENT_GetVar(2))
        return;
    tag = BTL_EVENT_GetVar(3);
    r = (Rec *)BTL_SERVER_FLOW_AllocCmdRecord(q, 12, tag);
    r->id = id;
    r->f04 = 1;
    r->f08 = BTL_CALC_MakeDefaultSickCont(1);
    BTL_SERVER_FLOW_CommitCmdRecord(q, r);
}
