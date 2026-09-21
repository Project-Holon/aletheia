/*
 * function: func_02005EB4
 * address:  0x02005EB4
 * packet:   pkt_02005EB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02072FC8 (arm) reached only by the `blx` inside this function
 *
 * symbols:
 *   func_02072FA8  0x02072FA8  arm
 *   func_02072FC8  0x02072FC8  arm
 *
 * Unregister one event from the connection slot's event list: the key handed
 * back is the one's complement of the argument, truncated to 16 bits by the
 * `lsls #16`/`lsrs #16` pair the conversion emits.  0xFFFF is a pool word
 * rather than a `movs`-able constant and is reused as the first call's
 * second argument, which is why it is loaded into a callee-saved register
 * before the first call instead of being rematerialised.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02005EB4.c \
 *       --func func_02005EB4 --addr 0x02005EB4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void  *sub_0200590C(void);
extern void   func_02072FA8(void *slot, u32 key, u32 f);
extern void   func_02072FC8(void *slot, u32 key, u32 f);

void func_02005EB4(u32 a0)
{
    u16 key = (u16)(a0 ^ 0xFFFF);

    func_02072FA8(sub_0200590C(), 0xFFFF, 0);
    if (key != 0) {
        func_02072FC8(sub_0200590C(), key, 1);
    }
}
