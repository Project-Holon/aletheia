/*
 * unit:     yes
 * address:  0x02012BE0
 * packet:   pkt_02012924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02012BE0
 *
 * symbols:
 *   func_0200C40C  0x0200C40C  thumb
 *   func_0200C418  0x0200C418  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *
 * One function, 24 bytes, because the function immediately after it is a near
 * miss and the one after that is src/matched/unit_02012C0C.c.
 *
 * 0x02012BF8, 20 bytes, is the twin of this one and reproduces every concrete
 * byte:
 *
 *     void func_02012BF8(void *p, u32 a)
 *     {
 *         func_0200C44C(func_0200C404(func_02012EC0(p)), a);
 *     }
 *
 * with `func_0200C404 0x0200C404 thumb`, `func_0200C44C 0x0200C44C thumb` and
 * `func_02012EC0 0x02012EC0 thumb`.  It caps at MATCH because the `bl` at
 * 0x02012C06 is the only branch to func_0200C44C anywhere in the image, so the
 * `label` class has no witness outside the range and, this being the only
 * caller, no cut can create one.  Evidence class: label, 0 witnesses outside.
 * The other five call targets here all have witnesses elsewhere.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012BE0.c \
 *       --addr 0x02012BE0 --thumb
 */

typedef unsigned int u32;

extern void *func_0200C40C(void *p);
extern void  func_0200C418(void *p, u32 a, u32 b);
struct Big;
extern void *func_02012EBC(struct Big *p);

void func_02012BE0(void *p, u32 a, u32 b)
{
    func_0200C418(func_0200C40C(func_02012EBC(p)), a, b);
}
