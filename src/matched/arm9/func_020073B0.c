/*
 * function: func_020073B0
 * address:  0x020073B0
 * packet:   pkt_02007374
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02031C30 (arm) reached only by the `blx` inside this function
 *
 * symbols:
 *   g_020A7064     0x020A7064  data
 *   func_02034714  0x02034714  arm
 *   func_02031C30  0x02031C30  arm
 *
 * The shortest member of the 0x14-stride handle-table family: guard, then
 * one call taking the object's +0x10 word and the table entry.  Same
 * double-named guard pointer as func_02007374 and func_02007400.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020073B0.c \
 *       --func func_020073B0 --addr 0x020073B0 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern char g_020A7064[];
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Obj;
extern int func_02031C30(struct Obj *a, struct Obj *b);

void func_020073B0(char *a0, u32 a1)
{
    u32 *slot = (u32 *)(a0 + 0x14);

    if (slot[a1] == 0) {
        func_02034714(g_020A7064, 0, g_020A7064);
    }
    func_02031C30((struct Obj *)*(u32 *)(a0 + 0x10), (struct Obj *)slot[a1]);
}
