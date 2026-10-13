/*
 * function: func_021D6064
 * address: 0x021D6064
 * packet: pkt_ov093_021D6064
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of zero alignment padding at 0x021D612E.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`slots = p;` before `slots = p;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT* in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   BTLV_CORE_GetSlotLow 0x021E8AFC thumb ov093
 *   BTLV_CORE_GetSlotValue 0x021E8B80 thumb ov093
 *   BTLV_CORE_GetZeroMasked 0x021E8918 thumb ov093
 *   BTL_POKEPARAM_HasMove 0x021D5750 thumb ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
union Slot { struct {u32 kind:3, lo:6, hi:6, rest:17;} s; };
extern u8 BTLV_CORE_GetSlotLow(union Slot);
extern u16 BTLV_CORE_GetSlotValue(union Slot);
extern union Slot BTLV_CORE_GetZeroMasked(void);
extern int BTL_POKEPARAM_HasMove(u8 *p, u16 id);
int func_021D6064(u8 *p, u32 k, union Slot *out, int *changed)
{
    u8 *slots;
    u8 max;
    union Slot slot;
    u32 tmp;
    if (k == 2 || k == 6) return 0;
    slots = p;
    slots = slots + 0x1c;
    if (((union Slot *)(slots + k * 4))->s.kind != 0) {
        max = BTLV_CORE_GetSlotLow(*(union Slot *)(slots + k * 4));
        slot = *(union Slot *)(slots + k * 4);
        if (out != 0) *out = slot;
        if (changed != 0) *changed = 0;
        if (k == 27 && BTL_POKEPARAM_HasMove(p, BTLV_CORE_GetSlotValue(slot)) == 0) {
            *(union Slot *)(slots + k * 4) = BTLV_CORE_GetZeroMasked();
            (p + 0xac)[k] = 0;
            if (changed != 0) *changed = 1;
        }
        if (max != 0) {
            (p + 0xac)[k]++;
            if ((p + 0xac)[k] >= max) {
                *(union Slot *)(slots + k * 4) = BTLV_CORE_GetZeroMasked();
                (p + 0xac)[k] = 0;
                if (changed != 0) *changed = 1;
            }
        } else if (((union Slot *)(slots + k * 4))->s.kind == 1 && ((union Slot *)(slots + k * 4))->s.lo != 0) {
            tmp = k * 4;
            if ((p + 0xac)[k] < ((union Slot *)(slots + tmp))->s.lo) (p + 0xac)[k]++;
        }
        return 1;
    }
    return 0;
}
