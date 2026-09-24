/*
 * function: func_021DCDD8
 * address:  0x021DCDD8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02021540
 *
 * symbols:
 *
 * Release the two objects hanging off +0x2c/+0x6c.
 *
 * MATCH, not EXACT: the second call site is `bl 0x02021540`, and that address
 * has no witness anywhere in the image outside this function (match.py:
 * "unresolved: 02021540 (thumb, from header) has no witness outside
 * 021DCDD8..021DCDF0").  The first site, 0x020215A0, resolves as a label with
 * 54 references; the two bodies are otherwise identical.  All 24 bytes are
 * right.  Written as a plain call to the address it is, not as a literal
 * function pointer: a `((void(*)(void))0x02021541)()` spelling kills the tail
 * call the image has here.
 */

extern void func_020215A0(void *, int);
extern void func_02021540(void *);

void func_021DCDD8(char *p)
{
    func_020215A0(*(void **)(*(char **)(p + 0x2c) + 0x6c), 0);
    func_02021540(*(void **)(*(char **)(p + 0x2c) + 0x6c));
}
