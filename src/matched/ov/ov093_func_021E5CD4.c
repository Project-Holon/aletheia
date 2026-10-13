/*
 * function: func_021E5CD4
 * address:  0x021E5CD4
 * packet:   pkt_ov093_021E5CD4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   func_021C824C  0x021C824C  thumb  ov093
 *   BTLV_CORE_CheckPartySlotPair  0x021E869C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern int func_021C824C(u8 *p, int v);
extern int BTLV_CORE_CheckPartySlotPair(void *p, int id);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E5CD4(u8 *p, void *a, int b)
{
    if (b != BTL_EVENT_GetVar(2))
        return;
    {
        void *r = func_021C7CF4(a, b);
        u16 v = (u32)BTL_POKEPARAM_GetItem(r);
        if (v == 0 || BTL_CALC_GetMonParamWithHeap((void *)v, 10) == 0 || func_021C824C(a, b) == 0
            || BTLV_CORE_CheckPartySlotPair(a, b) != 0)
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
    }
}
