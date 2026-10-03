/*
 * function: func_02005F24
 * address:  0x02005F24
 * packet:   pkt_02005F24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02072FE8 (arm) reached only by the `blx` inside this function
 *
 * symbols:
 *   func_02072FE8  0x02072FE8  arm
 *
 * Forward two arguments onto one event of the current connection slot:
 * `slot` is the result of sub_0200590C (0x0200590C, matched) and stays in r0
 * across the two parameter moves, which is why the two `adds rN, rN, #0`
 * copies appear after the call rather than before it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02005F24.c \
 *       --func func_02005F24 --addr 0x02005F24 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 *sub_0200590C(void);
struct Obj;
extern void   func_02072FE8(struct Obj *slot, u32 a, int b);

void func_02005F24(u32 a0, u32 a1)
{
    func_02072FE8((struct Obj *)sub_0200590C(), a0, (int)a1);
}
