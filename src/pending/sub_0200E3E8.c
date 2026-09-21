/*
 * function: sub_0200E3E8
 * address:  0x0200E3E8
 * packet:   pkt_0200E3E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 *
 * blocked on: no evidence class. Both calls target 0x02167380 and
 * 0x02167358, which lie in the ov009/ov010 overlap and are unlabelled
 * leaves in BOTH candidate listings (no lr-saving prologue, the
 * unlabelled-leaf-functions-hide-in-word-runs idiom), so `label` has no
 * label to read and a region hint cannot help: neither candidate has one.
 * sole-ref/code reads the ARM9 label map only, so it does not reach an
 * overlay address either. Every concrete byte matches at 86 bytes.
 *
 * near miss resolved (wave 4, permuter): the note's 88-byte version was a
 * six-register permutation away. Two spellings closed it, neither of which
 * the permuter's mutation set can reach (both change the emitted
 * instruction kinds, not the allocation):
 *   - the clear mask is (u8)(0xFFu ^ (1u << b)), which emits
 *     `movs r6,#0xff; eors r6,r7`; the ~ spelling emits a single `mvns`
 *     and is the whole 2-byte size gap.
 *   - inside the wrap test, `byte++` must precede `b = 0`; the reverse
 *     order emits `movs #0` before the `adds` and shifts the allocation.
 *
 * symbols:
 *   func_02167380  0x02167380  thumb
 *   func_02167358  0x02167358  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_02167380(int id);
extern u32 func_02167358(int id);

void sub_0200E3E8(u8 *bits, int id, u32 value)
{
    u32 bit = func_02167380(id);
    u32 n   = func_02167358(id);
    u32 byte = bit >> 3;
    u32 b    = bit & 7;

    while (n != 0) {
        bits[byte] &= (u8)(0xFFu ^ (1u << b));
        bits[byte] |= (u8)((value & 1) << b);
        b++;
        if (b > 7) {
            byte++;
            b = 0;
        }
        value >>= 1;
        n--;
    }
}
