/*
 * function: BTL_POKEPARAM_CureSickBySource
 * address:  0x021D6264
 * packet:   pkt_ov093_021D6264
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_CORE_IsSlotKindNone  0x021E8928  thumb  ov093
 *   BTLV_CORE_GetSlotPosition  0x021E8A98  thumb  ov093
 *   BTLV_CORE_GetZeroMasked  0x021E8918  thumb  ov093
 *   BTL_POKEPARAM_ClearDependentSick  0x021D621C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
struct Slot { u32 a : 3; u32 rest : 29; };
struct UtilSlots { u8 pad[0x1c]; struct Slot s[36]; };
extern int BTLV_CORE_IsSlotKindNone(struct Slot s);
extern int BTLV_CORE_GetSlotPosition(struct Slot s);
extern struct Slot BTLV_CORE_GetZeroMasked(void);
struct Unk021D621C;
extern void BTL_POKEPARAM_ClearDependentSick(struct Unk021D621C *p, int k);

void BTL_POKEPARAM_CureSickBySource(struct UtilSlots *p, int v)
{
    u32 i;
    if (v != 0x1f) {
        for (i = 0; i < 0x24; i++) {
            if (BTLV_CORE_IsSlotKindNone(p->s[i]) == 0 && v == BTLV_CORE_GetSlotPosition(p->s[i])) {
                p->s[i] = BTLV_CORE_GetZeroMasked();
                BTL_POKEPARAM_ClearDependentSick((struct Unk021D621C *)p, i);
            }
        }
    }
}
