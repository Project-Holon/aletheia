/*
 * function: EVENT_FIELD_PROCLINK_SetReturnSlot
 * address:  0x02162230
 * packet:   pkt_ov010_02162230
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     caller 0x02162008 forwards all three of its arguments unchanged
 *           (r0-r2); the copy is MI_CpuCopy8-shaped (src, dst, 8) into the
 *           index-th eight-byte slot after an 8-byte head, then bit index of
 *           the u16 at +2 is set.
 * symbols:
 *   func_02082D44  0x02082D44  arm
 */
typedef unsigned short u16;

extern void func_02082D44(void *src, void *dst, unsigned n);

void EVENT_FIELD_PROCLINK_SetReturnSlot(char *p, int index, void *s)
{
    func_02082D44(s, p + 8 + index * 8, 8);
    *(u16 *)(p + 2) = (u16)(*(u16 *)(p + 2) | (1 << index));
}
