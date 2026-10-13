/*
 * function: BTL_HANDLER_ITEM_ToxicOrbFlingPoison
 * address:  0x021DF5F4
 * packet:   pkt_ov093_021DF5F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When id matches the value for key 2, allocate a 12-byte record (tag from
 * key 3), fill it and post it to the queue.
 *
 * BTLV_CORE_MakeSlotKind1Index15 returns a one-word struct by value; that is what reserves
 * the empty frame word (push r3 / sub sp, #4). An int return drops it.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Index15  0x021E8A58  thumb  ov093
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
extern Word BTLV_CORE_MakeSlotKind1Index15(void);

void BTL_HANDLER_ITEM_ToxicOrbFlingPoison(void *self, void *q, int id)
{
    Rec *r;
    unsigned char tag;

    if (id != BTL_EVENT_GetVar(2))
        return;
    tag = BTL_EVENT_GetVar(3);
    r = (Rec *)func_021C88A4(q, 12, tag);
    r->id = id;
    r->f04 = 5;
    r->f08 = BTLV_CORE_MakeSlotKind1Index15();
    func_021C88C8(q, r);
}
