/*
 * function: func_0201240C
 * address:  0x0201240C
 * packet:   pkt_020123D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4     0x020124E4  thumb
 *   func_020120B4     0x020120B4  thumb
 *   func_020120F0     0x020120F0  thumb
 *
 * A three-state driver.  func_020124E4's result is bound before the switch and
 * is still live in r0 at the case-0 call, which is why the two loads of the
 * state go to r1 (not r0) and the callee's argument registers are r1, r2, r3
 * with r0 carrying the earlier call's result.  Both arms leave through the
 * shared `return 0` tail, so neither may be written as a `return`: writing
 * `return 0` in case 0 makes mwccarm duplicate `movs r0, #0` inline instead of
 * branching to +0x34, and the function comes out six bytes long with the last
 * two arms shifted.  `!= 0` / `== 0` in case 1 makes no difference.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201240C.c \
 *       --func func_0201240C --addr 0x0201240C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct IcaAnime;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
struct Ctx;
extern u32 func_020120F0(const struct Ctx *p);

int func_0201240C(void *o, u32 *state, u32 *item)
{
    u32 v = (u32)func_020124E4(o);

    switch (*state) {
    case 0:
        func_020120B4((struct IcaAnime *)v, item[0], (void *)item[1], (void *)item[2]);
        *state = *state + 1;
        break;
    case 1:
        if (func_020120F0((void *)v) == 0)
            return 1;
        break;
    }
    return 0;
}
