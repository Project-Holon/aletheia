/*
 * function: sub_02034F5C
 * address:  0x02034F5C
 * packet:   pkt_02034714
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02034F5C_Ptr  0x021469BC  data
 *   func_02034EF8   0x02034EF8  arm
 *
 * A tail call, `ldr r3,[pc]`/`bx r3`, passing one argument through: the
 * value of a global pointer, dereferenced once.
 *
 * Every concrete byte matches; neither the global pointer nor the callee
 * (both single-use, so far, in this ROM) has a witness outside this one
 * function, so both ABS32 sites stay unresolved under the honesty rule.
 * The tool also reports the original's listing extent as 40 bytes against
 * this function's 24: the territory ends at 0x02034FA0 with no further
 * label, so `disasm.py`'s extent runs into an unlabelled follower the
 * same way docs/MATCHING.md's "two missing labels" section describes.
 * That follower is outside this file's scope.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02034F5C.c \
 *       --func sub_02034F5C --addr 0x02034F5C --cc 1.1p1 --arm
 */

extern void *g_02034F5C_Ptr;
extern void func_02034EF8(void *a);

void sub_02034F5C(void)
{
    func_02034EF8(g_02034F5C_Ptr);
}
