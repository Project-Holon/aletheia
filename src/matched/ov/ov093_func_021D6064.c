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
 * symbols:
 *   func_021E8AFC 0x021E8AFC thumb ov093
 *   func_021E8B80 0x021E8B80 thumb ov093
 *   func_021E8918 0x021E8918 thumb ov093
 *   func_021D5750 0x021D5750 thumb ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
union Slot { struct {u32 kind:3, lo:6, hi:6, rest:17;} s; };
extern u8 func_021E8AFC(union Slot);
extern u16 func_021E8B80(union Slot);
extern union Slot func_021E8918(void);
extern int func_021D5750(u8 *, int);
int func_021D6064(u8 *p, u32 k, union Slot *out, int *changed)
{
    u8 *slots;
    u8 max;
    union Slot slot;
    u32 tmp;
    if (k == 2 || k == 6) return 0;
    slots = p;
    slots = p;
    slots = slots + 0x1c;
    if (((union Slot *)(slots + k * 4))->s.kind != 0) {
        max = func_021E8AFC(*(union Slot *)(slots + k * 4));
        slot = *(union Slot *)(slots + k * 4);
        if (out != 0) *out = slot;
        if (changed != 0) *changed = 0;
        if (k == 27 && func_021D5750(p, func_021E8B80(slot)) == 0) {
            *(union Slot *)(slots + k * 4) = func_021E8918();
            (p + 0xac)[k] = 0;
            if (changed != 0) *changed = 1;
        }
        if (max != 0) {
            (p + 0xac)[k]++;
            if ((p + 0xac)[k] >= max) {
                *(union Slot *)(slots + k * 4) = func_021E8918();
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
