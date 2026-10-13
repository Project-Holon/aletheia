/*
 * function: BTL_HANDLER_ITEM_AirBalloonEnterField
 * address:  0x021DFB4C
 * packet:   pkt_ov093_021DFB4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_FIELD_GetStaticSlotObject(int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void BTL_HANDLER_ITEM_AirBalloonEnterField(void *self, void *q, int id)
{
    u8 *r;

    if (id != BTL_EVENT_GetVar(2))
        return;
    if (BTL_FIELD_GetStaticSlotObject(2) != 0)
        return;
    r = (u8 *)func_021C88A4(q, 4, id);
    func_021C8838(r + 4, 2, 0x198);
    func_021C8860((struct S *)(r + 4), id);
    func_021C88C8(q, r);
}
