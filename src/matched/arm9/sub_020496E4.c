/*
 * unit:     no
 * function: sub_020496E4
 * address:  0x020496E4
 * packet:   pkt_0204968C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204A1BC       0x0204A1BC  arm
 *   func_0204979C       0x0204979C  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *
 * Loads an archive member with the top bit of its allocation flag word
 * forced on, hands the loaded buffer to func_0204979C to be registered, and
 * releases the loader's handle again. Returning 0 on a failed load is the
 * `movs`/`moveq`/`popeq` triple: the load result is tested by the move that
 * stores it, so no separate `cmp` appears.
 *
 * The flag word is the sixth argument and arrives as a halfword, and
 * func_0204A1BC's fourth parameter is `u16`, which is what turns
 * `(flags & 0x7FFF) | 0x8000` into an `and`/`orr` pair followed by a
 * `lsl #16`/`lsr #16` truncation rather than a single `orr`.
 *
 * The twin of src/matched/sub_02049740.c, differing only in which loader it
 * calls. func_0204A1BC has thirteen further callers image-wide and
 * func_0204979C its second caller at 0x02049780, so both resolve through the
 * `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020496E4.c \
 *       --func sub_020496E4 --addr 0x020496E4 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0204A1BC(u32 a0, u32 a1, u32 a2, u16 a3);
extern u32 func_0204979C(void *buf, u32 a1, u32 a2);
extern void ENV_SetResourceSet(void *p);

u32 sub_020496E4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags)
{
    void *buf;
    u32 res;

    buf = func_0204A1BC(a0, a1, a4, (flags & 0x7FFF) | 0x8000);
    if (buf == 0) {
        return 0;
    }

    res = func_0204979C(buf, a2, a3);
    ENV_SetResourceSet(buf);
    return res;
}
