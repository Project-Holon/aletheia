/*
 * function: GFL_NET_HANDLE_SetBitMask
 * address:  0x0203A28C
 * packet:   pkt_0203A28C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   file_020A7A68  0x020A7A68  data
 *   file_020A7AB0  0x020A7AB0  data
 *
 * Set or clear one bit of the 16-bit slot mask, reporting at line 0x391 (913)
 * when the bit index is the 0xFF sentinel.  This is the write half of
 * GFL_NET_HANDLE_IsBitSet's read (line 0x3AB), sharing its file/message pair.
 *
 * The mask is a u16 throughout, which is what the `lsl #0x10` / `lsr #16`
 * pairs around every store of it are: `1 << idx` is built in a word, narrowed
 * to 16 bits for the OR, and the complement for the clear arm is narrowed
 * THREE times: `~` widens back to int, the AND is done in int, and the result
 * is narrowed once more on the way to the variable.  Writing the clear arm as
 * the compound `mask &= (u16)~(u16)(1 << idx)` is 8 bytes short (one
 * `lsl`/`lsr` pair missing); the narrowing has to be spelled on the whole
 * assignment, `mask = (u16)((u16)mask & (u16)~(u16)(1 << idx))`.  The
 * set arm is the `orrne` and the clear arm the `mvneq` chain, so the source
 * polarity is `set != 0` first (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_SetBitMask.c \
 *       --func GFL_NET_HANDLE_SetBitMask --addr 0x0203A28C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02034714(const char *file, u32 line, const char *msg);
extern const char file_020A7A68[];
extern const char file_020A7AB0[];

u16 GFL_NET_HANDLE_SetBitMask(u16 mask, u32 idx, u32 set)
{
    if (idx == 0xFF)
        func_02034714(file_020A7A68, 0x391, file_020A7AB0);

    if (set != 0)
        mask |= (u16)(1 << idx);
    else
        mask = (u16)((u16)mask & (u16)~(u16)(1 << idx));

    return mask;
}
