/*
 * function: func_02007400
 * address:  0x02007400
 * packet:   pkt_02007400
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020A7064     0x020A7064  data
 *   func_02034714  0x02034714  arm
 *   func_020319F0  0x020319F0  arm
 *
 * Close sibling of func_020073B0 with a value instead of the object word:
 * the table entry is read into r0 *after* the local is moved to r6, so the
 * argument order at the call is (slot, a2), not (a2, slot).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02007400.c \
 *       --func func_02007400 --addr 0x02007400 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern char g_020A7064[];
extern void func_02034714(char *a, u32 b, char *c);
extern void func_020319F0(u32 a, u32 b);

void func_02007400(char *a0, u32 a1, u32 a2)
{
    u32 *slot = (u32 *)(a0 + 0x14);

    if (slot[a1] == 0) {
        func_02034714(g_020A7064, 0, g_020A7064);
    }
    func_020319F0(slot[a1], a2);
}
