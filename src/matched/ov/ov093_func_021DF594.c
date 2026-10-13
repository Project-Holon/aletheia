/*
 * function: BTL_HANDLER_ITEM_ToxicOrbPoisonHolderOnTurnEnd
 * address:  0x021DF594
 * packet:   pkt_ov093_021DF594
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Index15  0x021E8A58  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Rec {
    int f00;
    int f04;
    u32 f08;
    u8 f0c;
    u8 pad0d[2];
    u8 id;
} Rec;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
struct QQ;
extern int BTLV_CORE_MakeSlotKind1Index15(void);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);

void BTL_HANDLER_ITEM_ToxicOrbPoisonHolderOnTurnEnd(void *self, void *q, int id)
{
    Rec *r;

    if (id != BTL_EVENT_GetVar(2))
        return;
    r = (Rec *)func_021C88A4(q, 12, id);
    r->f04 = 5;
    r->f08 = BTLV_CORE_MakeSlotKind1Index15();
    r->f0c = 0;
    r->id = id;
    func_021C8838((u8 *)r + 0x14, 2, 0xf0);
    func_021C8860((struct S *)((u8 *)r + 0x14), id);
    func_021C8860((struct S *)((u8 *)r + 0x14), BTL_EVENT_GetFactorKey(self));
    func_021C88C8(q, r);
}
