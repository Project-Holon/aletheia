/*
 * unit:     no
 * function: sub_0204989C
 * address:  0x0204989C
 * packet:   pkt_0204968C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_02049A18  0x02049A18  arm
 *
 * Seven-argument front end: load an archive member with the top allocation
 * bit forced on, exactly as src/matched/sub_020496E4.c does, and forward the
 * buffer to func_02049A18 with two of its six arguments pinned to zero. The
 * handle is not released here; func_02049A18 does that itself (see its
 * near-miss note in docs/notes/func_02049A18.c.txt, which is where its
 * six-argument shape comes from).
 *
 * The two zeros are one `mov r3, #0` reused for the register argument and
 * the stack argument, so the stack store of a4 has to be emitted between the
 * two: writing the zeros first costs a second materialisation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204989C.c \
 *       --func sub_0204989C --addr 0x0204989C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0204A1BC(u32 a0, u32 a1, u32 a2, u16 a3);
extern void func_02049A18(void *buf, u32 a1, u32 a2, u32 a3, u32 a4,
                          u32 flag);

void sub_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags)
{
    func_02049A18(func_0204A1BC(a0, a1, a5, (flags & 0x7FFF) | 0x8000),
                  a2, a3, 0, a4, 0);
}
