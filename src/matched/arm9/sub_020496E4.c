/*
 * unit:     no
 * function: ARC_UTIL_RegisterObjCharFromArchive
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
 *   ARC_UTIL_LoadMember       0x0204A1BC  arm
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
 * ARC_UTIL_LoadMember's fourth parameter is `u16`, which is what turns
 * `(flags & 0x7FFF) | 0x8000` into an `and`/`orr` pair followed by a
 * `lsl #16`/`lsr #16` truncation rather than a single `orr`.
 *
 * The twin of src/matched/ARC_UTIL_RegisterObjCharFromHandle.c, differing only in which loader it
 * calls. ARC_UTIL_LoadMember has thirteen further callers image-wide and
 * func_0204979C its second caller at 0x02049780, so both resolve through the
 * `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_RegisterObjCharFromArchive.c \
 *       --func ARC_UTIL_RegisterObjCharFromArchive --addr 0x020496E4 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern u32 func_0204979C(void *buf, u32 a1, u32 a2);
extern void ENV_SetResourceSet(void *p);

u32 ARC_UTIL_RegisterObjCharFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags)
{
    void *buf;
    u32 res;

    buf = (void *)ARC_UTIL_LoadMember((u32)a0, (u32)a1, (u32)a4, (u16)((flags & 0x7FFF) | 0x8000));
    if (buf == 0) {
        return 0;
    }

    res = func_0204979C(buf, a2, a3);
    ENV_SetResourceSet(buf);
    return res;
}
