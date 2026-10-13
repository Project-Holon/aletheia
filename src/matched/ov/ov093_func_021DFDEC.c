/*
 * function: HAND_ITEM_CellBatteryUse
 * address:  0x021DFDEC
 * packet:   pkt_ov093_021DFDEC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */

typedef struct Rec {
    int pad00;
    int f04;
    unsigned char pad08[4];
    unsigned char f0c;
    unsigned char pad0d[2];
    unsigned char f0f;
    unsigned char f10;
} Rec;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_CellBatteryUse(void *self, void *q, int id)
{
    Rec *r;

    if (id != BTL_EVENT_GetVar(2))
        return;
    r = (Rec *)BTL_SERVER_FLOW_AllocCmdRecord(q, 14, id);
    r->f0f = 1;
    r->f10 = id;
    r->f04 = 1;
    r->f0c = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(q, r);
}
