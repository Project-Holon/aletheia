/*
 * unit:     yes
 * address:  0x02029CF0
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02029CF0
 *
 * The last function of pkt_020295D8, and not a task at all: it resolves a
 * sequence id for the request and issues one command 5 for it, with the fifth
 * argument 60 or 0 depending on a mode query.  func_02029E74 answers 0xFFFFFFFF
 * when it has no id of its own and func_02029E64 is the fallback.
 *
 * The mode test's two arms leave `movs r3, #0x3c` duplicated and cross-jump
 * everything after it, which is what says both the fourth and the fifth
 * argument are locals assigned in each arm, and that the fourth is assigned
 * the same 60 in both.  Passing the literal 60 at a single call site after the
 * `if` hoists that `movs` out of the arms; writing the whole call in each arm
 * duplicates the call as well
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * VERSION SENSITIVITY: 60 is a frame count, not a content id.
 *
 * symbols:
 *   func_02012984  0x02012984  thumb
 *   func_020289F8  0x020289F8  thumb
 *   func_02029E58  0x02029E58  thumb
 *   func_02029E64  0x02029E64  thumb
 *   func_02029E74  0x02029E74  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029CF0.c \
 *       --addr 0x02029CF0 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02012984(void *a);
extern u32   func_02029E74(void *a, void *b);
extern u32   func_02029E64(void *a, void *b, void *pri);
extern u32   func_02029E58(void *a);
extern void  func_020289F8(void *sys, u32 a, u32 b, u16 c, u16 d);

void func_02029CF0(void *sys, void *a, void *b)
{
    void *pri = func_02012984(a);
    u32 id = func_02029E74(a, b);
    u16 c;
    u16 v;

    if (id == 0xFFFFFFFF) {
        id = func_02029E64(a, b, pri);
    }
    if (func_02029E58(a) == 1) {
        c = 0x3C;
        v = 0x3C;
    } else {
        c = 0x3C;
        v = 0;
    }
    func_020289F8(sys, 5, id, c, v);
}
