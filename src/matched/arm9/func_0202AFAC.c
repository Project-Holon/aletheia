/*
 * function: func_0202AFAC
 * address:  0x0202AFAC
 * packet:   pkt_0202AFAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0202B0A4  0x0202B0A4  thumb
 *   func_0202B134  0x0202B134  thumb
 *   func_0202B194  0x0202B194  thumb
 *
 * iss_city_unit.c (docs/families/iss_city_unit.h): the first axis: pos[0], radius table at +0x16.
 * EXACT* (the listing extent includes the 2-byte pad).
 *
 * The residue every earlier pass left (docs/notes/func_0202AFAC.c.txt: the
 * stacked fifth argument stored to [sp] before the pp/pc address
 * computations instead of after them) was the const-qualification of the
 * pointers: `const u8 *obj`, `const s32 *pos`, const-pointee callees and
 * const pp/pc.  The three axis twins close with the same change.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AFAC.c  *       --func func_0202AFAC --addr 0x0202AFAC --thumb --cc 1.1p1
 */

typedef int            s32;
typedef unsigned int   u32;
typedef unsigned char  u8;

extern u32 func_0202B0A4(u8 *a0, s32 *a1);
extern s32 func_0202B134(u32 *a0);
extern s32 func_0202B194(s32 a, s32 b, s32 c, s32 d, s32 e);

u8 func_0202AFAC(const u8 *obj, const s32 *pos)
{
    u32 cur;
    u32 prev;
    s32 v;
    s32 d;
    const u8 *pp;
    const u8 *pc;

    cur = func_0202B0A4((u8 *)obj, (s32 *)pos);
    if (cur == 0)
        prev = 0;
    else
        prev = (u8)(cur - 1);

    if (cur == prev)
        return (obj + cur)[0x10];

    v = pos[0] >> 12;
    d = v - func_0202B134((u32 *)obj);
    if (d < 0)
        d = -d;

    pp = obj + prev;
    pc = obj + cur;

    return (u8)func_0202B194(pc[0x16] << 4, pc[0x10],
                             pp[0x16] << 4, pp[0x10], d);
}
