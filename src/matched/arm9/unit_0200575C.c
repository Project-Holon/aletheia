/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x0200575C
 * packet:   pkt_02005768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_GetArcPath, GFL_USE_WaitInputReady
 *
 * symbols:
 *   _ArcPathTable  0x020A6C58  data
 *   func_02034F5C       0x02034F5C  arm
 *   func_0203630C       0x0203630C  arm
 *
 * A pointer table lookup and a spin loop.  GFL_USE_GetArcPath was already matched
 * as a single function in arm9/legacy.json; it is the first function of this
 * range and is absorbed here.
 *
 * GFL_USE_WaitInputReady waits until four bits of func_0203630C's result are all set,
 * pumping func_02034F5C once per turn.  The four masks are 0x200, 0x100,
 * 0x400 and 0x800 and none of them is materialised with a literal pool word:
 * the compiler builds 0x100 with `movs`/`lsls` and then derives the other
 * three from it with one `lsls` each, hoisted out of the loop.  Testing them
 * as one combined `(x & 0xF00) == 0xF00` gives a single `ldr` from a pool and
 * a different loop, so the four separate short circuited tests are in the
 * source, and their order in the source is 0x200, 0x100, 0x400, 0x800, not
 * the ascending order the hoisted constants suggest.
 */

typedef unsigned int u32;

extern void *_ArcPathTable[];

extern void func_02034F5C(void);
extern unsigned int func_0203630C(void);

void *GFL_USE_GetArcPath(u32 index)
{
    return _ArcPathTable[index];
}

void GFL_USE_WaitInputReady(void)
{
    u32 x;

    do {
        func_02034F5C();
        x = func_0203630C();
    } while (!(x & 0x200) || !(x & 0x100) || !(x & 0x400) || !(x & 0x800));
}
