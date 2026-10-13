/*
 * function: BTL_HANDLER_ITEM_PoisonBarbFlingPoison
 * address:  0x021DF7F4
 * packet:   pkt_ov093_021DF7F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of BTL_HANDLER_ITEM_LightBallFlingParalyze with kind 5.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
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
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern Word BTL_CALC_MakeDefaultSickCont(int x);

void BTL_HANDLER_ITEM_PoisonBarbFlingPoison(void *self, void *q, int id)
{
    Rec *r;
    unsigned char tag;

    if (id != BTL_EVENT_GetVar(2))
        return;
    tag = BTL_EVENT_GetVar(3);
    r = (Rec *)func_021C88A4(q, 12, tag);
    r->id = id;
    r->f04 = 5;
    r->f08 = BTL_CALC_MakeDefaultSickCont(5);
    func_021C88C8(q, r);
}
